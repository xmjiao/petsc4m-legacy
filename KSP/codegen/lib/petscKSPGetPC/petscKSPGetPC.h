#ifndef PETSCKSPGETPC_H
#define PETSCKSPGETPC_H

#include "petscKSPGetPC_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetPC(const M2C_OpaqueType *ksp, M2C_OpaqueType *pc,
                          int *errCode, boolean_T *toplevel);

extern void petscKSPGetPC_initialize(void);

extern void petscKSPGetPC_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
