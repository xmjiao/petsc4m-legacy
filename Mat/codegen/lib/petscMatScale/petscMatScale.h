#ifndef PETSCMATSCALE_H
#define PETSCMATSCALE_H

#include "petscMatScale_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatScale(const M2C_OpaqueType *mat, float a, int *errCode,
                          boolean_T *toplevel);

extern void petscMatScale_initialize(void);

extern void petscMatScale_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
