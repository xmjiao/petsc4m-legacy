#ifndef PETSCVECGETVALUES_H
#define PETSCVECGETVALUES_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscVecGetValues_types.h"

extern void petscVecGetValues(const struct0_T *vec, int ni, const
  emxArray_int32_T *ix, emxArray_real_T *y, int *errCode, boolean_T *toplevel);
extern void petscVecGetValues_Alloc(const struct0_T *vec, int ni, const
  emxArray_int32_T *ix, emxArray_real_T *y, int *errCode, boolean_T *toplevel);
extern void petscVecGetValues_initialize(void);
extern void petscVecGetValues_terminate(void);

#endif
