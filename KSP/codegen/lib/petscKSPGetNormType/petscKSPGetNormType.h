#ifndef PETSCKSPGETNORMTYPE_H
#define PETSCKSPGETNORMTYPE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscKSPGetNormType_types.h"

extern void petscKSPGetNormType(const struct0_T *ksp, int *normtype, int
  *errCode, boolean_T *toplevel);
extern void petscKSPGetNormType_initialize(void);
extern void petscKSPGetNormType_terminate(void);

#endif
