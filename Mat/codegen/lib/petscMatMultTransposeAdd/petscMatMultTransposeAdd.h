#ifndef PETSCMATMULTTRANSPOSEADD_H
#define PETSCMATMULTTRANSPOSEADD_H

#include "petscMatMultTransposeAdd_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatMultTransposeAdd(const M2C_OpaqueType *A,
                                     const M2C_OpaqueType *v1,
                                     const M2C_OpaqueType *v2,
                                     const M2C_OpaqueType *v3, int *errCode,
                                     boolean_T *toplevel);

extern void petscMatMultTransposeAdd_initialize(void);

extern void petscMatMultTransposeAdd_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
