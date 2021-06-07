#include "petscVecCreateSeq.h"
#include "petscVecCreateSeq_types.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static void m2c_error(int varargin_3);

static void m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "VecCreateSeq returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

void petscVecCreateSeq(int n, struct0_T *vec, int *errCode, boolean_T *toplevel)
{
  MPI_Comm comm;
  Vec arg;
  char *ptr;
  int i;
  int sizepe;
  comm = PETSC_COMM_SELF;
  *errCode = VecCreateSeq(comm, n, &arg);
  sizepe = sizeof(Vec);
  i = vec->data->size[0];
  vec->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(vec->data, i);
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
