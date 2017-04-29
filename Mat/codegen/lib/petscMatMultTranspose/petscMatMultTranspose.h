#ifndef PETSCMATMULTTRANSPOSE_H
#define PETSCMATMULTTRANSPOSE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatMultTranspose_types.h"

extern void petscMatMultTranspose(const struct0_T *A, const struct0_T *x, const
  struct0_T *y, int *errCode, boolean_T *toplevel);
extern void petscMatMultTranspose_initialize(void);
extern void petscMatMultTranspose_terminate(void);

#endif
