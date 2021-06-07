#ifndef PETSCGETENUM_H
#define PETSCGETENUM_H

#include "petscGetEnum_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscGetEnum(const emxArray_char_T *name, int *val,
                         boolean_T *toplevel);

extern void petscGetEnum_initialize(void);

extern void petscGetEnum_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
