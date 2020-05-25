#ifndef PETSCKSPCREATE_H
#define PETSCKSPCREATE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscKSPCreate_types.h"

extern void petscKSPCreate(const struct0_T *comm, struct0_T *ksp, int *errCode,
  boolean_T *toplevel);
extern void petscKSPCreate_World(struct0_T *ksp, int *errCode, boolean_T
  *toplevel);
extern void petscKSPCreate_initialize(void);
extern void petscKSPCreate_terminate(void);

#endif
