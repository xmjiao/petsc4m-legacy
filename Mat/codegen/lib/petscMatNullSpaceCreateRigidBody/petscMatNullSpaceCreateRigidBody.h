#ifndef PETSCMATNULLSPACECREATERIGIDBODY_H
#define PETSCMATNULLSPACECREATERIGIDBODY_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatNullSpaceCreateRigidBody_types.h"

extern void petscMatNullSpaceCreateRigidBody(const struct0_T *coords, struct0_T *
  nullsp, int *errCode, boolean_T *toplevel);
extern void petscMatNullSpaceCreateRigidBody_initialize(void);
extern void petscMatNullSpaceCreateRigidBody_terminate(void);

#endif
