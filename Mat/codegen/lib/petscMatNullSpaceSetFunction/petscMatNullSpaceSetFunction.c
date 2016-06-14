#include "petscMatNullSpaceSetFunction.h"
#include "m2c.h"
#include "mpetsc.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct1_T(struct1_T *pStruct);
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
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

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxFreeStruct_struct1_T(struct1_T *pStruct)
{
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static void emxInitStruct_struct1_T(struct1_T *pStruct)
{
  emxInit_char_T(&pStruct->type, 2);
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
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

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxDestroy_struct1_T(struct1_T emxArray)
{
  emxFreeStruct_struct1_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void emxInit_struct1_T(struct1_T *pStruct)
{
  emxInitStruct_struct1_T(pStruct);
}

void petscMatNullSpaceSetFunction(const struct0_T *nullSp, const struct0_T
  *rmvFunc, const struct1_T *ctx, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg5;
  boolean_T exitg4;
  emxArray_char_T *b_nullSp;
  static const char cv0[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  emxArray_uint8_T *data;
  int loop_ub;
  MatNullSpace t_nullSp;
  int exitg3;
  boolean_T exitg2;
  emxArray_char_T *b_rmvFunc;
  static const char cv1[22] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e', 'R', 'e', 'm', 'o', 'v', 'e', 'F', 'u', 'n', 'c' };

  MatNullSpaceRemoveFunc t_rmvFunc;
  unsigned long b_data;
  char * t_ctx;
  boolean_T exitg1;
  static const signed char iv0[6] = { 1, 2, 3, 4, 5, 6 };

  static const char cv2[6] = { 'c', 'o', 'n', 's', 't', ' ' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg5 = 0;
    if (k < 2) {
      if (nullSp->type->size[k] != 1 + 11 * k) {
        exitg5 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg5 = 1;
    }
  } while (exitg5 == 0);

  if (b_p && (!(nullSp->type->size[1] == 0))) {
    k = 0;
    exitg4 = false;
    while ((!exitg4) && (k < 12)) {
      if (!(nullSp->type->data[k] == cv0[k])) {
        b_p = false;
        exitg4 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_nullSp, 2);
    k = b_nullSp->size[0] * b_nullSp->size[1];
    b_nullSp->size[0] = 1;
    b_nullSp->size[1] = nullSp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_nullSp, k, (int)sizeof(char));
    loop_ub = nullSp->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_nullSp->data[b_nullSp->size[0] * k] = nullSp->type->data[nullSp->
        type->size[0] * k];
    }

    b_nullSp->data[b_nullSp->size[0] * nullSp->type->size[1]] = '\x00';
    m2c_error(b_nullSp);
    emxFree_char_T(&b_nullSp);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = nullSp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = nullSp->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = nullSp->data->data[k];
  }

  t_nullSp = *(MatNullSpace*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg3 = 0;
    if (k < 2) {
      if (rmvFunc->type->size[k] != 1 + 21 * k) {
        exitg3 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg3 = 1;
    }
  } while (exitg3 == 0);

  if (b_p && (!(rmvFunc->type->size[1] == 0))) {
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 22)) {
      if (!(rmvFunc->type->data[k] == cv1[k])) {
        b_p = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_rmvFunc, 2);
    k = b_rmvFunc->size[0] * b_rmvFunc->size[1];
    b_rmvFunc->size[0] = 1;
    b_rmvFunc->size[1] = rmvFunc->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_rmvFunc, k, (int)sizeof(char));
    loop_ub = rmvFunc->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_rmvFunc->data[b_rmvFunc->size[0] * k] = rmvFunc->type->data
        [rmvFunc->type->size[0] * k];
    }

    b_rmvFunc->data[b_rmvFunc->size[0] * rmvFunc->type->size[1]] = '\x00';
    b_m2c_error(b_rmvFunc);
    emxFree_char_T(&b_rmvFunc);
  }

  k = data->size[0];
  data->size[0] = rmvFunc->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
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

    if (!b_p) {
    } else {
      p = true;
    }

    if (p) {
      m2c_warn();
    }
  }

  if (ctx->offset != 0) {
    t_ctx = (t_ctx)+(ctx->offset);
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
