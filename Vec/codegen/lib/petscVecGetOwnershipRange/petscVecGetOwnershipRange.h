#ifndef PETSCVECGETOWNERSHIPRANGE_H
#define PETSCVECGETOWNERSHIPRANGE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscVecGetOwnershipRange_types.h"

extern void petscVecGetOwnershipRange(const struct0_T *vec, int *first_row, int *
  last_row, int *errCode, boolean_T *toplevel);
extern void petscVecGetOwnershipRange_initialize(void);
extern void petscVecGetOwnershipRange_terminate(void);

#endif
