#ifndef PETSCOPTIONSSETREAL_H
#define PETSCOPTIONSSETREAL_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscOptionsSetReal_types.h"

extern void petscOptionsSetReal(const emxArray_char_T *iname, double value, int *
  errCode, boolean_T *toplevel);
extern void petscOptionsSetReal_initialize(void);
extern void petscOptionsSetReal_terminate(void);

#endif
