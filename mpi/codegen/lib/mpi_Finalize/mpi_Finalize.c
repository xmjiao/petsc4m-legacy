#include "mpi_Finalize.h"
#include "mpetsc.h"
#include "m2c.h"

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif

#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T

typedef struct emxArray_char_T emxArray_char_T;

#endif

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

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void emxFree_char_T(emxArray_char_T **pEmxArray);
static void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);
static void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions);
static void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions);
static void m2c_error(int varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("MPI:RuntimeError", "MPI_Finalized failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("MPI:RuntimeError", "MPI_Finalize failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void emxFree_char_T(emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if (((*pEmxArray)->data != (char *)NULL) && (*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
  }
}

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

static void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxArray_char_T *emxArray;
  int i;
  *pEmxArray = (emxArray_char_T *)malloc(sizeof(emxArray_char_T));
  emxArray = *pEmxArray;
  emxArray->data = (char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
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

void mpi_Finalize(int *info, boolean_T *toplevel)
{
  int flag;
  int b_info;
  emxArray_uint8_T *varargin_1;
  emxArray_char_T *b_varargin_1;
  int b_flag;
  unsigned char msg0[1024];
  char * ptr;
  int resultlen;
  int loop_ub;
  emxArray_char_T *c_varargin_1;
  *info = 0;
  b_info = MPI_Finalized(&flag);
  emxInit_uint8_T(&varargin_1, 2);
  emxInit_char_T(&b_varargin_1, 2);
  if (b_info != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      memset(&msg0[0], 0, sizeof(unsigned char) << 10);
      ptr = (char *)(msg0);
      resultlen = 0;
      b_info = MPI_Error_string(b_info, ptr, &resultlen);
      if (1 > resultlen) {
        loop_ub = 0;
      } else {
        loop_ub = resultlen;
      }

      b_flag = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = 1;
      varargin_1->size[1] = loop_ub;
      emxEnsureCapacity((emxArray__common *)varargin_1, b_flag, (int)sizeof
                        (unsigned char));
      for (b_flag = 0; b_flag < loop_ub; b_flag++) {
        varargin_1->data[varargin_1->size[0] * b_flag] = msg0[b_flag];
      }

      if (b_info != 0) {
        b_flag = (M2C_DEBUG);
        if (b_flag != 0) {
          m2c_error(b_info);
        }
      }

      b_flag = b_varargin_1->size[0] * b_varargin_1->size[1];
      b_varargin_1->size[0] = 1;
      b_varargin_1->size[1] = (short)loop_ub;
      emxEnsureCapacity((emxArray__common *)b_varargin_1, b_flag, (int)sizeof
                        (char));
      loop_ub = (short)loop_ub;
      for (b_flag = 0; b_flag < loop_ub; b_flag++) {
        b_varargin_1->data[b_flag] = (signed char)varargin_1->data[b_flag];
      }

      b_m2c_error(b_varargin_1);
    }
  }

  emxFree_char_T(&b_varargin_1);
  if (!(flag != 0)) {
    *info = MPI_Finalize();
  }

  *toplevel = true;
  if (*info != 0) {
    memset(&msg0[0], 0, sizeof(unsigned char) << 10);
    ptr = (char *)(msg0);
    resultlen = 0;
    b_info = MPI_Error_string(*info, ptr, &resultlen);
    if (1 > resultlen) {
      loop_ub = 0;
    } else {
      loop_ub = resultlen;
    }

    b_flag = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)varargin_1, b_flag, (int)sizeof
                      (unsigned char));
    for (b_flag = 0; b_flag < loop_ub; b_flag++) {
      varargin_1->data[varargin_1->size[0] * b_flag] = msg0[b_flag];
    }

    if (b_info != 0) {
      flag = (M2C_DEBUG);
      if (flag != 0) {
        m2c_error(b_info);
      }
    }

    emxInit_char_T(&c_varargin_1, 2);
    b_flag = c_varargin_1->size[0] * c_varargin_1->size[1];
    c_varargin_1->size[0] = 1;
    c_varargin_1->size[1] = (short)loop_ub;
    emxEnsureCapacity((emxArray__common *)c_varargin_1, b_flag, (int)sizeof(char));
    loop_ub = (short)loop_ub;
    for (b_flag = 0; b_flag < loop_ub; b_flag++) {
      c_varargin_1->data[b_flag] = (signed char)varargin_1->data[b_flag];
    }

    c_m2c_error(c_varargin_1);
    emxFree_char_T(&c_varargin_1);
  }

  emxFree_uint8_T(&varargin_1);
}

void mpi_Finalize_initialize(void)
{
}

void mpi_Finalize_terminate(void)
{
}
