#include "mptKSPSolve.h"
#include "petscksp.h"
#include "petscsys.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void b_m2c_printf(double varargin_2, int varargin_3);
static void c_m2c_error(int varargin_3);
static void c_m2c_printf(int varargin_2);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static void e_m2c_error(int varargin_3);
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
static void m2c_printf(KSPType varargin_2, PCType varargin_3, double varargin_4,
  int varargin_5);
static void m_m2c_error(int varargin_3);
static void n_m2c_error(int varargin_3);
static void o_m2c_error(int varargin_3);
static boolean_T petscIsNULL(const emxArray_uint8_T *obj_data);
static int petscKSPGetConvergedReason(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type);
static int petscKSPGetIterationNumber(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type);
static PC petscKSPGetPC(const emxArray_uint8_T *ksp_data, const emxArray_char_T *
  ksp_type);
static double petscKSPGetResidualNorm(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type);
static KSPType petscKSPGetType(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type);
static void petscKSPSetInitialGuessNonzero(const emxArray_uint8_T *ksp_data,
  const emxArray_char_T *ksp_type, int flag);
static void petscKSPSetTolerances(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type, double rtol, int arg2);
static void petscKSPSolve(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type, const emxArray_uint8_T *b_data, const
  emxArray_char_T *b_type, const emxArray_uint8_T *x_data, const emxArray_char_T
  *x_type);
static void petscVecCopy(const emxArray_uint8_T *x_data, const emxArray_char_T
  *x_type, const emxArray_uint8_T *y_data, const emxArray_char_T *y_type);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetTolerances returned error code %d\n",
            varargin_3);
}

static void b_m2c_printf(double varargin_2, int varargin_3)
{
  M2C_printf("The relative convergence tolerance was %g. The max-iter was %d.\n",
             varargin_2, varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPSetInitialGuessNonzero returned error code %d\n", varargin_3);
}

static void c_m2c_printf(int varargin_2)
{
  M2C_printf("The return flag was %d. See http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPConvergedReason.html for explanations of the flag.\n",
             varargin_2);
}

static void d_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("PetscVec:WrongType", "Incorrect data type %s. Expected Vec.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void e_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSolve returned error code %d\n",
            varargin_3);
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
  M2C_error("petsc:RuntimeError",
            "KSPGetConvergedReason returned error code %d\n", varargin_3);
}

static void g_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetResidualNorm returned error code %d\n",
            varargin_3);
}

static void h_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetIterationNumber returned error code %d\n", varargin_3);
}

static void i_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscOptionsGetReal returned error code %d\n",
            varargin_3);
}

static void j_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscOptionsGetInt returned error code %d\n",
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

static void m2c_printf(KSPType varargin_2, PCType varargin_3, double varargin_4,
  int varargin_5)
{
  M2C_printf("### %s with %s stopped with relative residual %g after %d iterations.\n",
             varargin_2, varargin_3, varargin_4, varargin_5);
}

static void m_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCGetType returned error code %d\n",
            varargin_3);
}

static void n_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecCopy returned error code %d\n", varargin_3);
}

static void o_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPBuildResidual returned error code %d\n",
            varargin_3);
}

static boolean_T petscIsNULL(const emxArray_uint8_T *obj_data)
{
  boolean_T y;
  int ix;
  boolean_T exitg1;
  boolean_T b0;
  y = false;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= obj_data->size[0])) {
    b0 = (obj_data->data[ix - 1] == 0);
    if (!b0) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  return !y;
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
  static const char cv4[3] = { 'K', 'S', 'P' };

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
      if (!(ksp_type->data[k] == cv4[k])) {
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
      f_m2c_error(errCode);
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
      h_m2c_error(errCode);
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
  int i8;
  boolean_T exitg1;
  emxArray_char_T *b_ksp_type;
  static const char cv7[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP ksp;
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
      g_m2c_error(errCode);
    }
  }

  return rnorm;
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
  int i9;
  boolean_T exitg1;
  emxArray_char_T *b_ksp_type;
  static const char cv8[3] = { 'K', 'S', 'P' };

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
  int i2;
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
      i2 = ksp_type->size[k];
      if (i2 != (k << 1) + 1) {
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
    i2 = b_ksp_type->size[0] * b_ksp_type->size[1];
    b_ksp_type->size[0] = 1;
    b_ksp_type->size[1] = ksp_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp_type, i2, (int)sizeof(char));
    k = ksp_type->size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_ksp_type->data[b_ksp_type->size[0] * i2] = ksp_type->data[ksp_type->
        size[0] * i2];
    }

    b_ksp_type->data[b_ksp_type->size[0] * ksp_type->size[1]] = '\x00';
    m2c_error(b_ksp_type);
    emxFree_char_T(&b_ksp_type);
  }

  emxInit_uint8_T(&data, 1);
  i2 = data->size[0];
  data->size[0] = ksp_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i2, (int)sizeof(unsigned char));
  k = ksp_data->size[0];
  for (i2 = 0; i2 < k; i2++) {
    data->data[i2] = ksp_data->data[i2];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  errCode = KSPSetInitialGuessNonzero(t_ksp, flag);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      c_m2c_error(errCode);
    }
  }
}

