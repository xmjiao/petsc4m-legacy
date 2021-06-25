#ifndef PETSCVECAXPY_H
#define PETSCVECAXPY_H

#include "petscVecAXPY_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecAXPY(const M2C_OpaqueType *y, float a,
                         const M2C_OpaqueType *x, int *errCode,
                         boolean_T *toplevel);

extern void petscVecAXPY_initialize(void);

extern void petscVecAXPY_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
