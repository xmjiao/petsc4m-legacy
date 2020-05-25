#ifndef PETSCOPTIONSGETSTRING_H
#define PETSCOPTIONSGETSTRING_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscOptionsGetString_types.h"

extern void petscOptionsGetString(const emxArray_char_T *pre, const
  emxArray_char_T *name, char str_data[], int str_size[2], int *found, int
  *errCode, boolean_T *toplevel);
extern void petscOptionsGetString_initialize(void);
extern void petscOptionsGetString_terminate(void);

#endif
