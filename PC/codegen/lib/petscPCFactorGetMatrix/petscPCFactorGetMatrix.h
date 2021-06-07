#ifndef PETSCPCFACTORGETMATRIX_H
#define PETSCPCFACTORGETMATRIX_H

#include "petscPCFactorGetMatrix_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCFactorGetMatrix(const M2C_OpaqueType *pc,
                                   M2C_OpaqueType *mat, int *errCode,
                                   boolean_T *toplevel);

extern void petscPCFactorGetMatrix_initialize(void);

extern void petscPCFactorGetMatrix_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
