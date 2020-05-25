#include "petscSolveCRS.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static const char cv[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

static void b_m2c_error(int varargin_3);
static void b_m2c_printf(double varargin_2, int varargin_3);
static void b_petscKSPDriver(KSP ksp, Vec b, Vec x, double rtol, int maxits, Vec
  x0, int *flag, double *relres, int *iter, emxArray_real_T *reshis, double
  *time);
static void b_petscKSPSetup(Mat Amat, const emxArray_char_T *ksptype, const
  emxArray_char_T *pctype, const emxArray_char_T *pcopt, KSP *ksp, double *time);
static void c_m2c_printf(double varargin_2, double varargin_3);
static void d_m2c_printf(int varargin_2, double varargin_3);
static void e_m2c_printf(void);
static void m2c_error(void);
static void m2c_printf(KSPType varargin_2, PCType varargin_3, const
  emxArray_char_T *varargin_4, int varargin_5);
static void petscKSPDriver(KSP ksp, Vec b, Vec x, Vec x0, int *flag, double
  *relres, int *iter, emxArray_real_T *reshis, double *time);
static void petscKSPSetup(Mat Amat, const emxArray_char_T *ksptype, KSP *ksp,
  double *time);
static Mat petscMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val);
static Vec petscVecCreateFromArray(const emxArray_real_T *arr);
static void petscVecToArray(Vec vec, emxArray_real_T *arr);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "PetscOptionsInsertString returned error code %d\n", varargin_3);
}

static void b_m2c_printf(double varargin_2, int varargin_3)
{
  M2C_printf("### The relative residual was %g after %d iterations.\n",
             varargin_2, varargin_3);
}

