#ifndef PETSCOPTIONSGETBOOL_H
#define PETSCOPTIONSGETBOOL_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscOptionsGetBool_types.h"

extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern void petscOptionsGetBool(const emxArray_char_T *pre, const
  emxArray_char_T *name, int *value, int *found, int *errCode, boolean_T
  *toplevel);
extern void petscOptionsGetBool_initialize(void);
extern void petscOptionsGetBool_terminate(void);

#endif
