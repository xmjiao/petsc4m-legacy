#ifndef PETSCMATSEQAIJSETPREALLOCATIONCSR_H
#define PETSCMATSEQAIJSETPREALLOCATIONCSR_H

#include "petscMatSeqAIJSetPreallocationCSR_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatSeqAIJSetPreallocationCSR(const M2C_OpaqueType *mat,
                                              const emxArray_int32_T *ix,
                                              const emxArray_int32_T *jx,
                                              const emxArray_real_T *vs,
                                              int *errCode,
                                              boolean_T *toplevel);

extern void petscMatSeqAIJSetPreallocationCSR_Indexonly(
    const M2C_OpaqueType *mat, const emxArray_int32_T *ix,
    const emxArray_int32_T *jx, int *errCode, boolean_T *toplevel);

extern void petscMatSeqAIJSetPreallocationCSR_initialize(void);

extern void petscMatSeqAIJSetPreallocationCSR_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
