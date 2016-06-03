#include "mptKSPCleanup.h"
#include "m2c.h"
#include "mpetsc.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPDestroy returned error code %d\n",
            varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected KSP.\n", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

boolean_T mptKSPCleanup(struct0_T *ksp)
{
  boolean_T toplevel;
  boolean_T p;
  boolean_T b_p;
  int errCode;
  int exitg2;
  int i1;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv0[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data0;
  KSP t_ksp;
  int sizepe;
  char t0_type[3];
  static const char x2[3] = { 'K', 'S', 'P' };

  char * ptr;
  p = false;
  b_p = false;
  errCode = 0;
  do {
    exitg2 = 0;
    if (errCode < 2) {
      i1 = ksp->type->size[errCode];
      if (i1 != (errCode << 1) + 1) {
        exitg2 = 1;
      } else {
        errCode++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    errCode = 0;
    exitg1 = false;
    while ((!exitg1) && (errCode < 3)) {
      if (!(ksp->type->data[errCode] == cv0[errCode])) {
        b_p = false;
        exitg1 = true;
      } else {
        errCode++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_ksp, 2);
    i1 = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, i1, (int)sizeof(char));
    errCode = ksp->type->size[1];
    for (i1 = 0; i1 < errCode; i1++) {
      b_ksp->data[b_ksp->size[0] * i1] = ksp->type->data[ksp->type->size[0] * i1];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data0, 1);
  i1 = data0->size[0];
  data0->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i1, (int)sizeof(unsigned char));
  errCode = ksp->data->size[0];
  for (i1 = 0; i1 < errCode; i1++) {
    data0->data[i1] = ksp->data->data[i1];
  }

  t_ksp = *(KSP*)(&data0->data[0]);
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      b_m2c_error(errCode);
    }
  }

  toplevel = true;
  sizepe = sizeof(KSP);
  i1 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i1, (int)sizeof(unsigned char));
  for (i1 = 0; i1 < 3; i1++) {
    t0_type[i1] = x2[i1];
  }

  i1 = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, i1, (int)sizeof(unsigned char));
  errCode = data0->size[0];
  for (i1 = 0; i1 < errCode; i1++) {
    ksp->data->data[i1] = data0->data[i1];
  }

  emxFree_uint8_T(&data0);
  i1 = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, i1, (int)sizeof(char));
  for (i1 = 0; i1 < 3; i1++) {
    ksp->type->data[i1] = t0_type[i1];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (errCode = 1; errCode <= sizepe; errCode++) {
    ksp->data->data[errCode - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  return toplevel;
}

void mptKSPCleanup_initialize(void)
{
}

void mptKSPCleanup_terminate(void)
{
}
