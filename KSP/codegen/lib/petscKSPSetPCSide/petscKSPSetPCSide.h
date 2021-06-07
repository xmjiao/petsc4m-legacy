#ifndef PETSCKSPSETPCSIDE_H
#define PETSCKSPSETPCSIDE_H

#include "petscKSPSetPCSide_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPSetPCSide(const M2C_OpaqueType *ksp, int side, int *errCode,
                              boolean_T *toplevel);

extern void petscKSPSetPCSide_initialize(void);

extern void petscKSPSetPCSide_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
