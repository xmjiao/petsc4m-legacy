#ifndef PETSCMATMULTHERMITIANTRANSPOSEADD_H
#define PETSCMATMULTHERMITIANTRANSPOSEADD_H

#include "petscMatMultHermitianTransposeAdd_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatMultHermitianTransposeAdd(
    const M2C_OpaqueType *A, const M2C_OpaqueType *v1, const M2C_OpaqueType *v2,
    const M2C_OpaqueType *v3, int *errCode, boolean_T *toplevel);

extern void petscMatMultHermitianTransposeAdd_initialize(void);

extern void petscMatMultHermitianTransposeAdd_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
