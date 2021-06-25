#ifndef PETSCOPTIONSSETREAL_H
#define PETSCOPTIONSSETREAL_H

#include "petscOptionsSetReal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscOptionsSetReal(const emxArray_char_T *iname, float value,
                                int *errCode, boolean_T *toplevel);

extern void petscOptionsSetReal_initialize(void);

extern void petscOptionsSetReal_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
