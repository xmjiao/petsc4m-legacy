#ifndef PETSCOPTIONSGETSTRING_H
#define PETSCOPTIONSGETSTRING_H

#include "petscOptionsGetString_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscOptionsGetString(const emxArray_char_T *pre,
                                  const emxArray_char_T *name, char str_data[],
                                  int str_size[2], int *found, int *errCode,
                                  boolean_T *toplevel);

extern void petscOptionsGetString_initialize(void);

extern void petscOptionsGetString_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
