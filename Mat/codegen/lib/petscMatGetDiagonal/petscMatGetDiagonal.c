#include "petscMatGetDiagonal.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Vec.\n";
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i1);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatGetDiagonal returned error code %d\n";
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
  emxEnsureCapacity_char_T(b_varargin_3, i0);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscMatGetDiagonal(const struct0_T *A, const struct0_T *v, int *errCode,
  boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_A;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  int loop_ub;
  Mat mat;
  static const char cv1[3] = { 'V', 'e', 'c' };

  Vec vec;
  p = false;
  b_p = false;
  if (A->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(A->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(A->type->data[k] == cv0[k])) {
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

  emxInit_char_T(&b_A, 2);
  if (!p) {
    k = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = A->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, k);
    loop_ub = A->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_A->data[b_A->size[0] * k] = A->type->data[A->type->size[0] * k];
    }

    b_A->data[b_A->size[0] * A->type->size[1]] = '\x00';
    m2c_error(b_A);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = A->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = A->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = A->data->data[k];
  }

  mat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  if (v->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(v->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(v->type->data[k] == cv1[k])) {
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
    k = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = v->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, k);
    loop_ub = v->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_A->data[b_A->size[0] * k] = v->type->data[v->type->size[0] * k];
    }

    b_A->data[b_A->size[0] * v->type->size[1]] = '\x00';
    b_m2c_error(b_A);
  }

  emxFree_char_T(&b_A);
  k = data->size[0];
  data->size[0] = v->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = v->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = v->data->data[k];
  }

  vec = *(Vec*)(&data->data[0]);
  *errCode = MatGetDiagonal(mat, vec);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscMatGetDiagonal_initialize(void)
{
}

void petscMatGetDiagonal_terminate(void)
{
}
