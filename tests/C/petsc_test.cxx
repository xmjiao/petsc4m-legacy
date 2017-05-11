#include <petscksp.h>
#include <stdio.h>
#include <petsctime.h>
#include <petscsys.h> 

//Usage:

//mpirun -np 1 ./petsc_test -f testmat.txt -ksp_rtol 1e-10 -pc_type hypre -ksp_monitor_true_residual -ksp_converged_reason


//PetscErrorCode AssembleSystem(Mat &A,Vec &sys_rhs,Vec &x, int matsize, int *row_ptr, int *col_ind, double *vals, double *rhs);

#undef __FUNCT__
#define __FUNCT__ "main"
int main(int argc,char **args)
{
   int    i, matsize, *row_ptr, *col_ind;
   MatNullSpace nullsp;
   double  *vals, *rhs;
   PetscMPIInt    size;
   char filename[PETSC_MAX_PATH_LEN];
   PetscBool      flg;
   PetscErrorCode  ierr;
   KSP            ksp;
   Vec            x,sys_rhs;
   Mat            A;

  PetscInitialize(&argc,&args,(char*)0,NULL);
  ierr = MPI_Comm_size(PETSC_COMM_WORLD,&size);CHKERRQ(ierr);
//  ierr = PetscOptionsGetString(NULL,"-f",filename,sizeof(filename),&flg);CHKERRQ(ierr);
  ierr = PetscOptionsGetString(NULL,NULL,"-f",filename,sizeof(filename),&flg);CHKERRQ(ierr);
  
  //read data from file

   if (!flg) {
       printf("failed to get file name\n");
       exit(0);
   }

   FILE *fp;
   fp = fopen (filename, "r");
    if (fp==NULL) {
        printf("Can't open this file\n");
        exit(0);
    }

   //load dimensions
   fscanf(fp, "%d",&matsize);

  //Step 1: Assemble solution vector x
  ierr = VecCreate(PETSC_COMM_WORLD,&x);CHKERRQ(ierr);
  ierr = VecSetSizes(x,PETSC_DECIDE,matsize);CHKERRQ(ierr);
  ierr = VecSetFromOptions(x);CHKERRQ(ierr);
  ierr = VecSet(x,0);CHKERRQ(ierr);

  //Step 2: Assemble rhs
  ierr = VecCreate(PETSC_COMM_WORLD,&sys_rhs);CHKERRQ(ierr);
  ierr = VecSetSizes(sys_rhs,PETSC_DECIDE,matsize);CHKERRQ(ierr);
  ierr = VecSetFromOptions(sys_rhs);CHKERRQ(ierr);

  //Fill in the values
  //Get ownership
  PetscInt ownerstart, ownerend, localsize, iglobal;
  ierr = VecGetOwnershipRange(sys_rhs, &ownerstart, &ownerend);CHKERRQ(ierr);
  localsize = ownerend-ownerstart;


   //Read the remaining data according to Petsc's partition
   row_ptr = (int *) malloc(sizeof(int)*(localsize+1));
   PetscInt local_ind = 0, temp_ind;
   PetscScalar temp_val;

   for (i=0;i<=matsize;i++) {
     fscanf(fp, "%d",&temp_ind);    
     if(i>=ownerstart && i<=ownerend) {
       row_ptr[local_ind]=temp_ind-1;
       local_ind++;
     }
   }

   int local_nnz = row_ptr[localsize]-row_ptr[0];
   int global_nnz = temp_ind - 1;

   PetscPrintf(PETSC_COMM_WORLD,"Global(local on proc 0) matsize=%d (%d)\n",matsize,localsize);
   PetscPrintf(PETSC_COMM_WORLD,"Global(local on proc 0) nnz= %d (%d)\n",global_nnz,local_nnz);

   col_ind = (int *) malloc(sizeof(int)*local_nnz);
   vals = (double *) malloc(sizeof(double)*local_nnz);
   rhs = (double *) malloc(sizeof(double)*localsize);

   local_ind = 0;
   for (i=0;i<global_nnz;i++) {
     fscanf(fp, "%d",&temp_ind);
     if(i>=row_ptr[0] && i<row_ptr[localsize]) {
       col_ind[local_ind] = temp_ind-1;
       local_ind++;
     }
   }

   local_ind = 0;
   for (i=0;i<global_nnz;i++) {
     fscanf(fp, "%lf",&temp_val);
     if(i>=row_ptr[0] && i<row_ptr[localsize]) {
       vals[local_ind] = temp_val;
       local_ind++;
     }
   }

   local_ind = 0;
   for (i=0;i<matsize;i++) {
     fscanf(fp, "%lf",&temp_val);
     if(i>=ownerstart && i<ownerend) {
       rhs[local_ind]=temp_val;
       local_ind++;
     }
   }

   fclose(fp);


  int rowind,colind;
  double value;

  for(int i=0;i<localsize;i++) {
    iglobal=i+ownerstart;
    value=rhs[i];
    ierr = VecSetValues(sys_rhs,1,&iglobal,&value,INSERT_VALUES);CHKERRQ(ierr);
  }

  //Step 3: Assemble matrix A

  ierr = MatCreate(PETSC_COMM_WORLD,&A);CHKERRQ(ierr);
  ierr = MatSetType(A,MATAIJ);CHKERRQ(ierr);
  ierr = MatSetSizes(A,PETSC_DECIDE,PETSC_DECIDE,matsize,matsize);CHKERRQ(ierr);
  ierr = MatSetFromOptions(A);CHKERRQ(ierr);

  //Preallocation
  //Calculate sparsity pattern
  PetscInt *d_nnz, *o_nnz;
  d_nnz = (PetscInt *) malloc(sizeof(PetscInt)*localsize);
  o_nnz = (PetscInt *) malloc(sizeof(PetscInt)*localsize);

  //Go over the crs format and count number of nonzeroes
  for(int i=0;i<localsize;i++) {
    d_nnz[i]=0;
    o_nnz[i]=0;
    for(int j=row_ptr[i]-row_ptr[0];j<row_ptr[i+1]-row_ptr[0];j++) {
      if(col_ind[j]>=ownerstart && col_ind[j]<ownerend) {
        d_nnz[i]++;//Diagonal portion of the local matrix on core
      }
      else {
        o_nnz[i]++;//off core
      }
    }
  }

  
  ierr = MatSeqAIJSetPreallocation(A, 2, d_nnz); CHKERRQ(ierr);
  ierr = MatMPIAIJSetPreallocation(A, 2, d_nnz, 2, o_nnz);CHKERRQ(ierr);

  //Fill in the values
  for(int i=0;i<localsize;i++) {
    rowind=i+ownerstart;
    for(int j=row_ptr[i]-row_ptr[0];j<row_ptr[i+1]-row_ptr[0];j++) {
      colind=col_ind[j];
      value=vals[j];
      ierr = MatSetValues(A,1,&rowind,1,&colind,&value,INSERT_VALUES);CHKERRQ(ierr);
    }
  }

  ierr = MatAssemblyBegin(A,MAT_FINAL_ASSEMBLY);CHKERRQ(ierr);
  ierr = MatAssemblyEnd(A,MAT_FINAL_ASSEMBLY);CHKERRQ(ierr);
  ierr = VecAssemblyBegin(sys_rhs);CHKERRQ(ierr);
  ierr = VecAssemblyEnd(sys_rhs);CHKERRQ(ierr);


   //Create KSP context and solve the system
   ierr = KSPCreate(PETSC_COMM_WORLD,&ksp);CHKERRQ(ierr);

   PetscLogDouble time_start, time_end;
   PetscTime(&time_start);CHKERRQ(ierr);
   ierr = KSPSetOperators(ksp,A,A);CHKERRQ(ierr);
   //MPI_Barrier(PETSC_COMM_WORLD);
   //PetscTime(&time_end);CHKERRQ(ierr);
  // PetscPrintf(PETSC_COMM_WORLD, "setup time is %f\n", time_end-time_start);
//MPI_Barrier(PETSC_COMM_WORLD);
  // PetscTime(&time_end);CHKERRQ(ierr);
   //PetscPrintf(PETSC_COMM_WORLD, "setup time is %f\n", time_end-time_start);


   ierr = KSPSetFromOptions(ksp);CHKERRQ(ierr);
 //  MPI_Barrier(PETSC_COMM_WORLD);
  // PetscTime(&time_end);CHKERRQ(ierr);
  //PetscPrintf(PETSC_COMM_WORLD, "setup time is %f\n", time_end-time_start);
//   MatNullSpaceCreate(PETSC_COMM_WORLD, PETSC_TRUE, 0, NULL, &nullsp);CHKERRQ(ierr);
//   MatSetNullSpace(A,nullsp);CHKERRQ(ierr);
//  printf("The Null space is ", &nullsp);
//   MatNullSpaceDestroy(&nullsp);CHKERRQ(ierr);
   //cout << "Null space has been taken care of" <<std:: endl;
//  printf("Null space has been taken care of,.. \n"); 
   ierr = KSPSetUp(ksp);CHKERRQ(ierr);

   MPI_Barrier(PETSC_COMM_WORLD);
   PetscTime(&time_end);CHKERRQ(ierr);
   PetscPrintf(PETSC_COMM_WORLD, "setup time is %f\n", time_end-time_start);

   MPI_Barrier(PETSC_COMM_WORLD);
   PetscTime(&time_start);CHKERRQ(ierr);
   ierr = KSPSolve(ksp,sys_rhs,x);CHKERRQ(ierr);
   MPI_Barrier(PETSC_COMM_WORLD);
   PetscTime(&time_end);CHKERRQ(ierr);

   PetscPrintf(PETSC_COMM_WORLD, "solve time is %f\n", time_end-time_start);
   //PetscPrintf(PETSC_COMM_WORLD,"Solution x= %f\n",x);
   //VecView(x, PETSC_VIEWER_STDOUT_SELF);

  ierr = KSPDestroy(&ksp);CHKERRQ(ierr);
  ierr = MatDestroy(&A);CHKERRQ(ierr);
  ierr = VecDestroy(&x);CHKERRQ(ierr);
  ierr = VecDestroy(&sys_rhs);CHKERRQ(ierr);

   free(row_ptr);
   free(col_ind);
   free(vals);
   free(rhs);
   free(d_nnz);
   free(o_nnz);

   ierr = PetscFinalize();
   return 0;
}


  /*double *solution;
  ierr = VecGetArray(x,&solution);CHKERRQ(ierr);

  fp = fopen ("result.txt", "w");
  for (i=0;i<Nx*Ny;i++) {
    fprintf(fp, "%.12f\n", solution[i]);
  }
  fclose(fp);
  ierr = VecRestoreArray(x,&solution);CHKERRQ(iter);*/
