#ifndef PETSCVECGETOWNERSHIPRANGE_H
#define PETSCVECGETOWNERSHIPRANGE_H

#include "petscVecGetOwnershipRange_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecGetOwnershipRange(const M2C_OpaqueType *vec, int *first_row,
                                      int *last_row, int *errCode,
                                      boolean_T *toplevel);

extern void petscVecGetOwnershipRange_initialize(void);

extern void petscVecGetOwnershipRange_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
