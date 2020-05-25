#ifndef PETSCVECCREATE_H
#define PETSCVECCREATE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscVecCreate_types.h"

extern void petscVecCreate(const struct0_T *comm, struct0_T *vec, int *errCode,
  boolean_T *toplevel);
extern void petscVecCreate_World(struct0_T *vec, int *errCode, boolean_T
  *topleve);
extern void petscVecCreate_initialize(void);
extern void petscVecCreate_terminate(void);

#endif
