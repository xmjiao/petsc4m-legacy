#ifndef PETSCMATMULTHERMITIANTRANSPOSE_H
#define PETSCMATMULTHERMITIANTRANSPOSE_H

#include "petscMatMultHermitianTranspose_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatMultHermitianTranspose(const M2C_OpaqueType *A,
                                           const M2C_OpaqueType *x,
                                           const M2C_OpaqueType *y,
                                           int *errCode, boolean_T *toplevel);

extern void petscMatMultHermitianTranspose_initialize(void);

extern void petscMatMultHermitianTranspose_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
