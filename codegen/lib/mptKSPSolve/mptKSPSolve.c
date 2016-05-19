#include "mptKSPSolve.h"
#include "petscksp.h"
#include "petscsys.h"
#include "mpetsc.h"
#include "m2c.h"

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
static void f_m2c_error(int varargin_3);
static void g_m2c_error(int varargin_3);
static void h_m2c_error(int varargin_3);
static void i_m2c_error(int varargin_3);
static void j_m2c_error(int varargin_3);
static void k_m2c_error(int varargin_3);
static void l_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_printf(KSPType varargin_2, PCType varargin_3, int varargin_4);
static void m_m2c_error(int varargin_3);
static int petscKSPGetConvergedReason(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type);
static int petscKSPGetIterationNumber(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type);
static PC petscKSPGetPC(const emxArray_uint8_T *ksp_data, const emxArray_char_T *
  ksp_type);
static double petscKSPGetResidualNorm(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type);
static void petscKSPGetTolerances(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type, double *rtol, double *abstol, double *dtol, int
  *maxits);
static KSPType petscKSPGetType(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type);
static void petscKSPSetInitialGuessNonzero(const emxArray_uint8_T *ksp_data,
  const emxArray_char_T *ksp_type, int flag);
static void petscKSPSetTolerances(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type, double rtol, double abstol, double dtol, int maxits);
static void petscKSPSolve(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type, const emxArray_uint8_T *b_data, const
  emxArray_char_T *b_type, const emxArray_uint8_T *x_data, const emxArray_char_T
  *x_type);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetTolerances returned error code %d\n",
            varargin_3);
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

  M2C_error("PetscVec:WrongType", "Incorrect data type %s. Expected Vec.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_printf(double varargin_2, double varargin_3)
{
  M2C_printf("### The relative and absolute tolerances were %g and %g.\n",
             varargin_2, varargin_3);
}

static void d_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecCopy returned error code %d\n", varargin_3);
}

static void d_m2c_printf(int varargin_2, double varargin_3)
{
  M2C_printf("### The divergence and max-iter tolerances were %d and %g.\n",
             varargin_2, varargin_3);
}

static void e_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPSetInitialGuessNonzero returned error code %d\n", varargin_3);
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

static void f_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSolve returned error code %d\n",
            varargin_3);
}

static void g_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetConvergedReason returned error code %d\n", varargin_3);
}

static void h_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetResidualNorm returned error code %d\n",
            varargin_3);
}

static void i_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetIterationNumber returned error code %d\n", varargin_3);
}

static void j_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetTolerances returned error code %d\n",
            varargin_3);
}

static void k_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetPC returned error code %d\n",
            varargin_3);
}

static void l_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetType returned error code %d\n",
            varargin_3);
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

  M2C_error("PetscKSP:WrongType", "Incorrect data type %s. Expected KSP.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_printf(KSPType varargin_2, PCType varargin_3, int varargin_4)
{
  M2C_printf("### %s with %s preconditioner stopped with flag %d.\n", varargin_2,
             varargin_3, varargin_4);
}

static void m_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCGetType returned error code %d\n",
            varargin_3);
}

static int petscKSPGetConvergedReason(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type)
{
  int flag;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i5;
  boolean_T exitg1;
  emxArray_char_T *b_ksp_type;
  static const char cv5[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int errCode;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i5 = ksp_type->size[k];
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

  if (b_p && (!(ksp_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp_type->data[k] == cv5[k])) {
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
    emxInit_char_T(&b_ksp_type, 2);
    i5 = b_ksp_type->size[0] * b_ksp_type->size[1];
    b_ksp_type->size[0] = 1;
    b_ksp_type->size[1] = ksp_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp_type, i5, (int)sizeof(char));
    k = ksp_type->size[1];
    for (i5 = 0; i5 < k; i5++) {
      b_ksp_type->data[b_ksp_type->size[0] * i5] = ksp_type->data[ksp_type->
        size[0] * i5];
    }

    b_ksp_type->data[b_ksp_type->size[0] * ksp_type->size[1]] = '\x00';
    m2c_error(b_ksp_type);
    emxFree_char_T(&b_ksp_type);
  }

  emxInit_uint8_T(&data, 1);
  i5 = data->size[0];
  data->size[0] = ksp_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i5, (int)sizeof(unsigned char));
  k = ksp_data->size[0];
  for (i5 = 0; i5 < k; i5++) {
    data->data[i5] = ksp_data->data[i5];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  errCode = KSPGetConvergedReason(t_ksp, &flag);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      g_m2c_error(errCode);
    }
  }

  return flag;
}

