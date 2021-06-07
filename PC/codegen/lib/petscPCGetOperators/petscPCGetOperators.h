#ifndef PETSCPCGETOPERATORS_H
#define PETSCPCGETOPERATORS_H

#include "petscPCGetOperators_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCGetOperators(const M2C_OpaqueType *pc, M2C_OpaqueType *Amat,
                                M2C_OpaqueType *Pmat, int *errCode,
                                boolean_T *toplevel);

extern void petscPCGetOperators_initialize(void);

extern void petscPCGetOperators_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
