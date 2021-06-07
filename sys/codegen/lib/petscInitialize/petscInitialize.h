#ifndef PETSCINITIALIZE_H
#define PETSCINITIALIZE_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscInitialize(int *errCode, boolean_T *toplevel);

extern void petscInitialize_initialize(void);

extern void petscInitialize_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
