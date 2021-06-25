#ifndef PETSCMATMPIAIJSETPREALLOCATIONCSR_H
#define PETSCMATMPIAIJSETPREALLOCATIONCSR_H

#include "petscMatMPIAIJSetPreallocationCSR_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatMPIAIJSetPreallocationCSR(const M2C_OpaqueType *mat,
                                              const emxArray_int32_T *ix,
                                              const emxArray_int32_T *jx,
                                              const emxArray_real32_T *vs,
                                              int *errCode,
                                              boolean_T *toplevel);

extern void petscMatMPIAIJSetPreallocationCSR_Indexonly(
    const M2C_OpaqueType *mat, const emxArray_int32_T *ix,
    const emxArray_int32_T *jx, int *errCode, boolean_T *toplevel);

extern void petscMatMPIAIJSetPreallocationCSR_initialize(void);

extern void petscMatMPIAIJSetPreallocationCSR_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
