#ifndef PETSCVECAYPX_H
#define PETSCVECAYPX_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscVecAYPX_types.h"

extern void petscVecAYPX(const struct0_T *y, double a, const struct0_T *x, int
  *errCode, boolean_T *toplevel);
extern void petscVecAYPX_initialize(void);
extern void petscVecAYPX_terminate(void);

#endif
