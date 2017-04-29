#ifndef PETSCGETSIZEOF_H
#define PETSCGETSIZEOF_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscGetSizeof_types.h"

extern void petscGetSizeof(const emxArray_char_T *name, int *sz, boolean_T
  *toplevel);
extern void petscGetSizeof_initialize(void);
extern void petscGetSizeof_terminate(void);

#endif
