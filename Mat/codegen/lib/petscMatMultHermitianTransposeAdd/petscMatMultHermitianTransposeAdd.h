#ifndef PETSCMATMULTHERMITIANTRANSPOSEADD_H
#define PETSCMATMULTHERMITIANTRANSPOSEADD_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatMultHermitianTransposeAdd_types.h"

extern void petscMatMultHermitianTransposeAdd(const struct0_T *A, const
  struct0_T *v1, const struct0_T *v2, const struct0_T *v3, int *errCode,
  boolean_T *toplevel);
extern void petscMatMultHermitianTransposeAdd_initialize(void);
extern void petscMatMultHermitianTransposeAdd_terminate(void);

#endif
