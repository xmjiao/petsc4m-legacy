#ifndef PETSCKSPSOLVE_H
#define PETSCKSPSOLVE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPSolve_types.h"

extern void petscKSPSolve(const struct0_T *ksp, const struct0_T *b, const
  struct0_T *x, int *errCode, boolean_T *toplevel);
extern void petscKSPSolve_2args(const struct0_T *ksp, const struct0_T *b, int
  *errCode, boolean_T *toplevel);
extern void petscKSPSolve_initialize(void);
extern void petscKSPSolve_terminate(void);

#endif
