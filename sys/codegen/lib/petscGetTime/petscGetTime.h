#ifndef PETSCGETTIME_H
#define PETSCGETTIME_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscGetTime(double *t, int *errCode, boolean_T *toplevel);

extern void petscGetTime_initialize(void);

extern void petscGetTime_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
