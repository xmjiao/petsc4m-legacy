#ifndef PETSCVECDUPLICATE_H
#define PETSCVECDUPLICATE_H

#include "petscVecDuplicate_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecDuplicate(const M2C_OpaqueType *vec_in,
                              M2C_OpaqueType *vec_out, int *errCode,
                              boolean_T *toplevel);

extern void petscVecDuplicate_initialize(void);

extern void petscVecDuplicate_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
