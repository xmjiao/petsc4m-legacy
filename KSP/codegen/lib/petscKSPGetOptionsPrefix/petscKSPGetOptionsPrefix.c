#include "petscKSPGetOptionsPrefix.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static KSP m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "KSPGetOptionsPrefix returned error code %d\n";
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

void petscKSPGetOptionsPrefix(const struct0_T *ksp, emxArray_char_T *str, int
  *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int noprefx;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  KSP t_ksp;
  int i;
  static const char cv[3] = { 'K', 'S', 'P' };

  const char * str0;
  emxArray_uint8_T *str1;
  p = (ksp->type->size[1] == 3);
  if (p && (ksp->type->size[1] != 0)) {
    noprefx = 0;
    exitg1 = false;
    while ((!exitg1) && (noprefx < 3)) {
      if (!(ksp->type->data[noprefx] == cv[noprefx])) {
        p = false;
        exitg1 = true;
      } else {
        noprefx++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_ksp, 2);
    i = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, i);
    noprefx = ksp->type->size[1];
    for (i = 0; i < noprefx; i++) {
      b_ksp->data[i] = ksp->type->data[i];
    }

    b_ksp->data[ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  t_ksp = m2c_castdata(ksp->data);
  *errCode = KSPGetOptionsPrefix(t_ksp, &str0);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  noprefx = !(str0);
  emxInit_uint8_T(&str1, 2);
  if (noprefx == 0) {
    noprefx = strlen(str0) + 1;
    i = str1->size[0] * str1->size[1];
    str1->size[0] = 1;
    str1->size[1] = noprefx;
    emxEnsureCapacity_uint8_T(str1, i);
    for (i = 0; i < noprefx; i++) {
      str1->data[i] = 0U;
    }

    memcpy(&str1->data[0], str0, noprefx);
  } else {
    str1->size[0] = 1;
    str1->size[1] = 0;
  }

  i = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = str1->size[1];
  emxEnsureCapacity_char_T(str, i);
  noprefx = str1->size[1];
  for (i = 0; i < noprefx; i++) {
    str->data[i] = (signed char)str1->data[i];
  }

  emxFree_uint8_T(&str1);
  *toplevel = true;
}

void petscKSPGetOptionsPrefix_initialize(void)
{
}

void petscKSPGetOptionsPrefix_terminate(void)
{
}
