#ifndef PETSCKSPSETPC_H
#define PETSCKSPSETPC_H

#include "petscKSPSetPC_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPSetPC(const M2C_OpaqueType *ksp, const M2C_OpaqueType *pc,
                          int *errCode, boolean_T *toplevel);

extern void petscKSPSetPC_initialize(void);

extern void petscKSPSetPC_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