static void b_petscKSPDriver(KSP ksp, Vec b, Vec x, double rtol, int maxits, Vec
  x0, int *flag, double *relres, int *iter, emxArray_real_T *reshis, double
  *time)
{
  int type;
  double bnrm;
  PetscObject t_obj;
  MPI_Comm comm;
  double t;
  int val;
  boolean_T b_b;
  double secs;
  double res;
  double b_rtol;
  double abstol;
  double dtol;
  int b_maxits;
  emxArray_char_T *side;
  PC pc;
  PetscReal * a;
  int na;
  int switch_expression;
  static const char b_cv[5] = { 'r', 'i', 'g', 'h', 't' };

  KSPType b_type;
  PCType c_type;
  type = (NORM_2);
  VecNorm(b, type, &bnrm);
  t_obj = (PetscObject)(ksp);
  PetscObjectGetComm(t_obj, &comm);
  MPI_Barrier(comm);
  t = MPI_Wtime();
  if (maxits == 0) {
    maxits = (PETSC_DEFAULT);
  }

  if (rtol == 0.0) {
    type = (PETSC_DEFAULT);
    rtol = type;
  }

  type = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  KSPSetTolerances(ksp, rtol, (double)type, (double)val, maxits);
  type = !(x0);
  b_b = (type == 0);
  if (b_b) {
    VecCopy(x0, x);
  }

  type = (PETSC_TRUE);
  KSPSetResidualHistory(ksp, NULL, maxits, type);
  KSPSetInitialGuessNonzero(ksp, (int)b_b);
  KSPSolve(ksp, b, x);
  MPI_Barrier(comm);
  secs = MPI_Wtime();
  KSPGetConvergedReason(ksp, flag);
  KSPGetResidualNorm(ksp, &res);
  KSPGetIterationNumber(ksp, iter);
  *relres = res / bnrm;
  KSPGetTolerances(ksp, &b_rtol, &abstol, &dtol, &b_maxits);
  emxInit_char_T(&side, 2);
  if ((*flag < 0) || (*relres > b_rtol)) {
    KSPGetPC(ksp, &pc);
    val = (PC_LEFT);
    type = (PC_RIGHT);
    KSPGetPCSide(ksp, &switch_expression);
    if (val == switch_expression) {
      type = 0;
    } else if (type == switch_expression) {
      type = 1;
    } else {
      type = -1;
    }

    switch (type) {
     case 0:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity_char_T(side, type);
      side->data[0] = 'l';
      side->data[1] = 'e';
      side->data[2] = 'f';
      side->data[3] = 't';
      break;

     case 1:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity_char_T(side, type);
      for (type = 0; type < 5; type++) {
        side->data[type] = b_cv[type];
      }
      break;

     default:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity_char_T(side, type);
      for (type = 0; type < 9; type++) {
        side->data[type] = cv[type];
      }
      break;
    }

    KSPGetType(ksp, &b_type);
    PCGetType(pc, &c_type);
    m2c_printf(b_type, c_type, side, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(b_maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  KSPGetResidualHistory(ksp, &a, &na);
  type = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity_real_T(reshis, type);
  for (type = 0; type < na; type++) {
    reshis->data[type] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  *time = secs - t;
}

static void b_petscKSPSetup(Mat Amat, const emxArray_char_T *ksptype, const
  emxArray_char_T *pctype, const emxArray_char_T *pcopt, KSP *ksp, double *time)
{
  PetscObject t_obj;
  MPI_Comm t_comm;
  PC t_pc;
  boolean_T hasPC;
  boolean_T hasOpt;
  emxArray_char_T *pctype0;
  emxArray_char_T *ksptype0;
  int i;
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  static const char b_cv[4] = { 'l', 'e', 'f', 't' };

  static const char cv1[5] = { 'r', 'i', 'g', 'h', 't' };

  MPI_Comm comm;
  double t;
  double secs;
  t_obj = (PetscObject)(Amat);
  PetscObjectGetComm(t_obj, &t_comm);
  KSPCreate(t_comm, ksp);
  KSPGetPC(*ksp, &t_pc);
  KSPSetOperators(*ksp, Amat, Amat);
  hasPC = (pctype->size[1] != 0);
  hasOpt = (pcopt->size[1] != 0);
  emxInit_char_T(&pctype0, 2);
  if (hasPC || hasOpt) {
    if (hasPC) {
      if (pctype->data[pctype->size[1] - 1] != '\x00') {
        i = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1] + 1;
        emxEnsureCapacity_char_T(pctype0, i);
        k = pctype->size[1];
        for (i = 0; i < k; i++) {
          pctype0->data[i] = pctype->data[i];
        }

        pctype0->data[pctype->size[1]] = '\x00';
      } else {
        i = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1];
        emxEnsureCapacity_char_T(pctype0, i);
        k = pctype->size[0] * pctype->size[1];
        for (i = 0; i < k; i++) {
          pctype0->data[i] = pctype->data[i];
        }
      }

      PCSetType(t_pc, &pctype0->data[0]);
    }

    if (hasOpt) {
      p = (pcopt->size[1] == 4);
      if (p && (pcopt->size[1] != 0)) {
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 4)) {
          if (!(pcopt->data[k] == b_cv[k])) {
            p = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      b_p = (int)p;
      if (b_p) {
        k = (PC_LEFT);
        KSPSetPCSide(*ksp, k);
      } else {
        p = (pcopt->size[1] == 5);
        if (p && (pcopt->size[1] != 0)) {
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k < 5)) {
            if (!(pcopt->data[k] == cv1[k])) {
              p = false;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }

        b_p = (int)p;
        if (b_p) {
          k = (PC_RIGHT);
          KSPSetPCSide(*ksp, k);
        } else {
          p = (pcopt->size[1] == 9);
          if (p && (pcopt->size[1] != 0)) {
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 9)) {
              if (!(pcopt->data[k] == cv[k])) {
                p = false;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }

          b_p = (int)p;
          if (b_p) {
            k = (PC_SYMMETRIC);
            KSPSetPCSide(*ksp, k);
          }
        }
      }
    }
  }

  emxFree_char_T(&pctype0);
  emxInit_char_T(&ksptype0, 2);
  if ((ksptype->size[1] != 0) && ((unsigned char)ksptype->data[ksptype->size[1]
       - 1] != 0)) {
    i = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity_char_T(ksptype0, i);
    k = ksptype->size[1];
    for (i = 0; i < k; i++) {
      ksptype0->data[i] = ksptype->data[i];
    }

    ksptype0->data[ksptype->size[1]] = '\x00';
  } else {
    i = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1];
    emxEnsureCapacity_char_T(ksptype0, i);
    k = ksptype->size[0] * ksptype->size[1];
    for (i = 0; i < k; i++) {
      ksptype0->data[i] = ksptype->data[i];
    }
  }

  if (ksptype0->size[1] != 0) {
    KSPSetType(*ksp, &ksptype0->data[0]);
  }

  emxFree_char_T(&ksptype0);
  if (pcopt->size[1] == 0) {
    k = (PC_RIGHT);
    KSPSetPCSide(*ksp, k);
  }

  KSPSetFromOptions(*ksp);
  t_obj = (PetscObject)(*ksp);
  PetscObjectGetComm(t_obj, &comm);
  MPI_Barrier(comm);
  t = MPI_Wtime();
  KSPSetUp(*ksp);
  MPI_Barrier(comm);
  secs = MPI_Wtime();
  *time = secs - t;
}

static void c_m2c_printf(double varargin_2, double varargin_3)
{
  M2C_printf("### The relative and absolute tolerances were %g and %g.\n",
             varargin_2, varargin_3);
}

static void d_m2c_printf(int varargin_2, double varargin_3)
{
  M2C_printf("### The divergence and max-iter tolerances were %d and %g.\n",
             varargin_2, varargin_3);
}

static void e_m2c_printf(void)
{
  M2C_printf("### For explanation of the flag, see http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPConvergedReason.html.\n");
}

static void m2c_error(void)
{
  M2C_error("Petsc4m:petscOptionsInsertString:InputError",
            "The argument must be a null-terminated string.");
}

static void m2c_printf(KSPType varargin_2, PCType varargin_3, const
  emxArray_char_T *varargin_4, int varargin_5)
{
  emxArray_char_T *b_varargin_4;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_4, 2);
  i = b_varargin_4->size[0] * b_varargin_4->size[1];
  b_varargin_4->size[0] = 1;
  b_varargin_4->size[1] = varargin_4->size[1];
  emxEnsureCapacity_char_T(b_varargin_4, i);
  loop_ub = varargin_4->size[0] * varargin_4->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_4->data[i] = varargin_4->data[i];
  }

  M2C_printf("### %s with %s as %s preconditioner stopped with flag %d.\n",
             varargin_2, varargin_3, &b_varargin_4->data[0], varargin_5);
  emxFree_char_T(&b_varargin_4);
}

