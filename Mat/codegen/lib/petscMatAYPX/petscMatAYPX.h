#ifndef PETSCMATAYPX_H
#define PETSCMATAYPX_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatAYPX_types.h"

extern void petscMatAYPX(const struct0_T *Y, double a, const struct0_T *X, int
  mstr, int *errCode, boolean_T *toplevel);
extern void petscMatAYPX_3args(const struct0_T *Y, double a, const struct0_T *X,
  int *errCode, boolean_T *toplevel);
extern void petscMatAYPX_initialize(void);
extern void petscMatAYPX_terminate(void);

#endif
