#ifndef PETSCKSPSETTYPE_H
#define PETSCKSPSETTYPE_H

#include "petscKSPSetType_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPSetType(const M2C_OpaqueType *ksp,
                            const emxArray_char_T *type, int *errCode,
                            boolean_T *toplevel);

extern void petscKSPSetType_initialize(void);

extern void petscKSPSetType_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
