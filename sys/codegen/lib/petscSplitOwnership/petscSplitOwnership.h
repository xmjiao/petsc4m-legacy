#ifndef PETSCSPLITOWNERSHIP_H
#define PETSCSPLITOWNERSHIP_H

#include "petscSplitOwnership_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscSplitOwnership(const M2C_OpaqueType *comm, int *n, int *N,
                                int *errCode, boolean_T *toplevel);

extern void petscSplitOwnership_initialize(void);

extern void petscSplitOwnership_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