static int petscKSPGetIterationNumber(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type)
{
  int its;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i7;
  boolean_T exitg1;
  emxArray_char_T *b_ksp_type;
  static const char cv7[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int errCode;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i7 = ksp_type->size[k];
      if (i7 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp_type->data[k] == cv7[k])) {
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
    emxInit_char_T(&b_ksp_type, 2);
    i7 = b_ksp_type->size[0] * b_ksp_type->size[1];
    b_ksp_type->size[0] = 1;
    b_ksp_type->size[1] = ksp_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp_type, i7, (int)sizeof(char));
    k = ksp_type->size[1];
    for (i7 = 0; i7 < k; i7++) {
      b_ksp_type->data[b_ksp_type->size[0] * i7] = ksp_type->data[ksp_type->
        size[0] * i7];
    }

    b_ksp_type->data[b_ksp_type->size[0] * ksp_type->size[1]] = '\x00';
    m2c_error(b_ksp_type);
    emxFree_char_T(&b_ksp_type);
  }

  emxInit_uint8_T(&data, 1);
  i7 = data->size[0];
  data->size[0] = ksp_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i7, (int)sizeof(unsigned char));
  k = ksp_data->size[0];
  for (i7 = 0; i7 < k; i7++) {
    data->data[i7] = ksp_data->data[i7];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  errCode = KSPGetIterationNumber(t_ksp, &its);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      i_m2c_error(errCode);
    }
  }

  return its;
}

static PC petscKSPGetPC(const emxArray_uint8_T *ksp_data, const emxArray_char_T *
  ksp_type)
{
  PC pc;
  PC t_pc;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i9;
  boolean_T exitg1;
  emxArray_char_T *b_ksp_type;
  static const char cv9[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP ksp;
  int errCode;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i9 = ksp_type->size[k];
      if (i9 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp_type->data[k] == cv9[k])) {
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
    emxInit_char_T(&b_ksp_type, 2);
    i9 = b_ksp_type->size[0] * b_ksp_type->size[1];
    b_ksp_type->size[0] = 1;
    b_ksp_type->size[1] = ksp_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp_type, i9, (int)sizeof(char));
    k = ksp_type->size[1];
    for (i9 = 0; i9 < k; i9++) {
      b_ksp_type->data[b_ksp_type->size[0] * i9] = ksp_type->data[ksp_type->
        size[0] * i9];
    }

    b_ksp_type->data[b_ksp_type->size[0] * ksp_type->size[1]] = '\x00';
    m2c_error(b_ksp_type);
    emxFree_char_T(&b_ksp_type);
  }

  emxInit_uint8_T(&data, 1);
  i9 = data->size[0];
  data->size[0] = ksp_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i9, (int)sizeof(unsigned char));
  k = ksp_data->size[0];
  for (i9 = 0; i9 < k; i9++) {
    data->data[i9] = ksp_data->data[i9];
  }

  ksp = *(KSP*)(&data->data[0]);
  errCode = KSPGetPC(ksp, &t_pc);
  pc = t_pc;
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      k_m2c_error(errCode);
    }
  }

  return pc;
}

