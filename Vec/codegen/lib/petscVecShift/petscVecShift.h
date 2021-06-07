#ifndef PETSCVECSHIFT_H
#define PETSCVECSHIFT_H

#include "petscVecShift_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecShift(const M2C_OpaqueType *v, double a, int *errCode,
                          boolean_T *toplevel);

extern void petscVecShift_initialize(void);

extern void petscVecShift_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
