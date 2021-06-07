#ifndef PETSCKSPGETCONVERGEDREASON_H
#define PETSCKSPGETCONVERGEDREASON_H

#include "petscKSPGetConvergedReason_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetConvergedReason(const M2C_OpaqueType *ksp, int *flag,
                                       int *errCode, boolean_T *toplevel);

extern void petscKSPGetConvergedReason_initialize(void);

extern void petscKSPGetConvergedReason_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