static void petscKSPSetTolerances(const emxArray_uint8_T *ksp_data, const
  emxArray_char_T *ksp_type, double rtol, int arg2)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_ksp_type;
  static const char cv0[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int abstol;
  int dtol;
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
      if (!(ksp_type->data[k] == cv0[k])) {
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
  abstol = (PETSC_DEFAULT);
  dtol = (PETSC_DEFAULT);
  errCode = KSPSetTolerances(t_ksp, rtol, abstol, dtol, arg2);
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
  int i3;
  boolean_T exitg5;
  emxArray_char_T *b_ksp_type;
  static const char cv2[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *b_b_type;
  static const char cv3[3] = { 'V', 'e', 'c' };

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
      i3 = ksp_type->size[k];
      if (i3 != (k << 1) + 1) {
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
      if (!(ksp_type->data[k] == cv2[k])) {
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
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i3 = b_type->size[k];
      if (i3 != (k << 1) + 1) {
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
      if (!(b_type->data[k] == cv3[k])) {
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
    i3 = b_b_type->size[0] * b_b_type->size[1];
    b_b_type->size[0] = 1;
    b_b_type->size[1] = b_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_b_type, i3, (int)sizeof(char));
    k = b_type->size[1];
    for (i3 = 0; i3 < k; i3++) {
      b_b_type->data[b_b_type->size[0] * i3] = b_type->data[b_type->size[0] * i3];
    }

    b_b_type->data[b_b_type->size[0] * b_type->size[1]] = '\x00';
    d_m2c_error(b_b_type);
    emxFree_char_T(&b_b_type);
  }

  i3 = data->size[0];
  data->size[0] = b_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i3, (int)sizeof(unsigned char));
  k = b_data->size[0];
  for (i3 = 0; i3 < k; i3++) {
    data->data[i3] = b_data->data[i3];
  }

  t_b = *(Vec*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i3 = x_type->size[k];
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

  if (b_p && (!(x_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(x_type->data[k] == cv3[k])) {
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
    i3 = b_x_type->size[0] * b_x_type->size[1];
    b_x_type->size[0] = 1;
    b_x_type->size[1] = x_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_x_type, i3, (int)sizeof(char));
    k = x_type->size[1];
    for (i3 = 0; i3 < k; i3++) {
      b_x_type->data[b_x_type->size[0] * i3] = x_type->data[x_type->size[0] * i3];
    }

    b_x_type->data[b_x_type->size[0] * x_type->size[1]] = '\x00';
    d_m2c_error(b_x_type);
    emxFree_char_T(&b_x_type);
  }

  i3 = data->size[0];
  data->size[0] = x_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i3, (int)sizeof(unsigned char));
  k = x_data->size[0];
  for (i3 = 0; i3 < k; i3++) {
    data->data[i3] = x_data->data[i3];
  }

  t_x = *(Vec*)(&data->data[0]);
  errCode = KSPSolve(t_ksp, t_b, t_x);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      e_m2c_error(errCode);
    }
  }
}

static void petscVecCopy(const emxArray_uint8_T *x_data, const emxArray_char_T
  *x_type, const emxArray_uint8_T *y_data, const emxArray_char_T *y_type)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg4;
  int i11;
  boolean_T exitg3;
  emxArray_char_T *b_x_type;
  static const char cv11[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  Vec vec;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_y_type;
  Vec b_vec;
  int errCode;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i11 = x_type->size[k];
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

  if (b_p && (!(x_type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(x_type->data[k] == cv11[k])) {
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
    emxInit_char_T(&b_x_type, 2);
    i11 = b_x_type->size[0] * b_x_type->size[1];
    b_x_type->size[0] = 1;
    b_x_type->size[1] = x_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_x_type, i11, (int)sizeof(char));
    k = x_type->size[1];
    for (i11 = 0; i11 < k; i11++) {
      b_x_type->data[b_x_type->size[0] * i11] = x_type->data[x_type->size[0] *
        i11];
    }

    b_x_type->data[b_x_type->size[0] * x_type->size[1]] = '\x00';
    d_m2c_error(b_x_type);
    emxFree_char_T(&b_x_type);
  }

  emxInit_uint8_T(&data, 1);
  i11 = data->size[0];
  data->size[0] = x_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i11, (int)sizeof(unsigned char));
  k = x_data->size[0];
  for (i11 = 0; i11 < k; i11++) {
    data->data[i11] = x_data->data[i11];
  }

  vec = *(Vec*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i11 = y_type->size[k];
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

  if (b_p && (!(y_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(y_type->data[k] == cv11[k])) {
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
    emxInit_char_T(&b_y_type, 2);
    i11 = b_y_type->size[0] * b_y_type->size[1];
    b_y_type->size[0] = 1;
    b_y_type->size[1] = y_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_y_type, i11, (int)sizeof(char));
    k = y_type->size[1];
    for (i11 = 0; i11 < k; i11++) {
      b_y_type->data[b_y_type->size[0] * i11] = y_type->data[y_type->size[0] *
        i11];
    }

    b_y_type->data[b_y_type->size[0] * y_type->size[1]] = '\x00';
    d_m2c_error(b_y_type);
    emxFree_char_T(&b_y_type);
  }

  i11 = data->size[0];
  data->size[0] = y_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i11, (int)sizeof(unsigned char));
  k = y_data->size[0];
  for (i11 = 0; i11 < k; i11++) {
    data->data[i11] = y_data->data[i11];
  }

  b_vec = *(Vec*)(&data->data[0]);
  errCode = VecCopy(vec, b_vec);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      n_m2c_error(errCode);
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
                 double rtol, int maxit, int *flag, double *relres, int *iter)
{
  int val;
  PetscBool b_flag;
  int errCode;
  static const char name[10] = { '-', 'k', 's', 'p', '-', 'r', 't', 'o', 'l',
    '\x00' };

  PC pc;
  static const char b_name[12] = { '-', 'k', 's', 'p', '_', 'm', 'a', 'x', '_',
    'i', 't', '\x00' };

  PCType t_type;
  petscKSPSetTolerances(ksp->data, ksp->type, rtol, maxit);
  val = (PETSC_FALSE);
  petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, val);
  petscKSPSolve(ksp->data, ksp->type, b->data, b->type, x->data, x->type);
  *flag = petscKSPGetConvergedReason(ksp->data, ksp->type);
  *relres = petscKSPGetResidualNorm(ksp->data, ksp->type);
  *iter = petscKSPGetIterationNumber(ksp->data, ksp->type);
  if (rtol < 0.0) {
    errCode = (int)PetscOptionsGetReal(NULL, NULL, name, &rtol, &b_flag);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        i_m2c_error(errCode);
      }
    }
  }

  if (maxit < 0) {
    errCode = (int)PetscOptionsGetInt(NULL, NULL, b_name, &maxit, &b_flag);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        j_m2c_error(errCode);
      }
    }
  }

  if (*relres > rtol) {
    pc = petscKSPGetPC(ksp->data, ksp->type);
    errCode = PCGetType(pc, &t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(petscKSPGetType(ksp->data, ksp->type), t_type, *relres, *iter);
    b_m2c_printf(rtol, maxit);
    c_m2c_printf(*flag);
  }
}

