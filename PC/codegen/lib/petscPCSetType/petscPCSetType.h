#ifndef PETSCPCSETTYPE_H
#define PETSCPCSETTYPE_H

#include "petscPCSetType_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCSetType(const M2C_OpaqueType *pc,
                           const emxArray_char_T *type, int *errCode,
                           boolean_T *toplevel);

extern void petscPCSetType_initialize(void);

extern void petscPCSetType_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
