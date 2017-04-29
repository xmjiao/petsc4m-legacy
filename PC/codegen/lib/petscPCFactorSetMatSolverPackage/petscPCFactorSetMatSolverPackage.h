#ifndef PETSCPCFACTORSETMATSOLVERPACKAGE_H
#define PETSCPCFACTORSETMATSOLVERPACKAGE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscPCFactorSetMatSolverPackage_types.h"

extern void petscPCFactorSetMatSolverPackage(const struct0_T *pc, const
  emxArray_char_T *solver, int *errCode, boolean_T *toplevel);
extern void petscPCFactorSetMatSolverPackage_initialize(void);
extern void petscPCFactorSetMatSolverPackage_terminate(void);

#endif
