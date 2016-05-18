#include "mptMatCreateAIJFromCRS.h"
#include "petscksp.h"
#include "petscsys.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

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
static void j_m2c_error(int varargin_3);
static void m2c_error(int varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatSetValues returned error code %d\n",
            varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatAssemblyBegin returned error code %d\n",
            varargin_3);
}

static void d_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatAssemblyEnd returned error code %d\n",
            varargin_3);
}

static void e_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatCreate returned error code %d\n",
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
  M2C_error("MPETSc:petscMatSetOptionsPrefix:InputError",
            "The 2nd argument must be a null-terminated string.");
}

static void g_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatSetOptionsPrefix returned error code %d\n",
            varargin_3);
}

static void h_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatSetFromOptions returned error code %d\n",
            varargin_3);
}

static void i_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatSetSizes returned error code %d\n",
            varargin_3);
}

static void j_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "MatGetOwnershipRange returned error code %d\first_row", varargin_3);
}

static void m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatCreateSeqAIJ returned error code %d\n",
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

void mptMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, struct0_T *mat_out,
  boolean_T *toplevel)
{
  emxArray_int32_T *nnz;
  int n;
  int i0;
  int i;
  int b_val;
  Mat t_mat;
  int errCode;
  emxArray_int32_T *jidx;
  emxArray_real_T *rowval;
  int i1;
  int type;
  emxArray_uint8_T *data0;
  int sizepe;
  char t2_type[3];
  int iroa;
  static const char cv0[3] = { 'M', 'a', 't' };

  char * ptr;
  emxInit_int32_T(&nnz, 1);
  n = row_ptr->size[0] - 1;
  i0 = nnz->size[0];
  nnz->size[0] = n;
  emxEnsureCapacity((emxArray__common *)nnz, i0, (int)sizeof(int));
  for (i = 1; i <= n; i++) {
    nnz->data[i - 1] = row_ptr->data[i] - row_ptr->data[i - 1];
  }

  b_val = (PETSC_DEFAULT);
  errCode = MatCreateSeqAIJ(PETSC_COMM_SELF, n, n, b_val, &nnz->data[0], &t_mat);
  if (errCode != 0) {
    b_val = (M2C_DEBUG);
    if (b_val != 0) {
      m2c_error(errCode);
    }
  }

  i = 0;
  emxInit_int32_T(&jidx, 1);
  emxInit_real_T(&rowval, 1);
  while (i + 1 <= n) {
    i0 = row_ptr->data[i + 1] - 1;
    if (row_ptr->data[i] > i0) {
      i1 = 0;
      i0 = 0;
    } else {
      i1 = row_ptr->data[i] - 1;
    }

    b_val = jidx->size[0];
    jidx->size[0] = i0 - i1;
    emxEnsureCapacity((emxArray__common *)jidx, b_val, (int)sizeof(int));
    b_val = i0 - i1;
    for (i0 = 0; i0 < b_val; i0++) {
      jidx->data[i0] = col_ind->data[i1 + i0] - 1;
    }

    i0 = row_ptr->data[i + 1] - 1;
    if (row_ptr->data[i] > i0) {
      i1 = 0;
      i0 = 0;
    } else {
      i1 = row_ptr->data[i] - 1;
    }

    b_val = rowval->size[0];
    rowval->size[0] = i0 - i1;
    emxEnsureCapacity((emxArray__common *)rowval, b_val, (int)sizeof(double));
    b_val = i0 - i1;
    for (i0 = 0; i0 < b_val; i0++) {
      rowval->data[i0] = val->data[i1 + i0];
    }

    iroa = (INSERT_VALUES);
    errCode = MatSetValues(t_mat, 1, &i, nnz->data[i], &jidx->data[0],
      &rowval->data[0], iroa);
    if (errCode != 0) {
      b_val = (M2C_DEBUG);
      if (b_val != 0) {
        b_m2c_error(errCode);
      }
    }

    i++;
  }

  emxFree_real_T(&rowval);
  emxFree_int32_T(&jidx);
  emxFree_int32_T(&nnz);
  type = (MAT_FINAL_ASSEMBLY);
  errCode = MatAssemblyBegin(t_mat, type);
  if (errCode != 0) {
    b_val = (M2C_DEBUG);
    if (b_val != 0) {
      c_m2c_error(errCode);
    }
  }

  type = (MAT_FINAL_ASSEMBLY);
  errCode = MatAssemblyEnd(t_mat, type);
  if (errCode != 0) {
    b_val = (M2C_DEBUG);
    if (b_val != 0) {
      d_m2c_error(errCode);
    }
  }

  emxInit_uint8_T(&data0, 1);
  *toplevel = true;
  sizepe = sizeof(Mat);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 3; i0++) {
    t2_type[i0] = cv0[i0];
  }

  i0 = mat_out->data->size[0];
  mat_out->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)mat_out->data, i0, (int)sizeof(unsigned
    char));
  b_val = data0->size[0];
  for (i0 = 0; i0 < b_val; i0++) {
    mat_out->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = mat_out->type->size[0] * mat_out->type->size[1];
  mat_out->type->size[0] = 1;
  mat_out->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)mat_out->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 3; i0++) {
    mat_out->type->data[i0] = t2_type[i0];
  }

  mat_out->nitems = 1;
  ptr = (char *)(&t_mat);
  for (i = 1; i <= sizepe; i++) {
    mat_out->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }
}

