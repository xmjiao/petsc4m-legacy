#ifndef PETSCMATSETNULLSPACE_H
#define PETSCMATSETNULLSPACE_H

#include "petscMatSetNullSpace_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatSetNullSpace(const M2C_OpaqueType *mat,
                                 const M2C_OpaqueType *nullSp, int *errCode,
                                 boolean_T *toplevel);

extern void petscMatSetNullSpace_initialize(void);

extern void petscMatSetNullSpace_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
