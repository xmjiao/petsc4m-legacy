#ifndef PETSCKSPSETINITIALGUESSNONZERO_H
#define PETSCKSPSETINITIALGUESSNONZERO_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPSetInitialGuessNonzero_types.h"

extern void petscKSPSetInitialGuessNonzero(const struct0_T *ksp, int flag, int
  *errCode, boolean_T *toplevel);
extern void petscKSPSetInitialGuessNonzero_initialize(void);
extern void petscKSPSetInitialGuessNonzero_terminate(void);

#endif
