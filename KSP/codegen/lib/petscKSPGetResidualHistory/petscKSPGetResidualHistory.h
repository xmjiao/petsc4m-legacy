#ifndef PETSCKSPGETRESIDUALHISTORY_H
#define PETSCKSPGETRESIDUALHISTORY_H

#include "petscKSPGetResidualHistory_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetResidualHistory(const M2C_OpaqueType *ksp,
                                       emxArray_real32_T *reshis, int *errCode,
                                       boolean_T *toplevel);

extern void petscKSPGetResidualHistory_initialize(void);

extern void petscKSPGetResidualHistory_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
