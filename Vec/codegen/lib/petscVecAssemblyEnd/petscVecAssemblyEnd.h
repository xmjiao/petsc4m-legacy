#ifndef PETSCVECASSEMBLYEND_H
#define PETSCVECASSEMBLYEND_H

#include "petscVecAssemblyEnd_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecAssemblyEnd(const M2C_OpaqueType *vec, int *errCode,
                                boolean_T *toplevel);

extern void petscVecAssemblyEnd_initialize(void);

extern void petscVecAssemblyEnd_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
