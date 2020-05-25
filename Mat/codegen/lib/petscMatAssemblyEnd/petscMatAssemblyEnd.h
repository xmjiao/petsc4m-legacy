#ifndef PETSCMATASSEMBLYEND_H
#define PETSCMATASSEMBLYEND_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatAssemblyEnd_types.h"

extern void petscMatAssemblyEnd(const struct0_T *mat, int type, int *errCode,
  boolean_T *toplevel);
extern void petscMatAssemblyEnd_Final(const struct0_T *mat, int *errCode,
  boolean_T *toplevel);
extern void petscMatAssemblyEnd_initialize(void);
extern void petscMatAssemblyEnd_terminate(void);

#endif
