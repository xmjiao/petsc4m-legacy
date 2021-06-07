#ifndef PETSCMATGETNEARNULLSPACE_H
#define PETSCMATGETNEARNULLSPACE_H

#include "petscMatGetNearNullSpace_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatGetNearNullSpace(const M2C_OpaqueType *mat,
                                     M2C_OpaqueType *nullsp, int *errCode,
                                     boolean_T *toplevel);

extern void petscMatGetNearNullSpace_initialize(void);

extern void petscMatGetNearNullSpace_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
