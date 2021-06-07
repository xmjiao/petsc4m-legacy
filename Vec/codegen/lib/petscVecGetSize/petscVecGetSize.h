#ifndef PETSCVECGETSIZE_H
#define PETSCVECGETSIZE_H

#include "petscVecGetSize_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecGetSize(const M2C_OpaqueType *vec, int *n, int *errCode,
                            boolean_T *toplevel);

extern void petscVecGetSize_initialize(void);

extern void petscVecGetSize_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
