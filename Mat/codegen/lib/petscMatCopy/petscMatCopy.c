#include "petscMatCopy.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatCopy returned error code %d\n";
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
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Mat.\n";
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
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
  boolean_T exitg3;
  emxArray_char_T *b_A;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  int loop_ub;
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
      if (A->type->size[k] != 1 + (k << 1)) {
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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_A, 2);
    k = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = A->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_A, k, (int)sizeof(char));
    loop_ub = A->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_A->data[b_A->size[0] * k] = A->type->data[A->type->size[0] * k];
    }

    b_A->data[b_A->size[0] * A->type->size[1]] = '\x00';
    m2c_error(b_A);
    emxFree_char_T(&b_A);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = A->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = A->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = A->data->data[k];
  }

  mat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      if (B->type->size[k] != 1 + (k << 1)) {
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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_B, 2);
    k = b_B->size[0] * b_B->size[1];
    b_B->size[0] = 1;
    b_B->size[1] = B->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_B, k, (int)sizeof(char));
    loop_ub = B->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_B->data[b_B->size[0] * k] = B->type->data[B->type->size[0] * k];
    }

    b_B->data[b_B->size[0] * B->type->size[1]] = '\x00';
    m2c_error(b_B);
    emxFree_char_T(&b_B);
  }

  k = data->size[0];
  data->size[0] = B->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = B->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = B->data->data[k];
  }

  b_mat = *(Mat*)(&data->data[0]);
  *errCode = MatCopy(mat, b_mat, mstr);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
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
  boolean_T exitg3;
  emxArray_char_T *b_A;
  static const char cv1[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  int loop_ub;
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
      if (A->type->size[k] != 1 + (k << 1)) {
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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_A, 2);
    k = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = A->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_A, k, (int)sizeof(char));
    loop_ub = A->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_A->data[b_A->size[0] * k] = A->type->data[A->type->size[0] * k];
    }

    b_A->data[b_A->size[0] * A->type->size[1]] = '\x00';
    m2c_error(b_A);
    emxFree_char_T(&b_A);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = A->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = A->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = A->data->data[k];
  }

  mat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      if (B->type->size[k] != 1 + (k << 1)) {
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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_B, 2);
    k = b_B->size[0] * b_B->size[1];
    b_B->size[0] = 1;
    b_B->size[1] = B->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_B, k, (int)sizeof(char));
    loop_ub = B->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_B->data[b_B->size[0] * k] = B->type->data[B->type->size[0] * k];
    }

    b_B->data[b_B->size[0] * B->type->size[1]] = '\x00';
    m2c_error(b_B);
    emxFree_char_T(&b_B);
  }

  k = data->size[0];
  data->size[0] = B->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = B->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = B->data->data[k];
  }

  b_mat = *(Mat*)(&data->data[0]);
  *errCode = MatCopy(mat, b_mat, mstr);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscMatCopy_initialize(void)
{
}

void petscMatCopy_terminate(void)
{
}
