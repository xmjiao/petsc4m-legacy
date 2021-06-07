#ifndef PETSCMATASSEMBLYEND_H
#define PETSCMATASSEMBLYEND_H

#include "petscMatAssemblyEnd_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatAssemblyEnd(const M2C_OpaqueType *mat, int type,
                                int *errCode, boolean_T *toplevel);

extern void petscMatAssemblyEnd_Final(const M2C_OpaqueType *mat, int *errCode,
                                      boolean_T *toplevel);

extern void petscMatAssemblyEnd_initialize(void);

extern void petscMatAssemblyEnd_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
