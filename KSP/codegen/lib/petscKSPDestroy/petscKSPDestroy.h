#ifndef PETSCKSPDESTROY_H
#define PETSCKSPDESTROY_H

#include "petscKSPDestroy_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPDestroy(const M2C_OpaqueType *ksp, M2C_OpaqueType *ksp_out,
                            int *errCode, boolean_T *toplevel);

extern void petscKSPDestroy_initialize(void);

extern void petscKSPDestroy_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
