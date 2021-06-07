#ifndef PETSCMATSETSIZES_H
#define PETSCMATSETSIZES_H

#include "petscMatSetSizes_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatSetSizes(const M2C_OpaqueType *mat, int m, int n, int M,
                             int N, int *errCode, boolean_T *toplevel);

extern void petscMatSetSizes_Local(const M2C_OpaqueType *mat, int m, int n,
                                   int *errCode, boolean_T *toplevel);

extern void petscMatSetSizes_initialize(void);

extern void petscMatSetSizes_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
