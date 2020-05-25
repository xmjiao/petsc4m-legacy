#ifndef PETSCMATDUPLICATE_H
#define PETSCMATDUPLICATE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatDuplicate_types.h"

extern void petscMatDuplicate(const struct0_T *mat_in, int op, struct0_T
  *mat_out, int *errCode, boolean_T *toplevel);
extern void petscMatDuplicate_initialize(void);
extern void petscMatDuplicate_terminate(void);

#endif
