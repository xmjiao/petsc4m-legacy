#ifndef PETSCFINALIZE_H
#define PETSCFINALIZE_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscFinalize(int *errCode, boolean_T *toplevel);

extern void petscFinalize_initialize(void);

extern void petscFinalize_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
