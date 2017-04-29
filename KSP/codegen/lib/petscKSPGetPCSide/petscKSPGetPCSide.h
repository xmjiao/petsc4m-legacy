#ifndef PETSCKSPGETPCSIDE_H
#define PETSCKSPGETPCSIDE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPGetPCSide_types.h"

extern void petscKSPGetPCSide(const struct0_T *ksp, int *side, int *errCode,
  boolean_T *toplevel);
extern void petscKSPGetPCSide_initialize(void);
extern void petscKSPGetPCSide_terminate(void);

#endif
