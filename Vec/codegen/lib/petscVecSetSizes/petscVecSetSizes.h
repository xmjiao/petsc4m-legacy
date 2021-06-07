#ifndef PETSCVECSETSIZES_H
#define PETSCVECSETSIZES_H

#include "petscVecSetSizes_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecSetSizes(const M2C_OpaqueType *vec, int n, int N,
                             int *errCode, boolean_T *toplevel);

extern void petscVecSetSizes_Local(const M2C_OpaqueType *vec, int n,
                                   int *errCode, boolean_T *toplevel);

extern void petscVecSetSizes_initialize(void);

extern void petscVecSetSizes_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
