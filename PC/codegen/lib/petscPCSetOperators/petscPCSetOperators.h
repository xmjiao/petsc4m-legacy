#ifndef PETSCPCSETOPERATORS_H
#define PETSCPCSETOPERATORS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscPCSetOperators_types.h"

extern void petscPCSetOperators(const struct0_T *pc, const struct0_T *Amat,
  const struct0_T *Pmat, int *errCode, boolean_T *toplevel);
extern void petscPCSetOperators_AforP(const struct0_T *ksp, const struct0_T
  *Amat, int *errCode, boolean_T *toplevel);
extern void petscPCSetOperators_initialize(void);
extern void petscPCSetOperators_terminate(void);

#endif
