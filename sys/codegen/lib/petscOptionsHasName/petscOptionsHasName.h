#ifndef PETSCOPTIONSHASNAME_H
#define PETSCOPTIONSHASNAME_H

#include "petscOptionsHasName_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscOptionsHasName(const M2C_OpaqueType *options,
                                const emxArray_char_T *pre,
                                const emxArray_char_T *name, int *found,
                                int *errCode, boolean_T *toplevel);

extern void petscOptionsHasName_initialize(void);

extern void petscOptionsHasName_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
