#ifndef PETSCKSPSETNORMTYPE_H
#define PETSCKSPSETNORMTYPE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPSetNormType_types.h"

extern void petscKSPSetNormType(const struct0_T *ksp, int normtype, int *errCode,
  boolean_T *toplevel);
extern void petscKSPSetNormType_initialize(void);
extern void petscKSPSetNormType_terminate(void);

#endif
