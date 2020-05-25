#ifndef PETSCPCAPPLYTRANSPOSE_H
#define PETSCPCAPPLYTRANSPOSE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscPCApplyTranspose_types.h"

extern void petscPCApplyTranspose(const struct0_T *pc, const struct0_T *b, const
  struct0_T *x, int *errCode, boolean_T *toplevel);
extern void petscPCApplyTranspose_2args(const struct0_T *ksp, const struct0_T *b,
  int *errCode, boolean_T *toplevel);
extern void petscPCApplyTranspose_initialize(void);
extern void petscPCApplyTranspose_terminate(void);

#endif
