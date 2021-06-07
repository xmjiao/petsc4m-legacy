#ifndef PETSCPCCREATE_H
#define PETSCPCCREATE_H

#include "petscPCCreate_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCCreate(const M2C_OpaqueType *comm, M2C_OpaqueType *pc,
                          int *errCode, boolean_T *toplevel);

extern void petscPCCreate_World(M2C_OpaqueType *ksp, int *errCode,
                                boolean_T *toplevel);

extern void petscPCCreate_initialize(void);

extern void petscPCCreate_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
