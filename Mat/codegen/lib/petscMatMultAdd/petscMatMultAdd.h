#ifndef PETSCMATMULTADD_H
#define PETSCMATMULTADD_H

#include "petscMatMultAdd_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatMultAdd(const M2C_OpaqueType *A, const M2C_OpaqueType *v1,
                            const M2C_OpaqueType *v2, const M2C_OpaqueType *v3,
                            int *errCode, boolean_T *toplevel);

extern void petscMatMultAdd_initialize(void);

extern void petscMatMultAdd_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
