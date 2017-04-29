#ifndef PETSCPCGETTYPE_H
#define PETSCPCGETTYPE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscPCGetType_types.h"

extern void petscPCGetType(const struct0_T *pc, emxArray_char_T *type, int
  *errCode, boolean_T *toplevel);
extern void petscPCGetType_initialize(void);
extern void petscPCGetType_terminate(void);

#endif
