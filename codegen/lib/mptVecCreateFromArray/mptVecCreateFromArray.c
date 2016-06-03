#include "mptVecCreateFromArray.h"
#include "m2c.h"
#include "mpetsc.h"

static void b_m2c_error(int varargin_3);
static void c_m2c_error(int varargin_3);
static void d_m2c_error(int varargin_3);
static void e_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
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

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
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
  boolean_T flag;
  int b_n;
  emxArray_int32_T *y;
  int i0;
  emxArray_int32_T *idx;
  int sizepe;
  emxArray_uint8_T *data0;
  char t1_type[3];
  static const char cv0[3] = { 'V', 'e', 'c' };

  char * ptr;
  n = arr->size[0];
  errCode = VecCreateSeq(PETSC_COMM_SELF, n, &t_vec);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      m2c_error(errCode);
    }
  }

  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }

  emxInit_int32_T(&y, 2);
  i0 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity((emxArray__common *)y, i0, (int)sizeof(int));
  if (b_n > 0) {
    y->data[0] = 0;
    errCode = 0;
    for (sizepe = 2; sizepe <= b_n; sizepe++) {
      errCode++;
      y->data[sizepe - 1] = errCode;
    }
  }

  emxInit_int32_T(&idx, 1);
  i0 = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)idx, i0, (int)sizeof(int));
  errCode = y->size[1];
  for (i0 = 0; i0 < errCode; i0++) {
    idx->data[i0] = y->data[y->size[0] * i0];
  }

  emxFree_int32_T(&y);
  errCode = (INSERT_VALUES);
  errCode = VecSetValues(t_vec, n, &idx->data[0], &arr->data[0], errCode);
  emxFree_int32_T(&idx);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      b_m2c_error(errCode);
    }
  }

  errCode = VecAssemblyBegin(t_vec);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      c_m2c_error(errCode);
    }
  }

  errCode = VecAssemblyEnd(t_vec);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      d_m2c_error(errCode);
    }
  }

  emxInit_uint8_T(&data0, 1);
  *toplevel = true;
  sizepe = sizeof(Vec);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 3; i0++) {
    t1_type[i0] = cv0[i0];
  }

  i0 = vec_out->data->size[0];
  vec_out->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)vec_out->data, i0, (int)sizeof(unsigned
    char));
  errCode = data0->size[0];
  for (i0 = 0; i0 < errCode; i0++) {
    vec_out->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = vec_out->type->size[0] * vec_out->type->size[1];
  vec_out->type->size[0] = 1;
  vec_out->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)vec_out->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 3; i0++) {
    vec_out->type->data[i0] = t1_type[i0];
  }

  vec_out->nitems = 1;
  ptr = (char *)(&t_vec);
  for (errCode = 1; errCode <= sizepe; errCode++) {
    vec_out->data->data[errCode - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }
}

void mptVecCreateFromArray_2args(const emxArray_real_T *arr, const
  emxArray_char_T *prefix, struct0_T *vec_out, boolean_T *toplevel)
{
  int n;
  Vec t_vec;
  int errCode;
  boolean_T flag;
  emxArray_char_T *b_prefix;
  int i1;
  int b_n;
  emxArray_int32_T *y;
  emxArray_int32_T *idx;
  int sizepe;
  emxArray_uint8_T *data0;
  char t0_type[3];
  static const char cv1[3] = { 'V', 'e', 'c' };

  char * ptr;
  n = arr->size[0];
  errCode = VecCreate(PETSC_COMM_WORLD, &t_vec);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      e_m2c_error(errCode);
    }
  }

  emxInit_char_T(&b_prefix, 2);
  if ((prefix->size[1] == 0) || (!(prefix->data[prefix->size[1] - 1] != '\x00')))
  {
    i1 = b_prefix->size[0] * b_prefix->size[1];
    b_prefix->size[0] = 1;
    b_prefix->size[1] = prefix->size[1];
    emxEnsureCapacity((emxArray__common *)b_prefix, i1, (int)sizeof(char));
    errCode = prefix->size[0] * prefix->size[1];
    for (i1 = 0; i1 < errCode; i1++) {
      b_prefix->data[i1] = prefix->data[i1];
    }
  } else {
    i1 = b_prefix->size[0] * b_prefix->size[1];
    b_prefix->size[0] = 1;
    b_prefix->size[1] = prefix->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_prefix, i1, (int)sizeof(char));
    errCode = prefix->size[1];
    for (i1 = 0; i1 < errCode; i1++) {
      b_prefix->data[b_prefix->size[0] * i1] = prefix->data[prefix->size[0] * i1];
    }

    b_prefix->data[b_prefix->size[0] * prefix->size[1]] = '\x00';
  }

  if ((!(b_prefix->size[1] == 0)) && (b_prefix->data[b_prefix->size[1] - 1] !=
       '\x00')) {
    flag = (M2C_DEBUG);
    if (flag) {
      f_m2c_error();
    }
  }

  errCode = VecSetOptionsPrefix(t_vec, &b_prefix->data[0]);
  emxFree_char_T(&b_prefix);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      g_m2c_error(errCode);
    }
  }

  errCode = VecSetFromOptions(t_vec);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      h_m2c_error(errCode);
    }
  }

  errCode = (PETSC_DECIDE);
  errCode = VecSetSizes(t_vec, n, errCode);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      i_m2c_error(errCode);
    }
  }

  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }

  emxInit_int32_T(&y, 2);
  i1 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity((emxArray__common *)y, i1, (int)sizeof(int));
  if (b_n > 0) {
    y->data[0] = 0;
    errCode = 0;
    for (sizepe = 2; sizepe <= b_n; sizepe++) {
      errCode++;
      y->data[sizepe - 1] = errCode;
    }
  }

  emxInit_int32_T(&idx, 1);
  i1 = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)idx, i1, (int)sizeof(int));
  errCode = y->size[1];
  for (i1 = 0; i1 < errCode; i1++) {
    idx->data[i1] = y->data[y->size[0] * i1];
  }

  emxFree_int32_T(&y);
  errCode = (INSERT_VALUES);
  errCode = VecSetValues(t_vec, n, &idx->data[0], &arr->data[0], errCode);
  emxFree_int32_T(&idx);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      b_m2c_error(errCode);
    }
  }

  errCode = VecAssemblyBegin(t_vec);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      c_m2c_error(errCode);
    }
  }

  errCode = VecAssemblyEnd(t_vec);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag) {
      d_m2c_error(errCode);
    }
  }

  emxInit_uint8_T(&data0, 1);
  sizepe = sizeof(Vec);
  i1 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i1, (int)sizeof(unsigned char));
  for (i1 = 0; i1 < 3; i1++) {
    t0_type[i1] = cv1[i1];
  }

  i1 = vec_out->data->size[0];
  vec_out->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)vec_out->data, i1, (int)sizeof(unsigned
    char));
  errCode = data0->size[0];
  for (i1 = 0; i1 < errCode; i1++) {
    vec_out->data->data[i1] = data0->data[i1];
  }

  emxFree_uint8_T(&data0);
  i1 = vec_out->type->size[0] * vec_out->type->size[1];
  vec_out->type->size[0] = 1;
  vec_out->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)vec_out->type, i1, (int)sizeof(char));
  for (i1 = 0; i1 < 3; i1++) {
    vec_out->type->data[i1] = t0_type[i1];
  }

  vec_out->nitems = 1;
  ptr = (char *)(&t_vec);
  for (errCode = 1; errCode <= sizepe; errCode++) {
    vec_out->data->data[errCode - 1] = *(ptr);
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
