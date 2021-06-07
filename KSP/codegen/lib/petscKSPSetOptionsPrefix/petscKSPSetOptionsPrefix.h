#ifndef PETSCKSPSETOPTIONSPREFIX_H
#define PETSCKSPSETOPTIONSPREFIX_H

#include "petscKSPSetOptionsPrefix_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPSetOptionsPrefix(const M2C_OpaqueType *ksp,
                                     const emxArray_char_T *prefix,
                                     int *errCode, boolean_T *toplevel);

extern void petscKSPSetOptionsPrefix_initialize(void);

extern void petscKSPSetOptionsPrefix_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
