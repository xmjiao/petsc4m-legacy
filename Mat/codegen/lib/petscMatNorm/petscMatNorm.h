#ifndef PETSCMATNORM_H
#define PETSCMATNORM_H

#include "petscMatNorm_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatNorm(const M2C_OpaqueType *A, int type, double *nrm,
                         int *errCode, boolean_T *toplevel);

extern void petscMatNorm_initialize(void);

extern void petscMatNorm_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
