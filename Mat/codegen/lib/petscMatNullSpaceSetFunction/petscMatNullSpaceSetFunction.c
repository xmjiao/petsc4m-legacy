#include "petscMatNullSpaceSetFunction.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected MatNullSpaceRemoveFunc.\n";
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
  fmt = "MatNullSpaceSetFunction returned error code %d\n";
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
  fmt = "Incorrect data type %s. Expected MatNullSpace.\n";
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

static void m2c_warn(void)
{
  const char * msgid;
  const char * fmt;
  msgid = "m2c_opaque_ptr:ConstPtr";
  fmt = "Discarding the const modifier of an m2c_opaque_ptr.";
  M2C_warn(msgid, fmt);
}

void petscMatNullSpaceSetFunction(const struct0_T *nullSp, const struct0_T
  *rmvFunc, const struct1_T *ctx, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_nullSp;
  static const char cv0[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  emxArray_uint8_T *data;
  int loop_ub;
  MatNullSpace t_nullSp;
  static const char cv1[22] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e', 'R', 'e', 'm', 'o', 'v', 'e', 'F', 'u', 'n', 'c' };

  MatNullSpaceRemoveFunc t_rmvFunc;
  unsigned long b_data;
  char * t_ctx;
  static const signed char iv0[6] = { 1, 2, 3, 4, 5, 6 };

  static const char cv2[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  p = false;
  b_p = false;
  if (nullSp->type->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(nullSp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(nullSp->type->data[k] == cv0[k])) {
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

  emxInit_char_T(&b_nullSp, 2);
  if (!p) {
    k = b_nullSp->size[0] * b_nullSp->size[1];
    b_nullSp->size[0] = 1;
    b_nullSp->size[1] = nullSp->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_nullSp, k);
    loop_ub = nullSp->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_nullSp->data[b_nullSp->size[0] * k] = nullSp->type->data[nullSp->
        type->size[0] * k];
    }

    b_nullSp->data[b_nullSp->size[0] * nullSp->type->size[1]] = '\x00';
    m2c_error(b_nullSp);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = nullSp->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = nullSp->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = nullSp->data->data[k];
  }

  t_nullSp = *(MatNullSpace*)(&data->data[0]);
  p = false;
  b_p = false;
  if (rmvFunc->type->size[1] == 22) {
    b_p = true;
  }

  if (b_p && (!(rmvFunc->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 22)) {
      if (!(rmvFunc->type->data[k] == cv1[k])) {
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
    k = b_nullSp->size[0] * b_nullSp->size[1];
    b_nullSp->size[0] = 1;
    b_nullSp->size[1] = rmvFunc->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_nullSp, k);
    loop_ub = rmvFunc->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_nullSp->data[b_nullSp->size[0] * k] = rmvFunc->type->data[rmvFunc->
        type->size[0] * k];
    }

    b_nullSp->data[b_nullSp->size[0] * rmvFunc->type->size[1]] = '\x00';
    b_m2c_error(b_nullSp);
  }

  emxFree_char_T(&b_nullSp);
  k = data->size[0];
  data->size[0] = rmvFunc->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = rmvFunc->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = rmvFunc->data->data[k];
  }

  t_rmvFunc = *(MatNullSpaceRemoveFunc*)(&data->data[0]);
  b_data = ctx->data;
  t_ctx = *(char **)(&b_data);
  emxFree_uint8_T(&data);
  if (ctx->type->size[1] > 6) {
    p = false;
    b_p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(ctx->type->data[iv0[k] - 1] == cv2[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    if (b_p) {
      p = true;
    }

    if (p) {
      m2c_warn();
    }
  }

  if (ctx->offset != 0) {
    t_ctx = t_ctx + ctx->offset;
  }

  *errCode = MatNullSpaceSetFunction(t_nullSp, t_rmvFunc, t_ctx);
  *toplevel = true;
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscMatNullSpaceSetFunction_initialize(void)
{
}

void petscMatNullSpaceSetFunction_terminate(void)
{
}
