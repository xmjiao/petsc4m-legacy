#ifndef PETSCKSPGETTOLERANCES_H
#define PETSCKSPGETTOLERANCES_H

#include "petscKSPGetTolerances_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetTolerances(const M2C_OpaqueType *ksp, double *rtol,
                                  double *abstol, double *dtol, int *maxits,
                                  int *errCode, boolean_T *toplevel);

extern void petscKSPGetTolerances_initialize(void);

extern void petscKSPGetTolerances_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
