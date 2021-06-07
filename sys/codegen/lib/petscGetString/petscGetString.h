#ifndef PETSCGETSTRING_H
#define PETSCGETSTRING_H

#include "petscGetString_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscGetString(const emxArray_char_T *name, emxArray_char_T *str,
                           boolean_T *toplevel);

extern void petscGetString_initialize(void);

extern void petscGetString_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
