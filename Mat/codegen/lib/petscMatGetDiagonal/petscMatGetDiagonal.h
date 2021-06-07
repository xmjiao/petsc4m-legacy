#ifndef PETSCMATGETDIAGONAL_H
#define PETSCMATGETDIAGONAL_H

#include "petscMatGetDiagonal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatGetDiagonal(const M2C_OpaqueType *A,
                                const M2C_OpaqueType *v, int *errCode,
                                boolean_T *toplevel);

extern void petscMatGetDiagonal_initialize(void);

extern void petscMatGetDiagonal_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
