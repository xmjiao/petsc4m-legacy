#ifndef PETSCPCAPPENDOPTIONSPREFIX_H
#define PETSCPCAPPENDOPTIONSPREFIX_H

#include "petscPCAppendOptionsPrefix_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscPCAppendOptionsPrefix(const M2C_OpaqueType *pc,
                                       const emxArray_char_T *prefix,
                                       int *errCode, boolean_T *toplevel);

extern void petscPCAppendOptionsPrefix_initialize(void);

extern void petscPCAppendOptionsPrefix_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