static void petscKSPDriver(KSP ksp, Vec b, Vec x, Vec x0, int *flag, double
  *relres, int *iter, emxArray_real_T *reshis, double *time)
{
  int type;
  double bnrm;
  PetscObject t_obj;
  MPI_Comm comm;
  double t;
  int maxits;
  int val;
  int b_val;
  boolean_T b_b;
  double secs;
  double res;
  double rtol;
  double abstol;
  double dtol;
  emxArray_char_T *side;
  PC pc;
  PetscReal * a;
  int na;
  static const char b_cv[5] = { 'r', 'i', 'g', 'h', 't' };

  KSPType b_type;
  PCType c_type;
  type = (NORM_2);
  VecNorm(b, type, &bnrm);
  t_obj = (PetscObject)(ksp);
  PetscObjectGetComm(t_obj, &comm);
  MPI_Barrier(comm);
  t = MPI_Wtime();
  maxits = (PETSC_DEFAULT);
  type = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  b_val = (PETSC_DEFAULT);
  KSPSetTolerances(ksp, (double)type, (double)val, (double)b_val, maxits);
  type = !(x0);
  b_b = (type == 0);
  if (b_b) {
    VecCopy(x0, x);
  }

  type = (PETSC_TRUE);
  KSPSetResidualHistory(ksp, NULL, maxits, type);
  KSPSetInitialGuessNonzero(ksp, (int)b_b);
  KSPSolve(ksp, b, x);
  MPI_Barrier(comm);
  secs = MPI_Wtime();
  KSPGetConvergedReason(ksp, flag);
  KSPGetResidualNorm(ksp, &res);
  KSPGetIterationNumber(ksp, iter);
  *relres = res / bnrm;
  KSPGetTolerances(ksp, &rtol, &abstol, &dtol, &maxits);
  emxInit_char_T(&side, 2);
  if ((*flag < 0) || (*relres > rtol)) {
    KSPGetPC(ksp, &pc);
    val = (PC_LEFT);
    type = (PC_RIGHT);
    KSPGetPCSide(ksp, &b_val);
    if (val == b_val) {
      type = 0;
    } else if (type == b_val) {
      type = 1;
    } else {
      type = -1;
    }

    switch (type) {
     case 0:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity_char_T(side, type);
      side->data[0] = 'l';
      side->data[1] = 'e';
      side->data[2] = 'f';
      side->data[3] = 't';
      break;

     case 1:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity_char_T(side, type);
      for (type = 0; type < 5; type++) {
        side->data[type] = b_cv[type];
      }
      break;

     default:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity_char_T(side, type);
      for (type = 0; type < 9; type++) {
        side->data[type] = cv[type];
      }
      break;
    }

    KSPGetType(ksp, &b_type);
    PCGetType(pc, &c_type);
    m2c_printf(b_type, c_type, side, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  KSPGetResidualHistory(ksp, &a, &na);
  type = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity_real_T(reshis, type);
  for (type = 0; type < na; type++) {
    reshis->data[type] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  *time = secs - t;
}

static void petscKSPSetup(Mat Amat, const emxArray_char_T *ksptype, KSP *ksp,
  double *time)
{
  PetscObject t_obj;
  MPI_Comm t_comm;
  PC t_pc;
  emxArray_char_T *ksptype0;
  int i;
  int loop_ub;
  MPI_Comm comm;
  double t;
  double secs;
  t_obj = (PetscObject)(Amat);
  PetscObjectGetComm(t_obj, &t_comm);
  KSPCreate(t_comm, ksp);
  KSPGetPC(*ksp, &t_pc);
  KSPSetOperators(*ksp, Amat, Amat);
  emxInit_char_T(&ksptype0, 2);
  if ((ksptype->size[1] != 0) && ((unsigned char)ksptype->data[ksptype->size[1]
       - 1] != 0)) {
    i = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity_char_T(ksptype0, i);
    loop_ub = ksptype->size[1];
    for (i = 0; i < loop_ub; i++) {
      ksptype0->data[i] = ksptype->data[i];
    }

    ksptype0->data[ksptype->size[1]] = '\x00';
  } else {
    i = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1];
    emxEnsureCapacity_char_T(ksptype0, i);
    loop_ub = ksptype->size[0] * ksptype->size[1];
    for (i = 0; i < loop_ub; i++) {
      ksptype0->data[i] = ksptype->data[i];
    }
  }

  if (ksptype0->size[1] != 0) {
    KSPSetType(*ksp, &ksptype0->data[0]);
  }

  emxFree_char_T(&ksptype0);
  loop_ub = (PC_RIGHT);
  KSPSetPCSide(*ksp, loop_ub);
  KSPSetFromOptions(*ksp);
  t_obj = (PetscObject)(*ksp);
  PetscObjectGetComm(t_obj, &comm);
  MPI_Barrier(comm);
  t = MPI_Wtime();
  KSPSetUp(*ksp);
  MPI_Barrier(comm);
  secs = MPI_Wtime();
  *time = secs - t;
}

static Mat petscMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val)
{
  Mat mat;
  emxArray_int32_T *nnz;
  int n;
  int i;
  int b_i;
  int nz;
  emxArray_int32_T *jidx;
  emxArray_real_T *rowval;
  int i1;
  int type;
  int loop_ub;
  int iroa;
  emxInit_int32_T(&nnz, 1);
  n = row_ptr->size[0] - 1;
  i = nnz->size[0];
  nnz->size[0] = row_ptr->size[0] - 1;
  emxEnsureCapacity_int32_T(nnz, i);
  for (b_i = 0; b_i < n; b_i++) {
    nnz->data[b_i] = row_ptr->data[b_i + 1] - row_ptr->data[b_i];
  }

  nz = (PETSC_DEFAULT);
  MatCreateSeqAIJ(PETSC_COMM_SELF, row_ptr->size[0] - 1, row_ptr->size[0] - 1,
                  nz, &nnz->data[0], &mat);
  emxInit_int32_T(&jidx, 1);
  emxInit_real_T(&rowval, 1);
  for (b_i = 0; b_i < n; b_i++) {
    i = row_ptr->data[b_i + 1] - 1;
    if (row_ptr->data[b_i] > i) {
      nz = 0;
      i1 = 0;
    } else {
      nz = row_ptr->data[b_i] - 1;
      i1 = i;
    }

    loop_ub = i1 - nz;
    i1 = jidx->size[0];
    jidx->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(jidx, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      jidx->data[i1] = col_ind->data[nz + i1] - 1;
    }

    if (row_ptr->data[b_i] > i) {
      nz = 0;
      i = 0;
    } else {
      nz = row_ptr->data[b_i] - 1;
    }

    loop_ub = i - nz;
    i = rowval->size[0];
    rowval->size[0] = loop_ub;
    emxEnsureCapacity_real_T(rowval, i);
    for (i = 0; i < loop_ub; i++) {
      rowval->data[i] = val->data[nz + i];
    }

    iroa = (INSERT_VALUES);
    MatSetValues(mat, 1, &b_i, nnz->data[b_i], &jidx->data[0], &rowval->data[0],
                 iroa);
  }

  emxFree_real_T(&rowval);
  emxFree_int32_T(&jidx);
  emxFree_int32_T(&nnz);
  type = (MAT_FINAL_ASSEMBLY);
  MatAssemblyBegin(mat, type);
  type = (MAT_FINAL_ASSEMBLY);
  MatAssemblyEnd(mat, type);
  return mat;
}

static Vec petscVecCreateFromArray(const emxArray_real_T *arr)
{
  Vec vec;
  emxArray_int32_T *y;
  int n;
  int k;
  emxArray_int32_T *idx;
  int yk;
  int iroa;
  emxInit_int32_T(&y, 2);
  VecCreateSeq(PETSC_COMM_SELF, arr->size[0], &vec);
  if (arr->size[0] - 1 < 0) {
    n = 0;
  } else {
    n = arr->size[0];
  }

  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, k);
  if (n > 0) {
    y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx->data[k] = y->data[k];
  }

  emxFree_int32_T(&y);
  iroa = (INSERT_VALUES);
  VecSetValues(vec, arr->size[0], &idx->data[0], &arr->data[0], iroa);
  VecAssemblyBegin(vec);
  VecAssemblyEnd(vec);
  emxFree_int32_T(&idx);
  return vec;
}

