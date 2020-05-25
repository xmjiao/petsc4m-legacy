#ifndef PETSCMATSETSIZES_H
#define PETSCMATSETSIZES_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatSetSizes_types.h"

extern void petscMatSetSizes(const struct0_T *mat, int m, int n, int M, int N,
  int *errCode, boolean_T *toplevel);
extern void petscMatSetSizes_Local(const struct0_T *mat, int m, int n, int
  *errCode, boolean_T *toplevel);
extern void petscMatSetSizes_initialize(void);
extern void petscMatSetSizes_terminate(void);

#endif
