#include "petscMatCreateSeqAIJ.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static void m2c_error(int varargin_3);
static void m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatCreateSeqAIJ returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

void petscMatCreateSeqAIJ(int m, int n, int nz, const emxArray_int32_T *nnz,
  struct0_T *mat, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  MPI_Comm comm;
  Mat arg;
  int sizepe;
  int i;
  char * ptr;
  emxInit_uint8_T(&data0, 1);
  comm = PETSC_COMM_SELF;
  *errCode = MatCreateSeqAIJ(comm, m, n, nz, &nnz->data[0], &arg);
  sizepe = sizeof(Mat);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = mat->data->size[0];
  mat->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(mat->data, i);
  for (i = 0; i < sizepe; i++) {
    mat->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  mat->type.size[0] = 1;
  mat->type.size[1] = 3;
  mat->type.data[0] = 'M';
  mat->type.data[1] = 'a';
  mat->type.data[2] = 't';
  mat->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    mat->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscMatCreateSeqAIJ_FixedRows(int m, int n, int nz, struct0_T *mat, int
  *errCode, boolean_T *topleve)
{
  emxArray_uint8_T *data0;
  MPI_Comm comm;
  PetscInt * nnz;
  Mat arg;
  int sizepe;
  int i;
  char * ptr;
  emxInit_uint8_T(&data0, 1);
  comm = PETSC_COMM_SELF;
  nnz = NULL;
  *errCode = MatCreateSeqAIJ(comm, m, n, nz, nnz, &arg);
  sizepe = sizeof(Mat);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = mat->data->size[0];
  mat->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(mat->data, i);
  for (i = 0; i < sizepe; i++) {
    mat->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  mat->type.size[0] = 1;
  mat->type.size[1] = 3;
  mat->type.data[0] = 'M';
  mat->type.data[1] = 'a';
  mat->type.data[2] = 't';
  mat->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    mat->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    m2c_error(*errCode);
  }

  *topleve = true;
}

void petscMatCreateSeqAIJ_initialize(void)
{
}

void petscMatCreateSeqAIJ_terminate(void)
{
}
