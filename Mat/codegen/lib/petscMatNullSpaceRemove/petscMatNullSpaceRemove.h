#ifndef PETSCMATNULLSPACEREMOVE_H
#define PETSCMATNULLSPACEREMOVE_H

#include "petscMatNullSpaceRemove_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatNullSpaceRemove(const M2C_OpaqueType *mat,
                                    const M2C_OpaqueType *vec, int *errCode,
                                    boolean_T *toplevel);

extern void petscMatNullSpaceRemove_initialize(void);

extern void petscMatNullSpaceRemove_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
