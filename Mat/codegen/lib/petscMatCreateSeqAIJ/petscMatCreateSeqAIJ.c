#include "petscMatCreateSeqAIJ.h"
#include "mpetsc.h"
#include "m2c.h"

static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(int varargin_3);

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

static void m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatCreateSeqAIJ returned error code %d\n",
            varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscMatCreateSeqAIJ(int m, int n, int nz, const emxArray_int32_T *nnz,
  struct0_T *mat, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  Mat t_mat;
  int sizepe;
  int i0;
  char t1_type[3];
  static const char cv0[3] = { 'M', 'a', 't' };

  int loop_ub;
  char * ptr;
  int i;
  emxInit_uint8_T(&data0, 1);
  *errCode = MatCreateSeqAIJ(PETSC_COMM_SELF, m, n, nz, &nnz->data[0], &t_mat);
  *toplevel = true;
  sizepe = sizeof(Mat);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 3; i0++) {
    t1_type[i0] = cv0[i0];
  }

  i0 = mat->data->size[0];
  mat->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)mat->data, i0, (int)sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    mat->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = mat->type->size[0] * mat->type->size[1];
  mat->type->size[0] = 1;
  mat->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)mat->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 3; i0++) {
    mat->type->data[i0] = t1_type[i0];
  }

  mat->nitems = 1;
  ptr = (char *)(&t_mat);
  for (i = 1; i <= sizepe; i++) {
    mat->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (*errCode != 0) {
    m2c_error(*errCode);
  }
}

void petscMatCreateSeqAIJ_FixedRows(int m, int n, int nz, struct0_T *mat, int
  *errCode, boolean_T *topleve)
{
  emxArray_uint8_T *data0;
  Mat t_mat;
  int b_errCode;
  int sizepe;
  int i1;
  char t0_type[3];
  static const char cv1[3] = { 'M', 'a', 't' };

  int loop_ub;
  char * ptr;
  int i;
  emxInit_uint8_T(&data0, 1);
  b_errCode = MatCreateSeqAIJ(PETSC_COMM_SELF, m, n, nz, NULL, &t_mat);
  sizepe = sizeof(Mat);
  i1 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i1, (int)sizeof(unsigned char));
  for (i1 = 0; i1 < 3; i1++) {
    t0_type[i1] = cv1[i1];
  }

  i1 = mat->data->size[0];
  mat->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)mat->data, i1, (int)sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    mat->data->data[i1] = data0->data[i1];
  }

  emxFree_uint8_T(&data0);
  i1 = mat->type->size[0] * mat->type->size[1];
  mat->type->size[0] = 1;
  mat->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)mat->type, i1, (int)sizeof(char));
  for (i1 = 0; i1 < 3; i1++) {
    mat->type->data[i1] = t0_type[i1];
  }

  mat->nitems = 1;
  ptr = (char *)(&t_mat);
  for (i = 1; i <= sizepe; i++) {
    mat->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (b_errCode != 0) {
    m2c_error(b_errCode);
  }

  *errCode = b_errCode;
  *topleve = true;
}

void petscMatCreateSeqAIJ_initialize(void)
{
}

void petscMatCreateSeqAIJ_terminate(void)
{
}
