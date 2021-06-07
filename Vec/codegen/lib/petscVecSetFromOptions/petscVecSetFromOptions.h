#ifndef PETSCVECSETFROMOPTIONS_H
#define PETSCVECSETFROMOPTIONS_H

#include "petscVecSetFromOptions_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecSetFromOptions(const M2C_OpaqueType *vec, int *errCode,
                                   boolean_T *toplevel);

extern void petscVecSetFromOptions_initialize(void);

extern void petscVecSetFromOptions_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
