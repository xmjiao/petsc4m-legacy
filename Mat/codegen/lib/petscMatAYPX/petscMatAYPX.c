#include "petscMatAYPX.h"
#include "petscMatAYPX_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static boolean_T isequal(const emxArray_char_T *varargin_1);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "MatAYPX returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[3] = {'M', 'a', 't'};
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }
  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return b_p || p;
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Mat.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscMatAYPX(const M2C_OpaqueType *Y, float a, const M2C_OpaqueType *X,
                  int mstr, int *errCode, boolean_T *toplevel)
{
  Mat b_mat;
  Mat mat;
  emxArray_char_T *b_Y;
  int i;
  int loop_ub;
  emxInit_char_T(&b_Y, 2);
  if (!isequal(Y->type)) {
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = Y->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    loop_ub = Y->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_Y->data[i] = Y->type->data[i];
    }
    b_Y->data[Y->type->size[1]] = '\x00';
    m2c_error(b_Y);
  }
  mat = *(Mat *)(&Y->data->data[0]);
  if (!isequal(X->type)) {
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = X->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    loop_ub = X->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_Y->data[i] = X->type->data[i];
    }
    b_Y->data[X->type->size[1]] = '\x00';
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

void petscMatAYPX_3args(const M2C_OpaqueType *Y, float a,
                        const M2C_OpaqueType *X, int *errCode,
                        boolean_T *toplevel)
{
  Mat b_mat;
  Mat mat;
  emxArray_char_T *b_Y;
  int i;
  int loop_ub;
  int mstr;
  mstr = (SAME_NONZERO_PATTERN);
  emxInit_char_T(&b_Y, 2);
  if (!isequal(Y->type)) {
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = Y->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    loop_ub = Y->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_Y->data[i] = Y->type->data[i];
    }
    b_Y->data[Y->type->size[1]] = '\x00';
    m2c_error(b_Y);
  }
  mat = *(Mat *)(&Y->data->data[0]);
  if (!isequal(X->type)) {
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = X->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    loop_ub = X->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_Y->data[i] = X->type->data[i];
    }
    b_Y->data[X->type->size[1]] = '\x00';
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
