#ifndef PETSCPCSETFROMOPTIONS_H
#define PETSCPCSETFROMOPTIONS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscPCSetFromOptions_types.h"

extern void petscPCSetFromOptions(const struct0_T *pc, int *errCode, boolean_T
  *toplevel);
extern void petscPCSetFromOptions_initialize(void);
extern void petscPCSetFromOptions_terminate(void);

#endif
