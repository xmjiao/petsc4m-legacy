#ifndef PETSCMATNULLSPACESETFUNCTION_H
#define PETSCMATNULLSPACESETFUNCTION_H

#include "petscMatNullSpaceSetFunction_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatNullSpaceSetFunction(const M2C_OpaqueType *nullSp,
                                         const M2C_OpaqueType *rmvFunc,
                                         const M2C_OpaquePtrType *ctx,
                                         int *errCode, boolean_T *toplevel);

extern void petscMatNullSpaceSetFunction_initialize(void);

extern void petscMatNullSpaceSetFunction_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
