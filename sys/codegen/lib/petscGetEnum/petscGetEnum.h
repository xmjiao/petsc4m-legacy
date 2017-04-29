#ifndef PETSCGETENUM_H
#define PETSCGETENUM_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscGetEnum_types.h"

extern void petscGetEnum(const emxArray_char_T *name, int *val, boolean_T
  *toplevel);
extern void petscGetEnum_initialize(void);
extern void petscGetEnum_terminate(void);

#endif
