#ifndef PETSCGETOBJECT_H
#define PETSCGETOBJECT_H

#include "petscGetObject_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscGetObject(const emxArray_char_T *name, struct0_T *obj,
                           boolean_T *toplevel);

extern void petscGetObject_initialize(void);

extern void petscGetObject_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
