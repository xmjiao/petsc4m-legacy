#ifndef PETSCKSPAPPENDOPTIONSPREFIX_H
#define PETSCKSPAPPENDOPTIONSPREFIX_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPAppendOptionsPrefix_types.h"

extern void petscKSPAppendOptionsPrefix(const struct0_T *ksp, const
  emxArray_char_T *prefix, int *errCode, boolean_T *toplevel);
extern void petscKSPAppendOptionsPrefix_initialize(void);
extern void petscKSPAppendOptionsPrefix_terminate(void);

#endif
