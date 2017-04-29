#ifndef PETSCKSPGETOPTIONSPREFIX_H
#define PETSCKSPGETOPTIONSPREFIX_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPGetOptionsPrefix_types.h"

extern void petscKSPGetOptionsPrefix(const struct0_T *ksp, emxArray_char_T *str,
  int *errCode, boolean_T *toplevel);
extern void petscKSPGetOptionsPrefix_initialize(void);
extern void petscKSPGetOptionsPrefix_terminate(void);

#endif
