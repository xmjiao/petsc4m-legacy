#ifndef PETSCGETCPUTIME_H
#define PETSCGETCPUTIME_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscGetCPUTime(double *t, int *errCode, boolean_T *toplevel);

extern void petscGetCPUTime_initialize(void);

extern void petscGetCPUTime_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
