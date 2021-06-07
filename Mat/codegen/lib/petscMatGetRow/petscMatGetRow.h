#ifndef PETSCMATGETROW_H
#define PETSCMATGETROW_H

#include "petscMatGetRow_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatGetRow(const M2C_OpaqueType *mat, int row, int *ncols,
                           emxArray_int32_T *cols, emxArray_real_T *vals,
                           int *errCode, boolean_T *toplevel);

extern void petscMatGetRow_initialize(void);

extern void petscMatGetRow_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
