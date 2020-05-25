#include "petscMatAXPY.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static Mat m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatAXPY returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static Mat m2c_castdata(const emxArray_uint8_T *data)
{
  return *(Mat*)(&data->data[0]);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Mat.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscMatAXPY(const struct0_T *Y, double a, const struct0_T *X, int mstr,
                  int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_Y;
  int i;
  static const char cv[3] = { 'M', 'a', 't' };

  Mat mat;
  Mat b_mat;
  p = (Y->type->size[1] == 3);
  if (p && (Y->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Y->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_Y, 2);
  if (!b_p) {
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = Y->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    k = Y->type->size[1];
    for (i = 0; i < k; i++) {
      b_Y->data[i] = Y->type->data[i];
    }

    b_Y->data[Y->type->size[1]] = '\x00';
    m2c_error(b_Y);
  }

  mat = m2c_castdata(Y->data);
  p = (X->type->size[1] == 3);
  if (p && (X->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(X->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = X->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    k = X->type->size[1];
    for (i = 0; i < k; i++) {
      b_Y->data[i] = X->type->data[i];
    }

    b_Y->data[X->type->size[1]] = '\x00';
    m2c_error(b_Y);
  }

  emxFree_char_T(&b_Y);
  b_mat = m2c_castdata(X->data);
  *errCode = MatAXPY(mat, a, b_mat, mstr);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscMatAXPY_3args(const struct0_T *Y, double a, const struct0_T *X, int
  *errCode, boolean_T *toplevel)
{
  int mstr;
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_Y;
  int i;
  static const char cv[3] = { 'M', 'a', 't' };

  Mat mat;
  Mat b_mat;
  mstr = (SAME_NONZERO_PATTERN);
  p = (Y->type->size[1] == 3);
  if (p && (Y->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Y->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_Y, 2);
  if (!b_p) {
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = Y->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    k = Y->type->size[1];
    for (i = 0; i < k; i++) {
      b_Y->data[i] = Y->type->data[i];
    }

    b_Y->data[Y->type->size[1]] = '\x00';
    m2c_error(b_Y);
  }

  mat = m2c_castdata(Y->data);
  p = (X->type->size[1] == 3);
  if (p && (X->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(X->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = X->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    k = X->type->size[1];
    for (i = 0; i < k; i++) {
      b_Y->data[i] = X->type->data[i];
    }

    b_Y->data[X->type->size[1]] = '\x00';
    m2c_error(b_Y);
  }

  emxFree_char_T(&b_Y);
  b_mat = m2c_castdata(X->data);
  *errCode = MatAXPY(mat, a, b_mat, mstr);
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
