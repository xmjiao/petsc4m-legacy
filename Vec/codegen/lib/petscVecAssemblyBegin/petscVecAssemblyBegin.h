#ifndef PETSCVECASSEMBLYBEGIN_H
#define PETSCVECASSEMBLYBEGIN_H

#include "petscVecAssemblyBegin_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecAssemblyBegin(const M2C_OpaqueType *vec, int *errCode,
                                  boolean_T *toplevel);

extern void petscVecAssemblyBegin_initialize(void);

extern void petscVecAssemblyBegin_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
