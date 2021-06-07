#ifndef PETSCMATASSEMBLYBEGIN_H
#define PETSCMATASSEMBLYBEGIN_H

#include "petscMatAssemblyBegin_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatAssemblyBegin(const M2C_OpaqueType *mat, int type,
                                  int *errCode, boolean_T *toplevel);

extern void petscMatAssemblyBegin_Final(const M2C_OpaqueType *mat, int *errCode,
                                        boolean_T *toplevel);

extern void petscMatAssemblyBegin_initialize(void);

extern void petscMatAssemblyBegin_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
