#ifndef PETSCMATAXPY_H
#define PETSCMATAXPY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatAXPY_types.h"

extern void petscMatAXPY(const struct0_T *Y, double a, const struct0_T *X, int
  mstr, int *errCode, boolean_T *toplevel);
extern void petscMatAXPY_3args(const struct0_T *Y, double a, const struct0_T *X,
  int *errCode, boolean_T *toplevel);
extern void petscMatAXPY_initialize(void);
extern void petscMatAXPY_terminate(void);

#endif
