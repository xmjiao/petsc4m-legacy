#include "petscMatAXPY.h"
#include "petscksp.h"
#include "petscsys.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatAXPY returned error code %d\n", varargin_3);
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
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("PetscMat:WrongType", "Incorrect data type %s. Expected Mat.",
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

void petscMatAXPY(const struct0_T *Y, double a, const struct0_T *X, int mstr,
                  int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg4;
  int i0;
  boolean_T exitg3;
  emxArray_char_T *b_Y;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  Mat mat;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_X;
  Mat b_mat;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i0 = Y->type->size[k];
      if (i0 != (k << 1) + 1) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(Y->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(Y->type->data[k] == cv0[k])) {
        b_p = false;
        exitg3 = true;
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
    emxInit_char_T(&b_Y, 2);
    i0 = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = Y->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_Y, i0, (int)sizeof(char));
    k = Y->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_Y->data[b_Y->size[0] * i0] = Y->type->data[Y->type->size[0] * i0];
    }

    b_Y->data[b_Y->size[0] * Y->type->size[1]] = '\x00';
    m2c_error(b_Y);
    emxFree_char_T(&b_Y);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = Y->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = Y->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = Y->data->data[i0];
  }

  mat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = X->type->size[k];
      if (i0 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(X->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(X->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_X, 2);
    i0 = b_X->size[0] * b_X->size[1];
    b_X->size[0] = 1;
    b_X->size[1] = X->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_X, i0, (int)sizeof(char));
    k = X->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_X->data[b_X->size[0] * i0] = X->type->data[X->type->size[0] * i0];
    }

    b_X->data[b_X->size[0] * X->type->size[1]] = '\x00';
    m2c_error(b_X);
    emxFree_char_T(&b_X);
  }

  i0 = data->size[0];
  data->size[0] = X->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = X->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = X->data->data[i0];
  }

  b_mat = *(Mat*)(&data->data[0]);
  *errCode = MatAXPY(mat, a, b_mat, mstr);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscMatAXPY_3args(const struct0_T *Y, double a, const struct0_T *X, int
  *errCode, boolean_T *toplevel)
{
  int mstr;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg4;
  int i2;
  boolean_T exitg3;
  emxArray_char_T *b_Y;
  static const char cv1[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  Mat mat;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_X;
  Mat b_mat;
  mstr = (SAME_NONZERO_PATTERN);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i2 = Y->type->size[k];
      if (i2 != (k << 1) + 1) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(Y->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(Y->type->data[k] == cv1[k])) {
        b_p = false;
        exitg3 = true;
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
    emxInit_char_T(&b_Y, 2);
    i2 = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = Y->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_Y, i2, (int)sizeof(char));
    k = Y->type->size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_Y->data[b_Y->size[0] * i2] = Y->type->data[Y->type->size[0] * i2];
    }

    b_Y->data[b_Y->size[0] * Y->type->size[1]] = '\x00';
    m2c_error(b_Y);
    emxFree_char_T(&b_Y);
  }

  emxInit_uint8_T(&data, 1);
  i2 = data->size[0];
  data->size[0] = Y->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i2, (int)sizeof(unsigned char));
  k = Y->data->size[0];
  for (i2 = 0; i2 < k; i2++) {
    data->data[i2] = Y->data->data[i2];
  }

  mat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i2 = X->type->size[k];
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

  if (b_p && (!(X->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(X->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_X, 2);
    i2 = b_X->size[0] * b_X->size[1];
    b_X->size[0] = 1;
    b_X->size[1] = X->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_X, i2, (int)sizeof(char));
    k = X->type->size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_X->data[b_X->size[0] * i2] = X->type->data[X->type->size[0] * i2];
    }

    b_X->data[b_X->size[0] * X->type->size[1]] = '\x00';
    m2c_error(b_X);
    emxFree_char_T(&b_X);
  }

  i2 = data->size[0];
  data->size[0] = X->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i2, (int)sizeof(unsigned char));
  k = X->data->size[0];
  for (i2 = 0; i2 < k; i2++) {
    data->data[i2] = X->data->data[i2];
  }

  b_mat = *(Mat*)(&data->data[0]);
  *errCode = MatAXPY(mat, a, b_mat, mstr);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscMatAXPY_initialize(void)
{
}

void petscMatAXPY_terminate(void)
{
}
