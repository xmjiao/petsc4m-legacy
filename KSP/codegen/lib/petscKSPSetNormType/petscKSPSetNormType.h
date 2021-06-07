#ifndef PETSCKSPSETNORMTYPE_H
#define PETSCKSPSETNORMTYPE_H

#include "petscKSPSetNormType_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPSetNormType(const M2C_OpaqueType *ksp, int normtype,
                                int *errCode, boolean_T *toplevel);

extern void petscKSPSetNormType_initialize(void);

extern void petscKSPSetNormType_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
