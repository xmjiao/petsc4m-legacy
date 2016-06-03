#ifndef PETSCMATCREATESEQAIJ_H
#define PETSCMATCREATESEQAIJ_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatCreateSeqAIJ_types.h"

extern emxArray_int32_T *emxCreateND_int32_T(int numDimensions, int *size);
extern emxArray_uint8_T *emxCreateND_uint8_T(int numDimensions, int *size);
extern emxArray_int32_T *emxCreateWrapperND_int32_T(int *data, int numDimensions,
  int *size);
extern emxArray_uint8_T *emxCreateWrapperND_uint8_T(unsigned char *data, int
  numDimensions, int *size);
extern emxArray_int32_T *emxCreateWrapper_int32_T(int *data, int rows, int cols);
extern emxArray_uint8_T *emxCreateWrapper_uint8_T(unsigned char *data, int rows,
  int cols);
extern emxArray_int32_T *emxCreate_int32_T(int rows, int cols);
extern emxArray_uint8_T *emxCreate_uint8_T(int rows, int cols);
extern void emxDestroyArray_int32_T(emxArray_int32_T *emxArray);
extern void emxDestroyArray_uint8_T(emxArray_uint8_T *emxArray);
extern void emxDestroy_struct0_T(struct0_T emxArray);
extern void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_struct0_T(struct0_T *pStruct);
extern void petscMatCreateSeqAIJ(int m, int n, int nz, const emxArray_int32_T
  *nnz, struct0_T *mat, int *errCode, boolean_T *toplevel);
extern void petscMatCreateSeqAIJ_FixedRows(int m, int n, int nz, struct0_T *mat,
  int *errCode, boolean_T *topleve);
extern void petscMatCreateSeqAIJ_initialize(void);
extern void petscMatCreateSeqAIJ_terminate(void);

#endif
