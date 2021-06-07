#ifndef PETSCMATSETNEARNULLSPACE_H
#define PETSCMATSETNEARNULLSPACE_H

#include "petscMatSetNearNullSpace_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatSetNearNullSpace(const M2C_OpaqueType *mat,
                                     const M2C_OpaqueType *nullSp, int *errCode,
                                     boolean_T *toplevel);

extern void petscMatSetNearNullSpace_initialize(void);

extern void petscMatSetNearNullSpace_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
