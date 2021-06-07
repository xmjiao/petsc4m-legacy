#ifndef PETSCVECSETOPTIONSPREFIX_H
#define PETSCVECSETOPTIONSPREFIX_H

#include "petscVecSetOptionsPrefix_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecSetOptionsPrefix(const M2C_OpaqueType *vec,
                                     const emxArray_char_T *prefix,
                                     int *errCode, boolean_T *toplevel);

extern void petscVecSetOptionsPrefix_initialize(void);

extern void petscVecSetOptionsPrefix_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
