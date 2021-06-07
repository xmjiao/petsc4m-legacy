#ifndef PETSCPCSETFROMOPTIONS_H
#define PETSCPCSETFROMOPTIONS_H

#include "petscPCSetFromOptions_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCSetFromOptions(const M2C_OpaqueType *pc, int *errCode,
                                  boolean_T *toplevel);

extern void petscPCSetFromOptions_initialize(void);

extern void petscPCSetFromOptions_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
