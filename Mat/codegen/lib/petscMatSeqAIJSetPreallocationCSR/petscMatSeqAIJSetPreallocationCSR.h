#ifndef PETSCMATSEQAIJSETPREALLOCATIONCSR_H
#define PETSCMATSEQAIJSETPREALLOCATIONCSR_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatSeqAIJSetPreallocationCSR_types.h"

extern void petscMatSeqAIJSetPreallocationCSR(const struct0_T *mat, const
  emxArray_int32_T *ix, const emxArray_int32_T *jx, const emxArray_real_T *vs,
  int *errCode, boolean_T *toplevel);
extern void petscMatSeqAIJSetPreallocationCSR_Indexonly(const struct0_T *mat,
  const emxArray_int32_T *ix, const emxArray_int32_T *jx, int *errCode,
  boolean_T *toplevel);
extern void petscMatSeqAIJSetPreallocationCSR_initialize(void);
extern void petscMatSeqAIJSetPreallocationCSR_terminate(void);

#endif
