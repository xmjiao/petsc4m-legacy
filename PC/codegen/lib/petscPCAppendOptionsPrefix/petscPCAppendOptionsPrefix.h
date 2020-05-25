#ifndef PETSCPCAPPENDOPTIONSPREFIX_H
#define PETSCPCAPPENDOPTIONSPREFIX_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscPCAppendOptionsPrefix_types.h"

extern void petscPCAppendOptionsPrefix(const struct0_T *pc, const
  emxArray_char_T *prefix, int *errCode, boolean_T *toplevel);
extern void petscPCAppendOptionsPrefix_initialize(void);
extern void petscPCAppendOptionsPrefix_terminate(void);

#endif
