#include "petscMatCopy.h"
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
  fmt = "MatCopy returned error code %d\n";
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

void petscMatCopy(const struct0_T *A, const struct0_T *B, int mstr, int *errCode,
                  boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_A;
  int i;
  static const char cv[3] = { 'M', 'a', 't' };

  Mat mat;
  Mat b_mat;
  p = (A->type->size[1] == 3);
  if (p && (A->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(A->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_A, 2);
  if (!b_p) {
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = A->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    k = A->type->size[1];
    for (i = 0; i < k; i++) {
      b_A->data[i] = A->type->data[i];
    }

    b_A->data[A->type->size[1]] = '\x00';
    m2c_error(b_A);
  }

  mat = m2c_castdata(A->data);
  p = (B->type->size[1] == 3);
  if (p && (B->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(B->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = B->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    k = B->type->size[1];
    for (i = 0; i < k; i++) {
      b_A->data[i] = B->type->data[i];
    }

    b_A->data[B->type->size[1]] = '\x00';
    m2c_error(b_A);
  }

  emxFree_char_T(&b_A);
  b_mat = m2c_castdata(B->data);
  *errCode = MatCopy(mat, b_mat, mstr);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscMatCopy_2args(const struct0_T *A, const struct0_T *B, int *errCode,
  boolean_T *toplevel)
{
  int mstr;
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_A;
  int i;
  static const char cv[3] = { 'M', 'a', 't' };

  Mat mat;
  Mat b_mat;
  mstr = (SAME_NONZERO_PATTERN);
  p = (A->type->size[1] == 3);
  if (p && (A->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(A->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_A, 2);
  if (!b_p) {
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = A->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    k = A->type->size[1];
    for (i = 0; i < k; i++) {
      b_A->data[i] = A->type->data[i];
    }

    b_A->data[A->type->size[1]] = '\x00';
    m2c_error(b_A);
  }

  mat = m2c_castdata(A->data);
  p = (B->type->size[1] == 3);
  if (p && (B->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(B->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = B->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    k = B->type->size[1];
    for (i = 0; i < k; i++) {
      b_A->data[i] = B->type->data[i];
    }

    b_A->data[B->type->size[1]] = '\x00';
    m2c_error(b_A);
  }

  emxFree_char_T(&b_A);
  b_mat = m2c_castdata(B->data);
  *errCode = MatCopy(mat, b_mat, mstr);
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
