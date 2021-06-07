#ifndef PETSCKSPSETFROMOPTIONS_H
#define PETSCKSPSETFROMOPTIONS_H

#include "petscKSPSetFromOptions_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPSetFromOptions(const M2C_OpaqueType *ksp, int *errCode,
                                   boolean_T *toplevel);

extern void petscKSPSetFromOptions_initialize(void);

extern void petscKSPSetFromOptions_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
