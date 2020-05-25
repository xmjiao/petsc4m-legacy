#include "petscMatMultHermitianTransposeAdd.h"
#include "m2c.h"
#include "petsc4m.h"

static Vec b_m2c_castdata(const emxArray_uint8_T *data);
static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static Mat m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static Vec b_m2c_castdata(const emxArray_uint8_T *data)
{
  return *(Vec*)(&data->data[0]);
}

static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Vec.\n";
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

static void c_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatMultHermitianTransposeAdd returned error code %d\n";
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

void petscMatMultHermitianTransposeAdd(const struct0_T *A, const struct0_T *v1,
  const struct0_T *v2, const struct0_T *v3, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_A;
  int i;
  static const char cv[3] = { 'M', 'a', 't' };

  Mat mat;
  Vec vec;
  static const char cv1[3] = { 'V', 'e', 'c' };

  Vec b_vec;
  Vec c_vec;
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
  p = (v1->type->size[1] == 3);
  if (p && (v1->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(v1->type->data[k] == cv1[k])) {
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
    b_A->size[1] = v1->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    k = v1->type->size[1];
    for (i = 0; i < k; i++) {
      b_A->data[i] = v1->type->data[i];
    }

    b_A->data[v1->type->size[1]] = '\x00';
    b_m2c_error(b_A);
  }

  vec = b_m2c_castdata(v1->data);
  p = (v2->type->size[1] == 3);
  if (p && (v2->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(v2->type->data[k] == cv1[k])) {
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
    b_A->size[1] = v2->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    k = v2->type->size[1];
    for (i = 0; i < k; i++) {
      b_A->data[i] = v2->type->data[i];
    }

    b_A->data[v2->type->size[1]] = '\x00';
    b_m2c_error(b_A);
  }

  b_vec = b_m2c_castdata(v2->data);
  p = (v3->type->size[1] == 3);
  if (p && (v3->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(v3->type->data[k] == cv1[k])) {
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
    b_A->size[1] = v3->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    k = v3->type->size[1];
    for (i = 0; i < k; i++) {
      b_A->data[i] = v3->type->data[i];
    }

    b_A->data[v3->type->size[1]] = '\x00';
    b_m2c_error(b_A);
  }

  emxFree_char_T(&b_A);
  c_vec = b_m2c_castdata(v3->data);
  *errCode = MatMultHermitianTransposeAdd(mat, vec, b_vec, c_vec);
  *toplevel = true;
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscMatMultHermitianTransposeAdd_initialize(void)
{
}

void petscMatMultHermitianTransposeAdd_terminate(void)
{
}
