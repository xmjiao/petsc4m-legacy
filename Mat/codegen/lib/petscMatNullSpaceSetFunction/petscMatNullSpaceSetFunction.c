#include "petscMatNullSpaceSetFunction.h"
#include "m2c.h"
#include "petsc4m.h"

static MatNullSpaceRemoveFunc b_m2c_castdata(const emxArray_uint8_T *data);
static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static MatNullSpace m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_warn(void);
static MatNullSpaceRemoveFunc b_m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MatNullSpaceRemoveFunc*)(&data->data[0]);
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
  fmt = "Incorrect data type %s. Expected MatNullSpaceRemoveFunc.\n";
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
  fmt = "MatNullSpaceSetFunction returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static MatNullSpace m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MatNullSpace*)(&data->data[0]);
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
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_nullSp;
  int i;
  static const char cv[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  MatNullSpace t_nullSp;
  static const char cv1[22] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e', 'R', 'e', 'm', 'o', 'v', 'e', 'F', 'u', 'n', 'c' };

  MatNullSpaceRemoveFunc t_rmvFunc;
  char * t_ctx;
  static const char cv2[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  p = (nullSp->type->size[1] == 12);
  if (p && (nullSp->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(nullSp->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_nullSp, 2);
  if (!b_p) {
    i = b_nullSp->size[0] * b_nullSp->size[1];
    b_nullSp->size[0] = 1;
    b_nullSp->size[1] = nullSp->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_nullSp, i);
    k = nullSp->type->size[1];
    for (i = 0; i < k; i++) {
      b_nullSp->data[i] = nullSp->type->data[i];
    }

    b_nullSp->data[nullSp->type->size[1]] = '\x00';
    m2c_error(b_nullSp);
  }

  t_nullSp = m2c_castdata(nullSp->data);
  p = (rmvFunc->type->size[1] == 22);
  if (p && (rmvFunc->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 22)) {
      if (!(rmvFunc->type->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_nullSp->size[0] * b_nullSp->size[1];
    b_nullSp->size[0] = 1;
    b_nullSp->size[1] = rmvFunc->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_nullSp, i);
    k = rmvFunc->type->size[1];
    for (i = 0; i < k; i++) {
      b_nullSp->data[i] = rmvFunc->type->data[i];
    }

    b_nullSp->data[rmvFunc->type->size[1]] = '\x00';
    b_m2c_error(b_nullSp);
  }

  emxFree_char_T(&b_nullSp);
  t_rmvFunc = b_m2c_castdata(rmvFunc->data);
  t_ctx = *(char **)(&ctx->data);
  if (ctx->type->size[1] > 6) {
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(ctx->type->data[k] == cv2[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    b_p = (int)p;
    if (b_p) {
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
