#ifndef PETSCGETSIZEOF_H
#define PETSCGETSIZEOF_H

#include "petscGetSizeof_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscGetSizeof(const emxArray_char_T *name, int *sz,
                           boolean_T *toplevel);

extern void petscGetSizeof_initialize(void);

extern void petscGetSizeof_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
