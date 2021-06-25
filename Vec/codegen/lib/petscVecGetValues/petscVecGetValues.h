#ifndef PETSCVECGETVALUES_H
#define PETSCVECGETVALUES_H

#include "petscVecGetValues_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecGetValues(const M2C_OpaqueType *vec, int ni,
                              const emxArray_int32_T *ix, emxArray_real32_T *y,
                              int *errCode, boolean_T *toplevel);

extern void petscVecGetValues_Alloc(const M2C_OpaqueType *vec, int ni,
                                    const emxArray_int32_T *ix,
                                    emxArray_real32_T *y, int *errCode,
                                    boolean_T *toplevel);

extern void petscVecGetValues_initialize(void);

extern void petscVecGetValues_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
