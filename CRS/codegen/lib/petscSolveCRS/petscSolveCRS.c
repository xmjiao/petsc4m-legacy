#include "petscSolveCRS.h"
#include "petscSolveCRS_types.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static const char cv[9] = {'s', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c'};

static void b_m2c_error(int varargin_3);

static void b_m2c_printf(double varargin_2, int varargin_3);

static void b_petscKSPDriver(KSP ksp, Vec b, Vec x, double rtol, int maxits,
                             Vec x0, int *flag, double *relres, int *iter,
                             emxArray_real_T *reshis, double *b_time);

static void b_petscKSPSetup(Mat Amat, const emxArray_char_T *ksptype,
                            const emxArray_char_T *pctype,
                            const emxArray_char_T *pcopt, KSP *ksp,
                            double *b_time);

static void c_m2c_printf(double varargin_2, double varargin_3);

static void d_m2c_printf(int varargin_2, double varargin_3);

static void e_m2c_printf(void);

static void m2c_error(void);

static void m2c_printf(KSPType varargin_2, PCType varargin_3,
                       const emxArray_char_T *varargin_4, int varargin_5);

static void petscKSPDriver(KSP ksp, Vec b, Vec x, Vec x0, int *flag,
                           double *relres, int *iter, emxArray_real_T *reshis,
                           double *b_time);

static void petscKSPSetup(Mat Amat, const emxArray_char_T *ksptype, KSP *ksp,
                          double *b_time);

static Mat petscMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr,
                                    const emxArray_int32_T *col_ind,
                                    const emxArray_real_T *val);

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

static void b_petscKSPDriver(KSP ksp, Vec b, Vec x, double rtol, int maxits,
                             Vec x0, int *flag, double *relres, int *iter,
                             emxArray_real_T *reshis, double *b_time)
{
  static const char b_cv[5] = {'r', 'i', 'g', 'h', 't'};
  KSPType b_type;
  PC pc;
  PCType c_type;
  PetscObject t_obj;
  const PetscReal *a;
  emxArray_char_T *side;
  double abstol;
  double b_rtol;
  double b_t;
  double bnrm;
  double dtol;
  double res;
  double t;
  double *reshis_data;
  int b_maxits;
  int b_x;
  int na;
  int type;
  char *side_data;
  boolean_T b_b;
  type = (NORM_2);
  VecNorm(b, type, &bnrm);
  t_obj = (PetscObject)(ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&t);
  if (maxits == 0) {
    maxits = (PETSC_DEFAULT);
  }
  if (rtol == 0.0) {
    type = (PETSC_DEFAULT);
    rtol = type;
  }
  type = (PETSC_DEFAULT);
  b_x = (PETSC_DEFAULT);
  KSPSetTolerances(ksp, rtol, (double)type, (double)b_x, maxits);
  type = !(x0);
  b_b = (type == 0);
  if (b_b) {
    VecCopy(x0, x);
  }
  type = (PETSC_TRUE);
  KSPSetResidualHistory(ksp, NULL, maxits, type);
  KSPSetInitialGuessNonzero(ksp, (int)b_b);
  KSPSolve(ksp, b, x);
  t_obj = (PetscObject)(ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&b_t);
  KSPGetConvergedReason(ksp, flag);
  KSPGetResidualNorm(ksp, &res);
  KSPGetIterationNumber(ksp, iter);
  *relres = res / bnrm;
  KSPGetTolerances(ksp, &b_rtol, &abstol, &dtol, &b_maxits);
  emxInit_char_T(&side, 2);
  if ((*flag < 0) || (*relres > b_rtol)) {
    int switch_expression;
    KSPGetPC(ksp, &pc);
    b_x = (PC_LEFT);
    type = (PC_RIGHT);
    KSPGetPCSide(ksp, &switch_expression);
    if (b_x == switch_expression) {
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
      side_data = side->data;
      side_data[0] = 'l';
      side_data[1] = 'e';
      side_data[2] = 'f';
      side_data[3] = 't';
      break;
    case 1:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity_char_T(side, type);
      side_data = side->data;
      for (type = 0; type < 5; type++) {
        side_data[type] = b_cv[type];
      }
      break;
    default:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity_char_T(side, type);
      side_data = side->data;
      for (type = 0; type < 9; type++) {
        side_data[type] = cv[type];
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
  reshis_data = reshis->data;
  for (type = 0; type < na; type++) {
    reshis_data[type] = 0.0;
  }
  memcpy(&reshis_data[0], a, na << 3);
  *b_time = b_t - t;
}

static void b_petscKSPSetup(Mat Amat, const emxArray_char_T *ksptype,
                            const emxArray_char_T *pctype,
                            const emxArray_char_T *pcopt, KSP *ksp,
                            double *b_time)
{
  static const char cv1[5] = {'r', 'i', 'g', 'h', 't'};
  static const char b_cv[4] = {'l', 'e', 'f', 't'};
  MPI_Comm t_comm;
  PC t_pc;
  PetscObject t_obj;
  emxArray_char_T *ksptype0;
  emxArray_char_T *pctype0;
  double b_t;
  double t;
  int i;
  int k;
  const char *ksptype_data;
  const char *pcopt_data;
  const char *pctype_data;
  char *ksptype0_data;
  char *pctype0_data;
  boolean_T hasOpt;
  boolean_T hasPC;
  pcopt_data = pcopt->data;
  pctype_data = pctype->data;
  ksptype_data = ksptype->data;
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
      if (pctype_data[pctype->size[1] - 1] != '\x00') {
        i = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1] + 1;
        emxEnsureCapacity_char_T(pctype0, i);
        pctype0_data = pctype0->data;
        k = pctype->size[1];
        for (i = 0; i < k; i++) {
          pctype0_data[i] = pctype_data[i];
        }
        pctype0_data[pctype->size[1]] = '\x00';
      } else {
        i = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1];
        emxEnsureCapacity_char_T(pctype0, i);
        pctype0_data = pctype0->data;
        k = pctype->size[1];
        for (i = 0; i < k; i++) {
          pctype0_data[i] = pctype_data[i];
        }
      }
      PCSetType(t_pc, &pctype0_data[0]);
    }
    if (hasOpt) {
      boolean_T exitg1;
      boolean_T p;
      p = (pcopt->size[1] == 4);
      if (p && (pcopt->size[1] != 0)) {
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 4)) {
          if (pcopt_data[k] != b_cv[k]) {
            p = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (p) {
        k = (PC_LEFT);
        KSPSetPCSide(*ksp, k);
      } else {
        p = (pcopt->size[1] == 5);
        if (p && (pcopt->size[1] != 0)) {
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k < 5)) {
            if (pcopt_data[k] != cv1[k]) {
              p = false;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (p) {
          k = (PC_RIGHT);
          KSPSetPCSide(*ksp, k);
        } else {
          p = (pcopt->size[1] == 9);
          if (p && (pcopt->size[1] != 0)) {
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 9)) {
              if (pcopt_data[k] != cv[k]) {
                p = false;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }
          if (p) {
            k = (PC_SYMMETRIC);
            KSPSetPCSide(*ksp, k);
          }
        }
      }
    }
  }
  emxFree_char_T(&pctype0);
  emxInit_char_T(&ksptype0, 2);
  if ((ksptype->size[1] != 0) &&
      ((unsigned char)ksptype_data[ksptype->size[1] - 1] != 0)) {
    i = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity_char_T(ksptype0, i);
    ksptype0_data = ksptype0->data;
    k = ksptype->size[1];
    for (i = 0; i < k; i++) {
      ksptype0_data[i] = ksptype_data[i];
    }
    ksptype0_data[ksptype->size[1]] = '\x00';
  } else {
    i = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1];
    emxEnsureCapacity_char_T(ksptype0, i);
    ksptype0_data = ksptype0->data;
    k = ksptype->size[1];
    for (i = 0; i < k; i++) {
      ksptype0_data[i] = ksptype_data[i];
    }
  }
  if (ksptype0->size[1] != 0) {
    KSPSetType(*ksp, &ksptype0_data[0]);
  }
  emxFree_char_T(&ksptype0);
  if (pcopt->size[1] == 0) {
    k = (PC_RIGHT);
    KSPSetPCSide(*ksp, k);
  }
  KSPSetFromOptions(*ksp);
  t_obj = (PetscObject)(*ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&t);
  KSPSetUp(*ksp);
  t_obj = (PetscObject)(*ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&b_t);
  *b_time = b_t - t;
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
  M2C_printf("### For explanation of the flag, see "
             "http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/"
             "KSPConvergedReason.html.\n");
}

