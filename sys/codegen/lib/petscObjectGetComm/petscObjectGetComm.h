#ifndef PETSCOBJECTGETCOMM_H
#define PETSCOBJECTGETCOMM_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscObjectGetComm_types.h"

extern void petscObjectGetComm(const struct0_T *obj, struct0_T *comm, int
  *errCode, boolean_T *toplevel);
extern void petscObjectGetComm_initialize(void);
extern void petscObjectGetComm_terminate(void);

#endif
