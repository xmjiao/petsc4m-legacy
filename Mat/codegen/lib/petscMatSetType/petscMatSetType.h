#ifndef PETSCMATSETTYPE_H
#define PETSCMATSETTYPE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatSetType_types.h"

extern void petscMatSetType(const struct0_T *mat, const emxArray_char_T *type,
  int *errCode, boolean_T *toplevel);
extern void petscMatSetType_initialize(void);
extern void petscMatSetType_terminate(void);

#endif
