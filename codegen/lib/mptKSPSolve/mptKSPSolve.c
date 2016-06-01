#include "mptKSPSolve.h"
#include "m2c.h"
#include "mpetsc.h"

static void b_m2c_error(int varargin_3);
static void b_m2c_printf(double varargin_2, int varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_printf(double varargin_2, double varargin_3);
static void d_m2c_error(int varargin_3);
static void d_m2c_printf(int varargin_2, double varargin_3);
static void e_m2c_error(int varargin_3);
static void e_m2c_printf(void);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void emxInit_uint8_T1(emxArray_uint8_T **pEmxArray, int numDimensions);
static void f_m2c_error(const emxArray_char_T *varargin_3);
static void g_m2c_error(int varargin_3);
static void h_m2c_error(int varargin_3);
static void i_m2c_error(int varargin_3);
static void j_m2c_error(int varargin_3);
static void k_m2c_error(int varargin_3);
static void l_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_printf(KSPType varargin_2, PCType varargin_3, const
  emxArray_char_T *varargin_4, int varargin_5);
static void m_m2c_error(int varargin_3);
static void mpi_Barrier(MPI_Comm comm);
static void n_m2c_error(int varargin_3);
static void o_m2c_error(int varargin_3);
static void p_m2c_error(int varargin_3);
static void petscKSPSetTolerances(KSP ksp, double rtol, double abstol, double
  dtol, int maxits);
static void petscKSPSolve(KSP ksp, const emxArray_uint8_T *b_data, const
  emxArray_char_T *b_type, const emxArray_uint8_T *x_data, const emxArray_char_T
  *x_type);
static MPI_Comm petscObjectGetComm(KSP obj);
static double petscVecNorm(const emxArray_uint8_T *x_data, const emxArray_char_T
  *x_type, int type);
static void q_m2c_error(int varargin_3);
static void r_m2c_error(int varargin_3);
static void s_m2c_error(int varargin_3);
static void t_m2c_error(int varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecNorm returned error code %d\n", varargin_3);
}

static void b_m2c_printf(double varargin_2, int varargin_3)
{
  M2C_printf("### The relative residual was %g after %d iterations.\n",
             varargin_2, varargin_3);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected KSP.\n", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_printf(double varargin_2, double varargin_3)
{
  M2C_printf("### The relative and absolute tolerances were %g and %g.\n",
             varargin_2, varargin_3);
}

static void d_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscObjectGetComm returned error code %d\n",
            varargin_3);
}

static void d_m2c_printf(int varargin_2, double varargin_3)
{
  M2C_printf("### The divergence and max-iter tolerances were %d and %g.\n",
             varargin_2, varargin_3);
}

static void e_m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Error_string with error code %d\n",
            varargin_3);
}

static void e_m2c_printf(void)
{
  M2C_printf("### For explanation of the flag, see http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPConvergedReason.html.\n");
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static void emxInit_uint8_T1(emxArray_uint8_T **pEmxArray, int numDimensions)
{
  emxArray_uint8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint8_T *)malloc(sizeof(emxArray_uint8_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void f_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i4;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i4 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i4, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_varargin_3->data[i4] = varargin_3->data[i4];
  }

  M2C_error("MPI:RuntimeError", "MPI_Barrier failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void g_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetTolerances returned error code %d\n",
            varargin_3);
}

static void h_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecCopy returned error code %d\n", varargin_3);
}

static void i_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "petscKSPSetResidualHistory returned error code %d\n", varargin_3);
}

static void j_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPSetInitialGuessNonzero returned error code %d\n", varargin_3);
}

static void k_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSolve returned error code %d\n",
            varargin_3);
}

static void l_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetConvergedReason returned error code %d\n", varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected Vec.\n", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_printf(KSPType varargin_2, PCType varargin_3, const
  emxArray_char_T *varargin_4, int varargin_5)
{
  emxArray_char_T *b_varargin_4;
  int i6;
  int loop_ub;
  emxInit_char_T(&b_varargin_4, 2);
  i6 = b_varargin_4->size[0] * b_varargin_4->size[1];
  b_varargin_4->size[0] = 1;
  b_varargin_4->size[1] = varargin_4->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_4, i6, (int)sizeof(char));
  loop_ub = varargin_4->size[0] * varargin_4->size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    b_varargin_4->data[i6] = varargin_4->data[i6];
  }

  M2C_printf("### %s with %s as %s preconditioner stopped with flag %d.\n",
             varargin_2, varargin_3, &b_varargin_4->data[0], varargin_5);
  emxFree_char_T(&b_varargin_4);
}

