#include "petscMatCreateSeqAIJ.h"
#include "petscMatCreateSeqAIJ_types.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static void m2c_error(int varargin_3);

static void m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "MatCreateSeqAIJ returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

void petscMatCreateSeqAIJ(int m, int n, int nz, const emxArray_int32_T *nnz,
                          struct0_T *mat, int *errCode, boolean_T *toplevel)
{
  MPI_Comm comm;
  Mat arg;
  char *ptr;
  const int *nnz_data;
  int i;
  int sizepe;
  nnz_data = nnz->data;
  comm = PETSC_COMM_SELF;
  *errCode = MatCreateSeqAIJ(comm, m, n, nz, &nnz_data[0], &arg);
  sizepe = sizeof(Mat);
  i = mat->data->size[0];
  mat->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(mat->data, i);
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

void petscMatCreateSeqAIJ_FixedRows(int m, int n, int nz, struct0_T *mat,
                                    int *errCode, boolean_T *topleve)
{
  MPI_Comm comm;
  Mat arg;
  PetscInt *nnz;
  char *ptr;
  int i;
  int sizepe;
  comm = PETSC_COMM_SELF;
  nnz = NULL;
  *errCode = MatCreateSeqAIJ(comm, m, n, nz, nnz, &arg);
  sizepe = sizeof(Mat);
  i = mat->data->size[0];
  mat->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(mat->data, i);
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
