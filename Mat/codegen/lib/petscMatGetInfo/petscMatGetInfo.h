#ifndef PETSCMATGETINFO_H
#define PETSCMATGETINFO_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatGetInfo_types.h"

extern void petscMatGetInfo(const struct0_T *mat, int flag, PetscMatInfo *info,
  int *errCode, boolean_T *toplevel);
extern void petscMatGetInfo_Local(const struct0_T *mat, PetscMatInfo *info, int *
  errCode, boolean_T *toplevel);
extern void petscMatGetInfo_initialize(void);
extern void petscMatGetInfo_terminate(void);

#endif
