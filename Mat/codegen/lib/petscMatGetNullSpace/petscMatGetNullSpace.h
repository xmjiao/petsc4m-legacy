#ifndef PETSCMATGETNULLSPACE_H
#define PETSCMATGETNULLSPACE_H

#include "petscMatGetNullSpace_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatGetNullSpace(const M2C_OpaqueType *mat,
                                 M2C_OpaqueType *nullsp, int *errCode,
                                 boolean_T *toplevel);

extern void petscMatGetNullSpace_initialize(void);

extern void petscMatGetNullSpace_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
