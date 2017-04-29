#ifndef PETSCVECSETTYPE_H
#define PETSCVECSETTYPE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecSetType_types.h"

extern void petscVecSetType(const struct0_T *vec, const emxArray_char_T *type,
  int *errCode, boolean_T *toplevel);
extern void petscVecSetType_initialize(void);
extern void petscVecSetType_terminate(void);

#endif
