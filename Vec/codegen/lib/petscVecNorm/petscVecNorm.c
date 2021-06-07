#include "petscVecNorm.h"
#include "petscVecNorm_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static boolean_T isequal(const emxArray_char_T *varargin_1);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "VecNorm returned error code %d\n";
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

void petscVecNorm(const M2C_OpaqueType *x, int type, double nrm[2],
                  int *errCode, boolean_T *toplevel)
{
  Vec vec;
  emxArray_char_T *b_x;
  int i;
  int loop_ub;
  if (!isequal(x->type)) {
    emxInit_char_T(&b_x, 2);
    i = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_x, i);
    loop_ub = x->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_x->data[i] = x->type->data[i];
    }
    b_x->data[x->type->size[1]] = '\x00';
    m2c_error(b_x);
    emxFree_char_T(&b_x);
  }
  vec = *(Vec *)(&x->data->data[0]);
  *errCode = VecNorm(vec, type, &nrm[0]);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscVecNorm_2args(const M2C_OpaqueType *x, int type, double *nrm,
                        int *errCode, boolean_T *toplevel)
{
  Vec vec;
  emxArray_char_T *b_x;
  int i;
  int loop_ub;
  if (!isequal(x->type)) {
    emxInit_char_T(&b_x, 2);
    i = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_x, i);
    loop_ub = x->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_x->data[i] = x->type->data[i];
    }
    b_x->data[x->type->size[1]] = '\x00';
    m2c_error(b_x);
    emxFree_char_T(&b_x);
  }
  vec = *(Vec *)(&x->data->data[0]);
  *errCode = VecNorm(vec, type, nrm);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
  *toplevel = true;
}

void petscVecNorm_initialize(void)
{
}

void petscVecNorm_terminate(void)
{
}
