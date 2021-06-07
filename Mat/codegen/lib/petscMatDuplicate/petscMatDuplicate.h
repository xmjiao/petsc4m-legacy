#ifndef PETSCMATDUPLICATE_H
#define PETSCMATDUPLICATE_H

#include "petscMatDuplicate_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatDuplicate(const M2C_OpaqueType *mat_in, int op,
                              M2C_OpaqueType *mat_out, int *errCode,
                              boolean_T *toplevel);

extern void petscMatDuplicate_initialize(void);

extern void petscMatDuplicate_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
