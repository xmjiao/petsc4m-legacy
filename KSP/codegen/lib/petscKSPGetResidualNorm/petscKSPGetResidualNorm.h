#ifndef PETSCKSPGETRESIDUALNORM_H
#define PETSCKSPGETRESIDUALNORM_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPGetResidualNorm_types.h"

extern void petscKSPGetResidualNorm(const struct0_T *ksp, double *rnorm, int
  *errCode, boolean_T *toplevel);
extern void petscKSPGetResidualNorm_initialize(void);
extern void petscKSPGetResidualNorm_terminate(void);

#endif
