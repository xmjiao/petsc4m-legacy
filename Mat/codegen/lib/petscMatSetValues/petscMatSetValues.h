#ifndef PETSCMATSETVALUES_H
#define PETSCMATSETVALUES_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatSetValues_types.h"

extern void petscMatSetValues(const struct0_T *mat, int ni, const
  emxArray_int32_T *ix, int nj, const emxArray_int32_T *jx, const
  emxArray_real_T *v, int iroa, int *errCode, boolean_T *toplevel);
extern void petscMatSetValues_Insert(const struct0_T *mat, int ni, const
  emxArray_int32_T *ix, int nj, const emxArray_int32_T *jx, const
  emxArray_real_T *v, int *errCode, boolean_T *toplevel);
extern void petscMatSetValues_initialize(void);
extern void petscMatSetValues_terminate(void);

#endif
