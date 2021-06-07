#ifndef PETSCVECDESTROY_H
#define PETSCVECDESTROY_H

#include "petscVecDestroy_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecDestroy(M2C_OpaqueType *vec, int *errCode,
                            boolean_T *toplevel);

extern void petscVecDestroy_initialize(void);

extern void petscVecDestroy_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
