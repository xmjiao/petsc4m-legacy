#ifndef PETSCGETOBJECT_H
#define PETSCGETOBJECT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscGetObject_types.h"

extern void petscGetObject(const emxArray_char_T *name, struct0_T *obj,
  boolean_T *toplevel);
extern void petscGetObject_initialize(void);
extern void petscGetObject_terminate(void);

#endif
