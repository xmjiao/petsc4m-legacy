#ifndef PETSCMATNULLSPACEDESTROY_H
#define PETSCMATNULLSPACEDESTROY_H

#include "petscMatNullSpaceDestroy_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatNullSpaceDestroy(M2C_OpaqueType *matNull, int *errCode,
                                     boolean_T *toplevel);

extern void petscMatNullSpaceDestroy_initialize(void);

extern void petscMatNullSpaceDestroy_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
