#ifndef PETSCMATGETNULLSPACE_H
#define PETSCMATGETNULLSPACE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatGetNullSpace_types.h"

extern void petscMatGetNullSpace(const struct0_T *mat, struct0_T *nullsp, int
  *errCode, boolean_T *toplevel);
extern void petscMatGetNullSpace_initialize(void);
extern void petscMatGetNullSpace_terminate(void);

#endif
