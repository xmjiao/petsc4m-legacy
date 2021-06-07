#ifndef PETSCVECGETLOCALSIZE_H
#define PETSCVECGETLOCALSIZE_H

#include "petscVecGetLocalSize_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecGetLocalSize(const M2C_OpaqueType *vec, int *n,
                                 int *errCode, boolean_T *toplevel);

extern void petscVecGetLocalSize_initialize(void);

extern void petscVecGetLocalSize_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
