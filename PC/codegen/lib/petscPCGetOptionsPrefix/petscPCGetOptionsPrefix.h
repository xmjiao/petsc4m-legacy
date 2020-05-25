#ifndef PETSCPCGETOPTIONSPREFIX_H
#define PETSCPCGETOPTIONSPREFIX_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscPCGetOptionsPrefix_types.h"

extern void petscPCGetOptionsPrefix(const struct0_T *pc, emxArray_char_T *str,
  int *errCode, boolean_T *toplevel);
extern void petscPCGetOptionsPrefix_initialize(void);
extern void petscPCGetOptionsPrefix_terminate(void);

#endif
