#ifndef PETSCINITIALIZED_H
#define PETSCINITIALIZED_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscInitialized(int *initialized, int *errCode,
                             boolean_T *toplevel);

extern void petscInitialized_initialize(void);

extern void petscInitialized_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
