#ifndef PETSCMATNULLSPACESETFUNCTION_H
#define PETSCMATNULLSPACESETFUNCTION_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatNullSpaceSetFunction_types.h"

extern void petscMatNullSpaceSetFunction(const struct0_T *nullSp, const
  struct0_T *rmvFunc, const struct1_T *ctx, int *errCode, boolean_T *toplevel);
extern void petscMatNullSpaceSetFunction_initialize(void);
extern void petscMatNullSpaceSetFunction_terminate(void);

#endif
