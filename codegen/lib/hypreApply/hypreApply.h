#ifndef HYPREAPPLY_H
#define HYPREAPPLY_H

#include "hypreApply_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void hypreApply(const M2C_OpaqueType *pc, const emxArray_real32_T *x,
                       emxArray_real32_T *y);

extern void hypreApply_initialize(void);

extern void hypreApply_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
