#ifndef PETSCVECDOT_H
#define PETSCVECDOT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecDot_types.h"

extern void petscVecDot(const struct0_T *x, const struct0_T *y, double *val, int
  *errCode, boolean_T *toplevel);
extern void petscVecDot_initialize(void);
extern void petscVecDot_terminate(void);

#endif
