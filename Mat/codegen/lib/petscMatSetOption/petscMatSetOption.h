#ifndef PETSCMATSETOPTION_H
#define PETSCMATSETOPTION_H

#include "petscMatSetOption_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatSetOption(const M2C_OpaqueType *mat, int op, int flg,
                              int *errCode, boolean_T *toplevel);

extern void petscMatSetOption_initialize(void);

extern void petscMatSetOption_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
