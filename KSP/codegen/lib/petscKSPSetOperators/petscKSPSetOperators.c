#include "petscKSPSetOperators.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Mat.\n";
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i1);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "KSPSetOperators returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected KSP.\n";
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i0);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscKSPSetOperators(const struct0_T *ksp, const struct0_T *Amat, const
  struct0_T *Pmat, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv0[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  int loop_ub;
  KSP t_ksp;
  static const char cv1[3] = { 'M', 'a', 't' };

  Mat t_Amat;
  Mat t_Pmat;
  p = false;
  b_p = false;
  if (ksp->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp->type->data[k] == cv0[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  emxInit_char_T(&b_ksp, 2);
  if (!p) {
    k = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, k);
    loop_ub = ksp->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_ksp->data[b_ksp->size[0] * k] = ksp->type->data[ksp->type->size[0] * k];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = ksp->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = ksp->data->data[k];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  p = false;
  b_p = false;
  if (Amat->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(Amat->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Amat->type->data[k] == cv1[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    k = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = Amat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, k);
    loop_ub = Amat->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_ksp->data[b_ksp->size[0] * k] = Amat->type->data[Amat->type->size[0] * k];
    }

    b_ksp->data[b_ksp->size[0] * Amat->type->size[1]] = '\x00';
    b_m2c_error(b_ksp);
  }

  k = data->size[0];
  data->size[0] = Amat->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = Amat->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = Amat->data->data[k];
  }

  t_Amat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  if (Pmat->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(Pmat->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Pmat->type->data[k] == cv1[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    k = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = Pmat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, k);
    loop_ub = Pmat->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_ksp->data[b_ksp->size[0] * k] = Pmat->type->data[Pmat->type->size[0] * k];
    }

    b_ksp->data[b_ksp->size[0] * Pmat->type->size[1]] = '\x00';
    b_m2c_error(b_ksp);
  }

  emxFree_char_T(&b_ksp);
  k = data->size[0];
  data->size[0] = Pmat->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = Pmat->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = Pmat->data->data[k];
  }

  t_Pmat = *(Mat*)(&data->data[0]);
  *errCode = KSPSetOperators(t_ksp, t_Amat, t_Pmat);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscKSPSetOperators_AforP(const struct0_T *ksp, const struct0_T *Amat, int
  *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv2[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  int loop_ub;
  KSP t_ksp;
  static const char cv3[3] = { 'M', 'a', 't' };

  Mat t_Amat;
  p = false;
  b_p = false;
  if (ksp->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp->type->data[k] == cv2[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  emxInit_char_T(&b_ksp, 2);
  if (!p) {
    k = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, k);
    loop_ub = ksp->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_ksp->data[b_ksp->size[0] * k] = ksp->type->data[ksp->type->size[0] * k];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = ksp->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = ksp->data->data[k];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  p = false;
  b_p = false;
  if (Amat->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(Amat->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Amat->type->data[k] == cv3[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    k = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = Amat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, k);
    loop_ub = Amat->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_ksp->data[b_ksp->size[0] * k] = Amat->type->data[Amat->type->size[0] * k];
    }

    b_ksp->data[b_ksp->size[0] * Amat->type->size[1]] = '\x00';
    b_m2c_error(b_ksp);
  }

  emxFree_char_T(&b_ksp);
  k = data->size[0];
  data->size[0] = Amat->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = Amat->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = Amat->data->data[k];
  }

  t_Amat = *(Mat*)(&data->data[0]);
  *errCode = KSPSetOperators(t_ksp, t_Amat, t_Amat);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscKSPSetOperators_initialize(void)
{
}

void petscKSPSetOperators_terminate(void)
{
}