static void m2c_error(void)
{
  M2C_error("Petsc4m:petscOptionsInsertString:InputError",
            "The argument must be a null-terminated string.");
}

static void m2c_printf(KSPType varargin_2, PCType varargin_3,
                       const emxArray_char_T *varargin_4, int varargin_5)
{
  emxArray_char_T *b_varargin_4;
  int i;
  int loop_ub;
  const char *varargin_4_data;
  char *b_varargin_4_data;
  varargin_4_data = varargin_4->data;
  emxInit_char_T(&b_varargin_4, 2);
  i = b_varargin_4->size[0] * b_varargin_4->size[1];
  b_varargin_4->size[0] = 1;
  b_varargin_4->size[1] = varargin_4->size[1];
  emxEnsureCapacity_char_T(b_varargin_4, i);
  b_varargin_4_data = b_varargin_4->data;
  loop_ub = varargin_4->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_4_data[i] = varargin_4_data[i];
  }
  M2C_printf("### %s with %s as %s preconditioner stopped with flag %d.\n",
             varargin_2, varargin_3, &b_varargin_4_data[0], varargin_5);
  emxFree_char_T(&b_varargin_4);
}

static void petscKSPDriver(KSP ksp, Vec b, Vec x, Vec x0, int *flag,
                           double *relres, int *iter, emxArray_real_T *reshis,
                           double *b_time)
{
  static const char b_cv[5] = {'r', 'i', 'g', 'h', 't'};
  KSPType b_type;
  PC pc;
  PCType c_type;
  PetscObject t_obj;
  const PetscReal *a;
  emxArray_char_T *side;
  double abstol;
  double b_t;
  double bnrm;
  double dtol;
  double res;
  double rtol;
  double t;
  double *reshis_data;
  int b_x;
  int c_x;
  int maxits;
  int na;
  int type;
  char *side_data;
  boolean_T b_b;
  type = (NORM_2);
  VecNorm(b, type, &bnrm);
  t_obj = (PetscObject)(ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&t);
  maxits = (PETSC_DEFAULT);
  type = (PETSC_DEFAULT);
  b_x = (PETSC_DEFAULT);
  c_x = (PETSC_DEFAULT);
  KSPSetTolerances(ksp, (double)type, (double)b_x, (double)c_x, maxits);
  type = !(x0);
  b_b = (type == 0);
  if (b_b) {
    VecCopy(x0, x);
  }
  type = (PETSC_TRUE);
  KSPSetResidualHistory(ksp, NULL, maxits, type);
  KSPSetInitialGuessNonzero(ksp, (int)b_b);
  KSPSolve(ksp, b, x);
  t_obj = (PetscObject)(ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&b_t);
  KSPGetConvergedReason(ksp, flag);
  KSPGetResidualNorm(ksp, &res);
  KSPGetIterationNumber(ksp, iter);
  *relres = res / bnrm;
  KSPGetTolerances(ksp, &rtol, &abstol, &dtol, &maxits);
  emxInit_char_T(&side, 2);
  if ((*flag < 0) || (*relres > rtol)) {
    KSPGetPC(ksp, &pc);
    b_x = (PC_LEFT);
    type = (PC_RIGHT);
    KSPGetPCSide(ksp, &c_x);
    if (b_x == c_x) {
      type = 0;
    } else if (type == c_x) {
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
      side_data = side->data;
      side_data[0] = 'l';
      side_data[1] = 'e';
      side_data[2] = 'f';
      side_data[3] = 't';
      break;
    case 1:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity_char_T(side, type);
      side_data = side->data;
      for (type = 0; type < 5; type++) {
        side_data[type] = b_cv[type];
      }
      break;
    default:
      type = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity_char_T(side, type);
      side_data = side->data;
      for (type = 0; type < 9; type++) {
        side_data[type] = cv[type];
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
  reshis_data = reshis->data;
  for (type = 0; type < na; type++) {
    reshis_data[type] = 0.0;
  }
  memcpy(&reshis_data[0], a, na << 3);
  *b_time = b_t - t;
}

static void petscKSPSetup(Mat Amat, const emxArray_char_T *ksptype, KSP *ksp,
                          double *b_time)
{
  MPI_Comm t_comm;
  PC t_pc;
  PetscObject t_obj;
  emxArray_char_T *ksptype0;
  double b_t;
  double t;
  int i;
  int loop_ub;
  const char *ksptype_data;
  char *ksptype0_data;
  ksptype_data = ksptype->data;
  t_obj = (PetscObject)(Amat);
  PetscObjectGetComm(t_obj, &t_comm);
  KSPCreate(t_comm, ksp);
  KSPGetPC(*ksp, &t_pc);
  KSPSetOperators(*ksp, Amat, Amat);
  emxInit_char_T(&ksptype0, 2);
  if ((ksptype->size[1] != 0) &&
      ((unsigned char)ksptype_data[ksptype->size[1] - 1] != 0)) {
    i = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity_char_T(ksptype0, i);
    ksptype0_data = ksptype0->data;
    loop_ub = ksptype->size[1];
    for (i = 0; i < loop_ub; i++) {
      ksptype0_data[i] = ksptype_data[i];
    }
    ksptype0_data[ksptype->size[1]] = '\x00';
  } else {
    i = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1];
    emxEnsureCapacity_char_T(ksptype0, i);
    ksptype0_data = ksptype0->data;
    loop_ub = ksptype->size[1];
    for (i = 0; i < loop_ub; i++) {
      ksptype0_data[i] = ksptype_data[i];
    }
  }
  if (ksptype0->size[1] != 0) {
    KSPSetType(*ksp, &ksptype0_data[0]);
  }
  emxFree_char_T(&ksptype0);
  loop_ub = (PC_RIGHT);
  KSPSetPCSide(*ksp, loop_ub);
  KSPSetFromOptions(*ksp);
  t_obj = (PetscObject)(*ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&t);
  KSPSetUp(*ksp);
  t_obj = (PetscObject)(*ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&b_t);
  *b_time = b_t - t;
}

static Mat petscMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr,
                                    const emxArray_int32_T *col_ind,
                                    const emxArray_real_T *val)
{
  Mat t_mat;
  emxArray_int32_T *jidx;
  emxArray_int32_T *nnz;
  emxArray_real_T *rowval;
  const double *val_data;
  double *rowval_data;
  const int *col_ind_data;
  const int *row_ptr_data;
  int b_i;
  int i;
  int i1;
  int n;
  int nz;
  int *jidx_data;
  int *nnz_data;
  val_data = val->data;
  col_ind_data = col_ind->data;
  row_ptr_data = row_ptr->data;
  emxInit_int32_T(&nnz, 1);
  n = row_ptr->size[0] - 2;
  i = nnz->size[0];
  nnz->size[0] = row_ptr->size[0] - 1;
  emxEnsureCapacity_int32_T(nnz, i);
  nnz_data = nnz->data;
  for (b_i = 0; b_i <= n; b_i++) {
    nnz_data[b_i] = row_ptr_data[b_i + 1] - row_ptr_data[b_i];
  }
  nz = (PETSC_DEFAULT);
  MatCreateSeqAIJ(PETSC_COMM_SELF, row_ptr->size[0] - 1, row_ptr->size[0] - 1,
                  nz, &nnz_data[0], &t_mat);
  emxInit_int32_T(&jidx, 1);
  emxInit_real_T(&rowval, 1);
  for (b_i = 0; b_i <= n; b_i++) {
    int loop_ub;
    i = row_ptr_data[b_i + 1] - 1;
    if (row_ptr_data[b_i] > i) {
      nz = 0;
      i1 = 0;
    } else {
      nz = row_ptr_data[b_i] - 1;
      i1 = i;
    }
    loop_ub = i1 - nz;
    i1 = jidx->size[0];
    jidx->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(jidx, i1);
    jidx_data = jidx->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      jidx_data[i1] = col_ind_data[nz + i1] - 1;
    }
    if (row_ptr_data[b_i] > i) {
      nz = 0;
      i = 0;
    } else {
      nz = row_ptr_data[b_i] - 1;
    }
    loop_ub = i - nz;
    i = rowval->size[0];
    rowval->size[0] = loop_ub;
    emxEnsureCapacity_real_T(rowval, i);
    rowval_data = rowval->data;
    for (i = 0; i < loop_ub; i++) {
      rowval_data[i] = val_data[nz + i];
    }
    int iroa;
    iroa = (INSERT_VALUES);
    MatSetValues(t_mat, 1, &b_i, nnz_data[b_i], &jidx_data[0], &rowval_data[0],
                 iroa);
  }
  int type;
  emxFree_real_T(&rowval);
  emxFree_int32_T(&jidx);
  emxFree_int32_T(&nnz);
  type = (MAT_FINAL_ASSEMBLY);
  MatAssemblyBegin(t_mat, type);
  type = (MAT_FINAL_ASSEMBLY);
  MatAssemblyEnd(t_mat, type);
  return t_mat;
}

