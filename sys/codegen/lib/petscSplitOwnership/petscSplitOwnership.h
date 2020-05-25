#ifndef PETSCSPLITOWNERSHIP_H
#define PETSCSPLITOWNERSHIP_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscSplitOwnership_types.h"

extern void petscSplitOwnership(const struct0_T *comm, int *n, int *N, int
  *errCode, boolean_T *toplevel);
extern void petscSplitOwnership_initialize(void);
extern void petscSplitOwnership_terminate(void);

#endif
