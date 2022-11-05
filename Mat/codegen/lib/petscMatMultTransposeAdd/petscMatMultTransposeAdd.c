#include "petscMatMultTransposeAdd.h"
#include "petscMatMultTransposeAdd_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(const emxArray_char_T *varargin_3)
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
  fmt = "Incorrect data type %s. Expected Vec.\n";
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

static void c_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "MatMultTransposeAdd returned error code %d\n";
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

void petscMatMultTransposeAdd(const M2C_OpaqueType *A, const M2C_OpaqueType *v1,
                              const M2C_OpaqueType *v2,
                              const M2C_OpaqueType *v3, int *errCode,
                              boolean_T *toplevel)
{
  static const char cv[3] = {'M', 'a', 't'};
  static const char cv1[3] = {'V', 'e', 'c'};
  static const char cv2[3] = {'V', 'e', 'c'};
  static const char cv3[3] = {'V', 'e', 'c'};
  Mat mat;
  Vec b_vec;
  Vec c_vec;
  Vec vec;
  emxArray_char_T *b_A;
  int i;
  int k;
  const char *varargin_1_data;
  char *A_data;
  boolean_T exitg1;
  boolean_T p;
  p = (A->type->size[1] == 3);
  if (p && (A->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (A->type->data[k] != cv[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  emxInit_char_T(&b_A, 2);
  if (!p) {
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = A->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    A_data = b_A->data;
    k = A->type->size[1];
    for (i = 0; i < k; i++) {
      A_data[i] = A->type->data[i];
    }
    A_data[A->type->size[1]] = '\x00';
    m2c_error(b_A);
  }
  mat = *(Mat *)(&A->data->data[0]);
  varargin_1_data = v1->type->data;
  p = (v1->type->size[1] == 3);
  if (p && (v1->type->size[1] != 0)) {
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
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = v1->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    A_data = b_A->data;
    k = v1->type->size[1];
    for (i = 0; i < k; i++) {
      A_data[i] = v1->type->data[i];
    }
    A_data[v1->type->size[1]] = '\x00';
    b_m2c_error(b_A);
  }
  vec = *(Vec *)(&v1->data->data[0]);
  varargin_1_data = v2->type->data;
  p = (v2->type->size[1] == 3);
  if (p && (v2->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (varargin_1_data[k] != cv2[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (!p) {
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = v2->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    A_data = b_A->data;
    k = v2->type->size[1];
    for (i = 0; i < k; i++) {
      A_data[i] = v2->type->data[i];
    }
    A_data[v2->type->size[1]] = '\x00';
    b_m2c_error(b_A);
  }
  b_vec = *(Vec *)(&v2->data->data[0]);
  varargin_1_data = v3->type->data;
  p = (v3->type->size[1] == 3);
  if (p && (v3->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (varargin_1_data[k] != cv3[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (!p) {
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = v3->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_A, i);
    A_data = b_A->data;
    k = v3->type->size[1];
    for (i = 0; i < k; i++) {
      A_data[i] = v3->type->data[i];
    }
    A_data[v3->type->size[1]] = '\x00';
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
