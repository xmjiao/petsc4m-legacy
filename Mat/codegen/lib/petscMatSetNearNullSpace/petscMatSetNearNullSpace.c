#include "petscMatSetNearNullSpace.h"
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
  fmt = "Incorrect data type %s. Expected MatNullSpace.\n";
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
  fmt = "MatSetNearNullSpace returned error code %d\n";
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

void petscMatSetNearNullSpace(const struct0_T *mat, const struct0_T *nullSp, int
  *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  int loop_ub;
  Mat t_mat;
  static const char cv1[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  MatNullSpace t_nullSp;
  p = false;
  b_p = false;
  if (mat->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(mat->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(mat->type->data[k] == cv0[k])) {
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

  emxInit_char_T(&b_mat, 2);
  if (!p) {
    k = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat, k);
    loop_ub = mat->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_mat->data[b_mat->size[0] * k] = mat->type->data[mat->type->size[0] * k];
    }

    b_mat->data[b_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = mat->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = mat->data->data[k];
  }

  t_mat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  if (nullSp->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(nullSp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(nullSp->type->data[k] == cv1[k])) {
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
    k = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = nullSp->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat, k);
    loop_ub = nullSp->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_mat->data[b_mat->size[0] * k] = nullSp->type->data[nullSp->type->size[0]
        * k];
    }

    b_mat->data[b_mat->size[0] * nullSp->type->size[1]] = '\x00';
    b_m2c_error(b_mat);
  }

  emxFree_char_T(&b_mat);
  k = data->size[0];
  data->size[0] = nullSp->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = nullSp->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = nullSp->data->data[k];
  }

  t_nullSp = *(MatNullSpace*)(&data->data[0]);
  *errCode = MatSetNearNullSpace(t_mat, t_nullSp);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscMatSetNearNullSpace_initialize(void)
{
}

void petscMatSetNearNullSpace_terminate(void)
{
}
