#ifndef PETSCMATNULLSPACECREATE_H
#define PETSCMATNULLSPACECREATE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatNullSpaceCreate_types.h"

extern void petscMatNullSpaceCreate(const struct0_T *comm, int has_cnst, int n,
  const struct0_T *vecs, struct0_T *nullsp, int *errCode, boolean_T *toplevel);
extern void petscMatNullSpaceCreate_2args(const struct0_T *comm, int has_cnst,
  struct0_T *nullsp, int *errCode, boolean_T *toplevel);
extern void petscMatNullSpaceCreate_initialize(void);
extern void petscMatNullSpaceCreate_terminate(void);

#endif