static void m_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetResidualNorm returned error code %d\n",
            varargin_3);
}

static void mpi_Barrier(MPI_Comm comm)
{
  int info;
  emxArray_uint8_T *varargin_1;
  emxArray_char_T *b_varargin_1;
  boolean_T flag;
  unsigned char msg0[1024];
  char * ptr;
  int resultlen;
  int loop_ub;
  int i3;
  info = MPI_Barrier(comm);
  emxInit_uint8_T1(&varargin_1, 2);
  emxInit_char_T(&b_varargin_1, 2);
  if (info != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      memset(&msg0[0], 0, sizeof(unsigned char) << 10);
      ptr = (char *)(msg0);
      resultlen = 0;
      info = MPI_Error_string(info, ptr, &resultlen);
      if (1 > resultlen) {
        loop_ub = 0;
      } else {
        loop_ub = resultlen;
      }

      i3 = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = 1;
      varargin_1->size[1] = loop_ub;
      emxEnsureCapacity((emxArray__common *)varargin_1, i3, (int)sizeof(unsigned
        char));
      for (i3 = 0; i3 < loop_ub; i3++) {
        varargin_1->data[varargin_1->size[0] * i3] = msg0[i3];
      }

      if (info != 0) {
        flag = (M2C_DEBUG);
        if (flag) {
          e_m2c_error(info);
        }
      }

      i3 = b_varargin_1->size[0] * b_varargin_1->size[1];
      b_varargin_1->size[0] = 1;
      b_varargin_1->size[1] = (short)loop_ub;
      emxEnsureCapacity((emxArray__common *)b_varargin_1, i3, (int)sizeof(char));
      loop_ub = (short)loop_ub;
      for (i3 = 0; i3 < loop_ub; i3++) {
        b_varargin_1->data[i3] = (signed char)varargin_1->data[i3];
      }

      f_m2c_error(b_varargin_1);
    }
  }

  emxFree_char_T(&b_varargin_1);
  emxFree_uint8_T(&varargin_1);
}

static void n_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetIterationNumber returned error code %d\n", varargin_3);
}

static void o_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetTolerances returned error code %d\n",
            varargin_3);
}

static void p_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetPC returned error code %d\n",
            varargin_3);
}

static void petscKSPSetTolerances(KSP ksp, double rtol, double abstol, double
  dtol, int maxits)
{
  int errCode;
  boolean_T flag;
  errCode = KSPSetTolerances(ksp, rtol, abstol, dtol, maxits);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      g_m2c_error(errCode);
    }
  }
}

