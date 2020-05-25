#ifndef PETSCKSPSETOPTIONSPREFIX_H
#define PETSCKSPSETOPTIONSPREFIX_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPSetOptionsPrefix_types.h"

extern void petscKSPSetOptionsPrefix(const struct0_T *ksp, const emxArray_char_T
  *prefix, int *errCode, boolean_T *toplevel);
extern void petscKSPSetOptionsPrefix_initialize(void);
extern void petscKSPSetOptionsPrefix_terminate(void);

#endif