void mptKSPSolve_2args(const struct0_T *ksp, const struct0_T *b, int *flag,
  double *relres, int *iter)
{
  int k;
  boolean_T p;
  boolean_T b_p;
  int exitg4;
  int i10;
  boolean_T exitg3;
  emxArray_char_T *b_ksp;
  static const char cv9[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_b;
  static const char cv10[3] = { 'V', 'e', 'c' };

  Vec t_b;
  int errCode;
  double rtol;
  PetscBool b_flag;
  static const char name[10] = { '-', 'k', 's', 'p', '-', 'r', 't', 'o', 'l',
    '\x00' };

  int maxit;
  static const char b_name[12] = { '-', 'k', 's', 'p', '_', 'm', 'a', 'x', '_',
    'i', 't', '\x00' };

  PC pc;
  PCType t_type;
  k = (PETSC_FALSE);
  petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, k);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i10 = ksp->type->size[k];
      if (i10 != (k << 1) + 1) {
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
      if (!(ksp->type->data[k] == cv9[k])) {
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
    i10 = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, i10, (int)sizeof(char));
    k = ksp->type->size[1];
    for (i10 = 0; i10 < k; i10++) {
      b_ksp->data[b_ksp->size[0] * i10] = ksp->type->data[ksp->type->size[0] *
        i10];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  i10 = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i10, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (i10 = 0; i10 < k; i10++) {
    data->data[i10] = ksp->data->data[i10];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i10 = b->type->size[k];
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

  if (b_p && (!(b->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(b->type->data[k] == cv10[k])) {
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
    i10 = b_b->size[0] * b_b->size[1];
    b_b->size[0] = 1;
    b_b->size[1] = b->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_b, i10, (int)sizeof(char));
    k = b->type->size[1];
    for (i10 = 0; i10 < k; i10++) {
      b_b->data[b_b->size[0] * i10] = b->type->data[b->type->size[0] * i10];
    }

    b_b->data[b_b->size[0] * b->type->size[1]] = '\x00';
    d_m2c_error(b_b);
    emxFree_char_T(&b_b);
  }

  i10 = data->size[0];
  data->size[0] = b->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i10, (int)sizeof(unsigned char));
  k = b->data->size[0];
  for (i10 = 0; i10 < k; i10++) {
    data->data[i10] = b->data->data[i10];
  }

  t_b = *(Vec*)(&data->data[0]);
  errCode = KSPSolve(t_ksp, t_b, t_b);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      e_m2c_error(errCode);
    }
  }

  *flag = petscKSPGetConvergedReason(ksp->data, ksp->type);
  *relres = petscKSPGetResidualNorm(ksp->data, ksp->type);
  *iter = petscKSPGetIterationNumber(ksp->data, ksp->type);
  errCode = (int)PetscOptionsGetReal(NULL, NULL, name, &rtol, &b_flag);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      i_m2c_error(errCode);
    }
  }

  errCode = (int)PetscOptionsGetInt(NULL, NULL, b_name, &maxit, &b_flag);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      j_m2c_error(errCode);
    }
  }

  if (*relres > rtol) {
    pc = petscKSPGetPC(ksp->data, ksp->type);
    errCode = PCGetType(pc, &t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(petscKSPGetType(ksp->data, ksp->type), t_type, *relres, *iter);
    b_m2c_printf(rtol, maxit);
    c_m2c_printf(*flag);
  }
}