static double petscKSPGetResidualNorm(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type)
{
  double rnorm;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i6;
  boolean_T exitg1;
  emxArray_char_T *b_ksp_type;
  static const char cv6[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int errCode;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i6 = ksp_type->size[k];
      if (i6 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp_type->data[k] == cv6[k])) {
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
    emxInit_char_T(&b_ksp_type, 2);
    i6 = b_ksp_type->size[0] * b_ksp_type->size[1];
    b_ksp_type->size[0] = 1;
    b_ksp_type->size[1] = ksp_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp_type, i6, (int)sizeof(char));
    k = ksp_type->size[1];
    for (i6 = 0; i6 < k; i6++) {
      b_ksp_type->data[b_ksp_type->size[0] * i6] = ksp_type->data[ksp_type->
        size[0] * i6];
    }

    b_ksp_type->data[b_ksp_type->size[0] * ksp_type->size[1]] = '\x00';
    m2c_error(b_ksp_type);
    emxFree_char_T(&b_ksp_type);
  }

  emxInit_uint8_T(&data, 1);
  i6 = data->size[0];
  data->size[0] = ksp_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i6, (int)sizeof(unsigned char));
  k = ksp_data->size[0];
  for (i6 = 0; i6 < k; i6++) {
    data->data[i6] = ksp_data->data[i6];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  errCode = KSPGetResidualNorm(t_ksp, &rnorm);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      h_m2c_error(errCode);
    }
  }

  return rnorm;
}

static void petscKSPGetTolerances(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type, double *rtol, double *abstol, double *dtol, int
  *maxits)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i8;
  boolean_T exitg1;
  emxArray_char_T *b_ksp_type;
  static const char cv8[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int errCode;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i8 = ksp_type->size[k];
      if (i8 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp_type->data[k] == cv8[k])) {
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
    emxInit_char_T(&b_ksp_type, 2);
    i8 = b_ksp_type->size[0] * b_ksp_type->size[1];
    b_ksp_type->size[0] = 1;
    b_ksp_type->size[1] = ksp_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp_type, i8, (int)sizeof(char));
    k = ksp_type->size[1];
    for (i8 = 0; i8 < k; i8++) {
      b_ksp_type->data[b_ksp_type->size[0] * i8] = ksp_type->data[ksp_type->
        size[0] * i8];
    }

    b_ksp_type->data[b_ksp_type->size[0] * ksp_type->size[1]] = '\x00';
    m2c_error(b_ksp_type);
    emxFree_char_T(&b_ksp_type);
  }

  emxInit_uint8_T(&data, 1);
  i8 = data->size[0];
  data->size[0] = ksp_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i8, (int)sizeof(unsigned char));
  k = ksp_data->size[0];
  for (i8 = 0; i8 < k; i8++) {
    data->data[i8] = ksp_data->data[i8];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  errCode = KSPGetTolerances(t_ksp, rtol, abstol, dtol, maxits);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      j_m2c_error(errCode);
    }
  }
}

static KSPType petscKSPGetType(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type)
{
  KSPType type;
  KSPType t_type;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i10;
  boolean_T exitg1;
  emxArray_char_T *b_ksp_type;
  static const char cv10[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP ksp;
  int errCode;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i10 = ksp_type->size[k];
      if (i10 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp_type->data[k] == cv10[k])) {
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
    emxInit_char_T(&b_ksp_type, 2);
    i10 = b_ksp_type->size[0] * b_ksp_type->size[1];
    b_ksp_type->size[0] = 1;
    b_ksp_type->size[1] = ksp_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp_type, i10, (int)sizeof(char));
    k = ksp_type->size[1];
    for (i10 = 0; i10 < k; i10++) {
      b_ksp_type->data[b_ksp_type->size[0] * i10] = ksp_type->data
        [ksp_type->size[0] * i10];
    }

    b_ksp_type->data[b_ksp_type->size[0] * ksp_type->size[1]] = '\x00';
    m2c_error(b_ksp_type);
    emxFree_char_T(&b_ksp_type);
  }

  emxInit_uint8_T(&data, 1);
  i10 = data->size[0];
  data->size[0] = ksp_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i10, (int)sizeof(unsigned char));
  k = ksp_data->size[0];
  for (i10 = 0; i10 < k; i10++) {
    data->data[i10] = ksp_data->data[i10];
  }

  ksp = *(KSP*)(&data->data[0]);
  errCode = KSPGetType(ksp, &t_type);
  type = t_type;
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      l_m2c_error(errCode);
    }
  }

  return type;
}

