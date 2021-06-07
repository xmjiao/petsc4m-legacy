#include "petscKSPGetType.h"
#include "petscKSPGetType_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "KSPGetType returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected KSP.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscKSPGetType(const M2C_OpaqueType *ksp, emxArray_char_T *type,
                     int *errCode, boolean_T *toplevel)
{
  static const char cv[3] = {'K', 'S', 'P'};
  KSP c_ksp;
  KSPType str_in;
  const char *str;
  char *ptr;
  emxArray_char_T *b_ksp;
  emxArray_uint8_T *str1;
  int empty;
  int i;
  int n;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (ksp->type->size[1] == 3) {
    p = true;
  }
  if (p && (ksp->type->size[1] != 0)) {
    empty = 0;
    exitg1 = false;
    while ((!exitg1) && (empty < 3)) {
      if (!(ksp->type->data[empty] == cv[empty])) {
        p = false;
        exitg1 = true;
      } else {
        empty++;
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
    empty = ksp->type->size[1];
    for (i = 0; i < empty; i++) {
      b_ksp->data[i] = ksp->type->data[i];
    }
    b_ksp->data[ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }
  c_ksp = *(KSP *)(&ksp->data->data[0]);
  *errCode = KSPGetType(c_ksp, &str_in);
  str = (str_in);
  empty = !(str);
  emxInit_uint8_T(&str1, 2);
  if (empty == 0) {
    n = strlen(str);
    i = str1->size[0] * str1->size[1];
    str1->size[0] = 1;
    str1->size[1] = n + 1;
    emxEnsureCapacity_uint8_T(str1, i);
    empty = n + 1;
    for (i = 0; i < empty; i++) {
      str1->data[i] = 0U;
    }
    ptr = (char *)(str);
    for (empty = 0; empty <= n; empty++) {
      str1->data[empty] = *(ptr);
      ptr = ptr + 1;
    }
  } else {
    str1->size[0] = 1;
    str1->size[1] = 0;
  }
  i = type->size[0] * type->size[1];
  type->size[0] = 1;
  type->size[1] = str1->size[1];
  emxEnsureCapacity_char_T(type, i);
  empty = str1->size[1];
  for (i = 0; i < empty; i++) {
    type->data[i] = (signed char)str1->data[i];
  }
  emxFree_uint8_T(&str1);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
  *toplevel = true;
}

void petscKSPGetType_initialize(void)
{
}

void petscKSPGetType_terminate(void)
{
}
