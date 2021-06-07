#ifndef PETSCKSPSETINITIALGUESSNONZERO_H
#define PETSCKSPSETINITIALGUESSNONZERO_H

#include "petscKSPSetInitialGuessNonzero_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPSetInitialGuessNonzero(const M2C_OpaqueType *ksp, int flag,
                                           int *errCode, boolean_T *toplevel);

extern void petscKSPSetInitialGuessNonzero_initialize(void);

extern void petscKSPSetInitialGuessNonzero_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
