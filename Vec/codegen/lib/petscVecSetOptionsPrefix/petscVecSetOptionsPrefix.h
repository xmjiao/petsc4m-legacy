#ifndef PETSCVECSETOPTIONSPREFIX_H
#define PETSCVECSETOPTIONSPREFIX_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecSetOptionsPrefix_types.h"

extern void petscVecSetOptionsPrefix(const struct0_T *vec, const emxArray_char_T
  *prefix, int *errCode, boolean_T *toplevel);
extern void petscVecSetOptionsPrefix_initialize(void);
extern void petscVecSetOptionsPrefix_terminate(void);

#endif
