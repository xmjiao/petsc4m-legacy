#ifndef PETSCKSPGETTOTALITERATIONS_H
#define PETSCKSPGETTOTALITERATIONS_H

#include "petscKSPGetTotalIterations_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetTotalIterations(const M2C_OpaqueType *ksp, int *its,
                                       int *errCode, boolean_T *toplevel);

extern void petscKSPGetTotalIterations_initialize(void);

extern void petscKSPGetTotalIterations_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
