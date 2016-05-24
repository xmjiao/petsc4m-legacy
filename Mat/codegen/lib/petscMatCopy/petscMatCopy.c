#include "petscMatCopy.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatCopy returned error code %d\n", varargin_3);
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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected Mat.\n", &b_varargin_3->data[0]);
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

void petscMatCopy(const struct0_T *A, const struct0_T *B, int mstr, int *errCode,
                  boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg4;
  int i0;
  boolean_T exitg3;
  emxArray_char_T *b_A;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  Mat mat;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_B;
  Mat b_mat;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i0 = A->type->size[k];
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

  if (b_p && (!(A->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(A->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_A, 2);
    i0 = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = A->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_A, i0, (int)sizeof(char));
    k = A->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_A->data[b_A->size[0] * i0] = A->type->data[A->type->size[0] * i0];
    }

    b_A->data[b_A->size[0] * A->type->size[1]] = '\x00';
    m2c_error(b_A);
    emxFree_char_T(&b_A);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = A->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = A->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = A->data->data[i0];
  }

  mat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = B->type->size[k];
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

  if (b_p && (!(B->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(B->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_B, 2);
    i0 = b_B->size[0] * b_B->size[1];
    b_B->size[0] = 1;
    b_B->size[1] = B->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_B, i0, (int)sizeof(char));
    k = B->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_B->data[b_B->size[0] * i0] = B->type->data[B->type->size[0] * i0];
    }

    b_B->data[b_B->size[0] * B->type->size[1]] = '\x00';
    m2c_error(b_B);
    emxFree_char_T(&b_B);
  }

  i0 = data->size[0];
  data->size[0] = B->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = B->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = B->data->data[i0];
  }

  b_mat = *(Mat*)(&data->data[0]);
  *errCode = MatCopy(mat, b_mat, mstr);
  *toplevel = false;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      b_m2c_error(*errCode);
    }
  }
}

void petscMatCopy_2args(const struct0_T *A, const struct0_T *B, int *errCode,
  boolean_T *toplevel)
{
  int mstr;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg4;
  int i2;
  boolean_T exitg3;
  emxArray_char_T *b_A;
  static const char cv1[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  Mat mat;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_B;
  Mat b_mat;
  mstr = (SAME_NONZERO_PATTERN);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i2 = A->type->size[k];
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

  if (b_p && (!(A->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(A->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_A, 2);
    i2 = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = A->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_A, i2, (int)sizeof(char));
    k = A->type->size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_A->data[b_A->size[0] * i2] = A->type->data[A->type->size[0] * i2];
    }

    b_A->data[b_A->size[0] * A->type->size[1]] = '\x00';
    m2c_error(b_A);
    emxFree_char_T(&b_A);
  }

  emxInit_uint8_T(&data, 1);
  i2 = data->size[0];
  data->size[0] = A->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i2, (int)sizeof(unsigned char));
  k = A->data->size[0];
  for (i2 = 0; i2 < k; i2++) {
    data->data[i2] = A->data->data[i2];
  }

  mat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i2 = B->type->size[k];
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

  if (b_p && (!(B->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(B->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_B, 2);
    i2 = b_B->size[0] * b_B->size[1];
    b_B->size[0] = 1;
    b_B->size[1] = B->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_B, i2, (int)sizeof(char));
    k = B->type->size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_B->data[b_B->size[0] * i2] = B->type->data[B->type->size[0] * i2];
    }

    b_B->data[b_B->size[0] * B->type->size[1]] = '\x00';
    m2c_error(b_B);
    emxFree_char_T(&b_B);
  }

  i2 = data->size[0];
  data->size[0] = B->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i2, (int)sizeof(unsigned char));
  k = B->data->size[0];
  for (i2 = 0; i2 < k; i2++) {
    data->data[i2] = B->data->data[i2];
  }

  b_mat = *(Mat*)(&data->data[0]);
  *errCode = MatCopy(mat, b_mat, mstr);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      b_m2c_error(*errCode);
    }
  }

  *toplevel = false;
}

void petscMatCopy_initialize(void)
{
}

void petscMatCopy_terminate(void)
{
}
