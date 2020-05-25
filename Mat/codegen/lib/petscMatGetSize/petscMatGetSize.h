#ifndef PETSCMATGETSIZE_H
#define PETSCMATGETSIZE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatGetSize_types.h"

extern void petscMatGetSize(const struct0_T *mat, int *m, int *n, int *errCode,
  boolean_T *toplevel);
extern void petscMatGetSize_initialize(void);
extern void petscMatGetSize_terminate(void);

#endif
