#ifndef PETSCKSPGETCONVERGEDREASON_H
#define PETSCKSPGETCONVERGEDREASON_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPGetConvergedReason_types.h"

extern void petscKSPGetConvergedReason(const struct0_T *ksp, int *flag, int
  *errCode, boolean_T *toplevel);
extern void petscKSPGetConvergedReason_initialize(void);
extern void petscKSPGetConvergedReason_terminate(void);

#endif
