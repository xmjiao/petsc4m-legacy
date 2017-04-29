#ifndef PETSCOPTIONSGETREAL_H
#define PETSCOPTIONSGETREAL_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscOptionsGetReal_types.h"

extern void petscOptionsGetReal(const emxArray_char_T *pre, const
  emxArray_char_T *name, double *value, int *found, int *errCode, boolean_T
  *toplevel);
extern void petscOptionsGetReal_initialize(void);
extern void petscOptionsGetReal_terminate(void);

#endif
