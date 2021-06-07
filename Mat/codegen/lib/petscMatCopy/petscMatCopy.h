#ifndef PETSCMATCOPY_H
#define PETSCMATCOPY_H

#include "petscMatCopy_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatCopy(const M2C_OpaqueType *A, const M2C_OpaqueType *B,
                         int mstr, int *errCode, boolean_T *toplevel);

extern void petscMatCopy_2args(const M2C_OpaqueType *A, const M2C_OpaqueType *B,
                               int *errCode, boolean_T *toplevel);

extern void petscMatCopy_initialize(void);

extern void petscMatCopy_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
