#ifndef PETSCMATSETOPTIONSPREFIX_H
#define PETSCMATSETOPTIONSPREFIX_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatSetOptionsPrefix_types.h"

extern void petscMatSetOptionsPrefix(const struct0_T *mat, const emxArray_char_T
  *prefix, int *errCode, boolean_T *toplevel);
extern void petscMatSetOptionsPrefix_initialize(void);
extern void petscMatSetOptionsPrefix_terminate(void);

#endif
