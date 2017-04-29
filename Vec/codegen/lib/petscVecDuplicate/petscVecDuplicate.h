#ifndef PETSCVECDUPLICATE_H
#define PETSCVECDUPLICATE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecDuplicate_types.h"

extern void petscVecDuplicate(const struct0_T *vec_in, struct0_T *vec_out, int
  *errCode, boolean_T *toplevel);
extern void petscVecDuplicate_initialize(void);
extern void petscVecDuplicate_terminate(void);

#endif
