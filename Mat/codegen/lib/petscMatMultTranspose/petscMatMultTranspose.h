#ifndef PETSCMATMULTTRANSPOSE_H
#define PETSCMATMULTTRANSPOSE_H

#include "petscMatMultTranspose_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatMultTranspose(const M2C_OpaqueType *A,
                                  const M2C_OpaqueType *x,
                                  const M2C_OpaqueType *y, int *errCode,
                                  boolean_T *toplevel);

extern void petscMatMultTranspose_initialize(void);

extern void petscMatMultTranspose_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
