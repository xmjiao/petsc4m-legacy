#ifndef PETSCKSPGETPC_H
#define PETSCKSPGETPC_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPGetPC_types.h"

extern void petscKSPGetPC(const struct0_T *ksp, struct0_T *pc, int *errCode,
  boolean_T *toplevel);
extern void petscKSPGetPC_initialize(void);
extern void petscKSPGetPC_terminate(void);

#endif
