#ifndef PETSCVECSET_H
#define PETSCVECSET_H

#include "petscVecSet_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecSet(const M2C_OpaqueType *vec, float val, int *errCode,
                        boolean_T *toplevel);

extern void petscVecSet_initialize(void);

extern void petscVecSet_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
