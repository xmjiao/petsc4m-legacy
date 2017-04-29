#ifndef PETSCOPTIONSINSERTSTRING_H
#define PETSCOPTIONSINSERTSTRING_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscOptionsInsertString_types.h"

extern void petscOptionsInsertString(const emxArray_char_T *in_str, int *errCode,
  boolean_T *toplevel);
extern void petscOptionsInsertString_initialize(void);
extern void petscOptionsInsertString_terminate(void);

#endif
