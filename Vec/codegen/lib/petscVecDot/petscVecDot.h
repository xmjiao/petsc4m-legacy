#ifndef PETSCVECDOT_H
#define PETSCVECDOT_H

#include "petscVecDot_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecDot(const M2C_OpaqueType *x, const M2C_OpaqueType *y,
                        float *val, int *errCode, boolean_T *toplevel);

extern void petscVecDot_initialize(void);

extern void petscVecDot_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