void mptMatCreateAIJFromCRS_4args(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, int ncols, struct0_T
  *mat_out, boolean_T *toplevel)
{
  emxArray_int32_T *nnz;
  int n;
  int i2;
  int i;
  int b_val;
  Mat t_mat;
  int errCode;
  emxArray_int32_T *jidx;
  emxArray_real_T *rowval;
  int i3;
  int type;
  emxArray_uint8_T *data0;
  int sizepe;
  char t1_type[3];
  static const char cv1[3] = { 'M', 'a', 't' };

  int iroa;
  char * ptr;
  emxInit_int32_T(&nnz, 1);
  n = row_ptr->size[0] - 1;
  i2 = nnz->size[0];
  nnz->size[0] = n;
  emxEnsureCapacity((emxArray__common *)nnz, i2, (int)sizeof(int));
  for (i = 1; i <= n; i++) {
    nnz->data[i - 1] = row_ptr->data[i] - row_ptr->data[i - 1];
  }

  b_val = (PETSC_DEFAULT);
  errCode = MatCreateSeqAIJ(PETSC_COMM_SELF, n, ncols, b_val, &nnz->data[0],
    &t_mat);
  if (errCode != 0) {
    b_val = (M2C_DEBUG);
    if (b_val != 0) {
      m2c_error(errCode);
    }
  }

  i = 0;
  emxInit_int32_T(&jidx, 1);
  emxInit_real_T(&rowval, 1);
  while (i + 1 <= n) {
    i2 = row_ptr->data[i + 1] - 1;
    if (row_ptr->data[i] > i2) {
      i3 = 0;
      i2 = 0;
    } else {
      i3 = row_ptr->data[i] - 1;
    }

    b_val = jidx->size[0];
    jidx->size[0] = i2 - i3;
    emxEnsureCapacity((emxArray__common *)jidx, b_val, (int)sizeof(int));
    b_val = i2 - i3;
    for (i2 = 0; i2 < b_val; i2++) {
      jidx->data[i2] = col_ind->data[i3 + i2] - 1;
    }

    i2 = row_ptr->data[i + 1] - 1;
    if (row_ptr->data[i] > i2) {
      i3 = 0;
      i2 = 0;
    } else {
      i3 = row_ptr->data[i] - 1;
    }

    b_val = rowval->size[0];
    rowval->size[0] = i2 - i3;
    emxEnsureCapacity((emxArray__common *)rowval, b_val, (int)sizeof(double));
    b_val = i2 - i3;
    for (i2 = 0; i2 < b_val; i2++) {
      rowval->data[i2] = val->data[i3 + i2];
    }

    iroa = (INSERT_VALUES);
    errCode = MatSetValues(t_mat, 1, &i, nnz->data[i], &jidx->data[0],
      &rowval->data[0], iroa);
    if (errCode != 0) {
      b_val = (M2C_DEBUG);
      if (b_val != 0) {
        b_m2c_error(errCode);
      }
    }

    i++;
  }

  emxFree_real_T(&rowval);
  emxFree_int32_T(&jidx);
  emxFree_int32_T(&nnz);
  type = (MAT_FINAL_ASSEMBLY);
  errCode = MatAssemblyBegin(t_mat, type);
  if (errCode != 0) {
    b_val = (M2C_DEBUG);
    if (b_val != 0) {
      c_m2c_error(errCode);
    }
  }

  type = (MAT_FINAL_ASSEMBLY);
  errCode = MatAssemblyEnd(t_mat, type);
  if (errCode != 0) {
    b_val = (M2C_DEBUG);
    if (b_val != 0) {
      d_m2c_error(errCode);
    }
  }

  emxInit_uint8_T(&data0, 1);
  sizepe = sizeof(Mat);
  i2 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i2, (int)sizeof(unsigned char));
  for (i2 = 0; i2 < 3; i2++) {
    t1_type[i2] = cv1[i2];
  }

  i2 = mat_out->data->size[0];
  mat_out->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)mat_out->data, i2, (int)sizeof(unsigned
    char));
  b_val = data0->size[0];
  for (i2 = 0; i2 < b_val; i2++) {
    mat_out->data->data[i2] = data0->data[i2];
  }

  emxFree_uint8_T(&data0);
  i2 = mat_out->type->size[0] * mat_out->type->size[1];
  mat_out->type->size[0] = 1;
  mat_out->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)mat_out->type, i2, (int)sizeof(char));
  for (i2 = 0; i2 < 3; i2++) {
    mat_out->type->data[i2] = t1_type[i2];
  }

  mat_out->nitems = 1;
  ptr = (char *)(&t_mat);
  for (i = 1; i <= sizepe; i++) {
    mat_out->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  *toplevel = true;
}

