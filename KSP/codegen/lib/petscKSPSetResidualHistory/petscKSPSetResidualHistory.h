#ifndef PETSCKSPSETRESIDUALHISTORY_H
#define PETSCKSPSETRESIDUALHISTORY_H

#include "petscKSPSetResidualHistory_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPSetResidualHistory(const M2C_OpaqueType *ksp, int *errCode,
                                       boolean_T *toplevel);

extern void petscKSPSetResidualHistory_2args(const M2C_OpaqueType *ksp, int na,
                                             int *errCode, boolean_T *toplevel);

extern void petscKSPSetResidualHistory_3args(const M2C_OpaqueType *ksp, int na,
                                             int reset, int *errCode,
                                             boolean_T *toplevel);

extern void petscKSPSetResidualHistory_initialize(void);

extern void petscKSPSetResidualHistory_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
