#ifndef PETSCVECNORM_H
#define PETSCVECNORM_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecNorm_types.h"

extern void petscVecNorm(const struct0_T *x, int type, double nrm[2], int
  *errCode, boolean_T *toplevel);
extern void petscVecNorm_2args(const struct0_T *x, int type, double *nrm, int
  *errCode, boolean_T *toplevel);
extern void petscVecNorm_initialize(void);
extern void petscVecNorm_terminate(void);

#endif
