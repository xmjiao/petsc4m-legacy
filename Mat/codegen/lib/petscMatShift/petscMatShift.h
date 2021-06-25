#ifndef PETSCMATSHIFT_H
#define PETSCMATSHIFT_H

#include "petscMatShift_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatShift(const M2C_OpaqueType *Y, float a, int *errCode,
                          boolean_T *toplevel);

extern void petscMatShift_initialize(void);

extern void petscMatShift_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
