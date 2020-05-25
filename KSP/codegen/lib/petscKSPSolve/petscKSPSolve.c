#include "petscKSPSolve.h"
#include "m2c.h"
#include "petsc4m.h"

static Vec b_m2c_castdata(const emxArray_uint8_T *data);
static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static KSP m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static Vec b_m2c_castdata(const emxArray_uint8_T *data)
{
  return *(Vec*)(&data->data[0]);
}

static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Vec.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
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

static KSP m2c_castdata(const emxArray_uint8_T *data)
{
  return *(KSP*)(&data->data[0]);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected KSP.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscKSPSolve(const struct0_T *ksp, const struct0_T *b, const struct0_T *x,
                   int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  int i;
  static const char cv[3] = { 'K', 'S', 'P' };

  KSP t_ksp;
  Vec t_b;
  static const char cv1[3] = { 'V', 'e', 'c' };

  Vec t_x;
  p = (ksp->type->size[1] == 3);
  if (p && (ksp->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_ksp, 2);
  if (!b_p) {
    i = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, i);
    k = ksp->type->size[1];
    for (i = 0; i < k; i++) {
      b_ksp->data[i] = ksp->type->data[i];
    }

    b_ksp->data[ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
  }

  t_ksp = m2c_castdata(ksp->data);
  p = (b->type->size[1] == 3);
  if (p && (b->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(b->type->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = b->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, i);
    k = b->type->size[1];
    for (i = 0; i < k; i++) {
      b_ksp->data[i] = b->type->data[i];
    }

    b_ksp->data[b->type->size[1]] = '\x00';
    b_m2c_error(b_ksp);
  }

  t_b = b_m2c_castdata(b->data);
  p = (x->type->size[1] == 3);
  if (p && (x->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(x->type->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = x->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, i);
    k = x->type->size[1];
    for (i = 0; i < k; i++) {
      b_ksp->data[i] = x->type->data[i];
    }

    b_ksp->data[x->type->size[1]] = '\x00';
    b_m2c_error(b_ksp);
  }

  emxFree_char_T(&b_ksp);
  t_x = b_m2c_castdata(x->data);
  *errCode = KSPSolve(t_ksp, t_b, t_x);
  *toplevel = true;
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscKSPSolve_2args(const struct0_T *ksp, const struct0_T *b, int *errCode,
  boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  int i;
  static const char cv[3] = { 'K', 'S', 'P' };

  KSP t_ksp;
  static const char cv1[3] = { 'V', 'e', 'c' };

  Vec t_b;
  p = (ksp->type->size[1] == 3);
  if (p && (ksp->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_ksp, 2);
  if (!b_p) {
    i = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, i);
    k = ksp->type->size[1];
    for (i = 0; i < k; i++) {
      b_ksp->data[i] = ksp->type->data[i];
    }

    b_ksp->data[ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
  }

  t_ksp = m2c_castdata(ksp->data);
  p = (b->type->size[1] == 3);
  if (p && (b->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(b->type->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = b->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, i);
    k = b->type->size[1];
    for (i = 0; i < k; i++) {
      b_ksp->data[i] = b->type->data[i];
    }

    b_ksp->data[b->type->size[1]] = '\x00';
    b_m2c_error(b_ksp);
  }

  emxFree_char_T(&b_ksp);
  t_b = b_m2c_castdata(b->data);
  *errCode = KSPSolve(t_ksp, t_b, t_b);
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
