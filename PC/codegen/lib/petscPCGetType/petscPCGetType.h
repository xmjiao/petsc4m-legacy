#ifndef PETSCPCGETTYPE_H
#define PETSCPCGETTYPE_H

#include "petscPCGetType_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCGetType(const M2C_OpaqueType *pc, emxArray_char_T *type,
                           int *errCode, boolean_T *toplevel);

extern void petscPCGetType_initialize(void);

extern void petscPCGetType_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
