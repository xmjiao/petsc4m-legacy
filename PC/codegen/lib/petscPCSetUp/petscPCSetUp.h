#ifndef PETSCPCSETUP_H
#define PETSCPCSETUP_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscPCSetUp_types.h"

extern void petscPCSetUp(const struct0_T *pc, int *errCode, boolean_T *toplevel);
extern void petscPCSetUp_initialize(void);
extern void petscPCSetUp_terminate(void);

#endif
