#include "mpi_Error_string.h"
#include "m2c.h"
#include "mpetsc.h"

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T

struct emxArray_uint8_T
{
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif

#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T

typedef struct emxArray_uint8_T emxArray_uint8_T;

#endif

static void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);
static void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions);
static void m2c_error(int varargin_3);

static void emxFree_uint8_T(emxArray_uint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned char *)NULL) && (*pEmxArray)
        ->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_uint8_T *)NULL;
  }
}

static void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions)
{
  emxArray_uint8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint8_T *)malloc(sizeof(emxArray_uint8_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

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
  int loop_ub;
  emxArray_uint8_T *varargin_1;
  int i0;
  memset(&msg0[0], 0, sizeof(unsigned char) << 10);
  ptr = (char *)(msg0);
  resultlen = 0;
  *info = MPI_Error_string(errcode, ptr, &resultlen);
  if (1 > resultlen) {
    loop_ub = 0;
  } else {
    loop_ub = resultlen;
  }

  emxInit_uint8_T(&varargin_1, 2);
  i0 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  varargin_1->size[1] = loop_ub;
  emxEnsureCapacity((emxArray__common *)varargin_1, i0, (int)sizeof(unsigned
    char));
  for (i0 = 0; i0 < loop_ub; i0++) {
    varargin_1->data[varargin_1->size[0] * i0] = msg0[i0];
  }

  i0 = msg->size[0] * msg->size[1];
  msg->size[0] = 1;
  msg->size[1] = (short)loop_ub;
  emxEnsureCapacity((emxArray__common *)msg, i0, (int)sizeof(char));
  loop_ub = (short)loop_ub;
  for (i0 = 0; i0 < loop_ub; i0++) {
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
