#ifndef PETSCVECSETVALUES_H
#define PETSCVECSETVALUES_H

#include "petscVecSetValues_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecSetValues(const M2C_OpaqueType *vec, int ni,
                              const emxArray_int32_T *ix,
                              const emxArray_real32_T *y, int iroa,
                              int *errCode, boolean_T *toplevel);

extern void petscVecSetValues_Insert(const M2C_OpaqueType *vec, int ni,
                                     const emxArray_int32_T *ix,
                                     const emxArray_real32_T *y, int *errCode,
                                     boolean_T *toplevel);

extern void petscVecSetValues_initialize(void);

extern void petscVecSetValues_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
