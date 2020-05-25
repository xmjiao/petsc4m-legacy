#ifndef PETSCMATCOPY_H
#define PETSCMATCOPY_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatCopy_types.h"

extern void petscMatCopy(const struct0_T *A, const struct0_T *B, int mstr, int
  *errCode, boolean_T *toplevel);
extern void petscMatCopy_2args(const struct0_T *A, const struct0_T *B, int
  *errCode, boolean_T *toplevel);
extern void petscMatCopy_initialize(void);
extern void petscMatCopy_terminate(void);

#endif
