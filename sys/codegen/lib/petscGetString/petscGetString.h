#ifndef PETSCGETSTRING_H
#define PETSCGETSTRING_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscGetString_types.h"

extern void petscGetString(const emxArray_char_T *name, emxArray_char_T *str,
  boolean_T *toplevel);
extern void petscGetString_initialize(void);
extern void petscGetString_terminate(void);

#endif
