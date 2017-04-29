#ifndef PETSCPCFACTORSETUPMATSOLVERPACKAGE_H
#define PETSCPCFACTORSETUPMATSOLVERPACKAGE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscPCFactorSetUpMatSolverPackage_types.h"

extern void petscPCFactorSetUpMatSolverPackage(const struct0_T *pc, int *errCode,
  boolean_T *toplevel);
extern void petscPCFactorSetUpMatSolverPackage_initialize(void);
extern void petscPCFactorSetUpMatSolverPackage_terminate(void);

#endif
