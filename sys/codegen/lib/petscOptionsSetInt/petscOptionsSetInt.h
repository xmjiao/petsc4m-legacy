#ifndef PETSCOPTIONSSETINT_H
#define PETSCOPTIONSSETINT_H

#include "petscOptionsSetInt_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscOptionsSetInt(const emxArray_char_T *iname, int value,
                               int *errCode, boolean_T *toplevel);

extern void petscOptionsSetInt_initialize(void);

extern void petscOptionsSetInt_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
