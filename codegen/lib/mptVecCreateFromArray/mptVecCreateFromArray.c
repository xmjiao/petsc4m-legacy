#include "mptVecCreateFromArray.h"
#include "petscksp.h"
#include "petscsys.h"
#include "mpetsc.h"
#include "m2c.h"

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
static void c_m2c_error(int varargin_3);
static void d_m2c_error(int varargin_3);
static void e_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
static void emxInit_int32_T1(emxArray_int32_T **pEmxArray, int numDimensions);
static void f_m2c_error(void);
static void g_m2c_error(int varargin_3);
static void h_m2c_error(int varargin_3);
static void i_m2c_error(int varargin_3);
static void m2c_error(int varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecSetValues returned error code %d\n",
            varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecAssemblyBegin returned error code %d\n",
            varargin_3);
}

static void d_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecAssemblyEnd returned error code %d\n",
            varargin_3);
}

static void e_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecCreate returned error code %d\n",
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

static void f_m2c_error(void)
{
  M2C_error("MPETSc:petscVecSetOptionsPrefix:InputError",
            "The argument must be a null-terminated string.");
}

static void g_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecSetOptionsPrefix returned error code %d\n",
            varargin_3);
}

static void h_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecSetFromOptions returned error code %d\n",
            varargin_3);
}

static void i_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecSetSizes returned error code %d\n",
            varargin_3);
}

static void m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecCreateSeq returned error code %d\n",
            varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mptVecCreateFromArray(const emxArray_real_T *arr, struct0_T *vec_out,
  boolean_T *toplevel)
{
  int n;
  Vec t_vec;
  int errCode;
  int yk;
  int b_n;
  emxArray_int32_T *y;
  int k;
  emxArray_int32_T *idx;
  int iroa;
  emxArray_uint8_T *data0;
  int sizepe;
  char t1_type[3];
  static const char cv0[3] = { 'V', 'e', 'c' };

  char * ptr;
  int i;
  n = arr->size[0];
  errCode = VecCreateSeq(PETSC_COMM_SELF, n, &t_vec);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      m2c_error(errCode);
    }
  }

  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }

  emxInit_int32_T1(&y, 2);
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(int));
  if (b_n > 0) {
    y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)idx, k, (int)sizeof(int));
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx->data[k] = y->data[y->size[0] * k];
  }

  emxFree_int32_T(&y);
  iroa = (INSERT_VALUES);
  errCode = VecSetValues(t_vec, n, &idx->data[0], &arr->data[0], iroa);
  emxFree_int32_T(&idx);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      b_m2c_error(errCode);
    }
  }

  errCode = VecAssemblyBegin(t_vec);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      c_m2c_error(errCode);
    }
  }

  errCode = VecAssemblyEnd(t_vec);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      d_m2c_error(errCode);
    }
  }

  emxInit_uint8_T(&data0, 1);
  *toplevel = true;
  sizepe = sizeof(Vec);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, k, (int)sizeof(unsigned char));
  for (k = 0; k < 3; k++) {
    t1_type[k] = cv0[k];
  }

  k = vec_out->data->size[0];
  vec_out->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)vec_out->data, k, (int)sizeof(unsigned
    char));
  yk = data0->size[0];
  for (k = 0; k < yk; k++) {
    vec_out->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = vec_out->type->size[0] * vec_out->type->size[1];
  vec_out->type->size[0] = 1;
  vec_out->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)vec_out->type, k, (int)sizeof(char));
  for (k = 0; k < 3; k++) {
    vec_out->type->data[k] = t1_type[k];
  }

  vec_out->nitems = 1;
  ptr = (char *)(&t_vec);
  for (i = 1; i <= sizepe; i++) {
    vec_out->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }
}

