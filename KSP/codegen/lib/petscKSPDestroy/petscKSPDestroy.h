#ifndef PETSCKSPDESTROY_H
#define PETSCKSPDESTROY_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPDestroy_types.h"

extern void petscKSPDestroy(const struct0_T *ksp, struct0_T *ksp_out, int
  *errCode, boolean_T *toplevel);
extern void petscKSPDestroy_initialize(void);
extern void petscKSPDestroy_terminate(void);

#endif
