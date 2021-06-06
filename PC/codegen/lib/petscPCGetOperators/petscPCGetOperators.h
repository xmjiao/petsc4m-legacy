#ifndef PETSCPCGETOPERATORS_H
#define PETSCPCGETOPERATORS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscPCGetOperators_types.h"

extern void petscPCGetOperators(const M2C_OpaqueType *pc, struct0_T *Amat,
  struct0_T *Pmat, int *errCode, boolean_T *toplevel);
extern void petscPCGetOperators_initialize(void);
extern void petscPCGetOperators_terminate(void);

#endif