void mptVecCreateFromArray_2args(const emxArray_real_T *arr, const
  emxArray_char_T *prefix, struct0_T *vec_out, boolean_T *toplevel)
{
  int n;
  Vec t_vec;
  int errCode;
  int yk;
  emxArray_char_T *b_prefix;
  int k;
  int N;
  int b_n;
  emxArray_int32_T *y;
  emxArray_int32_T *idx;
  int iroa;
  emxArray_uint8_T *data0;
  int sizepe;
  char t0_type[3];
  static const char cv1[3] = { 'V', 'e', 'c' };

  char * ptr;
  int i;
  n = arr->size[0];
  errCode = VecCreate(PETSC_COMM_WORLD, &t_vec);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      e_m2c_error(errCode);
    }
  }

  emxInit_char_T(&b_prefix, 2);
  if ((prefix->size[1] == 0) || (!(prefix->data[prefix->size[1] - 1] != '\x00')))
  {
    k = b_prefix->size[0] * b_prefix->size[1];
    b_prefix->size[0] = 1;
    b_prefix->size[1] = prefix->size[1];
    emxEnsureCapacity((emxArray__common *)b_prefix, k, (int)sizeof(char));
    yk = prefix->size[0] * prefix->size[1];
    for (k = 0; k < yk; k++) {
      b_prefix->data[k] = prefix->data[k];
    }
  } else {
    k = b_prefix->size[0] * b_prefix->size[1];
    b_prefix->size[0] = 1;
    b_prefix->size[1] = prefix->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_prefix, k, (int)sizeof(char));
    yk = prefix->size[1];
    for (k = 0; k < yk; k++) {
      b_prefix->data[b_prefix->size[0] * k] = prefix->data[prefix->size[0] * k];
    }

    b_prefix->data[b_prefix->size[0] * prefix->size[1]] = '\x00';
  }

  if ((!(b_prefix->size[1] == 0)) && (b_prefix->data[b_prefix->size[1] - 1] !=
       '\x00')) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      f_m2c_error();
    }
  }

  errCode = VecSetOptionsPrefix(t_vec, &b_prefix->data[0]);
  emxFree_char_T(&b_prefix);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      g_m2c_error(errCode);
    }
  }

  errCode = VecSetFromOptions(t_vec);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      h_m2c_error(errCode);
    }
  }

  N = (PETSC_DECIDE);
  errCode = VecSetSizes(t_vec, n, N);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      i_m2c_error(errCode);
    }
  }

  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }

  emxInit_int32_T1(&y, 2);
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(int));
  if (b_n > 0) {
    y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)idx, k, (int)sizeof(int));
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx->data[k] = y->data[y->size[0] * k];
  }

  emxFree_int32_T(&y);
  iroa = (INSERT_VALUES);
  errCode = VecSetValues(t_vec, n, &idx->data[0], &arr->data[0], iroa);
  emxFree_int32_T(&idx);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      b_m2c_error(errCode);
    }
  }

  errCode = VecAssemblyBegin(t_vec);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      c_m2c_error(errCode);
    }
  }

  errCode = VecAssemblyEnd(t_vec);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      d_m2c_error(errCode);
    }
  }

  emxInit_uint8_T(&data0, 1);
  sizepe = sizeof(Vec);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, k, (int)sizeof(unsigned char));
  for (k = 0; k < 3; k++) {
    t0_type[k] = cv1[k];
  }

  k = vec_out->data->size[0];
  vec_out->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)vec_out->data, k, (int)sizeof(unsigned
    char));
  yk = data0->size[0];
  for (k = 0; k < yk; k++) {
    vec_out->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = vec_out->type->size[0] * vec_out->type->size[1];
  vec_out->type->size[0] = 1;
  vec_out->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)vec_out->type, k, (int)sizeof(char));
  for (k = 0; k < 3; k++) {
    vec_out->type->data[k] = t0_type[k];
  }

  vec_out->nitems = 1;
  ptr = (char *)(&t_vec);
  for (i = 1; i <= sizepe; i++) {
    vec_out->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  *toplevel = true;
}

void mptVecCreateFromArray_initialize(void)
{
}

void mptVecCreateFromArray_terminate(void)
{
}
