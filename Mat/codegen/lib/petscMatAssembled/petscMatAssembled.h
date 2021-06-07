#ifndef PETSCMATASSEMBLED_H
#define PETSCMATASSEMBLED_H

#include "petscMatAssembled_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatAssembled(const M2C_OpaqueType *mat, int *assembled,
                              int *errCode, boolean_T *toplevel);

extern void petscMatAssembled_initialize(void);

extern void petscMatAssembled_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
