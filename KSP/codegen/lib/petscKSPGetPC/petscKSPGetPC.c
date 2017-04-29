#include "petscKSPGetPC.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "KSPGetPC returned error code %d\n";
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscKSPGetPC(const struct0_T *ksp, struct0_T *pc, int *errCode, boolean_T *
                   toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv0[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data0;
  int loop_ub;
  KSP c_ksp;
  PC t_pc;
  int sizepe;
  char t0_type[2];
  static const char cv1[2] = { 'P', 'C' };

  char * ptr;
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

  if (!p) {
    emxInit_char_T(&b_ksp, 2);
    k = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, k, sizeof(char));
    loop_ub = ksp->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_ksp->data[b_ksp->size[0] * k] = ksp->type->data[ksp->type->size[0] * k];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data0, 1);
  k = data0->size[0];
  data0->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, k, sizeof(unsigned char));
  loop_ub = ksp->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data0->data[k] = ksp->data->data[k];
  }

  c_ksp = *(KSP*)(&data0->data[0]);
  *errCode = KSPGetPC(c_ksp, &t_pc);
  sizepe = sizeof(PC);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, k, sizeof(unsigned char));
  for (k = 0; k < 2; k++) {
    t0_type[k] = cv1[k];
  }

  k = pc->data->size[0];
  pc->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)pc->data, k, sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (k = 0; k < loop_ub; k++) {
    pc->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = pc->type->size[0] * pc->type->size[1];
  pc->type->size[0] = 1;
  pc->type->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)pc->type, k, sizeof(char));
  for (k = 0; k < 2; k++) {
    pc->type->data[k] = t0_type[k];
  }

  pc->nitems = 1;
  ptr = (char *)(&t_pc);
  for (k = 1; k <= sizepe; k++) {
    pc->data->data[k - 1] = *(ptr);
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
