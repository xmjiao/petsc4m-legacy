#ifndef PETSCOPTIONSGETBOOL_H
#define PETSCOPTIONSGETBOOL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscOptionsGetBool_types.h"

extern void petscOptionsGetBool(const emxArray_char_T *pre, const
  emxArray_char_T *name, int *value, int *found, int *errCode, boolean_T
  *toplevel);
extern void petscOptionsGetBool_initialize(void);
extern void petscOptionsGetBool_terminate(void);

#endif
