#ifndef PETSCMATCREATESEQAIJ_H
#define PETSCMATCREATESEQAIJ_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatCreateSeqAIJ_types.h"

extern void petscMatCreateSeqAIJ(int m, int n, int nz, const emxArray_int32_T
  *nnz, struct0_T *mat, int *errCode, boolean_T *toplevel);
extern void petscMatCreateSeqAIJ_FixedRows(int m, int n, int nz, struct0_T *mat,
  int *errCode, boolean_T *topleve);
extern void petscMatCreateSeqAIJ_initialize(void);
extern void petscMatCreateSeqAIJ_terminate(void);

#endif