void mptKSPSolve_3args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, int *flag, double *relres, int *iter)
{
  int val;
  double rtol;
  PetscBool b_flag;
  int errCode;
  static const char name[10] = { '-', 'k', 's', 'p', '-', 'r', 't', 'o', 'l',
    '\x00' };

  int maxit;
  static const char b_name[12] = { '-', 'k', 's', 'p', '_', 'm', 'a', 'x', '_',
    'i', 't', '\x00' };

  PC pc;
  PCType t_type;
  val = (PETSC_FALSE);
  petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, val);
  petscKSPSolve(ksp->data, ksp->type, b->data, b->type, x->data, x->type);
  *flag = petscKSPGetConvergedReason(ksp->data, ksp->type);
  *relres = petscKSPGetResidualNorm(ksp->data, ksp->type);
  *iter = petscKSPGetIterationNumber(ksp->data, ksp->type);
  errCode = (int)PetscOptionsGetReal(NULL, NULL, name, &rtol, &b_flag);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      i_m2c_error(errCode);
    }
  }

  errCode = (int)PetscOptionsGetInt(NULL, NULL, b_name, &maxit, &b_flag);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      j_m2c_error(errCode);
    }
  }

  if (*relres > rtol) {
    pc = petscKSPGetPC(ksp->data, ksp->type);
    errCode = PCGetType(pc, &t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(petscKSPGetType(ksp->data, ksp->type), t_type, *relres, *iter);
    b_m2c_printf(rtol, maxit);
    c_m2c_printf(*flag);
  }
}

