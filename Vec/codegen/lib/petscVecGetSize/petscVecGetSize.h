#ifndef PETSCVECGETSIZE_H
#define PETSCVECGETSIZE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecGetSize_types.h"

extern void petscVecGetSize(const struct0_T *vec, int *n, int *errCode,
  boolean_T *toplevel);
extern void petscVecGetSize_initialize(void);
extern void petscVecGetSize_terminate(void);

#endif
