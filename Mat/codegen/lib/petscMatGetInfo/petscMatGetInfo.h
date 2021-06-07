#ifndef PETSCMATGETINFO_H
#define PETSCMATGETINFO_H

#include "petscMatGetInfo_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatGetInfo(const M2C_OpaqueType *mat, int flag,
                            PetscMatInfo *info, int *errCode,
                            boolean_T *toplevel);

extern void petscMatGetInfo_Local(const M2C_OpaqueType *mat, PetscMatInfo *info,
                                  int *errCode, boolean_T *toplevel);

extern void petscMatGetInfo_initialize(void);

extern void petscMatGetInfo_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