void mptKSPSolve_4args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, double rtol, int *flag, double *relres, int *iter)
{
  double b_rtol;
  int maxit;
  int val;
  PetscBool b_flag;
  int errCode;
  static const char name[10] = { '-', 'k', 's', 'p', '-', 'r', 't', 'o', 'l',
    '\x00' };

  static const char b_name[12] = { '-', 'k', 's', 'p', '_', 'm', 'a', 'x', '_',
    'i', 't', '\x00' };

  PC pc;
  PCType t_type;
  b_rtol = rtol;
  maxit = (PETSC_DEFAULT);
  petscKSPSetTolerances(ksp->data, ksp->type, rtol, maxit);
  val = (PETSC_FALSE);
  petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, val);
  petscKSPSolve(ksp->data, ksp->type, b->data, b->type, x->data, x->type);
  *flag = petscKSPGetConvergedReason(ksp->data, ksp->type);
  *relres = petscKSPGetResidualNorm(ksp->data, ksp->type);
  *iter = petscKSPGetIterationNumber(ksp->data, ksp->type);
  if (rtol < 0.0) {
    errCode = (int)PetscOptionsGetReal(NULL, NULL, name, &b_rtol, &b_flag);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        i_m2c_error(errCode);
      }
    }
  }

  errCode = (int)PetscOptionsGetInt(NULL, NULL, b_name, &maxit, &b_flag);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      j_m2c_error(errCode);
    }
  }

  if (*relres > b_rtol) {
    pc = petscKSPGetPC(ksp->data, ksp->type);
    errCode = PCGetType(pc, &t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(petscKSPGetType(ksp->data, ksp->type), t_type, *relres, *iter);
    b_m2c_printf(b_rtol, maxit);
    c_m2c_printf(*flag);
  }
}

void mptKSPSolve_6args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, double rtol, int maxiter, const struct0_T *x0, int *flag, double *relres,
  int *iter)
{
  double b_rtol;
  int maxit;
  int val;
  PetscBool b_flag;
  int errCode;
  static const char name[10] = { '-', 'k', 's', 'p', '-', 'r', 't', 'o', 'l',
    '\x00' };

  PC pc;
  static const char b_name[12] = { '-', 'k', 's', 'p', '_', 'm', 'a', 'x', '_',
    'i', 't', '\x00' };

  PCType t_type;
  b_rtol = rtol;
  maxit = maxiter;
  petscKSPSetTolerances(ksp->data, ksp->type, rtol, maxiter);
  if (!petscIsNULL(x0->data)) {
    petscVecCopy(x0->data, x0->type, x->data, x->type);
    val = (PETSC_TRUE);
    petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, val);
  } else {
    val = (PETSC_FALSE);
    petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, val);
  }

  petscKSPSolve(ksp->data, ksp->type, b->data, b->type, x->data, x->type);
  *flag = petscKSPGetConvergedReason(ksp->data, ksp->type);
  *relres = petscKSPGetResidualNorm(ksp->data, ksp->type);
  *iter = petscKSPGetIterationNumber(ksp->data, ksp->type);
  if (rtol < 0.0) {
    errCode = (int)PetscOptionsGetReal(NULL, NULL, name, &b_rtol, &b_flag);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        i_m2c_error(errCode);
      }
    }
  }

  if (maxiter < 0) {
    errCode = (int)PetscOptionsGetInt(NULL, NULL, b_name, &maxit, &b_flag);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        j_m2c_error(errCode);
      }
    }
  }

  if (*relres > b_rtol) {
    pc = petscKSPGetPC(ksp->data, ksp->type);
    errCode = PCGetType(pc, &t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(petscKSPGetType(ksp->data, ksp->type), t_type, *relres, *iter);
    b_m2c_printf(b_rtol, maxit);
    c_m2c_printf(*flag);
  }
}

