#include "mptVecToArray.h"
#include "m2c.h"
#include "mpetsc.h"

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif

static void b_m2c_error(int varargin_3);
static void c_m2c_error(void);
static void d_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
static void emxInit_int32_T1(emxArray_int32_T **pEmxArray, int numDimensions);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecGetLocalSize returned error code %d\n",
            varargin_3);
}

static void c_m2c_error(void)
{
  M2C_error("runtime:Error", "Output array y is too small.");
}

static void d_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecGetValues returned error code %d\n",
            varargin_3);
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int *)NULL) && (*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_int32_T1(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
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
            "Incorrect data type %s. Expected Vec.\n", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mptVecToArray(const struct0_T *vec, emxArray_real_T *arr)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg4;
  int i0;
  boolean_T exitg3;
  emxArray_char_T *b_vec;
  static const char cv0[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  int yk;
  Vec t_vec;
  int n;
  int errCode;
  int b_n;
  emxArray_int32_T *y;
  emxArray_int32_T *idx;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *c_vec;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i0 = vec->type->size[k];
      if (i0 != (k << 1) + 1) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(vec->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(vec->type->data[k] == cv0[k])) {
        b_p = false;
        exitg3 = true;
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
    i0 = b_vec->size[0] * b_vec->size[1];
    b_vec->size[0] = 1;
    b_vec->size[1] = vec->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_vec, i0, (int)sizeof(char));
    yk = vec->type->size[1];
    for (i0 = 0; i0 < yk; i0++) {
      b_vec->data[b_vec->size[0] * i0] = vec->type->data[vec->type->size[0] * i0];
    }

    b_vec->data[b_vec->size[0] * vec->type->size[1]] = '\x00';
    m2c_error(b_vec);
    emxFree_char_T(&b_vec);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = vec->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  yk = vec->data->size[0];
  for (i0 = 0; i0 < yk; i0++) {
    data->data[i0] = vec->data->data[i0];
  }

  t_vec = *(Vec*)(&data->data[0]);
  errCode = VecGetLocalSize(t_vec, &n);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      b_m2c_error(errCode);
    }
  }

  i0 = arr->size[0];
  arr->size[0] = n;
  emxEnsureCapacity((emxArray__common *)arr, i0, (int)sizeof(double));
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }

  emxInit_int32_T1(&y, 2);
  i0 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity((emxArray__common *)y, i0, (int)sizeof(int));
  if (b_n > 0) {
    y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&idx, 1);
  i0 = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)idx, i0, (int)sizeof(int));
  yk = y->size[1];
  for (i0 = 0; i0 < yk; i0++) {
    idx->data[i0] = y->data[y->size[0] * i0];
  }

  emxFree_int32_T(&y);
  if (arr->size[0] < n) {
    c_m2c_error();
  }

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = vec->type->size[k];
      if (i0 != (k << 1) + 1) {
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
    emxInit_char_T(&c_vec, 2);
    i0 = c_vec->size[0] * c_vec->size[1];
    c_vec->size[0] = 1;
    c_vec->size[1] = vec->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)c_vec, i0, (int)sizeof(char));
    yk = vec->type->size[1];
    for (i0 = 0; i0 < yk; i0++) {
      c_vec->data[c_vec->size[0] * i0] = vec->type->data[vec->type->size[0] * i0];
    }

    c_vec->data[c_vec->size[0] * vec->type->size[1]] = '\x00';
    m2c_error(c_vec);
    emxFree_char_T(&c_vec);
  }

  i0 = data->size[0];
  data->size[0] = vec->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  yk = vec->data->size[0];
  for (i0 = 0; i0 < yk; i0++) {
    data->data[i0] = vec->data->data[i0];
  }

  t_vec = *(Vec*)(&data->data[0]);
  errCode = VecGetValues(t_vec, n, &idx->data[0], &arr->data[0]);
  emxFree_uint8_T(&data);
  emxFree_int32_T(&idx);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      d_m2c_error(errCode);
    }
  }
}

void mptVecToArray_initialize(void)
{
}

void mptVecToArray_terminate(void)
{
}
