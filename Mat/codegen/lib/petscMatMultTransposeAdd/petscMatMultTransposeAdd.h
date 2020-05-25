#ifndef PETSCMATMULTTRANSPOSEADD_H
#define PETSCMATMULTTRANSPOSEADD_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatMultTransposeAdd_types.h"

extern void petscMatMultTransposeAdd(const struct0_T *A, const struct0_T *v1,
  const struct0_T *v2, const struct0_T *v3, int *errCode, boolean_T *toplevel);
extern void petscMatMultTransposeAdd_initialize(void);
extern void petscMatMultTransposeAdd_terminate(void);

#endif
