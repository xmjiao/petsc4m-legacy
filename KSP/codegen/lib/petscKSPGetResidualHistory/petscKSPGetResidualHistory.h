#ifndef PETSCKSPGETRESIDUALHISTORY_H
#define PETSCKSPGETRESIDUALHISTORY_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPGetResidualHistory_types.h"

extern void petscKSPGetResidualHistory(const struct0_T *ksp, emxArray_real_T
  *reshis, int *errCode, boolean_T *toplevel);
extern void petscKSPGetResidualHistory_initialize(void);
extern void petscKSPGetResidualHistory_terminate(void);

#endif
