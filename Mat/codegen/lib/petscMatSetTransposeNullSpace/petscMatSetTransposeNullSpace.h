#ifndef PETSCMATSETTRANSPOSENULLSPACE_H
#define PETSCMATSETTRANSPOSENULLSPACE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatSetTransposeNullSpace_types.h"

extern void petscMatSetTransposeNullSpace(const struct0_T *mat, const struct0_T *
  nullSp, int *errCode, boolean_T *toplevel);
extern void petscMatSetTransposeNullSpace_initialize(void);
extern void petscMatSetTransposeNullSpace_terminate(void);

#endif
