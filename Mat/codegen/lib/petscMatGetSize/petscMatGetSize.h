#ifndef PETSCMATGETSIZE_H
#define PETSCMATGETSIZE_H

#include "petscMatGetSize_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatGetSize(const M2C_OpaqueType *mat, int *m, int *n,
                            int *errCode, boolean_T *toplevel);

extern void petscMatGetSize_initialize(void);

extern void petscMatGetSize_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
