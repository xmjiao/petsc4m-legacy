#ifndef PETSCMATCREATE_H
#define PETSCMATCREATE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatCreate_types.h"

extern void petscMatCreate(const struct0_T *comm, struct0_T *mat, int *errCode,
  boolean_T *toplevel);
extern void petscMatCreate_World(struct0_T *mat, int *errCode, boolean_T
  *topleve);
extern void petscMatCreate_initialize(void);
extern void petscMatCreate_terminate(void);

#endif
