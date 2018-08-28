#include "petscKSPGetResidualHistory.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "KSPGetResidualHistory returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected KSP.\n";
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

void petscKSPGetResidualHistory(const struct0_T *ksp, emxArray_real_T *reshis,
  int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int na;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv0[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  int i0;
  KSP t_ksp;
  PetscReal * a;
  p = false;
  b_p = false;
  if (ksp->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(ksp->type->size[1] == 0))) {
    na = 0;
    exitg1 = false;
    while ((!exitg1) && (na < 3)) {
      if (!(ksp->type->data[na] == cv0[na])) {
        b_p = false;
        exitg1 = true;
      } else {
        na++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_ksp, 2);
    i0 = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, i0);
    na = ksp->type->size[1];
    for (i0 = 0; i0 < na; i0++) {
      b_ksp->data[b_ksp->size[0] * i0] = ksp->type->data[ksp->type->size[0] * i0];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity_uint8_T(data, i0);
  na = ksp->data->size[0];
  for (i0 = 0; i0 < na; i0++) {
    data->data[i0] = ksp->data->data[i0];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  *errCode = KSPGetResidualHistory(t_ksp, &a, &na);
  i0 = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity_real_T(reshis, i0);
  emxFree_uint8_T(&data);
  for (i0 = 0; i0 < na; i0++) {
    reshis->data[i0] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscKSPGetResidualHistory_initialize(void)
{
}

void petscKSPGetResidualHistory_terminate(void)
{
}
