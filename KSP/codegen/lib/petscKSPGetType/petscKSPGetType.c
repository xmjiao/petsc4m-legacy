#include "petscKSPGetType.h"
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
  fmt = "KSPGetType returned error code %d\n";
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

void petscKSPGetType(const struct0_T *ksp, emxArray_char_T *type, int *errCode,
                     boolean_T *toplevel)
{
  KSPType t_type;
  boolean_T p;
  boolean_T b_p;
  int empty;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv0[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  int i0;
  KSP c_ksp;
  const char * str;
  emxArray_uint8_T *str1;
  int n;
  char * ptr;
  p = false;
  b_p = false;
  empty = 0;
  do {
    exitg2 = 0;
    if (empty < 2) {
      if (ksp->type->size[empty] != 1 + (empty << 1)) {
        exitg2 = 1;
      } else {
        empty++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    empty = 0;
    exitg1 = false;
    while ((!exitg1) && (empty < 3)) {
      if (!(ksp->type->data[empty] == cv0[empty])) {
        b_p = false;
        exitg1 = true;
      } else {
        empty++;
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
    empty = ksp->type->size[1];
    for (i0 = 0; i0 < empty; i0++) {
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
  empty = ksp->data->size[0];
  for (i0 = 0; i0 < empty; i0++) {
    data->data[i0] = ksp->data->data[i0];
  }

  c_ksp = *(KSP*)(&data->data[0]);
  *errCode = KSPGetType(c_ksp, &t_type);
  *toplevel = true;
  str = (t_type);
  empty = !(str);
  emxFree_uint8_T(&data);
  emxInit_uint8_T(&str1, 2);
  if (!(empty != 0)) {
    n = strlen(str) + 1;
    i0 = str1->size[0] * str1->size[1];
    str1->size[0] = 1;
    str1->size[1] = n;
    emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < n; i0++) {
      str1->data[i0] = 0;
    }

    ptr = (char *)(str);
    for (empty = 1; empty <= n; empty++) {
      str1->data[empty - 1] = *(ptr);
      ptr = M2C_OFFSET_PTR(ptr, 1);
    }
  } else {
    i0 = str1->size[0] * str1->size[1];
    str1->size[0] = 1;
    str1->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
  }

  i0 = type->size[0] * type->size[1];
  type->size[0] = 1;
  type->size[1] = str1->size[1];
  emxEnsureCapacity((emxArray__common *)type, i0, (int)sizeof(char));
  empty = str1->size[1];
  for (i0 = 0; i0 < empty; i0++) {
    type->data[i0] = (signed char)str1->data[i0];
  }

  emxFree_uint8_T(&str1);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscKSPGetType_initialize(void)
{
}

void petscKSPGetType_terminate(void)
{
}