static void petscKSPSolve(KSP ksp, const emxArray_uint8_T *b_data, const
  emxArray_char_T *b_type, const emxArray_uint8_T *x_data, const emxArray_char_T
  *x_type)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg4;
  int i5;
  boolean_T exitg3;
  emxArray_char_T *b_b_type;
  static const char cv6[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  Vec t_b;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_x_type;
  Vec t_x;
  int errCode;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i5 = b_type->size[k];
      if (i5 != (k << 1) + 1) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(b_type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(b_type->data[k] == cv6[k])) {
        b_p = false;
        exitg3 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_b_type, 2);
    i5 = b_b_type->size[0] * b_b_type->size[1];
    b_b_type->size[0] = 1;
    b_b_type->size[1] = b_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_b_type, i5, (int)sizeof(char));
    k = b_type->size[1];
    for (i5 = 0; i5 < k; i5++) {
      b_b_type->data[b_b_type->size[0] * i5] = b_type->data[b_type->size[0] * i5];
    }

    b_b_type->data[b_b_type->size[0] * b_type->size[1]] = '\x00';
    m2c_error(b_b_type);
    emxFree_char_T(&b_b_type);
  }

  emxInit_uint8_T(&data, 1);
  i5 = data->size[0];
  data->size[0] = b_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i5, (int)sizeof(unsigned char));
  k = b_data->size[0];
  for (i5 = 0; i5 < k; i5++) {
    data->data[i5] = b_data->data[i5];
  }

  t_b = *(Vec*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i5 = x_type->size[k];
      if (i5 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(x_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(x_type->data[k] == cv6[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_x_type, 2);
    i5 = b_x_type->size[0] * b_x_type->size[1];
    b_x_type->size[0] = 1;
    b_x_type->size[1] = x_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_x_type, i5, (int)sizeof(char));
    k = x_type->size[1];
    for (i5 = 0; i5 < k; i5++) {
      b_x_type->data[b_x_type->size[0] * i5] = x_type->data[x_type->size[0] * i5];
    }

    b_x_type->data[b_x_type->size[0] * x_type->size[1]] = '\x00';
    m2c_error(b_x_type);
    emxFree_char_T(&b_x_type);
  }

  i5 = data->size[0];
  data->size[0] = x_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i5, (int)sizeof(unsigned char));
  k = x_data->size[0];
  for (i5 = 0; i5 < k; i5++) {
    data->data[i5] = x_data->data[i5];
  }

  t_x = *(Vec*)(&data->data[0]);
  errCode = KSPSolve(ksp, t_b, t_x);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      k_m2c_error(errCode);
    }
  }
}

static MPI_Comm petscObjectGetComm(KSP obj)
{
  MPI_Comm comm;
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  boolean_T flag;
  t_obj = (PetscObject)(obj);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  comm = t_comm;
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      d_m2c_error(errCode);
    }
  }

  return comm;
}

static double petscVecNorm(const emxArray_uint8_T *x_data, const emxArray_char_T
  *x_type, int type)
{
  double nrm;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_x_type;
  static const char cv5[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  Vec vec;
  int errCode;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = x_type->size[k];
      if (i0 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(x_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(x_type->data[k] == cv5[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_x_type, 2);
    i0 = b_x_type->size[0] * b_x_type->size[1];
    b_x_type->size[0] = 1;
    b_x_type->size[1] = x_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_x_type, i0, (int)sizeof(char));
    k = x_type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_x_type->data[b_x_type->size[0] * i0] = x_type->data[x_type->size[0] * i0];
    }

    b_x_type->data[b_x_type->size[0] * x_type->size[1]] = '\x00';
    m2c_error(b_x_type);
    emxFree_char_T(&b_x_type);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = x_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = x_data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = x_data->data[i0];
  }

  vec = *(Vec*)(&data->data[0]);
  errCode = VecNorm(vec, type, &nrm);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      b_m2c_error(errCode);
    }
  }

  return nrm;
}

static void q_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetPCSide returned error code %d\n",
            varargin_3);
}

static void r_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetType returned error code %d\n",
            varargin_3);
}

static void s_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCGetType returned error code %d\n",
            varargin_3);
}

