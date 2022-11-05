#ifndef PETSCBARRIER_H
#define PETSCBARRIER_H

#include "petscBarrier_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscBarrier(const M2C_OpaqueType *obj, int *errCode,
                         boolean_T *toplevel);

extern void petscBarrier0(int *errCode, boolean_T *topLevel);

extern void petscBarrier_initialize(void);

extern void petscBarrier_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
