#ifndef PETSCVECSETVALUES_H
#define PETSCVECSETVALUES_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecSetValues_types.h"

extern void petscVecSetValues(const struct0_T *vec, int ni, const
  emxArray_int32_T *ix, const emxArray_real_T *y, int iroa, int *errCode,
  boolean_T *toplevel);
extern void petscVecSetValues_Insert(const struct0_T *vec, int ni, const
  emxArray_int32_T *ix, const emxArray_real_T *y, int *errCode, boolean_T
  *toplevel);
extern void petscVecSetValues_initialize(void);
extern void petscVecSetValues_terminate(void);

#endif
