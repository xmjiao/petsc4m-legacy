#ifndef PETSCKSPGETITERATIONNUMBER_H
#define PETSCKSPGETITERATIONNUMBER_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPGetIterationNumber_types.h"

extern void petscKSPGetIterationNumber(const struct0_T *ksp, int *its, int
  *errCode, boolean_T *toplevel);
extern void petscKSPGetIterationNumber_initialize(void);
extern void petscKSPGetIterationNumber_terminate(void);

#endif
