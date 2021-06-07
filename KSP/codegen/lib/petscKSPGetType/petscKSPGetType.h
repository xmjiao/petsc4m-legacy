#ifndef PETSCKSPGETTYPE_H
#define PETSCKSPGETTYPE_H

#include "petscKSPGetType_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetType(const M2C_OpaqueType *ksp, emxArray_char_T *type,
                            int *errCode, boolean_T *toplevel);

extern void petscKSPGetType_initialize(void);

extern void petscKSPGetType_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
