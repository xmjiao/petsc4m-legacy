#ifndef PETSCPCSETOPTIONSPREFIX_H
#define PETSCPCSETOPTIONSPREFIX_H

#include "petscPCSetOptionsPrefix_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCSetOptionsPrefix(const M2C_OpaqueType *pc,
                                    const emxArray_char_T *prefix, int *errCode,
                                    boolean_T *toplevel);

extern void petscPCSetOptionsPrefix_initialize(void);

extern void petscPCSetOptionsPrefix_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
