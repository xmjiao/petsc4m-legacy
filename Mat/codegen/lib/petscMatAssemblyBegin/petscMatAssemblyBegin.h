#ifndef PETSCMATASSEMBLYBEGIN_H
#define PETSCMATASSEMBLYBEGIN_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatAssemblyBegin_types.h"

extern void petscMatAssemblyBegin(const struct0_T *mat, int type, int *errCode,
  boolean_T *toplevel);
extern void petscMatAssemblyBegin_Final(const struct0_T *mat, int *errCode,
  boolean_T *toplevel);
extern void petscMatAssemblyBegin_initialize(void);
extern void petscMatAssemblyBegin_terminate(void);

#endif
