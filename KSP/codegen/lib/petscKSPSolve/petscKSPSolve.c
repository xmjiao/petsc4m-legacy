#include "petscKSPSolve.h"
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
  fmt = "Incorrect data type %s. Expected Vec.\n";
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
  fmt = "KSPSolve returned error code %d\n";
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

void petscKSPSolve(const struct0_T *ksp, const struct0_T *b, const struct0_T *x,
                   int *errCode, boolean_T *toplevel)
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
  static const char cv1[3] = { 'V', 'e', 'c' };

  Vec t_b;
  Vec t_x;
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
  if (b->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(b->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(b->type->data[k] == cv1[k])) {
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
    b_ksp->size[1] = b->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, k);
    loop_ub = b->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_ksp->data[b_ksp->size[0] * k] = b->type->data[b->type->size[0] * k];
    }

    b_ksp->data[b_ksp->size[0] * b->type->size[1]] = '\x00';
    b_m2c_error(b_ksp);
  }

  k = data->size[0];
  data->size[0] = b->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = b->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = b->data->data[k];
  }

  t_b = *(Vec*)(&data->data[0]);
  p = false;
  b_p = false;
  if (x->type->size[1] == 3) {
    b_p = true;
  }

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

  if (b_p) {
    p = true;
  }

  if (!p) {
    k = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = x->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, k);
    loop_ub = x->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_ksp->data[b_ksp->size[0] * k] = x->type->data[x->type->size[0] * k];
    }

    b_ksp->data[b_ksp->size[0] * x->type->size[1]] = '\x00';
    b_m2c_error(b_ksp);
  }

  emxFree_char_T(&b_ksp);
  k = data->size[0];
  data->size[0] = x->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = x->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = x->data->data[k];
  }

  t_x = *(Vec*)(&data->data[0]);
  *errCode = KSPSolve(t_ksp, t_b, t_x);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscKSPSolve_2args(const struct0_T *ksp, const struct0_T *b, int *errCode,
  boolean_T *toplevel)
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
  static const char cv3[3] = { 'V', 'e', 'c' };

  Vec t_b;
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
  if (b->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(b->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(b->type->data[k] == cv3[k])) {
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
    b_ksp->size[1] = b->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, k);
    loop_ub = b->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_ksp->data[b_ksp->size[0] * k] = b->type->data[b->type->size[0] * k];
    }

    b_ksp->data[b_ksp->size[0] * b->type->size[1]] = '\x00';
    b_m2c_error(b_ksp);
  }

  emxFree_char_T(&b_ksp);
  k = data->size[0];
  data->size[0] = b->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = b->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = b->data->data[k];
  }

  t_b = *(Vec*)(&data->data[0]);
  *errCode = KSPSolve(t_ksp, t_b, t_b);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscKSPSolve_initialize(void)
{
}

void petscKSPSolve_terminate(void)
{
}
