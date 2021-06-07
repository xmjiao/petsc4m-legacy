#ifndef PETSCVECSETTYPE_H
#define PETSCVECSETTYPE_H

#include "petscVecSetType_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecSetType(const M2C_OpaqueType *vec,
                            const emxArray_char_T *type, int *errCode,
                            boolean_T *toplevel);

extern void petscVecSetType_initialize(void);

extern void petscVecSetType_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
