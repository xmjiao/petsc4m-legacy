#include "petscMatCreateSeqAIJ.h"
#include "m2c.h"
#include "petsc4m.h"
#include "mpi.h"

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
  MPI_Comm obj;
  Mat t_mat;
  int sizepe;
  int i;
  char t1_type[3];
  static const char cv0[3] = { 'M', 'a', 't' };

  int loop_ub;
  char * ptr;
  emxInit_uint8_T(&data0, 1);
  obj = PETSC_COMM_SELF;
  *errCode = MatCreateSeqAIJ(obj, m, n, nz, &nnz->data[0], &t_mat);
  sizepe = sizeof(Mat);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i, sizeof(unsigned char));
  for (i = 0; i < 3; i++) {
    t1_type[i] = cv0[i];
  }

  i = mat->data->size[0];
  mat->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)mat->data, i, sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (i = 0; i < loop_ub; i++) {
    mat->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  mat->type.size[0] = 1;
  mat->type.size[1] = 3;
  for (i = 0; i < 3; i++) {
    mat->type.data[i] = t1_type[i];
  }

  mat->nitems = 1;
  ptr = (char *)(&t_mat);
  for (i = 1; i <= sizepe; i++) {
    mat->data->data[i - 1] = *(ptr);
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
  MPI_Comm obj;
  PetscInt * nnz;
  Mat t_mat;
  int sizepe;
  int i;
  char t0_type[3];
  static const char cv1[3] = { 'M', 'a', 't' };

  int loop_ub;
  char * ptr;
  emxInit_uint8_T(&data0, 1);
  obj = PETSC_COMM_SELF;
  nnz = NULL;
  *errCode = MatCreateSeqAIJ(obj, m, n, nz, nnz, &t_mat);
  sizepe = sizeof(Mat);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i, sizeof(unsigned char));
  for (i = 0; i < 3; i++) {
    t0_type[i] = cv1[i];
  }

  i = mat->data->size[0];
  mat->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)mat->data, i, sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (i = 0; i < loop_ub; i++) {
    mat->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  mat->type.size[0] = 1;
  mat->type.size[1] = 3;
  for (i = 0; i < 3; i++) {
    mat->type.data[i] = t0_type[i];
  }

  mat->nitems = 1;
  ptr = (char *)(&t_mat);
  for (i = 1; i <= sizepe; i++) {
    mat->data->data[i - 1] = *(ptr);
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
