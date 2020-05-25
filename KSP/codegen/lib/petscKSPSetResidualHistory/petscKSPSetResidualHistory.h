#ifndef PETSCKSPSETRESIDUALHISTORY_H
#define PETSCKSPSETRESIDUALHISTORY_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPSetResidualHistory_types.h"

extern void petscKSPSetResidualHistory(const struct0_T *ksp, int *errCode,
  boolean_T *toplevel);
extern void petscKSPSetResidualHistory_2args(const struct0_T *ksp, int na, int
  *errCode, boolean_T *toplevel);
extern void petscKSPSetResidualHistory_3args(const struct0_T *ksp, int na, int
  reset, int *errCode, boolean_T *toplevel);
extern void petscKSPSetResidualHistory_initialize(void);
extern void petscKSPSetResidualHistory_terminate(void);

#endif
