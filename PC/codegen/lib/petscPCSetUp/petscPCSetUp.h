#ifndef PETSCPCSETUP_H
#define PETSCPCSETUP_H

#include "petscPCSetUp_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCSetUp(const M2C_OpaqueType *pc, int *errCode,
                         boolean_T *toplevel);

extern void petscPCSetUp_initialize(void);

extern void petscPCSetUp_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
