#ifndef PETSCOPTIONSHASNAME_H
#define PETSCOPTIONSHASNAME_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscOptionsHasName_types.h"

extern void petscOptionsHasName(const struct0_T *options, const emxArray_char_T *
  pre, const emxArray_char_T *name, int *found, int *errCode, boolean_T
  *toplevel);
extern void petscOptionsHasName_initialize(void);
extern void petscOptionsHasName_terminate(void);

#endif
