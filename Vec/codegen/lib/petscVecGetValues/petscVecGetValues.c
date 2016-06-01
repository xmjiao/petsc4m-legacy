#include "petscVecGetValues.h"
#include "m2c.h"
#include "mpetsc.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected Vec.\n", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecGetValues returned error code %d\n",
            varargin_3);
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static void m2c_error(void)
{
  M2C_error("runtime:Error", "Output array y is too small.");
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscVecGetValues(const struct0_T *vec, int ni, const emxArray_int32_T *ix,
  emxArray_real_T *y, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i2;
  boolean_T exitg1;
  emxArray_char_T *b_vec;
  static const char cv1[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  Vec t_vec;
  if (y->size[0] < ni) {
    m2c_error();
  }

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i2 = vec->type->size[k];
      if (i2 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(vec->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(vec->type->data[k] == cv1[k])) {
        b_p = false;
        exitg1 = true;
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
    emxInit_char_T(&b_vec, 2);
    i2 = b_vec->size[0] * b_vec->size[1];
    b_vec->size[0] = 1;
    b_vec->size[1] = vec->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_vec, i2, (int)sizeof(char));
    k = vec->type->size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_vec->data[b_vec->size[0] * i2] = vec->type->data[vec->type->size[0] * i2];
    }

    b_vec->data[b_vec->size[0] * vec->type->size[1]] = '\x00';
    b_m2c_error(b_vec);
    emxFree_char_T(&b_vec);
  }

  emxInit_uint8_T(&data, 1);
  i2 = data->size[0];
  data->size[0] = vec->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i2, (int)sizeof(unsigned char));
  k = vec->data->size[0];
  for (i2 = 0; i2 < k; i2++) {
    data->data[i2] = vec->data->data[i2];
  }

  t_vec = *(Vec*)(&data->data[0]);
  *errCode = VecGetValues(t_vec, ni, &ix->data[0], &y->data[0]);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscVecGetValues_Alloc(const struct0_T *vec, int ni, const
  emxArray_int32_T *ix, emxArray_real_T *y, int *errCode)
{
  int i1;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_vec;
  static const char cv0[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  Vec t_vec;
  i1 = y->size[0];
  y->size[0] = ni;
  emxEnsureCapacity((emxArray__common *)y, i1, (int)sizeof(double));
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i1 = vec->type->size[k];
      if (i1 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(vec->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(vec->type->data[k] == cv0[k])) {
        b_p = false;
        exitg1 = true;
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
    emxInit_char_T(&b_vec, 2);
    i1 = b_vec->size[0] * b_vec->size[1];
    b_vec->size[0] = 1;
    b_vec->size[1] = vec->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_vec, i1, (int)sizeof(char));
    k = vec->type->size[1];
    for (i1 = 0; i1 < k; i1++) {
      b_vec->data[b_vec->size[0] * i1] = vec->type->data[vec->type->size[0] * i1];
    }

    b_vec->data[b_vec->size[0] * vec->type->size[1]] = '\x00';
    b_m2c_error(b_vec);
    emxFree_char_T(&b_vec);
  }

  emxInit_uint8_T(&data, 1);
  i1 = data->size[0];
  data->size[0] = vec->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i1, (int)sizeof(unsigned char));
  k = vec->data->size[0];
  for (i1 = 0; i1 < k; i1++) {
    data->data[i1] = vec->data->data[i1];
  }

  t_vec = *(Vec*)(&data->data[0]);
  k = VecGetValues(t_vec, ni, &ix->data[0], &y->data[0]);
  emxFree_uint8_T(&data);
  if (k != 0) {
    p = (M2C_DEBUG);
    if (p) {
      c_m2c_error(k);
    }
  }

  *errCode = k;
}

void petscVecGetValues_initialize(void)
{
}

void petscVecGetValues_terminate(void)
{
}
