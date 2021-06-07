#ifndef PETSCMATSETOPTIONSPREFIX_H
#define PETSCMATSETOPTIONSPREFIX_H

#include "petscMatSetOptionsPrefix_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatSetOptionsPrefix(const M2C_OpaqueType *mat,
                                     const emxArray_char_T *prefix,
                                     int *errCode, boolean_T *toplevel);

extern void petscMatSetOptionsPrefix_initialize(void);

extern void petscMatSetOptionsPrefix_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
