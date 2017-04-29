#ifndef PETSCOPTIONSGETINT_H
#define PETSCOPTIONSGETINT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscOptionsGetInt_types.h"

extern void petscOptionsGetInt(const emxArray_char_T *pre, const emxArray_char_T
  *name, int *ivalue, int *found, int *errCode, boolean_T *toplevel);
extern void petscOptionsGetInt_initialize(void);
extern void petscOptionsGetInt_terminate(void);

#endif
