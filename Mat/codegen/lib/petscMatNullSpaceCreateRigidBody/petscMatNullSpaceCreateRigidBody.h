#ifndef PETSCMATNULLSPACECREATERIGIDBODY_H
#define PETSCMATNULLSPACECREATERIGIDBODY_H

#include "petscMatNullSpaceCreateRigidBody_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatNullSpaceCreateRigidBody(const M2C_OpaqueType *coords,
                                             M2C_OpaqueType *nullsp,
                                             int *errCode, boolean_T *toplevel);

extern void petscMatNullSpaceCreateRigidBody_initialize(void);

extern void petscMatNullSpaceCreateRigidBody_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
