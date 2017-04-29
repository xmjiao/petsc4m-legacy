#ifndef PETSCOPTIONSSETVALUE_H
#define PETSCOPTIONSSETVALUE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscOptionsSetValue_types.h"

extern void petscOptionsSetValue(const emxArray_char_T *iname, const
  emxArray_char_T *value, int *errCode, boolean_T *toplevel);
extern void petscOptionsSetValue_initialize(void);
extern void petscOptionsSetValue_terminate(void);

#endif
