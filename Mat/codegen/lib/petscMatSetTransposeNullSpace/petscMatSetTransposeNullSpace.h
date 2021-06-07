#ifndef PETSCMATSETTRANSPOSENULLSPACE_H
#define PETSCMATSETTRANSPOSENULLSPACE_H

#include "petscMatSetTransposeNullSpace_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatSetTransposeNullSpace(const M2C_OpaqueType *mat,
                                          const M2C_OpaqueType *nullSp,
                                          int *errCode, boolean_T *toplevel);

extern void petscMatSetTransposeNullSpace_initialize(void);

extern void petscMatSetTransposeNullSpace_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
