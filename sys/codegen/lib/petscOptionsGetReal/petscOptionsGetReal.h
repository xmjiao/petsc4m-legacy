#ifndef PETSCOPTIONSGETREAL_H
#define PETSCOPTIONSGETREAL_H

#include "petscOptionsGetReal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscOptionsGetReal(const emxArray_char_T *pre,
                                const emxArray_char_T *name, double *value,
                                int *found, int *errCode, boolean_T *toplevel);

extern void petscOptionsGetReal_initialize(void);

extern void petscOptionsGetReal_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
