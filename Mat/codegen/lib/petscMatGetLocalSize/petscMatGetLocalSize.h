#ifndef PETSCMATGETLOCALSIZE_H
#define PETSCMATGETLOCALSIZE_H

#include "petscMatGetLocalSize_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatGetLocalSize(const M2C_OpaqueType *mat, int *m, int *n,
                                 int *errCode, boolean_T *toplevel);

extern void petscMatGetLocalSize_initialize(void);

extern void petscMatGetLocalSize_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
