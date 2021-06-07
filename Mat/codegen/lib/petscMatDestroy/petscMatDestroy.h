#ifndef PETSCMATDESTROY_H
#define PETSCMATDESTROY_H

#include "petscMatDestroy_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatDestroy(M2C_OpaqueType *mat, int *errCode,
                            boolean_T *toplevel);

extern void petscMatDestroy_initialize(void);

extern void petscMatDestroy_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
