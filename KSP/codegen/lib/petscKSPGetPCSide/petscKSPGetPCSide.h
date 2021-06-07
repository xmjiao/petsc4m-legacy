#ifndef PETSCKSPGETPCSIDE_H
#define PETSCKSPGETPCSIDE_H

#include "petscKSPGetPCSide_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetPCSide(const M2C_OpaqueType *ksp, int *side,
                              int *errCode, boolean_T *toplevel);

extern void petscKSPGetPCSide_initialize(void);

extern void petscKSPGetPCSide_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
