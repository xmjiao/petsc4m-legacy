#ifndef PETSCKSPSETUP_H
#define PETSCKSPSETUP_H

#include "petscKSPSetUp_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPSetUp(const M2C_OpaqueType *ksp, int *errCode,
                          boolean_T *toplevel);

extern void petscKSPSetUp_initialize(void);

extern void petscKSPSetUp_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
