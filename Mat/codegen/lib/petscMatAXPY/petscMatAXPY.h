#ifndef PETSCMATAXPY_H
#define PETSCMATAXPY_H

#include "petscMatAXPY_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatAXPY(const M2C_OpaqueType *Y, float a,
                         const M2C_OpaqueType *X, int mstr, int *errCode,
                         boolean_T *toplevel);

extern void petscMatAXPY_3args(const M2C_OpaqueType *Y, float a,
                               const M2C_OpaqueType *X, int *errCode,
                               boolean_T *toplevel);

extern void petscMatAXPY_initialize(void);

extern void petscMatAXPY_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