static void petscVecToArray(Vec vec, emxArray_real_T *arr)
{
  emxArray_int32_T *y;
  int n;
  int k;
  int b_n;
  emxArray_int32_T *idx;
  int yk;
  emxInit_int32_T(&y, 2);
  VecGetLocalSize(vec, &n);
  k = arr->size[0];
  arr->size[0] = n;
  emxEnsureCapacity_real_T(arr, k);
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }

  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity_int32_T(y, k);
  if (b_n > 0) {
    y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx->data[k] = y->data[k];
  }

  emxFree_int32_T(&y);
  VecGetValues(vec, n, &idx->data[0], &arr->data[0]);
  emxFree_int32_T(&idx);
}

void petscSolveCRS(int *flag, double *relres, int *iter, double times[2])
{
  *flag = -1;
  *relres = 1.7976931348623157E+308;
  *iter = 0;
  times[0] = 0.0;
  times[1] = 0.0;
}

void petscSolveCRS_10args(const emxArray_int32_T *Arows, const emxArray_int32_T *
  Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, const emxArray_real_T *x0,
  emxArray_real_T *x, int *flag, double *relres, int *iter, emxArray_real_T
  *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec x0Vec;
  Vec xVec;
  KSP ksp;
  double time_setup;
  double time_solve;
  KSP t_ksp;
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  if (x0->size[0] == 0) {
    x0Vec = NULL;
    VecDuplicate(bVec, &xVec);
  } else {
    x0Vec = petscVecCreateFromArray(x0);
    xVec = x0Vec;
  }

  b_petscKSPSetup(AMat, solver, pctype, solpack, &ksp, &time_setup);
  b_petscKSPDriver(ksp, bVec, xVec, rtol, maxiter, x0Vec, flag, relres, iter,
                   reshis, &time_solve);
  times[0] = time_setup;
  times[1] = time_solve;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(xVec, x);
  t_vec = xVec;
  VecDestroy(&t_vec);
}

