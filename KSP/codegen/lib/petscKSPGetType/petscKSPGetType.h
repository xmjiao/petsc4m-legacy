#ifndef PETSCKSPGETTYPE_H
#define PETSCKSPGETTYPE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPGetType_types.h"

extern void petscKSPGetType(const struct0_T *ksp, emxArray_char_T *type, int
  *errCode, boolean_T *toplevel);
extern void petscKSPGetType_initialize(void);
extern void petscKSPGetType_terminate(void);

#endif
