#ifndef PETSCKSPGETITERATIONNUMBER_H
#define PETSCKSPGETITERATIONNUMBER_H

#include "petscKSPGetIterationNumber_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetIterationNumber(const M2C_OpaqueType *ksp, int *its,
                                       int *errCode, boolean_T *toplevel);

extern void petscKSPGetIterationNumber_initialize(void);

extern void petscKSPGetIterationNumber_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
