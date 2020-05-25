#ifndef PETSCVECSET_H
#define PETSCVECSET_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscVecSet_types.h"

extern void petscVecSet(const struct0_T *vec, double val, int *errCode,
  boolean_T *toplevel);
extern void petscVecSet_initialize(void);
extern void petscVecSet_terminate(void);

#endif
