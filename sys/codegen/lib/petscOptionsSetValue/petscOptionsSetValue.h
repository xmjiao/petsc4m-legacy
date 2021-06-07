#ifndef PETSCOPTIONSSETVALUE_H
#define PETSCOPTIONSSETVALUE_H

#include "petscOptionsSetValue_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscOptionsSetValue(const emxArray_char_T *iname,
                                 const emxArray_char_T *value, int *errCode,
                                 boolean_T *toplevel);

extern void petscOptionsSetValue_initialize(void);

extern void petscOptionsSetValue_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