void petscSolveCRS(int *flag, double *relres, int *iter, double times[2])
{
  *flag = -1;
  *relres = 1.7976931348623157E+308;
  *iter = 0;
  times[0] = 0.0;
  times[1] = 0.0;
}

void petscSolveCRS_10args(
    const emxArray_int32_T *Arows, const emxArray_int32_T *Acols,
    const emxArray_real_T *Avals, const emxArray_real_T *b,
    const emxArray_char_T *solver, double rtol, int maxiter,
    const emxArray_char_T *pctype, const emxArray_char_T *solpack,
    const emxArray_real_T *x0, emxArray_real_T *x, int *flag, double *relres,
    int *iter, emxArray_real_T *reshis, double times[2])
{
  KSP ksp;
  KSP t_ksp;
  Mat AMat;
  Mat t_mat;
  Vec bVec;
  Vec t_vec;
  Vec x0Vec;
  Vec xVec;
  emxArray_int32_T *idx;
  emxArray_int32_T *y;
  const double *b_data;
  const double *x0_data;
  double time_setup;
  double time_solve;
  double *x_data;
  int b_n;
  int iroa;
  int k;
  int n;
  int yk;
  int *idx_data;
  int *y_data;
  x0_data = x0->data;
  b_data = b->data;
  emxInit_int32_T(&y, 2);
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  VecCreateSeq(PETSC_COMM_SELF, b->size[0], &bVec);
  if (b->size[0] - 1 < 0) {
    n = 0;
  } else {
    n = b->size[0];
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  iroa = (INSERT_VALUES);
  VecSetValues(bVec, b->size[0], &idx_data[0], &b_data[0], iroa);
  VecAssemblyBegin(bVec);
  VecAssemblyEnd(bVec);
  if (x0->size[0] == 0) {
    x0Vec = NULL;
    VecDuplicate(bVec, &xVec);
  } else {
    VecCreateSeq(PETSC_COMM_SELF, x0->size[0], &x0Vec);
    n = x0->size[0];
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x0->size[0];
    emxEnsureCapacity_int32_T(y, k);
    y_data = y->data;
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
    k = idx->size[0];
    idx->size[0] = y->size[1];
    emxEnsureCapacity_int32_T(idx, k);
    idx_data = idx->data;
    yk = y->size[1];
    for (k = 0; k < yk; k++) {
      idx_data[k] = y_data[k];
    }
    iroa = (INSERT_VALUES);
    VecSetValues(x0Vec, x0->size[0], &idx_data[0], &x0_data[0], iroa);
    VecAssemblyBegin(x0Vec);
    VecAssemblyEnd(x0Vec);
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
  VecGetLocalSize(xVec, &n);
  k = x->size[0];
  x->size[0] = n;
  emxEnsureCapacity_real_T(x, k);
  x_data = x->data;
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (b_n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  emxFree_int32_T(&y);
  VecGetValues(xVec, n, &idx_data[0], &x_data[0]);
  t_vec = xVec;
  VecDestroy(&t_vec);
  emxFree_int32_T(&idx);
}

void petscSolveCRS_11args(
    const emxArray_int32_T *Arows, const emxArray_int32_T *Acols,
    const emxArray_real_T *Avals, const emxArray_real_T *b,
    const emxArray_char_T *solver, double rtol, int maxiter,
    const emxArray_char_T *pctype, const emxArray_char_T *solpack,
    const emxArray_real_T *x0, const emxArray_char_T *opts, emxArray_real_T *x,
    int *flag, double *relres, int *iter, emxArray_real_T *reshis,
    double times[2])
{
  static const char in_str[25] = "-mat_superlu_printstat 0";
  static const char b_cv[24] = {'-', 'm', 'a', 't', '_', 's', 'u', 'p',
                                'e', 'r', 'l', 'u', '_', 'p', 'r', 'i',
                                'n', 't', 's', 't', 'a', 't', ' ', '1'};
  KSP ksp;
  KSP t_ksp;
  Mat AMat;
  Vec bVec;
  Vec t_vec;
  Vec x0Vec;
  Vec xVec;
  emxArray_char_T *opts1;
  emxArray_int32_T *idx;
  emxArray_int32_T *y;
  const double *b_data;
  const double *x0_data;
  double time_setup;
  double time_solve;
  double *x_data;
  int errCode;
  int iroa;
  int j;
  int k;
  int n;
  int yk;
  int *idx_data;
  int *y_data;
  const char *opts_data;
  char *opts1_data;
  boolean_T exitg1;
  opts_data = opts->data;
  x0_data = x0->data;
  b_data = b->data;
  emxInit_int32_T(&y, 2);
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  VecCreateSeq(PETSC_COMM_SELF, b->size[0], &bVec);
  if (b->size[0] - 1 < 0) {
    n = 0;
  } else {
    n = b->size[0];
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  iroa = (INSERT_VALUES);
  VecSetValues(bVec, b->size[0], &idx_data[0], &b_data[0], iroa);
  VecAssemblyBegin(bVec);
  VecAssemblyEnd(bVec);
  if (x0->size[0] == 0) {
    x0Vec = NULL;
    VecDuplicate(bVec, &xVec);
  } else {
    VecCreateSeq(PETSC_COMM_SELF, x0->size[0], &x0Vec);
    n = x0->size[0];
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x0->size[0];
    emxEnsureCapacity_int32_T(y, k);
    y_data = y->data;
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
    k = idx->size[0];
    idx->size[0] = y->size[1];
    emxEnsureCapacity_int32_T(idx, k);
    idx_data = idx->data;
    yk = y->size[1];
    for (k = 0; k < yk; k++) {
      idx_data[k] = y_data[k];
    }
    iroa = (INSERT_VALUES);
    VecSetValues(x0Vec, x0->size[0], &idx_data[0], &x0_data[0], iroa);
    VecAssemblyBegin(x0Vec);
    VecAssemblyEnd(x0Vec);
    xVec = x0Vec;
  }
  if (opts->size[1] != 0) {
    emxInit_char_T(&opts1, 2);
    if (opts_data[opts->size[1] - 1] != '\x00') {
      k = opts1->size[0] * opts1->size[1];
      opts1->size[0] = 1;
      opts1->size[1] = opts->size[1] + 1;
      emxEnsureCapacity_char_T(opts1, k);
      opts1_data = opts1->data;
      yk = opts->size[1];
      for (k = 0; k < yk; k++) {
        opts1_data[k] = opts_data[k];
      }
      opts1_data[opts->size[1]] = '\x00';
    } else {
      k = opts1->size[0] * opts1->size[1];
      opts1->size[0] = 1;
      opts1->size[1] = opts->size[1];
      emxEnsureCapacity_char_T(opts1, k);
      opts1_data = opts1->data;
      yk = opts->size[1];
      for (k = 0; k < yk; k++) {
        opts1_data[k] = opts_data[k];
      }
    }
    if (opts1_data[opts1->size[1] - 1] != '\x00') {
      m2c_error();
    }
    errCode = PetscOptionsInsertString(NULL, &opts1_data[0]);
    emxFree_char_T(&opts1);
    if (errCode != 0) {
      b_m2c_error(errCode);
    }
  }
  b_petscKSPSetup(AMat, solver, pctype, solpack, &ksp, &time_setup);
  yk = 0;
  exitg1 = false;
  while ((!exitg1) && (yk <= opts->size[1] - 24)) {
    j = 1;
    while ((j <= 24) && (opts_data[(yk + j) - 1] == b_cv[j - 1])) {
      j++;
    }
    if (j > 24) {
      t_ksp = ksp;
      KSPDestroy(&t_ksp);
      errCode = PetscOptionsInsertString(NULL, &in_str[0]);
      if (errCode != 0) {
        b_m2c_error(errCode);
      }
      b_petscKSPSetup(AMat, solver, pctype, solpack, &ksp, &time_setup);
      exitg1 = true;
    } else {
      yk++;
    }
  }
  Mat t_mat;
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
  VecGetLocalSize(xVec, &n);
  k = x->size[0];
  x->size[0] = n;
  emxEnsureCapacity_real_T(x, k);
  x_data = x->data;
  if (n - 1 < 0) {
    j = 0;
  } else {
    j = n;
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = j;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (j > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= j; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  emxFree_int32_T(&y);
  VecGetValues(xVec, n, &idx_data[0], &x_data[0]);
  t_vec = xVec;
  VecDestroy(&t_vec);
  emxFree_int32_T(&idx);
}

void petscSolveCRS_4args(const emxArray_int32_T *Arows,
                         const emxArray_int32_T *Acols,
                         const emxArray_real_T *Avals, const emxArray_real_T *b,
                         emxArray_real_T *x, int *flag, double *relres,
                         int *iter, emxArray_real_T *reshis, double times[2])
{
  KSP ksp;
  MPI_Comm t_comm;
  Mat AMat;
  Vec bVec;
  Vec t_vec;
  Vec xVec;
  emxArray_int32_T *idx;
  emxArray_int32_T *y;
  const double *b_data;
  double time_solve;
  double *x_data;
  int b_n;
  int k;
  int n;
  int yk;
  int *idx_data;
  int *y_data;
  b_data = b->data;
  emxInit_int32_T(&y, 2);
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  VecCreateSeq(PETSC_COMM_SELF, b->size[0], &bVec);
  if (b->size[0] - 1 < 0) {
    n = 0;
  } else {
    n = b->size[0];
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  KSP t_ksp;
  Mat t_mat;
  PC t_pc;
  PetscObject t_obj;
  double b_t;
  double t;
  int iroa;
  iroa = (INSERT_VALUES);
  VecSetValues(bVec, b->size[0], &idx_data[0], &b_data[0], iroa);
  VecAssemblyBegin(bVec);
  VecAssemblyEnd(bVec);
  VecDuplicate(bVec, &xVec);
  t_obj = (PetscObject)(AMat);
  PetscObjectGetComm(t_obj, &t_comm);
  KSPCreate(t_comm, &ksp);
  KSPGetPC(ksp, &t_pc);
  KSPSetOperators(ksp, AMat, AMat);
  yk = (PC_RIGHT);
  KSPSetPCSide(ksp, yk);
  KSPSetFromOptions(ksp);
  t_obj = (PetscObject)(ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&t);
  KSPSetUp(ksp);
  t_obj = (PetscObject)(ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&b_t);
  petscKSPDriver(ksp, bVec, xVec, NULL, flag, relres, iter, reshis,
                 &time_solve);
  times[0] = b_t - t;
  times[1] = time_solve;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  VecGetLocalSize(xVec, &n);
  k = x->size[0];
  x->size[0] = n;
  emxEnsureCapacity_real_T(x, k);
  x_data = x->data;
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (b_n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  emxFree_int32_T(&y);
  VecGetValues(xVec, n, &idx_data[0], &x_data[0]);
  t_vec = xVec;
  VecDestroy(&t_vec);
  emxFree_int32_T(&idx);
}

void petscSolveCRS_5args(const emxArray_int32_T *Arows,
                         const emxArray_int32_T *Acols,
                         const emxArray_real_T *Avals, const emxArray_real_T *b,
                         const emxArray_char_T *solver, emxArray_real_T *x,
                         int *flag, double *relres, int *iter,
                         emxArray_real_T *reshis, double times[2])
{
  KSP ksp;
  Mat AMat;
  Vec bVec;
  Vec t_vec;
  Vec xVec;
  emxArray_int32_T *idx;
  emxArray_int32_T *y;
  const double *b_data;
  double time_setup;
  double time_solve;
  double *x_data;
  int b_n;
  int k;
  int n;
  int yk;
  int *idx_data;
  int *y_data;
  b_data = b->data;
  emxInit_int32_T(&y, 2);
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  VecCreateSeq(PETSC_COMM_SELF, b->size[0], &bVec);
  if (b->size[0] - 1 < 0) {
    n = 0;
  } else {
    n = b->size[0];
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  KSP t_ksp;
  Mat t_mat;
  int iroa;
  iroa = (INSERT_VALUES);
  VecSetValues(bVec, b->size[0], &idx_data[0], &b_data[0], iroa);
  VecAssemblyBegin(bVec);
  VecAssemblyEnd(bVec);
  VecDuplicate(bVec, &xVec);
  petscKSPSetup(AMat, solver, &ksp, &time_setup);
  petscKSPDriver(ksp, bVec, xVec, NULL, flag, relres, iter, reshis,
                 &time_solve);
  times[0] = time_setup;
  times[1] = time_solve;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  VecGetLocalSize(xVec, &n);
  k = x->size[0];
  x->size[0] = n;
  emxEnsureCapacity_real_T(x, k);
  x_data = x->data;
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (b_n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  emxFree_int32_T(&y);
  VecGetValues(xVec, n, &idx_data[0], &x_data[0]);
  t_vec = xVec;
  VecDestroy(&t_vec);
  emxFree_int32_T(&idx);
}

void petscSolveCRS_6args(const emxArray_int32_T *Arows,
                         const emxArray_int32_T *Acols,
                         const emxArray_real_T *Avals, const emxArray_real_T *b,
                         const emxArray_char_T *solver, double rtol,
                         emxArray_real_T *x, int *flag, double *relres,
                         int *iter, emxArray_real_T *reshis, double times[2])
{
  static const char b_cv[5] = {'r', 'i', 'g', 'h', 't'};
  KSP ksp;
  KSPType type;
  Mat AMat;
  PC pc;
  PCType b_type;
  PetscObject t_obj;
  const PetscReal *a;
  Vec bVec;
  Vec t_vec;
  Vec x0;
  Vec xVec;
  emxArray_char_T *side;
  emxArray_int32_T *idx;
  emxArray_int32_T *y;
  const double *b_data;
  double abstol;
  double b_rtol;
  double b_t;
  double bnrm;
  double dtol;
  double res;
  double t;
  double time_setup;
  double *reshis_data;
  double *x_data;
  int b_n;
  int k;
  int maxits;
  int n;
  int na;
  int yk;
  int *idx_data;
  int *y_data;
  char *side_data;
  boolean_T b_b;
  b_data = b->data;
  emxInit_int32_T(&y, 2);
  b_rtol = rtol;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  VecCreateSeq(PETSC_COMM_SELF, b->size[0], &bVec);
  if (b->size[0] - 1 < 0) {
    n = 0;
  } else {
    n = b->size[0];
  }
  yk = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, yk);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  emxInit_int32_T(&idx, 1);
  yk = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, yk);
  idx_data = idx->data;
  b_n = y->size[1];
  for (yk = 0; yk < b_n; yk++) {
    idx_data[yk] = y_data[yk];
  }
  int iroa;
  iroa = (INSERT_VALUES);
  VecSetValues(bVec, b->size[0], &idx_data[0], &b_data[0], iroa);
  VecAssemblyBegin(bVec);
  VecAssemblyEnd(bVec);
  x0 = NULL;
  VecDuplicate(bVec, &xVec);
  petscKSPSetup(AMat, solver, &ksp, &time_setup);
  b_n = (NORM_2);
  VecNorm(bVec, b_n, &bnrm);
  t_obj = (PetscObject)(ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&t);
  maxits = (PETSC_DEFAULT);
  if (rtol == 0.0) {
    b_n = (PETSC_DEFAULT);
    b_rtol = b_n;
  }
  b_n = (PETSC_DEFAULT);
  yk = (PETSC_DEFAULT);
  KSPSetTolerances(ksp, b_rtol, (double)b_n, (double)yk, maxits);
  b_n = !(x0);
  b_b = (b_n == 0);
  if (b_b) {
    VecCopy(x0, xVec);
  }
  b_n = (PETSC_TRUE);
  KSPSetResidualHistory(ksp, NULL, maxits, b_n);
  KSPSetInitialGuessNonzero(ksp, (int)b_b);
  KSPSolve(ksp, bVec, xVec);
  t_obj = (PetscObject)(ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&b_t);
  KSPGetConvergedReason(ksp, flag);
  KSPGetResidualNorm(ksp, &res);
  KSPGetIterationNumber(ksp, iter);
  *relres = res / bnrm;
  KSPGetTolerances(ksp, &b_rtol, &abstol, &dtol, &maxits);
  emxInit_char_T(&side, 2);
  if ((*flag < 0) || (*relres > b_rtol)) {
    KSPGetPC(ksp, &pc);
    yk = (PC_LEFT);
    b_n = (PC_RIGHT);
    KSPGetPCSide(ksp, &n);
    if (yk == n) {
      b_n = 0;
    } else if (b_n == n) {
      b_n = 1;
    } else {
      b_n = -1;
    }
    switch (b_n) {
    case 0:
      yk = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity_char_T(side, yk);
      side_data = side->data;
      side_data[0] = 'l';
      side_data[1] = 'e';
      side_data[2] = 'f';
      side_data[3] = 't';
      break;
    case 1:
      yk = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity_char_T(side, yk);
      side_data = side->data;
      for (yk = 0; yk < 5; yk++) {
        side_data[yk] = b_cv[yk];
      }
      break;
    default:
      yk = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity_char_T(side, yk);
      side_data = side->data;
      for (yk = 0; yk < 9; yk++) {
        side_data[yk] = cv[yk];
      }
      break;
    }
    KSPGetType(ksp, &type);
    PCGetType(pc, &b_type);
    m2c_printf(type, b_type, side, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }
  emxFree_char_T(&side);
  KSPGetResidualHistory(ksp, &a, &na);
  yk = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity_real_T(reshis, yk);
  reshis_data = reshis->data;
  for (yk = 0; yk < na; yk++) {
    reshis_data[yk] = 0.0;
  }
  KSP t_ksp;
  Mat t_mat;
  memcpy(&reshis_data[0], a, na << 3);
  times[0] = time_setup;
  times[1] = b_t - t;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  VecGetLocalSize(xVec, &n);
  yk = x->size[0];
  x->size[0] = n;
  emxEnsureCapacity_real_T(x, yk);
  x_data = x->data;
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }
  yk = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity_int32_T(y, yk);
  y_data = y->data;
  if (b_n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  yk = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, yk);
  idx_data = idx->data;
  b_n = y->size[1];
  for (yk = 0; yk < b_n; yk++) {
    idx_data[yk] = y_data[yk];
  }
  emxFree_int32_T(&y);
  VecGetValues(xVec, n, &idx_data[0], &x_data[0]);
  t_vec = xVec;
  VecDestroy(&t_vec);
  emxFree_int32_T(&idx);
}

void petscSolveCRS_7args(const emxArray_int32_T *Arows,
                         const emxArray_int32_T *Acols,
                         const emxArray_real_T *Avals, const emxArray_real_T *b,
                         const emxArray_char_T *solver, double rtol,
                         int maxiter, emxArray_real_T *x, int *flag,
                         double *relres, int *iter, emxArray_real_T *reshis,
                         double times[2])
{
  KSP ksp;
  Mat AMat;
  Vec bVec;
  Vec t_vec;
  Vec xVec;
  emxArray_int32_T *idx;
  emxArray_int32_T *y;
  const double *b_data;
  double time_setup;
  double time_solve;
  double *x_data;
  int b_n;
  int k;
  int n;
  int yk;
  int *idx_data;
  int *y_data;
  b_data = b->data;
  emxInit_int32_T(&y, 2);
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  VecCreateSeq(PETSC_COMM_SELF, b->size[0], &bVec);
  if (b->size[0] - 1 < 0) {
    n = 0;
  } else {
    n = b->size[0];
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  KSP t_ksp;
  Mat t_mat;
  int iroa;
  iroa = (INSERT_VALUES);
  VecSetValues(bVec, b->size[0], &idx_data[0], &b_data[0], iroa);
  VecAssemblyBegin(bVec);
  VecAssemblyEnd(bVec);
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
  VecGetLocalSize(xVec, &n);
  k = x->size[0];
  x->size[0] = n;
  emxEnsureCapacity_real_T(x, k);
  x_data = x->data;
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (b_n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  emxFree_int32_T(&y);
  VecGetValues(xVec, n, &idx_data[0], &x_data[0]);
  t_vec = xVec;
  VecDestroy(&t_vec);
  emxFree_int32_T(&idx);
}

void petscSolveCRS_8args(const emxArray_int32_T *Arows,
                         const emxArray_int32_T *Acols,
                         const emxArray_real_T *Avals, const emxArray_real_T *b,
                         const emxArray_char_T *solver, double rtol,
                         int maxiter, const emxArray_char_T *pctype,
                         emxArray_real_T *x, int *flag, double *relres,
                         int *iter, emxArray_real_T *reshis, double times[2])
{
  KSP ksp;
  KSP t_ksp;
  MPI_Comm t_comm;
  Mat AMat;
  Mat t_mat;
  PC t_pc;
  PetscObject t_obj;
  Vec bVec;
  Vec t_vec;
  Vec xVec;
  emxArray_char_T *ksptype0;
  emxArray_char_T *pctype0;
  emxArray_int32_T *idx;
  emxArray_int32_T *y;
  const double *b_data;
  double b_t;
  double t;
  double time_solve;
  double *x_data;
  int b_n;
  int k;
  int n;
  int yk;
  int *idx_data;
  int *y_data;
  const char *pctype_data;
  const char *solver_data;
  char *ksptype0_data;
  char *pctype0_data;
  pctype_data = pctype->data;
  solver_data = solver->data;
  b_data = b->data;
  emxInit_int32_T(&y, 2);
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  VecCreateSeq(PETSC_COMM_SELF, b->size[0], &bVec);
  if (b->size[0] - 1 < 0) {
    n = 0;
  } else {
    n = b->size[0];
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  int iroa;
  iroa = (INSERT_VALUES);
  VecSetValues(bVec, b->size[0], &idx_data[0], &b_data[0], iroa);
  VecAssemblyBegin(bVec);
  VecAssemblyEnd(bVec);
  VecDuplicate(bVec, &xVec);
  t_obj = (PetscObject)(AMat);
  PetscObjectGetComm(t_obj, &t_comm);
  KSPCreate(t_comm, &ksp);
  KSPGetPC(ksp, &t_pc);
  KSPSetOperators(ksp, AMat, AMat);
  if (pctype->size[1] != 0) {
    emxInit_char_T(&pctype0, 2);
    if (pctype_data[pctype->size[1] - 1] != '\x00') {
      k = pctype0->size[0] * pctype0->size[1];
      pctype0->size[0] = 1;
      pctype0->size[1] = pctype->size[1] + 1;
      emxEnsureCapacity_char_T(pctype0, k);
      pctype0_data = pctype0->data;
      yk = pctype->size[1];
      for (k = 0; k < yk; k++) {
        pctype0_data[k] = pctype_data[k];
      }
      pctype0_data[pctype->size[1]] = '\x00';
    } else {
      k = pctype0->size[0] * pctype0->size[1];
      pctype0->size[0] = 1;
      pctype0->size[1] = pctype->size[1];
      emxEnsureCapacity_char_T(pctype0, k);
      pctype0_data = pctype0->data;
      yk = pctype->size[1];
      for (k = 0; k < yk; k++) {
        pctype0_data[k] = pctype_data[k];
      }
    }
    PCSetType(t_pc, &pctype0_data[0]);
    emxFree_char_T(&pctype0);
  }
  emxInit_char_T(&ksptype0, 2);
  if ((solver->size[1] != 0) &&
      ((unsigned char)solver_data[solver->size[1] - 1] != 0)) {
    k = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = solver->size[1] + 1;
    emxEnsureCapacity_char_T(ksptype0, k);
    ksptype0_data = ksptype0->data;
    yk = solver->size[1];
    for (k = 0; k < yk; k++) {
      ksptype0_data[k] = solver_data[k];
    }
    ksptype0_data[solver->size[1]] = '\x00';
  } else {
    k = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = solver->size[1];
    emxEnsureCapacity_char_T(ksptype0, k);
    ksptype0_data = ksptype0->data;
    yk = solver->size[1];
    for (k = 0; k < yk; k++) {
      ksptype0_data[k] = solver_data[k];
    }
  }
  if (ksptype0->size[1] != 0) {
    KSPSetType(ksp, &ksptype0_data[0]);
  }
  emxFree_char_T(&ksptype0);
  yk = (PC_RIGHT);
  KSPSetPCSide(ksp, yk);
  KSPSetFromOptions(ksp);
  t_obj = (PetscObject)(ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&t);
  KSPSetUp(ksp);
  t_obj = (PetscObject)(ksp);
  PetscBarrier(t_obj);
  PetscGetCPUTime(&b_t);
  b_petscKSPDriver(ksp, bVec, xVec, rtol, maxiter, NULL, flag, relres, iter,
                   reshis, &time_solve);
  times[0] = b_t - t;
  times[1] = time_solve;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  VecGetLocalSize(xVec, &n);
  k = x->size[0];
  x->size[0] = n;
  emxEnsureCapacity_real_T(x, k);
  x_data = x->data;
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (b_n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  emxFree_int32_T(&y);
  VecGetValues(xVec, n, &idx_data[0], &x_data[0]);
  t_vec = xVec;
  VecDestroy(&t_vec);
  emxFree_int32_T(&idx);
}

void petscSolveCRS_9args(const emxArray_int32_T *Arows,
                         const emxArray_int32_T *Acols,
                         const emxArray_real_T *Avals, const emxArray_real_T *b,
                         const emxArray_char_T *solver, double rtol,
                         int maxiter, const emxArray_char_T *pctype,
                         const emxArray_char_T *solpack, emxArray_real_T *x,
                         int *flag, double *relres, int *iter,
                         emxArray_real_T *reshis, double times[2])
{
  KSP ksp;
  Mat AMat;
  Vec bVec;
  Vec t_vec;
  Vec xVec;
  emxArray_int32_T *idx;
  emxArray_int32_T *y;
  const double *b_data;
  double time_setup;
  double time_solve;
  double *x_data;
  int b_n;
  int k;
  int n;
  int yk;
  int *idx_data;
  int *y_data;
  b_data = b->data;
  emxInit_int32_T(&y, 2);
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  VecCreateSeq(PETSC_COMM_SELF, b->size[0], &bVec);
  if (b->size[0] - 1 < 0) {
    n = 0;
  } else {
    n = b->size[0];
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  KSP t_ksp;
  Mat t_mat;
  int iroa;
  iroa = (INSERT_VALUES);
  VecSetValues(bVec, b->size[0], &idx_data[0], &b_data[0], iroa);
  VecAssemblyBegin(bVec);
  VecAssemblyEnd(bVec);
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
  VecGetLocalSize(xVec, &n);
  k = x->size[0];
  x->size[0] = n;
  emxEnsureCapacity_real_T(x, k);
  x_data = x->data;
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity_int32_T(y, k);
  y_data = y->data;
  if (b_n > 0) {
    y_data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  idx_data = idx->data;
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx_data[k] = y_data[k];
  }
  emxFree_int32_T(&y);
  VecGetValues(xVec, n, &idx_data[0], &x_data[0]);
  t_vec = xVec;
  VecDestroy(&t_vec);
  emxFree_int32_T(&idx);
}

void petscSolveCRS_initialize(void)
{
}

void petscSolveCRS_terminate(void)
{
}
