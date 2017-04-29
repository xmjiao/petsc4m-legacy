#ifndef PETSCKSPGETTOTALITERATIONS_H
#define PETSCKSPGETTOTALITERATIONS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPGetTotalIterations_types.h"

extern void petscKSPGetTotalIterations(const struct0_T *ksp, int *its, int
  *errCode, boolean_T *toplevel);
extern void petscKSPGetTotalIterations_initialize(void);
extern void petscKSPGetTotalIterations_terminate(void);

#endif
