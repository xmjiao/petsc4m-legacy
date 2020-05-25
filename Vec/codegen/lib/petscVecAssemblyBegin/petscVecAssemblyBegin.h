#ifndef PETSCVECASSEMBLYBEGIN_H
#define PETSCVECASSEMBLYBEGIN_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscVecAssemblyBegin_types.h"

extern void petscVecAssemblyBegin(const struct0_T *vec, int *errCode, boolean_T *
  toplevel);
extern void petscVecAssemblyBegin_initialize(void);
extern void petscVecAssemblyBegin_terminate(void);

#endif
