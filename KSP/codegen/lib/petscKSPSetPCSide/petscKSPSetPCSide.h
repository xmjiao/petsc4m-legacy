#ifndef PETSCKSPSETPCSIDE_H
#define PETSCKSPSETPCSIDE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPSetPCSide_types.h"

extern void petscKSPSetPCSide(const struct0_T *ksp, int side, int *errCode,
  boolean_T *toplevel);
extern void petscKSPSetPCSide_initialize(void);
extern void petscKSPSetPCSide_terminate(void);

#endif
