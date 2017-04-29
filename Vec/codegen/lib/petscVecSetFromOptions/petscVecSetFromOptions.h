#ifndef PETSCVECSETFROMOPTIONS_H
#define PETSCVECSETFROMOPTIONS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecSetFromOptions_types.h"

extern void petscVecSetFromOptions(const struct0_T *vec, int *errCode, boolean_T
  *toplevel);
extern void petscVecSetFromOptions_initialize(void);
extern void petscVecSetFromOptions_terminate(void);

#endif
