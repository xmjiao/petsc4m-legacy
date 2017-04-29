#ifndef PETSCPCCREATE_H
#define PETSCPCCREATE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscPCCreate_types.h"

extern void petscPCCreate(const struct0_T *comm, struct0_T *pc, int *errCode,
  boolean_T *toplevel);
extern void petscPCCreate_World(struct0_T *ksp, int *errCode, boolean_T
  *toplevel);
extern void petscPCCreate_initialize(void);
extern void petscPCCreate_terminate(void);

#endif
