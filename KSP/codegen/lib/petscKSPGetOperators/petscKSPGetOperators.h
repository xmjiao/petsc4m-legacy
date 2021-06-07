#ifndef PETSCKSPGETOPERATORS_H
#define PETSCKSPGETOPERATORS_H

#include "petscKSPGetOperators_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPGetOperators(const M2C_OpaqueType *pc, M2C_OpaqueType *Amat,
                                 M2C_OpaqueType *Pmat, int *errCode,
                                 boolean_T *toplevel);

extern void petscKSPGetOperators_initialize(void);

extern void petscKSPGetOperators_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
