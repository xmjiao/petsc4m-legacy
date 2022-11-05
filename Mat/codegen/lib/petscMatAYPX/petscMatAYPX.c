#include "petscMatAYPX.h"
#include "petscMatAYPX_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "MatAYPX returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  const char *varargin_3_data;
  char *b_varargin_3_data;
  varargin_3_data = varargin_3->data;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Mat.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  b_varargin_3_data = b_varargin_3->data;
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3_data[i] = varargin_3_data[i];
  }
  M2C_error(msgid, fmt, &b_varargin_3_data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscMatAYPX(const M2C_OpaqueType *Y, double a, const M2C_OpaqueType *X,
                  int mstr, int *errCode, boolean_T *toplevel)
{
  static const char cv[3] = {'M', 'a', 't'};
  static const char cv1[3] = {'M', 'a', 't'};
  Mat b_mat;
  Mat mat;
  emxArray_char_T *b_Y;
  int i;
  int k;
  const char *varargin_1_data;
  char *Y_data;
  boolean_T exitg1;
  boolean_T p;
  emxInit_char_T(&b_Y, 2);
  varargin_1_data = Y->type->data;
  p = (Y->type->size[1] == 3);
  if (p && (Y->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (varargin_1_data[k] != cv[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (!p) {
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = Y->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    Y_data = b_Y->data;
    k = Y->type->size[1];
    for (i = 0; i < k; i++) {
      Y_data[i] = Y->type->data[i];
    }
    Y_data[Y->type->size[1]] = '\x00';
    m2c_error(b_Y);
  }
  mat = *(Mat *)(&Y->data->data[0]);
  varargin_1_data = X->type->data;
  p = (X->type->size[1] == 3);
  if (p && (X->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (varargin_1_data[k] != cv1[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (!p) {
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = X->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    Y_data = b_Y->data;
    k = X->type->size[1];
    for (i = 0; i < k; i++) {
      Y_data[i] = X->type->data[i];
    }
    Y_data[X->type->size[1]] = '\x00';
    m2c_error(b_Y);
  }
  emxFree_char_T(&b_Y);
  b_mat = *(Mat *)(&X->data->data[0]);
  *errCode = MatAYPX(mat, a, b_mat, mstr);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscMatAYPX_3args(const M2C_OpaqueType *Y, double a,
                        const M2C_OpaqueType *X, int *errCode,
                        boolean_T *toplevel)
{
  static const char cv[3] = {'M', 'a', 't'};
  static const char cv1[3] = {'M', 'a', 't'};
  Mat b_mat;
  Mat mat;
  emxArray_char_T *b_Y;
  int i;
  int k;
  int mstr;
  const char *varargin_1_data;
  char *Y_data;
  boolean_T exitg1;
  boolean_T p;
  mstr = (SAME_NONZERO_PATTERN);
  emxInit_char_T(&b_Y, 2);
  varargin_1_data = Y->type->data;
  p = (Y->type->size[1] == 3);
  if (p && (Y->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (varargin_1_data[k] != cv[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (!p) {
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = Y->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    Y_data = b_Y->data;
    k = Y->type->size[1];
    for (i = 0; i < k; i++) {
      Y_data[i] = Y->type->data[i];
    }
    Y_data[Y->type->size[1]] = '\x00';
    m2c_error(b_Y);
  }
  mat = *(Mat *)(&Y->data->data[0]);
  varargin_1_data = X->type->data;
  p = (X->type->size[1] == 3);
  if (p && (X->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (varargin_1_data[k] != cv1[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (!p) {
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = X->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    Y_data = b_Y->data;
    k = X->type->size[1];
    for (i = 0; i < k; i++) {
      Y_data[i] = X->type->data[i];
    }
    Y_data[X->type->size[1]] = '\x00';
    m2c_error(b_Y);
  }
  emxFree_char_T(&b_Y);
  b_mat = *(Mat *)(&X->data->data[0]);
  *errCode = MatAYPX(mat, a, b_mat, mstr);
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
