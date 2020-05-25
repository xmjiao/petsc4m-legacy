#include "petscKSPGetPC.h"
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
  fmt = "KSPGetPC returned error code %d\n";
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

void petscKSPGetPC(const struct0_T *ksp, struct0_T *pc, int *errCode, boolean_T *
                   toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  emxArray_uint8_T *data0;
  int i;
  static const char cv[3] = { 'K', 'S', 'P' };

  KSP c_ksp;
  PC arg;
  char * ptr;
  p = (ksp->type->size[1] == 3);
  if (p && (ksp->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 3)) {
      if (!(ksp->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
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
    sizepe = ksp->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_ksp->data[i] = ksp->type->data[i];
    }

    b_ksp->data[ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data0, 1);
  c_ksp = m2c_castdata(ksp->data);
  *errCode = KSPGetPC(c_ksp, &arg);
  sizepe = sizeof(PC);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = pc->data->size[0];
  pc->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(pc->data, i);
  for (i = 0; i < sizepe; i++) {
    pc->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = pc->type->size[0] * pc->type->size[1];
  pc->type->size[0] = 1;
  pc->type->size[1] = 2;
  emxEnsureCapacity_char_T(pc->type, i);
  pc->type->data[0] = 'P';
  pc->type->data[1] = 'C';
  pc->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    pc->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscKSPGetPC_initialize(void)
{
}

void petscKSPGetPC_terminate(void)
{
}
