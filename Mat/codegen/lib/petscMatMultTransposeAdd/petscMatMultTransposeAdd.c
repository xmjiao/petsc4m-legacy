#include "petscMatMultTransposeAdd.h"
#include "petscMatMultTransposeAdd_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(int varargin_3);

static boolean_T isequal(const emxArray_char_T *varargin_1);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Vec.\n";
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

static void c_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "MatMultTransposeAdd returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[3] = {'V', 'e', 'c'};
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

void petscMatMultTransposeAdd(const M2C_OpaqueType *A, const M2C_OpaqueType *v1,
                              const M2C_OpaqueType *v2,
                              const M2C_OpaqueType *v3, int *errCode,
                              boolean_T *toplevel)
{
  static const char cv[3] = {'M', 'a', 't'};
  Mat mat;
  Vec b_vec;
  Vec c_vec;
  Vec vec;
  emxArray_char_T *b_A;
  int i;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (A->type->size[1] == 3) {
    p = true;
  }
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
  mat = *(Mat *)(&A->data->data[0]);
  if (!isequal(v1->type)) {
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
  vec = *(Vec *)(&v1->data->data[0]);
  if (!isequal(v2->type)) {
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
  b_vec = *(Vec *)(&v2->data->data[0]);
  if (!isequal(v3->type)) {
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
  c_vec = *(Vec *)(&v3->data->data[0]);
  *errCode = MatMultTransposeAdd(mat, vec, b_vec, c_vec);
  *toplevel = true;
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscMatMultTransposeAdd_initialize(void)
{
}

void petscMatMultTransposeAdd_terminate(void)
{
}
