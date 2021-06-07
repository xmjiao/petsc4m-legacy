#ifndef PETSCVECSETOPTION_H
#define PETSCVECSETOPTION_H

#include "petscVecSetOption_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecSetOption(const M2C_OpaqueType *vec, int op, int flg,
                              int *errCode, boolean_T *toplevel);

extern void petscVecSetOption_initialize(void);

extern void petscVecSetOption_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
