#ifndef PETSCPCDESTROY_H
#define PETSCPCDESTROY_H

#include "petscPCDestroy_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCDestroy(M2C_OpaqueType *pc, int *errCode,
                           boolean_T *toplevel);

extern void petscPCDestroy_initialize(void);

extern void petscPCDestroy_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
