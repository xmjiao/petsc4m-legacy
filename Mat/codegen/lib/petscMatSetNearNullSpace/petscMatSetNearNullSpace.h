#ifndef PETSCMATSETNEARNULLSPACE_H
#define PETSCMATSETNEARNULLSPACE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatSetNearNullSpace_types.h"

extern void petscMatSetNearNullSpace(const struct0_T *mat, const struct0_T
  *nullSp, int *errCode, boolean_T *toplevel);
extern void petscMatSetNearNullSpace_initialize(void);
extern void petscMatSetNearNullSpace_terminate(void);

#endif
