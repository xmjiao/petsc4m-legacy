#ifndef PETSCPCSETTYPE_H
#define PETSCPCSETTYPE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscPCSetType_types.h"

extern void petscPCSetType(const struct0_T *pc, const emxArray_char_T *type, int
  *errCode, boolean_T *toplevel);
extern void petscPCSetType_initialize(void);
extern void petscPCSetType_terminate(void);

#endif
