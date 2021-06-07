#ifndef PETSCVECCREATE_H
#define PETSCVECCREATE_H

#include "petscVecCreate_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecCreate(const M2C_OpaqueType *comm, M2C_OpaqueType *vec,
                           int *errCode, boolean_T *toplevel);

extern void petscVecCreate_World(M2C_OpaqueType *vec, int *errCode,
                                 boolean_T *topleve);

extern void petscVecCreate_initialize(void);

extern void petscVecCreate_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
