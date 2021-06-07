#ifndef PETSCKSPSOLVE_H
#define PETSCKSPSOLVE_H

#include "petscKSPSolve_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPSolve(const M2C_OpaqueType *ksp, const M2C_OpaqueType *b,
                          const M2C_OpaqueType *x, int *errCode,
                          boolean_T *toplevel);

extern void petscKSPSolve_2args(const M2C_OpaqueType *ksp,
                                const M2C_OpaqueType *b, int *errCode,
                                boolean_T *toplevel);

extern void petscKSPSolve_initialize(void);

extern void petscKSPSolve_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
