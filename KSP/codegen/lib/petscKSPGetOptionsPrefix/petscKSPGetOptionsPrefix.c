#include "petscKSPGetOptionsPrefix.h"
#include "m2c.h"
#include "mpetsc.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "KSPGetOptionsPrefix returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscKSPGetOptionsPrefix(const struct0_T *ksp, emxArray_char_T *str, int
  *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int noprefx;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv0[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  int i0;
  KSP t_ksp;
  const char * str0;
  emxArray_uint8_T *str1;
  p = false;
  b_p = false;
  noprefx = 0;
  do {
    exitg2 = 0;
    if (noprefx < 2) {
      if (ksp->type->size[noprefx] != 1 + (noprefx << 1)) {
        exitg2 = 1;
      } else {
        noprefx++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    noprefx = 0;
    exitg1 = false;
    while ((!exitg1) && (noprefx < 3)) {
      if (!(ksp->type->data[noprefx] == cv0[noprefx])) {
        b_p = false;
        exitg1 = true;
      } else {
        noprefx++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_ksp, 2);
    i0 = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, i0, (int)sizeof(char));
    noprefx = ksp->type->size[1];
    for (i0 = 0; i0 < noprefx; i0++) {
      b_ksp->data[b_ksp->size[0] * i0] = ksp->type->data[ksp->type->size[0] * i0];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  noprefx = ksp->data->size[0];
  for (i0 = 0; i0 < noprefx; i0++) {
    data->data[i0] = ksp->data->data[i0];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  *errCode = KSPGetOptionsPrefix(t_ksp, &str0);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  noprefx = !(str0);
  emxInit_uint8_T(&str1, 2);
  if (!(noprefx != 0)) {
    noprefx = strlen(str0) + 1;
    i0 = str1->size[0] * str1->size[1];
    str1->size[0] = 1;
    str1->size[1] = noprefx;
    emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < noprefx; i0++) {
      str1->data[i0] = 0;
    }

    memcpy(&str1->data[0], str0, noprefx);
  } else {
    i0 = str1->size[0] * str1->size[1];
    str1->size[0] = 1;
    str1->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
  }

  i0 = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = str1->size[1];
  emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
  noprefx = str1->size[1];
  for (i0 = 0; i0 < noprefx; i0++) {
    str->data[i0] = (signed char)str1->data[i0];
  }

  emxFree_uint8_T(&str1);
}

void petscKSPGetOptionsPrefix_initialize(void)
{
}

void petscKSPGetOptionsPrefix_terminate(void)
{
}
