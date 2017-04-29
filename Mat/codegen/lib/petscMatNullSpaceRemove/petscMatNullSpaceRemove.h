#ifndef PETSCMATNULLSPACEREMOVE_H
#define PETSCMATNULLSPACEREMOVE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatNullSpaceRemove_types.h"

extern void petscMatNullSpaceRemove(const struct0_T *mat, const struct0_T *vec,
  int *errCode, boolean_T *toplevel);
extern void petscMatNullSpaceRemove_initialize(void);
extern void petscMatNullSpaceRemove_terminate(void);

#endif
