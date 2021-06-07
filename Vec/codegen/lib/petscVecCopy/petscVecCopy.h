#ifndef PETSCVECCOPY_H
#define PETSCVECCOPY_H

#include "petscVecCopy_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecCopy(const M2C_OpaqueType *x, const M2C_OpaqueType *y,
                         int *errCode, boolean_T *toplevel);

extern void petscVecCopy_initialize(void);

extern void petscVecCopy_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
