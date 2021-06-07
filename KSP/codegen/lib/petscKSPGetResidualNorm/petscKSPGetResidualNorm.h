#ifndef PETSCKSPGETRESIDUALNORM_H
#define PETSCKSPGETRESIDUALNORM_H

#include "petscKSPGetResidualNorm_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetResidualNorm(const M2C_OpaqueType *ksp, double *rnorm,
                                    int *errCode, boolean_T *toplevel);

extern void petscKSPGetResidualNorm_initialize(void);

extern void petscKSPGetResidualNorm_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
