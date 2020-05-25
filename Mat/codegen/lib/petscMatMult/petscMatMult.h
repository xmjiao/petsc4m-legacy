#ifndef PETSCMATMULT_H
#define PETSCMATMULT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatMult_types.h"

extern void petscMatMult(const struct0_T *A, const struct0_T *x, const struct0_T
  *y, int *errCode, boolean_T *toplevel);
extern void petscMatMult_initialize(void);
extern void petscMatMult_terminate(void);

#endif
