#ifndef PETSCMATGETTRANSPOSENULLSPACE_H
#define PETSCMATGETTRANSPOSENULLSPACE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatGetTransposeNullSpace_types.h"

extern void petscMatGetTransposeNullSpace(const struct0_T *mat, struct0_T
  *nullsp, int *errCode, boolean_T *toplevel);
extern void petscMatGetTransposeNullSpace_initialize(void);
extern void petscMatGetTransposeNullSpace_terminate(void);

#endif
