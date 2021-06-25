#ifndef PETSCVECNORM_H
#define PETSCVECNORM_H

#include "petscVecNorm_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecNorm(const M2C_OpaqueType *x, int type, float nrm[2],
                         int *errCode, boolean_T *toplevel);

extern void petscVecNorm_2args(const M2C_OpaqueType *x, int type, float *nrm,
                               int *errCode, boolean_T *toplevel);

extern void petscVecNorm_initialize(void);

extern void petscVecNorm_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
