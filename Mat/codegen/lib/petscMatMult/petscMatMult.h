#ifndef PETSCMATMULT_H
#define PETSCMATMULT_H

#include "petscMatMult_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatMult(const M2C_OpaqueType *A, const M2C_OpaqueType *x,
                         const M2C_OpaqueType *y, int *errCode,
                         boolean_T *toplevel);

extern void petscMatMult_initialize(void);

extern void petscMatMult_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
