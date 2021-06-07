#ifndef PETSCPCAPPLY_H
#define PETSCPCAPPLY_H

#include "petscPCApply_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCApply(const M2C_OpaqueType *pc, const M2C_OpaqueType *b,
                         const M2C_OpaqueType *x, int *errCode,
                         boolean_T *toplevel);

extern void petscPCApply_2args(const M2C_OpaqueType *ksp,
                               const M2C_OpaqueType *b, int *errCode,
                               boolean_T *toplevel);

extern void petscPCApply_initialize(void);

extern void petscPCApply_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
