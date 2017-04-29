#ifndef PETSCVECCOPY_H
#define PETSCVECCOPY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecCopy_types.h"

extern void petscVecCopy(const struct0_T *x, const struct0_T *y, int *errCode,
  boolean_T *toplevel);
extern void petscVecCopy_initialize(void);
extern void petscVecCopy_terminate(void);

#endif
