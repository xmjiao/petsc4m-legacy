#ifndef PETSCKSPSETTOLERANCES_H
#define PETSCKSPSETTOLERANCES_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPSetTolerances_types.h"

extern void petscKSPSetTolerances(const struct0_T *ksp, double rtol, double
  abstol, double dtol, int maxits, int *errCode, boolean_T *toplevel);
extern void petscKSPSetTolerances_2args(const struct0_T *ksp, double rtol, int
  *errCode, boolean_T *toplevel);
extern void petscKSPSetTolerances_initialize(void);
extern void petscKSPSetTolerances_terminate(void);

#endif
