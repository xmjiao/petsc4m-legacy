#include "petscMatNullSpaceSetFunction.h"
#include "mpetsc.h"
#include "m2c.h"

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
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MatNullSpaceRemoveFunc.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "MatNullSpaceSetFunction returned error code %d\n", varargin_3);
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
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MatNullSpace.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_warn(void)
{
  M2C_warn("m2c_opaque_ptr:ConstPtr",
           "Discarding the const modifier of an m2c_opaque_ptr.");
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
  int i0;
  boolean_T exitg4;
  emxArray_char_T *b_nullSp;
  static const char cv0[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  emxArray_uint8_T *data;
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
      i0 = nullSp->type->size[k];
      if (i0 != 11 * k + 1) {
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
    i0 = b_nullSp->size[0] * b_nullSp->size[1];
    b_nullSp->size[0] = 1;
    b_nullSp->size[1] = nullSp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_nullSp, i0, (int)sizeof(char));
    k = nullSp->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_nullSp->data[b_nullSp->size[0] * i0] = nullSp->type->data[nullSp->
        type->size[0] * i0];
    }

    b_nullSp->data[b_nullSp->size[0] * nullSp->type->size[1]] = '\x00';
    m2c_error(b_nullSp);
    emxFree_char_T(&b_nullSp);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = nullSp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = nullSp->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = nullSp->data->data[i0];
  }

  t_nullSp = *(MatNullSpace*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg3 = 0;
    if (k < 2) {
      i0 = rmvFunc->type->size[k];
      if (i0 != 21 * k + 1) {
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
    i0 = b_rmvFunc->size[0] * b_rmvFunc->size[1];
    b_rmvFunc->size[0] = 1;
    b_rmvFunc->size[1] = rmvFunc->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_rmvFunc, i0, (int)sizeof(char));
    k = rmvFunc->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_rmvFunc->data[b_rmvFunc->size[0] * i0] = rmvFunc->type->data
        [rmvFunc->type->size[0] * i0];
    }

    b_rmvFunc->data[b_rmvFunc->size[0] * rmvFunc->type->size[1]] = '\x00';
    b_m2c_error(b_rmvFunc);
    emxFree_char_T(&b_rmvFunc);
  }

  i0 = data->size[0];
  data->size[0] = rmvFunc->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = rmvFunc->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = rmvFunc->data->data[i0];
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
    (M2C_DEBUG);
    t_ctx = M2C_OFFSET_PTR(t_ctx, ctx->offset);
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
