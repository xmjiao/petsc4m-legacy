#ifndef PETSCFINALIZED_H
#define PETSCFINALIZED_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscFinalized(int *finalized, int *errCode, boolean_T *toplevel);

extern void petscFinalized_initialize(void);

extern void petscFinalized_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
