#ifndef PETSCKSPBUILDRESIDUAL_H
#define PETSCKSPBUILDRESIDUAL_H

#include "petscKSPBuildResidual_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPBuildResidual(const M2C_OpaqueType *ksp,
                                  const M2C_OpaqueType *v, int *errCode,
                                  boolean_T *toplevel);

extern void petscKSPBuildResidual_initialize(void);

extern void petscKSPBuildResidual_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
