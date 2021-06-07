#include "petscMatSetNullSpace.h"
#include "petscMatSetNullSpace_types.h"
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
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected MatNullSpace.\n";
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
  fmt = "MatSetNullSpace returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
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

void petscMatSetNullSpace(const M2C_OpaqueType *mat,
                          const M2C_OpaqueType *nullSp, int *errCode,
                          boolean_T *toplevel)
{
  static const char cv1[12] = {'M', 'a', 't', 'N', 'u', 'l',
                               'l', 'S', 'p', 'a', 'c', 'e'};
  static const char cv[3] = {'M', 'a', 't'};
  Mat t_mat;
  MatNullSpace t_nullSp;
  emxArray_char_T *b_mat;
  int i;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (mat->type->size[1] == 3) {
    p = true;
  }
  if (p && (mat->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(mat->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  b_p = (int)p;
  emxInit_char_T(&b_mat, 2);
  if (!b_p) {
    i = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat, i);
    k = mat->type->size[1];
    for (i = 0; i < k; i++) {
      b_mat->data[i] = mat->type->data[i];
    }
    b_mat->data[mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
  }
  t_mat = *(Mat *)(&mat->data->data[0]);
  p = false;
  if (nullSp->type->size[1] == 12) {
    p = true;
  }
  if (p && (nullSp->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(nullSp->type->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    i = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = nullSp->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat, i);
    k = nullSp->type->size[1];
    for (i = 0; i < k; i++) {
      b_mat->data[i] = nullSp->type->data[i];
    }
    b_mat->data[nullSp->type->size[1]] = '\x00';
    b_m2c_error(b_mat);
  }
  emxFree_char_T(&b_mat);
  t_nullSp = *(MatNullSpace *)(&nullSp->data->data[0]);
  *errCode = MatSetNullSpace(t_mat, t_nullSp);
  *toplevel = true;
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscMatSetNullSpace_initialize(void)
{
}

void petscMatSetNullSpace_terminate(void)
{
}
