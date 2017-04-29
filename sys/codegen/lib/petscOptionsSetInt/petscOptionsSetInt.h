#ifndef PETSCOPTIONSSETINT_H
#define PETSCOPTIONSSETINT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscOptionsSetInt_types.h"

extern void petscOptionsSetInt(const emxArray_char_T *iname, int value, int
  *errCode, boolean_T *toplevel);
extern void petscOptionsSetInt_initialize(void);
extern void petscOptionsSetInt_terminate(void);

#endif
