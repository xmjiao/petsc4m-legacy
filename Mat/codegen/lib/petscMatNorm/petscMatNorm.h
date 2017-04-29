#ifndef PETSCMATNORM_H
#define PETSCMATNORM_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatNorm_types.h"

extern void petscMatNorm(const struct0_T *A, int type, double *nrm, int *errCode,
  boolean_T *toplevel);
extern void petscMatNorm_initialize(void);
extern void petscMatNorm_terminate(void);

#endif
