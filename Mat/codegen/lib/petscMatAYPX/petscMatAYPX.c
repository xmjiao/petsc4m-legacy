#include "petscMatAYPX.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatAYPX returned error code %d\n";
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
  fmt = "Incorrect data type %s. Expected Mat.\n";
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

void petscMatAYPX(const struct0_T *Y, double a, const struct0_T *X, int mstr,
                  int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_Y;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  int loop_ub;
  Mat mat;
  emxArray_char_T *b_X;
  Mat b_mat;
  p = false;
  b_p = false;
  if (Y->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(Y->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Y->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_Y, 2);
    k = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = Y->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_Y, k, sizeof(char));
    loop_ub = Y->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_Y->data[b_Y->size[0] * k] = Y->type->data[Y->type->size[0] * k];
    }

    b_Y->data[b_Y->size[0] * Y->type->size[1]] = '\x00';
    m2c_error(b_Y);
    emxFree_char_T(&b_Y);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = Y->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = Y->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = Y->data->data[k];
  }

  mat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  if (X->type->size[1] == 3) {
    b_p = true;
  }

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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_X, 2);
    k = b_X->size[0] * b_X->size[1];
    b_X->size[0] = 1;
    b_X->size[1] = X->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_X, k, sizeof(char));
    loop_ub = X->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_X->data[b_X->size[0] * k] = X->type->data[X->type->size[0] * k];
    }

    b_X->data[b_X->size[0] * X->type->size[1]] = '\x00';
    m2c_error(b_X);
    emxFree_char_T(&b_X);
  }

  k = data->size[0];
  data->size[0] = X->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = X->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = X->data->data[k];
  }

  b_mat = *(Mat*)(&data->data[0]);
  *errCode = MatAYPX(mat, a, b_mat, mstr);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscMatAYPX_3args(const struct0_T *Y, double a, const struct0_T *X, int
  *errCode, boolean_T *toplevel)
{
  int mstr;
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_Y;
  static const char cv1[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  int loop_ub;
  Mat mat;
  emxArray_char_T *b_X;
  Mat b_mat;
  mstr = (SAME_NONZERO_PATTERN);
  p = false;
  b_p = false;
  if (Y->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(Y->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Y->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_Y, 2);
    k = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = Y->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_Y, k, sizeof(char));
    loop_ub = Y->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_Y->data[b_Y->size[0] * k] = Y->type->data[Y->type->size[0] * k];
    }

    b_Y->data[b_Y->size[0] * Y->type->size[1]] = '\x00';
    m2c_error(b_Y);
    emxFree_char_T(&b_Y);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = Y->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = Y->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = Y->data->data[k];
  }

  mat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  if (X->type->size[1] == 3) {
    b_p = true;
  }

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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_X, 2);
    k = b_X->size[0] * b_X->size[1];
    b_X->size[0] = 1;
    b_X->size[1] = X->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_X, k, sizeof(char));
    loop_ub = X->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_X->data[b_X->size[0] * k] = X->type->data[X->type->size[0] * k];
    }

    b_X->data[b_X->size[0] * X->type->size[1]] = '\x00';
    m2c_error(b_X);
    emxFree_char_T(&b_X);
  }

  k = data->size[0];
  data->size[0] = X->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = X->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = X->data->data[k];
  }

  b_mat = *(Mat*)(&data->data[0]);
  *errCode = MatAYPX(mat, a, b_mat, mstr);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscMatAYPX_initialize(void)
{
}

void petscMatAYPX_terminate(void)
{
}
