#ifndef PETSCMATGETNEARNULLSPACE_H
#define PETSCMATGETNEARNULLSPACE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatGetNearNullSpace_types.h"

extern void petscMatGetNearNullSpace(const struct0_T *mat, struct0_T *nullsp,
  int *errCode, boolean_T *toplevel);
extern void petscMatGetNearNullSpace_initialize(void);
extern void petscMatGetNearNullSpace_terminate(void);

#endif
