#ifndef PETSCMATASSEMBLED_H
#define PETSCMATASSEMBLED_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatAssembled_types.h"

extern void petscMatAssembled(const struct0_T *mat, int *assembled, int *errCode,
  boolean_T *toplevel);
extern void petscMatAssembled_initialize(void);
extern void petscMatAssembled_terminate(void);

#endif
