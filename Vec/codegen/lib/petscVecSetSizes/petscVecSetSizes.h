#ifndef PETSCVECSETSIZES_H
#define PETSCVECSETSIZES_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecSetSizes_types.h"

extern void petscVecSetSizes(const struct0_T *vec, int n, int N, int *errCode,
  boolean_T *toplevel);
extern void petscVecSetSizes_Local(const struct0_T *vec, int n, int *errCode,
  boolean_T *toplevel);
extern void petscVecSetSizes_initialize(void);
extern void petscVecSetSizes_terminate(void);

#endif
