#ifndef PETSCOPTIONSGETINT_H
#define PETSCOPTIONSGETINT_H

#include "petscOptionsGetInt_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscOptionsGetInt(const emxArray_char_T *pre,
                               const emxArray_char_T *name, int *ivalue,
                               int *found, int *errCode, boolean_T *toplevel);

extern void petscOptionsGetInt_initialize(void);

extern void petscOptionsGetInt_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
