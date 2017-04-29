#ifndef PETSCMATNULLSPACEDESTROY_H
#define PETSCMATNULLSPACEDESTROY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatNullSpaceDestroy_types.h"

extern void petscMatNullSpaceDestroy(struct0_T *matNull, int *errCode, boolean_T
  *toplevel);
extern void petscMatNullSpaceDestroy_initialize(void);
extern void petscMatNullSpaceDestroy_terminate(void);

#endif
