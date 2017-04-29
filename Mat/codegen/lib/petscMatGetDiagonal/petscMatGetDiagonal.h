#ifndef PETSCMATGETDIAGONAL_H
#define PETSCMATGETDIAGONAL_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatGetDiagonal_types.h"

extern void petscMatGetDiagonal(const struct0_T *A, const struct0_T *v, int
  *errCode, boolean_T *toplevel);
extern void petscMatGetDiagonal_initialize(void);
extern void petscMatGetDiagonal_terminate(void);

#endif
