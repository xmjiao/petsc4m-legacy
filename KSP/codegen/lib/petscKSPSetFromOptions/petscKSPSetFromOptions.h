#ifndef PETSCKSPSETFROMOPTIONS_H
#define PETSCKSPSETFROMOPTIONS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPSetFromOptions_types.h"

extern void petscKSPSetFromOptions(const struct0_T *ksp, int *errCode, boolean_T
  *toplevel);
extern void petscKSPSetFromOptions_initialize(void);
extern void petscKSPSetFromOptions_terminate(void);

#endif
