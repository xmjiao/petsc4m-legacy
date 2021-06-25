#ifndef PETSCKSPSETTOLERANCES_H
#define PETSCKSPSETTOLERANCES_H

#include "petscKSPSetTolerances_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPSetTolerances(const M2C_OpaqueType *ksp, float rtol,
                                  float abstol, float dtol, int maxits,
                                  int *errCode, boolean_T *toplevel);

extern void petscKSPSetTolerances_2args(const M2C_OpaqueType *ksp, float rtol,
                                        int *errCode, boolean_T *toplevel);

extern void petscKSPSetTolerances_initialize(void);

extern void petscKSPSetTolerances_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
