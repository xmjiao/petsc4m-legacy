#ifndef PETSCKSPSETTYPE_H
#define PETSCKSPSETTYPE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPSetType_types.h"

extern void petscKSPSetType(const struct0_T *ksp, const emxArray_char_T *type,
  int *errCode, boolean_T *toplevel);
extern void petscKSPSetType_initialize(void);
extern void petscKSPSetType_terminate(void);

#endif
