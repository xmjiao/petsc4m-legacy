#ifndef PETSCKSPGETINITIALGUESSNONZERO_H
#define PETSCKSPGETINITIALGUESSNONZERO_H

#include "petscKSPGetInitialGuessNonzero_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetInitialGuessNonzero(const M2C_OpaqueType *ksp, int *flag,
                                           int *errCode, boolean_T *toplevel);

extern void petscKSPGetInitialGuessNonzero_initialize(void);

extern void petscKSPGetInitialGuessNonzero_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
