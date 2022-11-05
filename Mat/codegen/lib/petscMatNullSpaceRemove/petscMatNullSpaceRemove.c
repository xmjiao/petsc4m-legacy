#include "petscMatNullSpaceRemove.h"
#include "petscMatNullSpaceRemove_types.h"
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
  fmt = "MatNullSpaceRemove returned error code %d\n";
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
  fmt = "Incorrect data type %s. Expected MatNullSpace.\n";
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

void petscMatNullSpaceRemove(const M2C_OpaqueType *mat,
                             const M2C_OpaqueType *vec, int *errCode,
                             boolean_T *toplevel)
{
  static const char cv[12] = {'M', 'a', 't', 'N', 'u', 'l',
                              'l', 'S', 'p', 'a', 'c', 'e'};
  static const char cv1[3] = {'V', 'e', 'c'};
  MatNullSpace nullsp;
  Vec b_vec;
  emxArray_char_T *b_mat;
  int i;
  int k;
  char *mat_data;
  boolean_T exitg1;
  boolean_T p;
  p = (mat->type->size[1] == 12);
  if (p && (mat->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (mat->type->data[k] != cv[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  emxInit_char_T(&b_mat, 2);
  if (!p) {
    i = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat, i);
    mat_data = b_mat->data;
    k = mat->type->size[1];
    for (i = 0; i < k; i++) {
      mat_data[i] = mat->type->data[i];
    }
    mat_data[mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
  }
  nullsp = *(MatNullSpace *)(&mat->data->data[0]);
  p = (vec->type->size[1] == 3);
  if (p && (vec->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (vec->type->data[k] != cv1[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (!p) {
    i = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = vec->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat, i);
    mat_data = b_mat->data;
    k = vec->type->size[1];
    for (i = 0; i < k; i++) {
      mat_data[i] = vec->type->data[i];
    }
    mat_data[vec->type->size[1]] = '\x00';
    b_m2c_error(b_mat);
  }
  emxFree_char_T(&b_mat);
  b_vec = *(Vec *)(&vec->data->data[0]);
  *errCode = MatNullSpaceRemove(nullsp, b_vec);
  *toplevel = true;
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscMatNullSpaceRemove_initialize(void)
{
}

void petscMatNullSpaceRemove_terminate(void)
{
}
