#ifndef PETSCPCFACTORGETMATRIX_H
#define PETSCPCFACTORGETMATRIX_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscPCFactorGetMatrix_types.h"

extern void petscPCFactorGetMatrix(const struct0_T *pc, struct0_T *mat, int
  *errCode, boolean_T *toplevel);
extern void petscPCFactorGetMatrix_initialize(void);
extern void petscPCFactorGetMatrix_terminate(void);

#endif
