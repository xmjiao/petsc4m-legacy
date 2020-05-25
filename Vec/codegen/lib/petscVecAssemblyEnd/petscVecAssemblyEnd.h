#ifndef PETSCVECASSEMBLYEND_H
#define PETSCVECASSEMBLYEND_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscVecAssemblyEnd_types.h"

extern void petscVecAssemblyEnd(const struct0_T *vec, int *errCode, boolean_T
  *toplevel);
extern void petscVecAssemblyEnd_initialize(void);
extern void petscVecAssemblyEnd_terminate(void);

#endif
