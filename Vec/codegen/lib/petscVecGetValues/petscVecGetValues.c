#include "petscVecGetValues.h"
#include "petscVecGetValues_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(int varargin_3);

static boolean_T isequal(const emxArray_char_T *varargin_1);

static void m2c_error(void);

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
  fmt = "VecGetValues returned error code %d\n";
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

static void m2c_error(void)
{
  const char *fmt;
  fmt = "Output array y is too small.";
  M2C_error("runtime:Error", fmt);
}

void petscVecGetValues(const M2C_OpaqueType *vec, int ni,
                       const emxArray_int32_T *ix, emxArray_real32_T *y,
                       int *errCode, boolean_T *toplevel)
{
  Vec t_vec;
  emxArray_char_T *b_vec;
  int i;
  int loop_ub;
  if (y->size[0] < ni) {
    m2c_error();
  }
  if (!isequal(vec->type)) {
    emxInit_char_T(&b_vec, 2);
    i = b_vec->size[0] * b_vec->size[1];
    b_vec->size[0] = 1;
    b_vec->size[1] = vec->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_vec, i);
    loop_ub = vec->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_vec->data[i] = vec->type->data[i];
    }
    b_vec->data[vec->type->size[1]] = '\x00';
    b_m2c_error(b_vec);
    emxFree_char_T(&b_vec);
  }
  t_vec = *(Vec *)(&vec->data->data[0]);
  *errCode = VecGetValues(t_vec, ni, &ix->data[0], &y->data[0]);
  *toplevel = true;
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscVecGetValues_Alloc(const M2C_OpaqueType *vec, int ni,
                             const emxArray_int32_T *ix, emxArray_real32_T *y,
                             int *errCode, boolean_T *toplevel)
{
  Vec t_vec;
  emxArray_char_T *b_vec;
  int i;
  int loop_ub;
  i = y->size[0];
  y->size[0] = ni;
  emxEnsureCapacity_real32_T(y, i);
  if (!isequal(vec->type)) {
    emxInit_char_T(&b_vec, 2);
    i = b_vec->size[0] * b_vec->size[1];
    b_vec->size[0] = 1;
    b_vec->size[1] = vec->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_vec, i);
    loop_ub = vec->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_vec->data[i] = vec->type->data[i];
    }
    b_vec->data[vec->type->size[1]] = '\x00';
    b_m2c_error(b_vec);
    emxFree_char_T(&b_vec);
  }
  t_vec = *(Vec *)(&vec->data->data[0]);
  *errCode = VecGetValues(t_vec, ni, &ix->data[0], &y->data[0]);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
  *toplevel = true;
}

void petscVecGetValues_initialize(void)
{
}

void petscVecGetValues_terminate(void)
{
}
