#ifndef PETSCVECSCALE_H
#define PETSCVECSCALE_H

#include "petscVecScale_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecScale(const M2C_OpaqueType *v, double a, int *errCode,
                          boolean_T *toplevel);

extern void petscVecScale_initialize(void);

extern void petscVecScale_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
