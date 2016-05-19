#include "petscVecNorm.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecNorm returned error code %d\n", varargin_3);
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

  M2C_error("PetscVec:WrongType", "Incorrect data type %s. Expected Vec.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscVecNorm(const struct0_T *x, int type, double nrm[2], int *errCode,
                  boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i2;
  boolean_T exitg1;
  emxArray_char_T *b_x;
  static const char cv1[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  Vec vec;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i2 = x->type->size[k];
      if (i2 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

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

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_x, 2);
    i2 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_x, i2, (int)sizeof(char));
    k = x->type->size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_x->data[b_x->size[0] * i2] = x->type->data[x->type->size[0] * i2];
    }

    b_x->data[b_x->size[0] * x->type->size[1]] = '\x00';
    m2c_error(b_x);
    emxFree_char_T(&b_x);
  }

  emxInit_uint8_T(&data, 1);
  i2 = data->size[0];
  data->size[0] = x->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i2, (int)sizeof(unsigned char));
  k = x->data->size[0];
  for (i2 = 0; i2 < k; i2++) {
    data->data[i2] = x->data->data[i2];
  }

  vec = *(Vec*)(&data->data[0]);
  *errCode = VecNorm(vec, type, nrm);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscVecNorm_2args(const struct0_T *x, int type, double *nrm, int *errCode,
  boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i1;
  boolean_T exitg1;
  emxArray_char_T *b_x;
  static const char cv0[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  Vec vec;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i1 = x->type->size[k];
      if (i1 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(x->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(x->type->data[k] == cv0[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_x, 2);
    i1 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_x, i1, (int)sizeof(char));
    k = x->type->size[1];
    for (i1 = 0; i1 < k; i1++) {
      b_x->data[b_x->size[0] * i1] = x->type->data[x->type->size[0] * i1];
    }

    b_x->data[b_x->size[0] * x->type->size[1]] = '\x00';
    m2c_error(b_x);
    emxFree_char_T(&b_x);
  }

  emxInit_uint8_T(&data, 1);
  i1 = data->size[0];
  data->size[0] = x->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i1, (int)sizeof(unsigned char));
  k = x->data->size[0];
  for (i1 = 0; i1 < k; i1++) {
    data->data[i1] = x->data->data[i1];
  }

  vec = *(Vec*)(&data->data[0]);
  *errCode = VecNorm(vec, type, nrm);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscVecNorm_initialize(void)
{
}

void petscVecNorm_terminate(void)
{
}