void petscSolveCRS_11args(const emxArray_int32_T *Arows, const emxArray_int32_T *
  Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, const emxArray_real_T *x0, const
  emxArray_char_T *opts, emxArray_real_T *x, int *flag, double *relres, int
  *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec x0Vec;
  Vec xVec;
  emxArray_char_T *opts1;
  KSP ksp;
  double time_setup;
  int matchPos;
  int j;
  int exitg1;
  static const char b_cv[24] = { '-', 'm', 'a', 't', '_', 's', 'u', 'p', 'e',
    'r', 'l', 'u', '_', 'p', 'r', 'i', 'n', 't', 's', 't', 'a', 't', ' ', '1' };

  KSP t_ksp;
  double time_solve;
  static const char in_str[25] = "-mat_superlu_printstat 0";
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  if (x0->size[0] == 0) {
    x0Vec = NULL;
    VecDuplicate(bVec, &xVec);
  } else {
    x0Vec = petscVecCreateFromArray(x0);
    xVec = x0Vec;
  }

  if (opts->size[1] != 0) {
    emxInit_char_T(&opts1, 2);
    if (opts->data[opts->size[1] - 1] != '\x00') {
      j = opts1->size[0] * opts1->size[1];
      opts1->size[0] = 1;
      opts1->size[1] = opts->size[1] + 1;
      emxEnsureCapacity_char_T(opts1, j);
      matchPos = opts->size[1];
      for (j = 0; j < matchPos; j++) {
        opts1->data[j] = opts->data[j];
      }

      opts1->data[opts->size[1]] = '\x00';
    } else {
      j = opts1->size[0] * opts1->size[1];
      opts1->size[0] = 1;
      opts1->size[1] = opts->size[1];
      emxEnsureCapacity_char_T(opts1, j);
      matchPos = opts->size[0] * opts->size[1];
      for (j = 0; j < matchPos; j++) {
        opts1->data[j] = opts->data[j];
      }
    }

    if (opts1->data[opts1->size[1] - 1] != '\x00') {
      m2c_error();
    }

    matchPos = PetscOptionsInsertString(NULL, &opts1->data[0]);
    emxFree_char_T(&opts1);
    if (matchPos != 0) {
      b_m2c_error(matchPos);
    }
  }

  b_petscKSPSetup(AMat, solver, pctype, solpack, &ksp, &time_setup);
  matchPos = 0;
  do {
    exitg1 = 0;
    if (matchPos <= opts->size[1] - 24) {
      j = 1;
      while ((j <= 24) && (opts->data[(matchPos + j) - 1] == b_cv[j - 1])) {
        j++;
      }

      if (j > 24) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (matchPos > 0) {
    t_ksp = ksp;
    KSPDestroy(&t_ksp);
    matchPos = PetscOptionsInsertString(NULL, in_str);
    if (matchPos != 0) {
      b_m2c_error(matchPos);
    }

    b_petscKSPSetup(AMat, solver, pctype, solpack, &ksp, &time_setup);
  }

  b_petscKSPDriver(ksp, bVec, xVec, rtol, maxiter, x0Vec, flag, relres, iter,
                   reshis, &time_solve);
  times[0] = time_setup;
  times[1] = time_solve;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(xVec, x);
  t_vec = xVec;
  VecDestroy(&t_vec);
}

void petscSolveCRS_4args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b,
  emxArray_real_T *x, int *flag, double *relres, int *iter, emxArray_real_T
  *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec xVec;
  PetscObject t_obj;
  MPI_Comm t_comm;
  KSP ksp;
  PC t_pc;
  int side;
  MPI_Comm comm;
  double t;
  double secs;
  double time_solve;
  KSP t_ksp;
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  VecDuplicate(bVec, &xVec);
  t_obj = (PetscObject)(AMat);
  PetscObjectGetComm(t_obj, &t_comm);
  KSPCreate(t_comm, &ksp);
  KSPGetPC(ksp, &t_pc);
  KSPSetOperators(ksp, AMat, AMat);
  side = (PC_RIGHT);
  KSPSetPCSide(ksp, side);
  KSPSetFromOptions(ksp);
  t_obj = (PetscObject)(ksp);
  PetscObjectGetComm(t_obj, &comm);
  MPI_Barrier(comm);
  t = MPI_Wtime();
  KSPSetUp(ksp);
  MPI_Barrier(comm);
  secs = MPI_Wtime();
  petscKSPDriver(ksp, bVec, xVec, NULL, flag, relres, iter, reshis, &time_solve);
  times[0] = secs - t;
  times[1] = time_solve;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(xVec, x);
  t_vec = xVec;
  VecDestroy(&t_vec);
}

void petscSolveCRS_5args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, emxArray_real_T *x, int *flag, double *relres, int
  *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec xVec;
  KSP ksp;
  double time_setup;
  double time_solve;
  KSP t_ksp;
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  VecDuplicate(bVec, &xVec);
  petscKSPSetup(AMat, solver, &ksp, &time_setup);
  petscKSPDriver(ksp, bVec, xVec, NULL, flag, relres, iter, reshis, &time_solve);
  times[0] = time_setup;
  times[1] = time_solve;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(xVec, x);
  t_vec = xVec;
  VecDestroy(&t_vec);
}

