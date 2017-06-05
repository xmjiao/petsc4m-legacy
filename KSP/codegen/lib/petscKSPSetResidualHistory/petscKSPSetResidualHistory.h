#ifndef PETSCKSPSETRESIDUALHISTORY_H
#define PETSCKSPSETRESIDUALHISTORY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPSetResidualHistory_types.h"

extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_uint8_T *emxCreateND_uint8_T(int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_uint8_T *emxCreateWrapperND_uint8_T(unsigned char *data, int
  numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_uint8_T *emxCreateWrapper_uint8_T(unsigned char *data, int rows,
  int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern emxArray_uint8_T *emxCreate_uint8_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxDestroyArray_uint8_T(emxArray_uint8_T *emxArray);
extern void emxDestroy_struct0_T(struct0_T emxArray);
extern void emxInit_struct0_T(struct0_T *pStruct);
extern void petscKSPSetResidualHistory(const struct0_T *ksp, int *errCode,
  boolean_T *toplevel);
extern void petscKSPSetResidualHistory_2args(const struct0_T *ksp, int na, int
  *errCode, boolean_T *toplevel);
extern void petscKSPSetResidualHistory_3args(const struct0_T *ksp, int na, int
  reset, int *errCode, boolean_T *toplevel);
extern void petscKSPSetResidualHistory_initialize(void);
extern void petscKSPSetResidualHistory_terminate(void);

#endif
