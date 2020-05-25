#ifndef PETSCMATSETFROMOPTIONS_H
#define PETSCMATSETFROMOPTIONS_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatSetFromOptions_types.h"

extern void petscMatSetFromOptions(const struct0_T *mat, int *errCode, boolean_T
  *toplevel);
extern void petscMatSetFromOptions_initialize(void);
extern void petscMatSetFromOptions_terminate(void);

#endif
