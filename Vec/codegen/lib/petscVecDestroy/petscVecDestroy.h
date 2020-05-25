#ifndef PETSCVECDESTROY_H
#define PETSCVECDESTROY_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscVecDestroy_types.h"

extern void petscVecDestroy(struct0_T *vec, int *errCode, boolean_T *toplevel);
extern void petscVecDestroy_initialize(void);
extern void petscVecDestroy_terminate(void);

#endif
