#ifndef PETSCMATMPIAIJSETPREALLOCATIONCSR_H
#define PETSCMATMPIAIJSETPREALLOCATIONCSR_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatMPIAIJSetPreallocationCSR_types.h"

extern void petscMatMPIAIJSetPreallocationCSR(const struct0_T *mat, const
  emxArray_int32_T *ix, const emxArray_int32_T *jx, const emxArray_real_T *vs,
  int *errCode, boolean_T *toplevel);
extern void petscMatMPIAIJSetPreallocationCSR_Indexonly(const struct0_T *mat,
  const emxArray_int32_T *ix, const emxArray_int32_T *jx, int *errCode,
  boolean_T *toplevel);
extern void petscMatMPIAIJSetPreallocationCSR_initialize(void);
extern void petscMatMPIAIJSetPreallocationCSR_terminate(void);

#endif
