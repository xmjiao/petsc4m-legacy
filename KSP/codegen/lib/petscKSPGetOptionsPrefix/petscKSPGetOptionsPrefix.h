#ifndef PETSCKSPGETOPTIONSPREFIX_H
#define PETSCKSPGETOPTIONSPREFIX_H

#include "petscKSPGetOptionsPrefix_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetOptionsPrefix(const M2C_OpaqueType *ksp,
                                     emxArray_char_T *str, int *errCode,
                                     boolean_T *toplevel);

extern void petscKSPGetOptionsPrefix_initialize(void);

extern void petscKSPGetOptionsPrefix_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