static void petscKSPSetInitialGuessNonzero(const emxArray_uint8_T *ksp_data,
  const emxArray_char_T *ksp_type, int flag)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i3;
  boolean_T exitg1;
  emxArray_char_T *b_ksp_type;
  static const char cv2[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int errCode;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i3 = ksp_type->size[k];
      if (i3 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp_type->data[k] == cv2[k])) {
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
    emxInit_char_T(&b_ksp_type, 2);
    i3 = b_ksp_type->size[0] * b_ksp_type->size[1];
    b_ksp_type->size[0] = 1;
    b_ksp_type->size[1] = ksp_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp_type, i3, (int)sizeof(char));
    k = ksp_type->size[1];
    for (i3 = 0; i3 < k; i3++) {
      b_ksp_type->data[b_ksp_type->size[0] * i3] = ksp_type->data[ksp_type->
        size[0] * i3];
    }

    b_ksp_type->data[b_ksp_type->size[0] * ksp_type->size[1]] = '\x00';
    m2c_error(b_ksp_type);
    emxFree_char_T(&b_ksp_type);
  }

  emxInit_uint8_T(&data, 1);
  i3 = data->size[0];
  data->size[0] = ksp_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i3, (int)sizeof(unsigned char));
  k = ksp_data->size[0];
  for (i3 = 0; i3 < k; i3++) {
    data->data[i3] = ksp_data->data[i3];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  errCode = KSPSetInitialGuessNonzero(t_ksp, flag);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      e_m2c_error(errCode);
    }
  }
}

static void petscKSPSetTolerances(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type, double rtol, double abstol, double dtol, int maxits)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_ksp_type;
  static const char cv1[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int errCode;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = ksp_type->size[k];
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

  if (b_p && (!(ksp_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp_type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_ksp_type, 2);
    i0 = b_ksp_type->size[0] * b_ksp_type->size[1];
    b_ksp_type->size[0] = 1;
    b_ksp_type->size[1] = ksp_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp_type, i0, (int)sizeof(char));
    k = ksp_type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_ksp_type->data[b_ksp_type->size[0] * i0] = ksp_type->data[ksp_type->
        size[0] * i0];
    }

    b_ksp_type->data[b_ksp_type->size[0] * ksp_type->size[1]] = '\x00';
    m2c_error(b_ksp_type);
    emxFree_char_T(&b_ksp_type);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = ksp_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = ksp_data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = ksp_data->data[i0];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  errCode = KSPSetTolerances(t_ksp, rtol, abstol, dtol, maxits);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      b_m2c_error(errCode);
    }
  }
}