static void t_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetResidualHistory returned error code %d\n", varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mptKSPSolve(const struct0_T *ksp, const struct0_T *b, const struct0_T *x,
                 double rtol, int maxits, const struct0_T *x0, int *flag, double
                 *relres, int *iter, emxArray_real_T *reshis, double *time)
{
  int k;
  double bnrm;
  boolean_T p;
  boolean_T b_p;
  int exitg7;
  int val;
  boolean_T exitg6;
  emxArray_char_T *b_ksp;
  static const char cv0[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  MPI_Comm comm;
  double t;
  boolean_T exitg5;
  boolean_T b0;
  int errCode;
  int exitg4;
  double secs;
  boolean_T exitg3;
  emxArray_char_T *b_x0;
  static const char cv1[3] = { 'V', 'e', 'c' };

  double res;
  Vec vec;
  double b_rtol;
  double abstol;
  int exitg2;
  double dtol;
  int b_maxits;
  emxArray_char_T *side;
  PC t_pc;
  boolean_T exitg1;
  PetscReal * a;
  int na;
  emxArray_char_T *b_x;
  int b_side;
  Vec b_vec;
  static const char cv2[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  static const char cv3[4] = { 'l', 'e', 'f', 't' };

  static const char cv4[5] = { 'r', 'i', 'g', 'h', 't' };

  KSPType t_type;
  PCType b_t_type;
  k = (NORM_2);
  bnrm = petscVecNorm(b->data, b->type, k);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg7 = 0;
    if (k < 2) {
      val = ksp->type->size[k];
      if (val != (k << 1) + 1) {
        exitg7 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg7 = 1;
    }
  } while (exitg7 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg6 = false;
    while ((!exitg6) && (k < 3)) {
      if (!(ksp->type->data[k] == cv0[k])) {
        b_p = false;
        exitg6 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_ksp, 2);
    val = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, val, (int)sizeof(char));
    k = ksp->type->size[1];
    for (val = 0; val < k; val++) {
      b_ksp->data[b_ksp->size[0] * val] = ksp->type->data[ksp->type->size[0] *
        val];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    c_m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  val = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (val = 0; val < k; val++) {
    data->data[val] = ksp->data->data[val];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  comm = petscObjectGetComm(t_ksp);
  mpi_Barrier(comm);
  t = MPI_Wtime();
  if (maxits == 0) {
    maxits = (PETSC_DEFAULT);
  }

  if (rtol == 0.0) {
    k = (PETSC_DEFAULT);
    rtol = k;
  }

  k = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  petscKSPSetTolerances(t_ksp, rtol, k, val, maxits);
  p = false;
  k = 1;
  exitg5 = false;
  while ((!exitg5) && (k <= x0->data->size[0])) {
    b0 = (x0->data->data[k - 1] == 0);
    if (!b0) {
      p = true;
      exitg5 = true;
    } else {
      k++;
    }
  }

  b0 = !!p;
  if (b0) {
    p = false;
    b_p = false;
    k = 0;
    do {
      exitg4 = 0;
      if (k < 2) {
        val = x0->type->size[k];
        if (val != (k << 1) + 1) {
          exitg4 = 1;
        } else {
          k++;
        }
      } else {
        b_p = true;
        exitg4 = 1;
      }
    } while (exitg4 == 0);

    if (b_p && (!(x0->type->size[1] == 0))) {
      k = 0;
      exitg3 = false;
      while ((!exitg3) && (k < 3)) {
        if (!(x0->type->data[k] == cv1[k])) {
          b_p = false;
          exitg3 = true;
        } else {
          k++;
        }
      }
    }

    if (!b_p) {
    } else {
      p = true;
    }

    if (!p) {
      emxInit_char_T(&b_x0, 2);
      val = b_x0->size[0] * b_x0->size[1];
      b_x0->size[0] = 1;
      b_x0->size[1] = x0->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_x0, val, (int)sizeof(char));
      k = x0->type->size[1];
      for (val = 0; val < k; val++) {
        b_x0->data[b_x0->size[0] * val] = x0->type->data[x0->type->size[0] * val];
      }

      b_x0->data[b_x0->size[0] * x0->type->size[1]] = '\x00';
      m2c_error(b_x0);
      emxFree_char_T(&b_x0);
    }

    val = data->size[0];
    data->size[0] = x0->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
    k = x0->data->size[0];
    for (val = 0; val < k; val++) {
      data->data[val] = x0->data->data[val];
    }

    vec = *(Vec*)(&data->data[0]);
    p = false;
    b_p = false;
    k = 0;
    do {
      exitg2 = 0;
      if (k < 2) {
        val = x->type->size[k];
        if (val != (k << 1) + 1) {
          exitg2 = 1;
        } else {
          k++;
        }
      } else {
        b_p = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (b_p && (!(x->type->size[1] == 0))) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (!(x->type->data[k] == cv1[k])) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (!b_p) {
    } else {
      p = true;
    }

    if (!p) {
      emxInit_char_T(&b_x, 2);
      val = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = x->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_x, val, (int)sizeof(char));
      k = x->type->size[1];
      for (val = 0; val < k; val++) {
        b_x->data[b_x->size[0] * val] = x->type->data[x->type->size[0] * val];
      }

      b_x->data[b_x->size[0] * x->type->size[1]] = '\x00';
      m2c_error(b_x);
      emxFree_char_T(&b_x);
    }

    val = data->size[0];
    data->size[0] = x->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
    k = x->data->size[0];
    for (val = 0; val < k; val++) {
      data->data[val] = x->data->data[val];
    }

    b_vec = *(Vec*)(&data->data[0]);
    errCode = VecCopy(vec, b_vec);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        h_m2c_error(errCode);
      }
    }
  }

  emxFree_uint8_T(&data);
  k = (PETSC_TRUE);
  errCode = KSPSetResidualHistory(t_ksp, NULL, maxits, k);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPSetInitialGuessNonzero(t_ksp, (int)b0);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      j_m2c_error(errCode);
    }
  }

  petscKSPSolve(t_ksp, b->data, b->type, x->data, x->type);
  mpi_Barrier(comm);
  secs = MPI_Wtime();
  *time = secs - t;
  errCode = KSPGetConvergedReason(t_ksp, flag);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(t_ksp, &res);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      m_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(t_ksp, iter);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      n_m2c_error(errCode);
    }
  }

  *relres = res / bnrm;
  errCode = KSPGetTolerances(t_ksp, &b_rtol, &abstol, &dtol, &b_maxits);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      o_m2c_error(errCode);
    }
  }

  emxInit_char_T(&side, 2);
  if ((*flag < 0) || (*relres > b_rtol)) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        p_m2c_error(errCode);
      }
    }

    errCode = KSPGetPCSide(t_ksp, &b_side);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        q_m2c_error(errCode);
      }
    }

    k = (PC_LEFT);
    val = (PC_RIGHT);
    if (k == b_side) {
      k = 0;
    } else if (val == b_side) {
      k = 1;
    } else {
      k = -1;
    }

    switch (k) {
     case 0:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 4; val++) {
        side->data[val] = cv3[val];
      }
      break;

     case 1:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 5; val++) {
        side->data[val] = cv4[val];
      }
      break;

     default:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 9; val++) {
        side->data[val] = cv2[val];
      }
      break;
    }

    errCode = KSPGetType(t_ksp, &t_type);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        r_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        s_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, side, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(b_maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  errCode = KSPGetResidualHistory(t_ksp, &a, &na);
  val = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity((emxArray__common *)reshis, val, (int)sizeof(double));
  for (val = 0; val < na; val++) {
    reshis->data[val] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      t_m2c_error(errCode);
    }
  }
}

