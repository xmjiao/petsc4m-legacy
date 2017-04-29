#ifndef PETSCVECAXPY_H
#define PETSCVECAXPY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecAXPY_types.h"

extern void petscVecAXPY(const struct0_T *y, double a, const struct0_T *x, int
  *errCode, boolean_T *toplevel);
extern void petscVecAXPY_initialize(void);
extern void petscVecAXPY_terminate(void);

#endif
