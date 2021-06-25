#ifndef PETSCMATAYPX_H
#define PETSCMATAYPX_H

#include "petscMatAYPX_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatAYPX(const M2C_OpaqueType *Y, float a,
                         const M2C_OpaqueType *X, int mstr, int *errCode,
                         boolean_T *toplevel);

extern void petscMatAYPX_3args(const M2C_OpaqueType *Y, float a,
                               const M2C_OpaqueType *X, int *errCode,
                               boolean_T *toplevel);

extern void petscMatAYPX_initialize(void);

extern void petscMatAYPX_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
