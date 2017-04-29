#ifndef PETSCMATSETNULLSPACE_H
#define PETSCMATSETNULLSPACE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatSetNullSpace_types.h"

extern void petscMatSetNullSpace(const struct0_T *mat, const struct0_T *nullSp,
  int *errCode, boolean_T *toplevel);
extern void petscMatSetNullSpace_initialize(void);
extern void petscMatSetNullSpace_terminate(void);

#endif
