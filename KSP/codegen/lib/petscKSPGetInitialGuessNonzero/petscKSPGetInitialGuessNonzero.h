#ifndef PETSCKSPGETINITIALGUESSNONZERO_H
#define PETSCKSPGETINITIALGUESSNONZERO_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPGetInitialGuessNonzero_types.h"

extern void petscKSPGetInitialGuessNonzero(const struct0_T *ksp, int *flag, int *
  errCode, boolean_T *toplevel);
extern void petscKSPGetInitialGuessNonzero_initialize(void);
extern void petscKSPGetInitialGuessNonzero_terminate(void);

#endif
