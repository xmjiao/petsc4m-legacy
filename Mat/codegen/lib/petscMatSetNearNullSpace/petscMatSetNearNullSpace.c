#include "petscMatSetNearNullSpace.h"
#include "m2c.h"
#include "petsc4m.h"

static MatNullSpace b_m2c_castdata(const emxArray_uint8_T *data);
static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static Mat m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static MatNullSpace b_m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MatNullSpace*)(&data->data[0]);
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
  fmt = "Incorrect data type %s. Expected MatNullSpace.\n";
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
  fmt = "MatSetNearNullSpace returned error code %d\n";
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

void petscMatSetNearNullSpace(const struct0_T *mat, const struct0_T *nullSp, int
  *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  int i;
  static const char cv[3] = { 'M', 'a', 't' };

  Mat t_mat;
  static const char cv1[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  MatNullSpace t_nullSp;
  p = (mat->type->size[1] == 3);
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

  t_mat = m2c_castdata(mat->data);
  p = (nullSp->type->size[1] == 12);
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
  t_nullSp = b_m2c_castdata(nullSp->data);
  *errCode = MatSetNearNullSpace(t_mat, t_nullSp);
  *toplevel = true;
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
