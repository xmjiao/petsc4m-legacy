#ifndef PETSCVECGETLOCALSIZE_H
#define PETSCVECGETLOCALSIZE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecGetLocalSize_types.h"

extern void petscVecGetLocalSize(const struct0_T *vec, int *n, int *errCode,
  boolean_T *toplevel);
extern void petscVecGetLocalSize_initialize(void);
extern void petscVecGetLocalSize_terminate(void);

#endif
