#ifndef PETSCMATSETFROMOPTIONS_H
#define PETSCMATSETFROMOPTIONS_H

#include "petscMatSetFromOptions_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatSetFromOptions(const M2C_OpaqueType *mat, int *errCode,
                                   boolean_T *toplevel);

extern void petscMatSetFromOptions_initialize(void);

extern void petscMatSetFromOptions_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