void petscSolveCRS_6args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, emxArray_real_T *x, int *flag, double
  *relres, int *iter, emxArray_real_T *reshis, double times[2])
{
  double b_rtol;
  Mat AMat;
  Vec bVec;
  Vec x0;
  Vec xVec;
  KSP ksp;
  double time_setup;
  int type;
  double bnrm;
  PetscObject t_obj;
  MPI_Comm comm;
  double t;
  int maxits;
  int val;
  boolean_T b_b;
  double secs;
  double res;
  double abstol;
  double dtol;
  emxArray_char_T *side;
  PC pc;
  PetscReal * a;
  int na;
  int switch_expression;
  KSP t_ksp;
  Mat t_mat;
  static const char b_cv[5] = { 'r', 'i', 'g', 'h', 't' };

  Vec t_vec;
  KSPType b_type;
  PCType c_type;
  b_rtol = rtol;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  x0 = NULL;
  VecDuplicate(bVec, &xVec);
  petscKSPSetup(AMat, solver, &ksp, &time_setup);
  type = (NORM_2);
  VecNorm(bVec, type, &bnrm);
  t_obj = (PetscObject)(ksp);
  PetscObjectGetComm(t_obj, &comm);
  MPI_Barrier(comm);
  t = MPI_Wtime();
  maxits = (PETSC_DEFAULT);
  if (rtol == 0.0) {
    type = (PETSC_DEFAULT);
    b_rtol = type;
  }

  type = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  KSPSetTolerances(ksp, b_rtol, (double)type, (double)val, maxits);
  type = !(x0);
  b_b = (type == 0);
  if (b_b) {
    VecCopy(x0, xVec);
  }

  type = (PETSC_TRUE);
  KSPSetResidualHistory(ksp, NULL, maxits, type);
  KSPSetInitialGuessNonzero(ksp, (int)b_b);
  KSPSolve(ksp, bVec, xVec);
  MPI_Barrier(comm);
  secs = MPI_Wtime();
  KSPGetConvergedReason(ksp, flag);
  KSPGetResidualNorm(ksp, &res);
  KSPGetIterationNumber(ksp, iter);
  *relres = res / bnrm;
  KSPGetTolerances(ksp, &b_rtol, &abstol, &dtol, &maxits);
  emxInit_char_T(&side, 2);
  if ((*flag < 0) || (*relres > b_rtol)) {
    KSPGetPC(ksp, &pc);
    val = (PC_LEFT);
    type = (PC_RIGHT);
    KSPGetPCSide(ksp, &switch_expression);
    if (val == switch_expression) {
      type = 0;
    } else if (type == switch_expression) {
      type = 1;
    } else {
      type = -1;
    }

    switch (type) {
     case 0:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity_char_T(side, type);
      side->data[0] = 'l';
      side->data[1] = 'e';
      side->data[2] = 'f';
      side->data[3] = 't';
      break;

     case 1:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity_char_T(side, type);
      for (type = 0; type < 5; type++) {
        side->data[type] = b_cv[type];
      }
      break;

     default:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity_char_T(side, type);
      for (type = 0; type < 9; type++) {
        side->data[type] = cv[type];
      }
      break;
    }

    KSPGetType(ksp, &b_type);
    PCGetType(pc, &c_type);
    m2c_printf(b_type, c_type, side, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  KSPGetResidualHistory(ksp, &a, &na);
  type = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity_real_T(reshis, type);
  for (type = 0; type < na; type++) {
    reshis->data[type] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  times[0] = time_setup;
  times[1] = secs - t;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(xVec, x);
  t_vec = xVec;
  VecDestroy(&t_vec);
}

void petscSolveCRS_7args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, emxArray_real_T *x, int
  *flag, double *relres, int *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec xVec;
  KSP ksp;
  double time_setup;
  double time_solve;
  KSP t_ksp;
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  VecDuplicate(bVec, &xVec);
  petscKSPSetup(AMat, solver, &ksp, &time_setup);
  b_petscKSPDriver(ksp, bVec, xVec, rtol, maxiter, NULL, flag, relres, iter,
                   reshis, &time_solve);
  times[0] = time_setup;
  times[1] = time_solve;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(xVec, x);
  t_vec = xVec;
  VecDestroy(&t_vec);
}

void petscSolveCRS_8args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, emxArray_real_T *x, int *flag, double *relres, int *iter,
  emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec xVec;
  PetscObject t_obj;
  MPI_Comm t_comm;
  KSP ksp;
  PC t_pc;
  emxArray_char_T *pctype0;
  emxArray_char_T *ksptype0;
  int i;
  int loop_ub;
  MPI_Comm comm;
  double t;
  double secs;
  double time_solve;
  KSP t_ksp;
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  VecDuplicate(bVec, &xVec);
  t_obj = (PetscObject)(AMat);
  PetscObjectGetComm(t_obj, &t_comm);
  KSPCreate(t_comm, &ksp);
  KSPGetPC(ksp, &t_pc);
  KSPSetOperators(ksp, AMat, AMat);
  if (pctype->size[1] != 0) {
    emxInit_char_T(&pctype0, 2);
    if (pctype->data[pctype->size[1] - 1] != '\x00') {
      i = pctype0->size[0] * pctype0->size[1];
      pctype0->size[0] = 1;
      pctype0->size[1] = pctype->size[1] + 1;
      emxEnsureCapacity_char_T(pctype0, i);
      loop_ub = pctype->size[1];
      for (i = 0; i < loop_ub; i++) {
        pctype0->data[i] = pctype->data[i];
      }

      pctype0->data[pctype->size[1]] = '\x00';
    } else {
      i = pctype0->size[0] * pctype0->size[1];
      pctype0->size[0] = 1;
      pctype0->size[1] = pctype->size[1];
      emxEnsureCapacity_char_T(pctype0, i);
      loop_ub = pctype->size[0] * pctype->size[1];
      for (i = 0; i < loop_ub; i++) {
        pctype0->data[i] = pctype->data[i];
      }
    }

    PCSetType(t_pc, &pctype0->data[0]);
    emxFree_char_T(&pctype0);
  }

  emxInit_char_T(&ksptype0, 2);
  if ((solver->size[1] != 0) && ((unsigned char)solver->data[solver->size[1] - 1]
       != 0)) {
    i = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = solver->size[1] + 1;
    emxEnsureCapacity_char_T(ksptype0, i);
    loop_ub = solver->size[1];
    for (i = 0; i < loop_ub; i++) {
      ksptype0->data[i] = solver->data[i];
    }

    ksptype0->data[solver->size[1]] = '\x00';
  } else {
    i = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = solver->size[1];
    emxEnsureCapacity_char_T(ksptype0, i);
    loop_ub = solver->size[0] * solver->size[1];
    for (i = 0; i < loop_ub; i++) {
      ksptype0->data[i] = solver->data[i];
    }
  }

  if (ksptype0->size[1] != 0) {
    KSPSetType(ksp, &ksptype0->data[0]);
  }

  emxFree_char_T(&ksptype0);
  loop_ub = (PC_RIGHT);
  KSPSetPCSide(ksp, loop_ub);
  KSPSetFromOptions(ksp);
  t_obj = (PetscObject)(ksp);
  PetscObjectGetComm(t_obj, &comm);
  MPI_Barrier(comm);
  t = MPI_Wtime();
  KSPSetUp(ksp);
  MPI_Barrier(comm);
  secs = MPI_Wtime();
  b_petscKSPDriver(ksp, bVec, xVec, rtol, maxiter, NULL, flag, relres, iter,
                   reshis, &time_solve);
  times[0] = secs - t;
  times[1] = time_solve;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(xVec, x);
  t_vec = xVec;
  VecDestroy(&t_vec);
}

void petscSolveCRS_9args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, emxArray_real_T *x, int *flag, double
  *relres, int *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec xVec;
  KSP ksp;
  double time_setup;
  double time_solve;
  KSP t_ksp;
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  VecDuplicate(bVec, &xVec);
  b_petscKSPSetup(AMat, solver, pctype, solpack, &ksp, &time_setup);
  b_petscKSPDriver(ksp, bVec, xVec, rtol, maxiter, NULL, flag, relres, iter,
                   reshis, &time_solve);
  times[0] = time_setup;
  times[1] = time_solve;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(xVec, x);
  t_vec = xVec;
  VecDestroy(&t_vec);
}

void petscSolveCRS_initialize(void)
{
}

void petscSolveCRS_terminate(void)
{
}
