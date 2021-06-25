#ifndef PETSCVECAYPX_H
#define PETSCVECAYPX_H

#include "petscVecAYPX_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecAYPX(const M2C_OpaqueType *y, float a,
                         const M2C_OpaqueType *x, int *errCode,
                         boolean_T *toplevel);

extern void petscVecAYPX_initialize(void);

extern void petscVecAYPX_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
