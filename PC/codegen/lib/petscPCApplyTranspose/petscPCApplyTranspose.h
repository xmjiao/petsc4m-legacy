#ifndef PETSCPCAPPLYTRANSPOSE_H
#define PETSCPCAPPLYTRANSPOSE_H

#include "petscPCApplyTranspose_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCApplyTranspose(const M2C_OpaqueType *pc,
                                  const M2C_OpaqueType *b,
                                  const M2C_OpaqueType *x, int *errCode,
                                  boolean_T *toplevel);

extern void petscPCApplyTranspose_2args(const M2C_OpaqueType *ksp,
                                        const M2C_OpaqueType *b, int *errCode,
                                        boolean_T *toplevel);

extern void petscPCApplyTranspose_initialize(void);

extern void petscPCApplyTranspose_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
