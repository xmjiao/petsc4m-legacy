#ifndef PETSCKSPGETOPERATORS_H
#define PETSCKSPGETOPERATORS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPGetOperators_types.h"

extern void petscKSPGetOperators(const M2C_OpaqueType *pc, struct0_T *Amat,
  struct0_T *Pmat, int *errCode, boolean_T *toplevel);
extern void petscKSPGetOperators_initialize(void);
extern void petscKSPGetOperators_terminate(void);

#endif