void mptKSPSolve_7args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, double rtol, int maxiter, const struct0_T *x0, const struct0_T *resvec,
  int *flag, double *relres, int *iter)
{
  double b_rtol;
  int maxit;
  int k;
  PetscBool b_flag;
  int errCode;
  static const char name[10] = { '-', 'k', 's', 'p', '-', 'r', 't', 'o', 'l',
    '\x00' };

  PC pc;
  static const char b_name[12] = { '-', 'k', 's', 'p', '_', 'm', 'a', 'x', '_',
    'i', 't', '\x00' };

  PCType t_type;
  boolean_T p;
  boolean_T b_p;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *b_ksp;
  static const char cv12[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_resvec;
  static const char cv13[3] = { 'V', 'e', 'c' };

  Vec t_v;
  b_rtol = rtol;
  maxit = maxiter;
  petscKSPSetTolerances(ksp->data, ksp->type, rtol, maxiter);
  if (!petscIsNULL(x0->data)) {
    petscVecCopy(x0->data, x0->type, x->data, x->type);
    k = (PETSC_TRUE);
    petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, k);
  } else {
    k = (PETSC_FALSE);
    petscKSPSetInitialGuessNonzero(ksp->data, ksp->type, k);
  }

  petscKSPSolve(ksp->data, ksp->type, b->data, b->type, x->data, x->type);
  *flag = petscKSPGetConvergedReason(ksp->data, ksp->type);
  *relres = petscKSPGetResidualNorm(ksp->data, ksp->type);
  *iter = petscKSPGetIterationNumber(ksp->data, ksp->type);
  if (rtol < 0.0) {
    errCode = (int)PetscOptionsGetReal(NULL, NULL, name, &b_rtol, &b_flag);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        i_m2c_error(errCode);
      }
    }
  }

  if (maxiter < 0) {
    errCode = (int)PetscOptionsGetInt(NULL, NULL, b_name, &maxit, &b_flag);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        j_m2c_error(errCode);
      }
    }
  }

  if (*relres > b_rtol) {
    pc = petscKSPGetPC(ksp->data, ksp->type);
    errCode = PCGetType(pc, &t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(petscKSPGetType(ksp->data, ksp->type), t_type, *relres, *iter);
    b_m2c_printf(b_rtol, maxit);
    c_m2c_printf(*flag);
  }

  if (!petscIsNULL(resvec->data)) {
    p = false;
    b_p = false;
    k = 0;
    do {
      exitg4 = 0;
      if (k < 2) {
        maxit = ksp->type->size[k];
        if (maxit != (k << 1) + 1) {
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
        if (!(ksp->type->data[k] == cv12[k])) {
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
      maxit = b_ksp->size[0] * b_ksp->size[1];
      b_ksp->size[0] = 1;
      b_ksp->size[1] = ksp->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_ksp, maxit, (int)sizeof(char));
      k = ksp->type->size[1];
      for (maxit = 0; maxit < k; maxit++) {
        b_ksp->data[b_ksp->size[0] * maxit] = ksp->type->data[ksp->type->size[0]
          * maxit];
      }

      b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
      m2c_error(b_ksp);
      emxFree_char_T(&b_ksp);
    }

    emxInit_uint8_T(&data, 1);
    maxit = data->size[0];
    data->size[0] = ksp->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, maxit, (int)sizeof(unsigned char));
    k = ksp->data->size[0];
    for (maxit = 0; maxit < k; maxit++) {
      data->data[maxit] = ksp->data->data[maxit];
    }

    t_ksp = *(KSP*)(&data->data[0]);
    p = false;
    b_p = false;
    k = 0;
    do {
      exitg2 = 0;
      if (k < 2) {
        maxit = resvec->type->size[k];
        if (maxit != (k << 1) + 1) {
          exitg2 = 1;
        } else {
          k++;
        }
      } else {
        b_p = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (b_p && (!(resvec->type->size[1] == 0))) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (!(resvec->type->data[k] == cv13[k])) {
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
      emxInit_char_T(&b_resvec, 2);
      maxit = b_resvec->size[0] * b_resvec->size[1];
      b_resvec->size[0] = 1;
      b_resvec->size[1] = resvec->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_resvec, maxit, (int)sizeof(char));
      k = resvec->type->size[1];
      for (maxit = 0; maxit < k; maxit++) {
        b_resvec->data[b_resvec->size[0] * maxit] = resvec->type->data
          [resvec->type->size[0] * maxit];
      }

      b_resvec->data[b_resvec->size[0] * resvec->type->size[1]] = '\x00';
      d_m2c_error(b_resvec);
      emxFree_char_T(&b_resvec);
    }

    maxit = data->size[0];
    data->size[0] = resvec->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, maxit, (int)sizeof(unsigned char));
    k = resvec->data->size[0];
    for (maxit = 0; maxit < k; maxit++) {
      data->data[maxit] = resvec->data->data[maxit];
    }

    t_v = *(Vec*)(&data->data[0]);
    errCode = KSPBuildResidual(t_ksp, NULL, NULL, &t_v);
    emxFree_uint8_T(&data);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        o_m2c_error(errCode);
      }
    }
  }
}

void mptKSPSolve_initialize(void)
{
}

void mptKSPSolve_terminate(void)
{
}
