#ifndef PETSCKSPBUILDRESIDUAL_H
#define PETSCKSPBUILDRESIDUAL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPBuildResidual_types.h"

extern void petscKSPBuildResidual(const struct0_T *ksp, const struct0_T *v, int *
  errCode, boolean_T *toplevel);
extern void petscKSPBuildResidual_initialize(void);
extern void petscKSPBuildResidual_terminate(void);

#endif
