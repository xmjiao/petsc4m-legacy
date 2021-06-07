#ifndef PETSCKSPGETNORMTYPE_H
#define PETSCKSPGETNORMTYPE_H

#include "petscKSPGetNormType_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetNormType(const M2C_OpaqueType *ksp, int *normtype,
                                int *errCode, boolean_T *toplevel);

extern void petscKSPGetNormType_initialize(void);

extern void petscKSPGetNormType_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
