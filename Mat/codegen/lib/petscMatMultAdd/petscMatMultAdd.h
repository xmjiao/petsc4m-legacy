#ifndef PETSCMATMULTADD_H
#define PETSCMATMULTADD_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatMultAdd_types.h"

extern void petscMatMultAdd(const struct0_T *A, const struct0_T *v1, const
  struct0_T *v2, const struct0_T *v3, int *errCode, boolean_T *toplevel);
extern void petscMatMultAdd_initialize(void);
extern void petscMatMultAdd_terminate(void);

#endif
