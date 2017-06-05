#ifndef PETSCGETOBJECT_H
#define PETSCGETOBJECT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscGetObject_types.h"

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
extern void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern void emxInit_struct0_T(struct0_T *pStruct);
extern void petscGetObject(const emxArray_char_T *name, struct0_T *obj,
  boolean_T *toplevel);
extern void petscGetObject_initialize(void);
extern void petscGetObject_terminate(void);

#endif
