#ifndef PETSCMATGETOWNERSHIPRANGE_H
#define PETSCMATGETOWNERSHIPRANGE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatGetOwnershipRange_types.h"

extern void petscMatGetOwnershipRange(const struct0_T *mat, int *first_row, int *
  last_row, int *errCode, boolean_T *toplevel);
extern void petscMatGetOwnershipRange_initialize(void);
extern void petscMatGetOwnershipRange_terminate(void);

#endif