void mptKSPSolve_2args(const struct0_T *ksp, const struct0_T *b, int *flag,
  double *relres, int *iter, emxArray_real_T *reshis, double *time)
{
  int val;
  double bnrm;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv7[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  double t;
  int maxits;
  int nonzeroGuess;
  double secs;
  int b_flag;
  double res;
  int b_iter;
  double b_relres;
  double rtol;
  double abstol;
  double dtol;
  emxArray_char_T *side;
  PC t_pc;
  PetscReal * a;
  int na;
  int b_side;
  static const char cv8[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  static const char cv9[4] = { 'l', 'e', 'f', 't' };

  static const char cv10[5] = { 'r', 'i', 'g', 'h', 't' };

  KSPType t_type;
  PCType b_t_type;
  val = (NORM_2);
  bnrm = petscVecNorm(b->data, b->type, val);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      val = ksp->type->size[k];
      if (val != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp->type->data[k] == cv7[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_ksp, 2);
    val = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, val, (int)sizeof(char));
    k = ksp->type->size[1];
    for (val = 0; val < k; val++) {
      b_ksp->data[b_ksp->size[0] * val] = ksp->type->data[ksp->type->size[0] *
        val];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    c_m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  val = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (val = 0; val < k; val++) {
    data->data[val] = ksp->data->data[val];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  t_obj = (PetscObject)(t_ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      d_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  t = MPI_Wtime();
  maxits = (PETSC_DEFAULT);
  nonzeroGuess = (PETSC_FALSE);
  val = (PETSC_TRUE);
  errCode = KSPSetResidualHistory(t_ksp, NULL, maxits, val);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPSetInitialGuessNonzero(t_ksp, nonzeroGuess);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      j_m2c_error(errCode);
    }
  }

  petscKSPSolve(t_ksp, b->data, b->type, b->data, b->type);
  mpi_Barrier(t_comm);
  secs = MPI_Wtime();
  errCode = KSPGetConvergedReason(t_ksp, &b_flag);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(t_ksp, &res);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      m_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(t_ksp, &b_iter);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      n_m2c_error(errCode);
    }
  }

  b_relres = res / bnrm;
  errCode = KSPGetTolerances(t_ksp, &rtol, &abstol, &dtol, &maxits);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      o_m2c_error(errCode);
    }
  }

  emxInit_char_T(&side, 2);
  if ((b_flag < 0) || (b_relres > rtol)) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        p_m2c_error(errCode);
      }
    }

    errCode = KSPGetPCSide(t_ksp, &b_side);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        q_m2c_error(errCode);
      }
    }

    val = (PC_LEFT);
    k = (PC_RIGHT);
    if (val == b_side) {
      k = 0;
    } else if (k == b_side) {
      k = 1;
    } else {
      k = -1;
    }

    switch (k) {
     case 0:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 4; val++) {
        side->data[val] = cv9[val];
      }
      break;

     case 1:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 5; val++) {
        side->data[val] = cv10[val];
      }
      break;

     default:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 9; val++) {
        side->data[val] = cv8[val];
      }
      break;
    }

    errCode = KSPGetType(t_ksp, &t_type);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        r_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        s_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, side, b_flag);
    b_m2c_printf(b_relres, b_iter);
    c_m2c_printf(rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  errCode = KSPGetResidualHistory(t_ksp, &a, &na);
  val = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity((emxArray__common *)reshis, val, (int)sizeof(double));
  for (val = 0; val < na; val++) {
    reshis->data[val] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      t_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
  *time = secs - t;
}

void mptKSPSolve_3args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, int *flag, double *relres, int *iter, emxArray_real_T *reshis, double
  *time)
{
  int k;
  double bnrm;
  boolean_T p;
  boolean_T b_p;
  int exitg2;
  int val;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv11[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  double t;
  int maxits;
  double secs;
  int b_flag;
  double res;
  int b_iter;
  double b_relres;
  double rtol;
  double abstol;
  double dtol;
  emxArray_char_T *side;
  PC t_pc;
  PetscReal * a;
  int na;
  int b_side;
  static const char cv12[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  static const char cv13[4] = { 'l', 'e', 'f', 't' };

  static const char cv14[5] = { 'r', 'i', 'g', 'h', 't' };

  KSPType t_type;
  PCType b_t_type;
  k = (NORM_2);
  bnrm = petscVecNorm(b->data, b->type, k);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      val = ksp->type->size[k];
      if (val != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp->type->data[k] == cv11[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_ksp, 2);
    val = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, val, (int)sizeof(char));
    k = ksp->type->size[1];
    for (val = 0; val < k; val++) {
      b_ksp->data[b_ksp->size[0] * val] = ksp->type->data[ksp->type->size[0] *
        val];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    c_m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  val = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (val = 0; val < k; val++) {
    data->data[val] = ksp->data->data[val];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  t_obj = (PetscObject)(t_ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      d_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  t = MPI_Wtime();
  maxits = (PETSC_DEFAULT);
  k = (PETSC_TRUE);
  errCode = KSPSetResidualHistory(t_ksp, NULL, maxits, k);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPSetInitialGuessNonzero(t_ksp, 0);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      j_m2c_error(errCode);
    }
  }

  petscKSPSolve(t_ksp, b->data, b->type, x->data, x->type);
  mpi_Barrier(t_comm);
  secs = MPI_Wtime();
  errCode = KSPGetConvergedReason(t_ksp, &b_flag);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(t_ksp, &res);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      m_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(t_ksp, &b_iter);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      n_m2c_error(errCode);
    }
  }

  b_relres = res / bnrm;
  errCode = KSPGetTolerances(t_ksp, &rtol, &abstol, &dtol, &maxits);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      o_m2c_error(errCode);
    }
  }

  emxInit_char_T(&side, 2);
  if ((b_flag < 0) || (b_relres > rtol)) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        p_m2c_error(errCode);
      }
    }

    errCode = KSPGetPCSide(t_ksp, &b_side);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        q_m2c_error(errCode);
      }
    }

    k = (PC_LEFT);
    val = (PC_RIGHT);
    if (k == b_side) {
      k = 0;
    } else if (val == b_side) {
      k = 1;
    } else {
      k = -1;
    }

    switch (k) {
     case 0:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 4; val++) {
        side->data[val] = cv13[val];
      }
      break;

     case 1:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 5; val++) {
        side->data[val] = cv14[val];
      }
      break;

     default:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 9; val++) {
        side->data[val] = cv12[val];
      }
      break;
    }

    errCode = KSPGetType(t_ksp, &t_type);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        r_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        s_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, side, b_flag);
    b_m2c_printf(b_relres, b_iter);
    c_m2c_printf(rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  errCode = KSPGetResidualHistory(t_ksp, &a, &na);
  val = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity((emxArray__common *)reshis, val, (int)sizeof(double));
  for (val = 0; val < na; val++) {
    reshis->data[val] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      t_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
  *time = secs - t;
}

void mptKSPSolve_4args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, double rtol, int *flag, double *relres, int *iter, emxArray_real_T *reshis,
  double *time)
{
  double b_rtol;
  int k;
  double bnrm;
  boolean_T p;
  boolean_T b_p;
  int exitg2;
  int val;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv15[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  double t;
  int maxits;
  double secs;
  int b_flag;
  double res;
  int b_iter;
  double b_relres;
  double abstol;
  double dtol;
  emxArray_char_T *side;
  PC t_pc;
  PetscReal * a;
  int na;
  int b_side;
  static const char cv16[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  static const char cv17[4] = { 'l', 'e', 'f', 't' };

  static const char cv18[5] = { 'r', 'i', 'g', 'h', 't' };

  KSPType t_type;
  PCType b_t_type;
  b_rtol = rtol;
  k = (NORM_2);
  bnrm = petscVecNorm(b->data, b->type, k);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      val = ksp->type->size[k];
      if (val != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp->type->data[k] == cv15[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_ksp, 2);
    val = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, val, (int)sizeof(char));
    k = ksp->type->size[1];
    for (val = 0; val < k; val++) {
      b_ksp->data[b_ksp->size[0] * val] = ksp->type->data[ksp->type->size[0] *
        val];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    c_m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  val = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (val = 0; val < k; val++) {
    data->data[val] = ksp->data->data[val];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  t_obj = (PetscObject)(t_ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      d_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  t = MPI_Wtime();
  maxits = (PETSC_DEFAULT);
  if (rtol == 0.0) {
    k = (PETSC_DEFAULT);
    b_rtol = k;
  }

  k = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  errCode = KSPSetTolerances(t_ksp, b_rtol, (double)k, (double)val, maxits);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      g_m2c_error(errCode);
    }
  }

  k = (PETSC_TRUE);
  errCode = KSPSetResidualHistory(t_ksp, NULL, maxits, k);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPSetInitialGuessNonzero(t_ksp, 0);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      j_m2c_error(errCode);
    }
  }

  petscKSPSolve(t_ksp, b->data, b->type, x->data, x->type);
  mpi_Barrier(t_comm);
  secs = MPI_Wtime();
  errCode = KSPGetConvergedReason(t_ksp, &b_flag);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(t_ksp, &res);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      m_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(t_ksp, &b_iter);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      n_m2c_error(errCode);
    }
  }

  b_relres = res / bnrm;
  errCode = KSPGetTolerances(t_ksp, &b_rtol, &abstol, &dtol, &maxits);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      o_m2c_error(errCode);
    }
  }

  emxInit_char_T(&side, 2);
  if ((b_flag < 0) || (b_relres > b_rtol)) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        p_m2c_error(errCode);
      }
    }

    errCode = KSPGetPCSide(t_ksp, &b_side);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        q_m2c_error(errCode);
      }
    }

    k = (PC_LEFT);
    val = (PC_RIGHT);
    if (k == b_side) {
      k = 0;
    } else if (val == b_side) {
      k = 1;
    } else {
      k = -1;
    }

    switch (k) {
     case 0:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 4; val++) {
        side->data[val] = cv17[val];
      }
      break;

     case 1:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 5; val++) {
        side->data[val] = cv18[val];
      }
      break;

     default:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 9; val++) {
        side->data[val] = cv16[val];
      }
      break;
    }

    errCode = KSPGetType(t_ksp, &t_type);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        r_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        s_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, side, b_flag);
    b_m2c_printf(b_relres, b_iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  errCode = KSPGetResidualHistory(t_ksp, &a, &na);
  val = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity((emxArray__common *)reshis, val, (int)sizeof(double));
  for (val = 0; val < na; val++) {
    reshis->data[val] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      t_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
  *time = secs - t;
}

void mptKSPSolve_5args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, double rtol, int maxiter, int *flag, double *relres, int *iter,
  emxArray_real_T *reshis, double *time)
{
  double b_rtol;
  int maxits;
  int k;
  double bnrm;
  boolean_T p;
  boolean_T b_p;
  int exitg2;
  int val;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv19[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  double t;
  double secs;
  int b_flag;
  double res;
  int b_iter;
  double b_relres;
  double abstol;
  double dtol;
  emxArray_char_T *side;
  PC t_pc;
  PetscReal * a;
  int na;
  int b_side;
  static const char cv20[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  static const char cv21[4] = { 'l', 'e', 'f', 't' };

  static const char cv22[5] = { 'r', 'i', 'g', 'h', 't' };

  KSPType t_type;
  PCType b_t_type;
  b_rtol = rtol;
  maxits = maxiter;
  k = (NORM_2);
  bnrm = petscVecNorm(b->data, b->type, k);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      val = ksp->type->size[k];
      if (val != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp->type->data[k] == cv19[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_ksp, 2);
    val = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, val, (int)sizeof(char));
    k = ksp->type->size[1];
    for (val = 0; val < k; val++) {
      b_ksp->data[b_ksp->size[0] * val] = ksp->type->data[ksp->type->size[0] *
        val];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    c_m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  val = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (val = 0; val < k; val++) {
    data->data[val] = ksp->data->data[val];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  t_obj = (PetscObject)(t_ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      d_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  t = MPI_Wtime();
  if (maxiter == 0) {
    maxits = (PETSC_DEFAULT);
  }

  if (rtol == 0.0) {
    k = (PETSC_DEFAULT);
    b_rtol = k;
  }

  k = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  errCode = KSPSetTolerances(t_ksp, b_rtol, (double)k, (double)val, maxits);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      g_m2c_error(errCode);
    }
  }

  k = (PETSC_TRUE);
  errCode = KSPSetResidualHistory(t_ksp, NULL, maxits, k);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPSetInitialGuessNonzero(t_ksp, 0);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      j_m2c_error(errCode);
    }
  }

  petscKSPSolve(t_ksp, b->data, b->type, x->data, x->type);
  mpi_Barrier(t_comm);
  secs = MPI_Wtime();
  errCode = KSPGetConvergedReason(t_ksp, &b_flag);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(t_ksp, &res);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      m_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(t_ksp, &b_iter);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      n_m2c_error(errCode);
    }
  }

  b_relres = res / bnrm;
  errCode = KSPGetTolerances(t_ksp, &b_rtol, &abstol, &dtol, &maxits);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      o_m2c_error(errCode);
    }
  }

  emxInit_char_T(&side, 2);
  if ((b_flag < 0) || (b_relres > b_rtol)) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        p_m2c_error(errCode);
      }
    }

    errCode = KSPGetPCSide(t_ksp, &b_side);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        q_m2c_error(errCode);
      }
    }

    k = (PC_LEFT);
    val = (PC_RIGHT);
    if (k == b_side) {
      k = 0;
    } else if (val == b_side) {
      k = 1;
    } else {
      k = -1;
    }

    switch (k) {
     case 0:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 4; val++) {
        side->data[val] = cv21[val];
      }
      break;

     case 1:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 5; val++) {
        side->data[val] = cv22[val];
      }
      break;

     default:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 9; val++) {
        side->data[val] = cv20[val];
      }
      break;
    }

    errCode = KSPGetType(t_ksp, &t_type);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        r_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        s_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, side, b_flag);
    b_m2c_printf(b_relres, b_iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  errCode = KSPGetResidualHistory(t_ksp, &a, &na);
  val = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity((emxArray__common *)reshis, val, (int)sizeof(double));
  for (val = 0; val < na; val++) {
    reshis->data[val] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      t_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
  *time = secs - t;
}

void mptKSPSolve_initialize(void)
{
}

void mptKSPSolve_terminate(void)
{
}
