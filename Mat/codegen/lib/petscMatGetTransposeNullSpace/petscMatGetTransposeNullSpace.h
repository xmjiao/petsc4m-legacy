#ifndef PETSCMATGETTRANSPOSENULLSPACE_H
#define PETSCMATGETTRANSPOSENULLSPACE_H

#include "petscMatGetTransposeNullSpace_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatGetTransposeNullSpace(const M2C_OpaqueType *mat,
                                          M2C_OpaqueType *nullsp, int *errCode,
                                          boolean_T *toplevel);

extern void petscMatGetTransposeNullSpace_initialize(void);

extern void petscMatGetTransposeNullSpace_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
