#ifndef PETSCPCSETOPTIONSPREFIX_H
#define PETSCPCSETOPTIONSPREFIX_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscPCSetOptionsPrefix_types.h"

extern void petscPCSetOptionsPrefix(const struct0_T *pc, const emxArray_char_T
  *prefix, int *errCode, boolean_T *toplevel);
extern void petscPCSetOptionsPrefix_initialize(void);
extern void petscPCSetOptionsPrefix_terminate(void);

#endif
