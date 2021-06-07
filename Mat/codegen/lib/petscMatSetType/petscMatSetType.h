#ifndef PETSCMATSETTYPE_H
#define PETSCMATSETTYPE_H

#include "petscMatSetType_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatSetType(const M2C_OpaqueType *mat,
                            const emxArray_char_T *type, int *errCode,
                            boolean_T *toplevel);

extern void petscMatSetType_initialize(void);

extern void petscMatSetType_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
