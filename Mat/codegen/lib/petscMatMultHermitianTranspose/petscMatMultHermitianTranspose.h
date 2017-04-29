#ifndef PETSCMATMULTHERMITIANTRANSPOSE_H
#define PETSCMATMULTHERMITIANTRANSPOSE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatMultHermitianTranspose_types.h"

extern void petscMatMultHermitianTranspose(const struct0_T *A, const struct0_T
  *x, const struct0_T *y, int *errCode, boolean_T *toplevel);
extern void petscMatMultHermitianTranspose_initialize(void);
extern void petscMatMultHermitianTranspose_terminate(void);

#endif
