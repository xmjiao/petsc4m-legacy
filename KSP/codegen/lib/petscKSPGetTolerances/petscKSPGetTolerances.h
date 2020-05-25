#ifndef PETSCKSPGETTOLERANCES_H
#define PETSCKSPGETTOLERANCES_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPGetTolerances_types.h"

extern void petscKSPGetTolerances(const struct0_T *ksp, double *rtol, double
  *abstol, double *dtol, int *maxits, int *errCode, boolean_T *toplevel);
extern void petscKSPGetTolerances_initialize(void);
extern void petscKSPGetTolerances_terminate(void);

#endif
