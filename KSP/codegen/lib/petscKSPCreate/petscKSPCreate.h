#ifndef PETSCKSPCREATE_H
#define PETSCKSPCREATE_H

#include "petscKSPCreate_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPCreate(const M2C_OpaqueType *comm, M2C_OpaqueType *ksp,
                           int *errCode, boolean_T *toplevel);

extern void petscKSPCreate_World(M2C_OpaqueType *ksp, int *errCode,
                                 boolean_T *toplevel);

extern void petscKSPCreate_initialize(void);

extern void petscKSPCreate_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
