#include "petscVecCreateSeq.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static void m2c_error(int varargin_3);
static void m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "VecCreateSeq returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

void petscVecCreateSeq(int n, struct0_T *vec, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  MPI_Comm comm;
  Vec arg;
  int sizepe;
  int i;
  char * ptr;
  emxInit_uint8_T(&data0, 1);
  comm = PETSC_COMM_SELF;
  *errCode = VecCreateSeq(comm, n, &arg);
  sizepe = sizeof(Vec);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = vec->data->size[0];
  vec->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(vec->data, i);
  for (i = 0; i < sizepe; i++) {
    vec->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  vec->type.size[0] = 1;
  vec->type.size[1] = 3;
  vec->type.data[0] = 'V';
  vec->type.data[1] = 'e';
  vec->type.data[2] = 'c';
  vec->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    vec->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscVecCreateSeq_initialize(void)
{
}

void petscVecCreateSeq_terminate(void)
{
}
