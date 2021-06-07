#ifndef PETSCOPTIONSINSERTSTRING_H
#define PETSCOPTIONSINSERTSTRING_H

#include "petscOptionsInsertString_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscOptionsInsertString(const emxArray_char_T *in_str,
                                     int *errCode, boolean_T *toplevel);

extern void petscOptionsInsertString_initialize(void);

extern void petscOptionsInsertString_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