static void petscKSPSolve(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type, const emxArray_uint8_T *b_data, const
  emxArray_char_T *b_type, const emxArray_uint8_T *x_data, const emxArray_char_T
  *x_type)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg6;
  int i4;
  boolean_T exitg5;
  emxArray_char_T *b_ksp_type;
  static const char cv3[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *b_b_type;
  static const char cv4[3] = { 'V', 'e', 'c' };

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
    exitg6 = 0;
    if (k < 2) {
      i4 = ksp_type->size[k];
      if (i4 != (k << 1) + 1) {
        exitg6 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg6 = 1;
    }
  } while (exitg6 == 0);

  if (b_p && (!(ksp_type->size[1] == 0))) {
    k = 0;
    exitg5 = false;
    while ((!exitg5) && (k < 3)) {
      if (!(ksp_type->data[k] == cv3[k])) {
        b_p = false;
        exitg5 = true;
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
    emxInit_char_T(&b_ksp_type, 2);
    i4 = b_ksp_type->size[0] * b_ksp_type->size[1];
    b_ksp_type->size[0] = 1;
    b_ksp_type->size[1] = ksp_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp_type, i4, (int)sizeof(char));
    k = ksp_type->size[1];
    for (i4 = 0; i4 < k; i4++) {
      b_ksp_type->data[b_ksp_type->size[0] * i4] = ksp_type->data[ksp_type->
        size[0] * i4];
    }

    b_ksp_type->data[b_ksp_type->size[0] * ksp_type->size[1]] = '\x00';
    m2c_error(b_ksp_type);
    emxFree_char_T(&b_ksp_type);
  }

  emxInit_uint8_T(&data, 1);
  i4 = data->size[0];
  data->size[0] = ksp_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i4, (int)sizeof(unsigned char));
  k = ksp_data->size[0];
  for (i4 = 0; i4 < k; i4++) {
    data->data[i4] = ksp_data->data[i4];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i4 = b_type->size[k];
      if (i4 != (k << 1) + 1) {
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
      if (!(b_type->data[k] == cv4[k])) {
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
    i4 = b_b_type->size[0] * b_b_type->size[1];
    b_b_type->size[0] = 1;
    b_b_type->size[1] = b_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_b_type, i4, (int)sizeof(char));
    k = b_type->size[1];
    for (i4 = 0; i4 < k; i4++) {
      b_b_type->data[b_b_type->size[0] * i4] = b_type->data[b_type->size[0] * i4];
    }

    b_b_type->data[b_b_type->size[0] * b_type->size[1]] = '\x00';
    c_m2c_error(b_b_type);
    emxFree_char_T(&b_b_type);
  }

  i4 = data->size[0];
  data->size[0] = b_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i4, (int)sizeof(unsigned char));
  k = b_data->size[0];
  for (i4 = 0; i4 < k; i4++) {
    data->data[i4] = b_data->data[i4];
  }

  t_b = *(Vec*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i4 = x_type->size[k];
      if (i4 != (k << 1) + 1) {
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
      if (!(x_type->data[k] == cv4[k])) {
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
    i4 = b_x_type->size[0] * b_x_type->size[1];
    b_x_type->size[0] = 1;
    b_x_type->size[1] = x_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_x_type, i4, (int)sizeof(char));
    k = x_type->size[1];
    for (i4 = 0; i4 < k; i4++) {
      b_x_type->data[b_x_type->size[0] * i4] = x_type->data[x_type->size[0] * i4];
    }

    b_x_type->data[b_x_type->size[0] * x_type->size[1]] = '\x00';
    c_m2c_error(b_x_type);
    emxFree_char_T(&b_x_type);
  }

  i4 = data->size[0];
  data->size[0] = x_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i4, (int)sizeof(unsigned char));
  k = x_data->size[0];
  for (i4 = 0; i4 < k; i4++) {
    data->data[i4] = x_data->data[i4];
  }

  t_x = *(Vec*)(&data->data[0]);
  errCode = KSPSolve(t_ksp, t_b, t_x);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      f_m2c_error(errCode);
    }
  }
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mptKSPSolve(const struct0_T *ksp, const struct0_T *b, const struct0_T *x,
                 double rtol, int maxits, const struct0_T *x0, int *flag, double
                 *relres, int *iter, double *time)
{
  int ix;
  int val;
  boolean_T y;
  boolean_T exitg5;
  boolean_T p;
  double t;
  int exitg4;
  double b_t;
  double b_rtol;
  double abstol;
  double dtol;
  int b_maxits;
  PC pc;
  boolean_T exitg3;
  PCType t_type;
  int errCode;
  emxArray_char_T *b_x0;
  static const char cv0[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  Vec vec;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_x;
  Vec b_vec;
  if (rtol == 0.0) {
    ix = (PETSC_DEFAULT);
    rtol = ix;
  }

  if (maxits == 0) {
    maxits = (PETSC_DEFAULT);
  }

  ix = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  petscKSPSetTolerances(ksp->data, ksp->type, rtol, ix, val, maxits);
  y = false;
  ix = 1;
  exitg5 = false;
  while ((!exitg5) && (ix <= x0->data->size[0])) {
    p = (x0->data->data[ix - 1] == 0);
    if (!p) {
      y = true;
      exitg5 = true;
    } else {
      ix++;
    }
  }

  if (!!y) {
    y = false;
    p = false;
    ix = 0;
    do {
      exitg4 = 0;
      if (ix < 2) {
        val = x0->type->size[ix];
        if (val != (ix << 1) + 1) {
          exitg4 = 1;
        } else {
          ix++;
        }
      } else {
        p = true;
        exitg4 = 1;
      }
    } while (exitg4 == 0);

    if (p && (!(x0->type->size[1] == 0))) {
      ix = 0;
      exitg3 = false;
      while ((!exitg3) && (ix < 3)) {
        if (!(x0->type->data[ix] == cv0[ix])) {
          p = false;
          exitg3 = true;
        } else {
          ix++;
        }
      }
    }

    if (!p) {
    } else {
      y = true;
    }

    if (!y) {
      emxInit_char_T(&b_x0, 2);
      val = b_x0->size[0] * b_x0->size[1];
      b_x0->size[0] = 1;
      b_x0->size[1] = x0->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_x0, val, (int)sizeof(char));
      ix = x0->type->size[1];
      for (val = 0; val < ix; val++) {
        b_x0->data[b_x0->size[0] * val] = x0->type->data[x0->type->size[0] * val];
      }

      b_x0->data[b_x0->size[0] * x0->type->size[1]] = '\x00';
      c_m2c_error(b_x0);
      emxFree_char_T(&b_x0);
    }

    emxInit_uint8_T(&data, 1);
    val = data->size[0];
    data->size[0] = x0->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
    ix = x0->data->size[0];
    for (val = 0; val < ix; val++) {
      data->data[val] = x0->data->data[val];
    }

    vec = *(Vec*)(&data->data[0]);
    y = false;
    p = false;
    ix = 0;
    do {
      exitg2 = 0;
      if (ix < 2) {
        val = x->type->size[ix];
        if (val != (ix << 1) + 1) {
          exitg2 = 1;
        } else {
          ix++;
        }
      } else {
        p = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (p && (!(x->type->size[1] == 0))) {
      ix = 0;
      exitg1 = false;
      while ((!exitg1) && (ix < 3)) {
        if (!(x->type->data[ix] == cv0[ix])) {
          p = false;
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (!p) {
    } else {
      y = true;
    }

    if (!y) {
      emxInit_char_T(&b_x, 2);
      val = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = x->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_x, val, (int)sizeof(char));
      ix = x->type->size[1];
      for (val = 0; val < ix; val++) {
        b_x->data[b_x->size[0] * val] = x->type->data[x->type->size[0] * val];
      }

      b_x->data[b_x->size[0] * x->type->size[1]] = '\x00';
      c_m2c_error(b_x);
      emxFree_char_T(&b_x);
    }

    val = data->size[0];
    data->size[0] = x->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
    ix = x->data->size[0];
    for (val = 0; val < ix; val++) {
      data->data[val] = x->data->data[val];
    }

    b_vec = *(Vec*)(&data->data[0]);
    errCode = VecCopy(vec, b_vec);
    emxFree_uint8_T(&data);
    if (errCode != 0) {
      *flag = (M2C_DEBUG);
      if (*flag != 0) {
        d_m2c_error(errCode);
      }
    }

    ix = (PETSC_TRUE);
    petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, ix);
  } else {
    ix = (PETSC_FALSE);
    petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, ix);
  }

  t = M2C_wtime();
  petscKSPSolve(ksp->data, ksp->type, b->data, b->type, x->data, x->type);
  b_t = M2C_wtime();
  *time = b_t - t;
  *flag = petscKSPGetConvergedReason(ksp->data, ksp->type);
  *relres = petscKSPGetResidualNorm(ksp->data, ksp->type);
  *iter = petscKSPGetIterationNumber(ksp->data, ksp->type);
  petscKSPGetTolerances(ksp->data, ksp->type, &b_rtol, &abstol, &dtol, &b_maxits);
  if ((*flag < 0) || (*relres > b_rtol)) {
    pc = petscKSPGetPC(ksp->data, ksp->type);
    errCode = PCGetType(pc, &t_type);
    if (errCode != 0) {
      ix = (M2C_DEBUG);
      if (ix != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(petscKSPGetType(ksp->data, ksp->type), t_type, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(b_maxits, dtol);
    e_m2c_printf();
  }
}

void mptKSPSolve_2args(const struct0_T *ksp, const struct0_T *b, int *flag,
  double *relres, int *iter, double *time)
{
  int k;
  double t;
  boolean_T p;
  boolean_T b_p;
  int exitg4;
  int i11;
  boolean_T exitg3;
  emxArray_char_T *b_ksp;
  static const char cv11[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_b;
  static const char cv12[3] = { 'V', 'e', 'c' };

  Vec t_b;
  int errCode;
  double b_t;
  double rtol;
  double abstol;
  double dtol;
  int maxits;
  PC pc;
  PCType t_type;
  k = (PETSC_FALSE);
  petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, k);
  t = M2C_wtime();
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i11 = ksp->type->size[k];
      if (i11 != (k << 1) + 1) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(ksp->type->data[k] == cv11[k])) {
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
    emxInit_char_T(&b_ksp, 2);
    i11 = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, i11, (int)sizeof(char));
    k = ksp->type->size[1];
    for (i11 = 0; i11 < k; i11++) {
      b_ksp->data[b_ksp->size[0] * i11] = ksp->type->data[ksp->type->size[0] *
        i11];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  i11 = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i11, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (i11 = 0; i11 < k; i11++) {
    data->data[i11] = ksp->data->data[i11];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i11 = b->type->size[k];
      if (i11 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(b->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(b->type->data[k] == cv12[k])) {
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
    emxInit_char_T(&b_b, 2);
    i11 = b_b->size[0] * b_b->size[1];
    b_b->size[0] = 1;
    b_b->size[1] = b->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_b, i11, (int)sizeof(char));
    k = b->type->size[1];
    for (i11 = 0; i11 < k; i11++) {
      b_b->data[b_b->size[0] * i11] = b->type->data[b->type->size[0] * i11];
    }

    b_b->data[b_b->size[0] * b->type->size[1]] = '\x00';
    c_m2c_error(b_b);
    emxFree_char_T(&b_b);
  }

  i11 = data->size[0];
  data->size[0] = b->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i11, (int)sizeof(unsigned char));
  k = b->data->size[0];
  for (i11 = 0; i11 < k; i11++) {
    data->data[i11] = b->data->data[i11];
  }

  t_b = *(Vec*)(&data->data[0]);
  errCode = KSPSolve(t_ksp, t_b, t_b);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      f_m2c_error(errCode);
    }
  }

  b_t = M2C_wtime();
  *flag = petscKSPGetConvergedReason(ksp->data, ksp->type);
  *relres = petscKSPGetResidualNorm(ksp->data, ksp->type);
  *iter = petscKSPGetIterationNumber(ksp->data, ksp->type);
  petscKSPGetTolerances(ksp->data, ksp->type, &rtol, &abstol, &dtol, &maxits);
  if ((*flag < 0) || (*relres > rtol)) {
    pc = petscKSPGetPC(ksp->data, ksp->type);
    errCode = PCGetType(pc, &t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(petscKSPGetType(ksp->data, ksp->type), t_type, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  *time = b_t - t;
}

void mptKSPSolve_3args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, int *flag, double *relres, int *iter, double *time)
{
  int val;
  double t;
  double b_t;
  double rtol;
  double abstol;
  double dtol;
  int maxits;
  PC pc;
  PCType t_type;
  int errCode;
  val = (PETSC_FALSE);
  petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, val);
  t = M2C_wtime();
  petscKSPSolve(ksp->data, ksp->type, b->data, b->type, x->data, x->type);
  b_t = M2C_wtime();
  *flag = petscKSPGetConvergedReason(ksp->data, ksp->type);
  *relres = petscKSPGetResidualNorm(ksp->data, ksp->type);
  *iter = petscKSPGetIterationNumber(ksp->data, ksp->type);
  petscKSPGetTolerances(ksp->data, ksp->type, &rtol, &abstol, &dtol, &maxits);
  if ((*flag < 0) || (*relres > rtol)) {
    pc = petscKSPGetPC(ksp->data, ksp->type);
    errCode = PCGetType(pc, &t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(petscKSPGetType(ksp->data, ksp->type), t_type, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  *time = b_t - t;
}

void mptKSPSolve_4args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, double rtol, int *flag, double *relres, int *iter, double *time)
{
  double b_rtol;
  int val;
  int maxits;
  int b_val;
  double t;
  double b_t;
  double abstol;
  double dtol;
  PC pc;
  PCType t_type;
  int errCode;
  b_rtol = rtol;
  if (rtol == 0.0) {
    val = (PETSC_DEFAULT);
    b_rtol = val;
  }

  maxits = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  b_val = (PETSC_DEFAULT);
  petscKSPSetTolerances(ksp->data, ksp->type, b_rtol, val, b_val, maxits);
  val = (PETSC_FALSE);
  petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, val);
  t = M2C_wtime();
  petscKSPSolve(ksp->data, ksp->type, b->data, b->type, x->data, x->type);
  b_t = M2C_wtime();
  *flag = petscKSPGetConvergedReason(ksp->data, ksp->type);
  *relres = petscKSPGetResidualNorm(ksp->data, ksp->type);
  *iter = petscKSPGetIterationNumber(ksp->data, ksp->type);
  petscKSPGetTolerances(ksp->data, ksp->type, &b_rtol, &abstol, &dtol, &maxits);
  if ((*flag < 0) || (*relres > b_rtol)) {
    pc = petscKSPGetPC(ksp->data, ksp->type);
    errCode = PCGetType(pc, &t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(petscKSPGetType(ksp->data, ksp->type), t_type, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  *time = b_t - t;
}

void mptKSPSolve_5args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, double rtol, int maxiter, int *flag, double *relres, int *iter, double
  *time)
{
  double b_rtol;
  int maxits;
  int val;
  int b_val;
  double t;
  double b_t;
  double abstol;
  double dtol;
  PC pc;
  PCType t_type;
  int errCode;
  b_rtol = rtol;
  maxits = maxiter;
  if (rtol == 0.0) {
    val = (PETSC_DEFAULT);
    b_rtol = val;
  }

  if (maxiter == 0) {
    maxits = (PETSC_DEFAULT);
  }

  val = (PETSC_DEFAULT);
  b_val = (PETSC_DEFAULT);
  petscKSPSetTolerances(ksp->data, ksp->type, b_rtol, val, b_val, maxits);
  val = (PETSC_FALSE);
  petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, val);
  t = M2C_wtime();
  petscKSPSolve(ksp->data, ksp->type, b->data, b->type, x->data, x->type);
  b_t = M2C_wtime();
  *flag = petscKSPGetConvergedReason(ksp->data, ksp->type);
  *relres = petscKSPGetResidualNorm(ksp->data, ksp->type);
  *iter = petscKSPGetIterationNumber(ksp->data, ksp->type);
  petscKSPGetTolerances(ksp->data, ksp->type, &b_rtol, &abstol, &dtol, &maxits);
  if ((*flag < 0) || (*relres > b_rtol)) {
    pc = petscKSPGetPC(ksp->data, ksp->type);
    errCode = PCGetType(pc, &t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(petscKSPGetType(ksp->data, ksp->type), t_type, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  *time = b_t - t;
}

void mptKSPSolve_initialize(void)
{
}

void mptKSPSolve_terminate(void)
{
}
