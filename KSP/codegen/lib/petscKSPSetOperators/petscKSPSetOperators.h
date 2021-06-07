#ifndef PETSCKSPSETOPERATORS_H
#define PETSCKSPSETOPERATORS_H

#include "petscKSPSetOperators_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPSetOperators(const M2C_OpaqueType *ksp,
                                 const M2C_OpaqueType *Amat,
                                 const M2C_OpaqueType *Pmat, int *errCode,
                                 boolean_T *toplevel);

extern void petscKSPSetOperators_AforP(const M2C_OpaqueType *ksp,
                                       const M2C_OpaqueType *Amat, int *errCode,
                                       boolean_T *toplevel);

extern void petscKSPSetOperators_initialize(void);

extern void petscKSPSetOperators_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
