#ifndef PETSCPCGETOPTIONSPREFIX_H
#define PETSCPCGETOPTIONSPREFIX_H

#include "petscPCGetOptionsPrefix_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCGetOptionsPrefix(const M2C_OpaqueType *pc,
                                    emxArray_char_T *str, int *errCode,
                                    boolean_T *toplevel);

extern void petscPCGetOptionsPrefix_initialize(void);

extern void petscPCGetOptionsPrefix_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
