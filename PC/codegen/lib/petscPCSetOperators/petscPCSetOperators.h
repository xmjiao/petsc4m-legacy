#ifndef PETSCPCSETOPERATORS_H
#define PETSCPCSETOPERATORS_H

#include "petscPCSetOperators_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCSetOperators(const M2C_OpaqueType *pc,
                                const M2C_OpaqueType *Amat,
                                const M2C_OpaqueType *Pmat, int *errCode,
                                boolean_T *toplevel);

extern void petscPCSetOperators_AforP(const M2C_OpaqueType *ksp,
                                      const M2C_OpaqueType *Amat, int *errCode,
                                      boolean_T *toplevel);

extern void petscPCSetOperators_initialize(void);

extern void petscPCSetOperators_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
