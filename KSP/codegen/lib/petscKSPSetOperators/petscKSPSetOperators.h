#ifndef PETSCKSPSETOPERATORS_H
#define PETSCKSPSETOPERATORS_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPSetOperators_types.h"

extern void petscKSPSetOperators(const struct0_T *ksp, const struct0_T *Amat,
  const struct0_T *Pmat, int *errCode, boolean_T *toplevel);
extern void petscKSPSetOperators_AforP(const struct0_T *ksp, const struct0_T
  *Amat, int *errCode, boolean_T *toplevel);
extern void petscKSPSetOperators_initialize(void);
extern void petscKSPSetOperators_terminate(void);

#endif
