#ifndef PETSCMATGETLOCALSIZE_H
#define PETSCMATGETLOCALSIZE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatGetLocalSize_types.h"

extern void petscMatGetLocalSize(const struct0_T *mat, int *m, int *n, int
  *errCode, boolean_T *toplevel);
extern void petscMatGetLocalSize_initialize(void);
extern void petscMatGetLocalSize_terminate(void);

#endif