void mptMatCreateAIJFromCRS_5args(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val, int ncols, const
  emxArray_char_T *prefix, struct0_T *mat_out, boolean_T *toplevel)
{
  emxArray_int32_T *nnz;
  int n;
  int i4;
  int i;
  Mat t_mat;
  int errCode;
  int flag;
  emxArray_char_T *b_prefix;
  int loop_ub;
  int first_row;
  int last_row;
  emxArray_int32_T *jidx;
  emxArray_real_T *rowval;
  int type;
  emxArray_uint8_T *data0;
  int sizepe;
  char t0_type[3];
  static const char cv2[3] = { 'M', 'a', 't' };

  int iroa;
  char * ptr;
  emxInit_int32_T(&nnz, 1);
  n = row_ptr->size[0] - 1;
  i4 = nnz->size[0];
  nnz->size[0] = n;
  emxEnsureCapacity((emxArray__common *)nnz, i4, (int)sizeof(int));
  for (i = 1; i <= n; i++) {
    nnz->data[i - 1] = row_ptr->data[i] - row_ptr->data[i - 1];
  }

  errCode = MatCreate(PETSC_COMM_WORLD, &t_mat);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      e_m2c_error(errCode);
    }
  }

  emxInit_char_T(&b_prefix, 2);
  if ((prefix->size[1] == 0) || (!(prefix->data[prefix->size[1] - 1] != '\x00')))
  {
    i4 = b_prefix->size[0] * b_prefix->size[1];
    b_prefix->size[0] = 1;
    b_prefix->size[1] = prefix->size[1];
    emxEnsureCapacity((emxArray__common *)b_prefix, i4, (int)sizeof(char));
    loop_ub = prefix->size[0] * prefix->size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b_prefix->data[i4] = prefix->data[i4];
    }
  } else {
    i4 = b_prefix->size[0] * b_prefix->size[1];
    b_prefix->size[0] = 1;
    b_prefix->size[1] = prefix->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_prefix, i4, (int)sizeof(char));
    loop_ub = prefix->size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b_prefix->data[b_prefix->size[0] * i4] = prefix->data[prefix->size[0] * i4];
    }

    b_prefix->data[b_prefix->size[0] * prefix->size[1]] = '\x00';
  }

  if ((!(b_prefix->size[1] == 0)) && (b_prefix->data[b_prefix->size[1] - 1] !=
       '\x00')) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      f_m2c_error();
    }
  }

  errCode = MatSetOptionsPrefix(t_mat, &b_prefix->data[0]);
  emxFree_char_T(&b_prefix);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      g_m2c_error(errCode);
    }
  }

  errCode = MatSetFromOptions(t_mat);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      h_m2c_error(errCode);
    }
  }

  flag = (PETSC_DECIDE);
  loop_ub = (PETSC_DETERMINE);
  errCode = MatSetSizes(t_mat, n, flag, loop_ub, ncols);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      i_m2c_error(errCode);
    }
  }

  errCode = MatGetOwnershipRange(t_mat, &first_row, &last_row);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      j_m2c_error(errCode);
    }
  }

  i = 0;
  emxInit_int32_T(&jidx, 1);
  emxInit_real_T(&rowval, 1);
  while (i + 1 <= n) {
    i4 = row_ptr->data[i + 1] - 1;
    if (row_ptr->data[i] > i4) {
      flag = 0;
      i4 = 0;
    } else {
      flag = row_ptr->data[i] - 1;
    }

    loop_ub = jidx->size[0];
    jidx->size[0] = i4 - flag;
    emxEnsureCapacity((emxArray__common *)jidx, loop_ub, (int)sizeof(int));
    loop_ub = i4 - flag;
    for (i4 = 0; i4 < loop_ub; i4++) {
      jidx->data[i4] = col_ind->data[flag + i4] - 1;
    }

    i4 = row_ptr->data[i + 1] - 1;
    if (row_ptr->data[i] > i4) {
      flag = 0;
      i4 = 0;
    } else {
      flag = row_ptr->data[i] - 1;
    }

    loop_ub = rowval->size[0];
    rowval->size[0] = i4 - flag;
    emxEnsureCapacity((emxArray__common *)rowval, loop_ub, (int)sizeof(double));
    loop_ub = i4 - flag;
    for (i4 = 0; i4 < loop_ub; i4++) {
      rowval->data[i4] = val->data[flag + i4];
    }

    loop_ub = i + first_row;
    iroa = (INSERT_VALUES);
    errCode = MatSetValues(t_mat, 1, &loop_ub, nnz->data[i], &jidx->data[0],
      &rowval->data[0], iroa);
    if (errCode != 0) {
      flag = (M2C_DEBUG);
      if (flag != 0) {
        b_m2c_error(errCode);
      }
    }

    i++;
  }

  emxFree_real_T(&rowval);
  emxFree_int32_T(&jidx);
  emxFree_int32_T(&nnz);
  type = (MAT_FINAL_ASSEMBLY);
  errCode = MatAssemblyBegin(t_mat, type);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      c_m2c_error(errCode);
    }
  }

  type = (MAT_FINAL_ASSEMBLY);
  errCode = MatAssemblyEnd(t_mat, type);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      d_m2c_error(errCode);
    }
  }

  emxInit_uint8_T(&data0, 1);
  sizepe = sizeof(Mat);
  i4 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i4, (int)sizeof(unsigned char));
  for (i4 = 0; i4 < 3; i4++) {
    t0_type[i4] = cv2[i4];
  }

  i4 = mat_out->data->size[0];
  mat_out->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)mat_out->data, i4, (int)sizeof(unsigned
    char));
  loop_ub = data0->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    mat_out->data->data[i4] = data0->data[i4];
  }

  emxFree_uint8_T(&data0);
  i4 = mat_out->type->size[0] * mat_out->type->size[1];
  mat_out->type->size[0] = 1;
  mat_out->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)mat_out->type, i4, (int)sizeof(char));
  for (i4 = 0; i4 < 3; i4++) {
    mat_out->type->data[i4] = t0_type[i4];
  }

  mat_out->nitems = 1;
  ptr = (char *)(&t_mat);
  for (i = 1; i <= sizepe; i++) {
    mat_out->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  *toplevel = true;
}

void mptMatCreateAIJFromCRS_initialize(void)
{
}

void mptMatCreateAIJFromCRS_terminate(void)
{
}
