#ifndef PETSCMATGETVALUES_H
#define PETSCMATGETVALUES_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatGetValues_types.h"

extern void petscMatGetValues(const struct0_T *mat, int ni, const
  emxArray_int32_T *ix, int nj, const emxArray_int32_T *jx, emxArray_real_T *v,
  int *errCode, boolean_T *toplevel);
extern void petscMatGetValues_Alloc(const struct0_T *mat, int ni, const
  emxArray_int32_T *ix, int nj, const emxArray_int32_T *jx, emxArray_real_T *v,
  int *errCode, boolean_T *toplevel);
extern void petscMatGetValues_initialize(void);
extern void petscMatGetValues_terminate(void);

#endif
