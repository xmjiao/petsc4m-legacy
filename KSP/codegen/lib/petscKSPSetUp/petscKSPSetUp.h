#ifndef PETSCKSPSETUP_H
#define PETSCKSPSETUP_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPSetUp_types.h"

extern void petscKSPSetUp(const struct0_T *ksp, int *errCode, boolean_T
  *toplevel);
extern void petscKSPSetUp_initialize(void);
extern void petscKSPSetUp_terminate(void);

#endif
