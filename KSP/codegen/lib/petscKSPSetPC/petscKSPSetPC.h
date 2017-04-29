#ifndef PETSCKSPSETPC_H
#define PETSCKSPSETPC_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPSetPC_types.h"

extern void petscKSPSetPC(const struct0_T *ksp, const struct0_T *pc, int
  *errCode, boolean_T *toplevel);
extern void petscKSPSetPC_initialize(void);
extern void petscKSPSetPC_terminate(void);

#endif
