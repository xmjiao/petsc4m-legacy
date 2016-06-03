#include "mpi_Error_string.h"
#include "m2c.h"
#include "mpetsc.h"

static void m2c_error(int varargin_3);

static void m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Error_string with error code %d\n",
            varargin_3);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void mpi_Error_string(int errcode, emxArray_char_T *msg, int *info, boolean_T
                      *toplevel)
{
  unsigned char msg0[1024];
  char * ptr;
  int resultlen;
  emxArray_uint8_T *varargin_1;
  int i0;
  memset(&msg0[0], 0, sizeof(unsigned char) << 10);
  ptr = (char *)(msg0);
  resultlen = 0;
  *info = MPI_Error_string(errcode, ptr, &resultlen);
  if (1 > resultlen) {
    resultlen = 0;
  }

  emxInit_uint8_T(&varargin_1, 2);
  i0 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  varargin_1->size[1] = resultlen;
  emxEnsureCapacity((emxArray__common *)varargin_1, i0, (int)sizeof(unsigned
    char));
  for (i0 = 0; i0 < resultlen; i0++) {
    varargin_1->data[varargin_1->size[0] * i0] = msg0[i0];
  }

  i0 = msg->size[0] * msg->size[1];
  msg->size[0] = 1;
  msg->size[1] = (short)resultlen;
  emxEnsureCapacity((emxArray__common *)msg, i0, (int)sizeof(char));
  resultlen = (short)resultlen;
  for (i0 = 0; i0 < resultlen; i0++) {
    msg->data[i0] = (signed char)varargin_1->data[i0];
  }

  emxFree_uint8_T(&varargin_1);
  *toplevel = true;
  if (*info != 0) {
    m2c_error(*info);
  }
}

void mpi_Error_string_initialize(void)
{
}

void mpi_Error_string_terminate(void)
{
}
