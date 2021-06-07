#ifndef PETSCMATGETOWNERSHIPRANGE_H
#define PETSCMATGETOWNERSHIPRANGE_H

#include "petscMatGetOwnershipRange_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatGetOwnershipRange(const M2C_OpaqueType *mat, int *first_row,
                                      int *last_row, int *errCode,
                                      boolean_T *toplevel);

extern void petscMatGetOwnershipRange_initialize(void);

extern void petscMatGetOwnershipRange_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
