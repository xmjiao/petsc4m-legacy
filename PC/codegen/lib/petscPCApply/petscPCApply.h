#ifndef PETSCPCAPPLY_H
#define PETSCPCAPPLY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscPCApply_types.h"

extern void petscPCApply(const struct0_T *pc, const struct0_T *b, const
  struct0_T *x, int *errCode, boolean_T *toplevel);
extern void petscPCApply_2args(const struct0_T *ksp, const struct0_T *b, int
  *errCode, boolean_T *toplevel);
extern void petscPCApply_initialize(void);
extern void petscPCApply_terminate(void);

#endif
