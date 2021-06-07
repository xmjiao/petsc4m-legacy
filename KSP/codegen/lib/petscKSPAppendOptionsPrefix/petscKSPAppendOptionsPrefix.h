#ifndef PETSCKSPAPPENDOPTIONSPREFIX_H
#define PETSCKSPAPPENDOPTIONSPREFIX_H

#include "petscKSPAppendOptionsPrefix_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscKSPAppendOptionsPrefix(const M2C_OpaqueType *ksp,
                                        const emxArray_char_T *prefix,
                                        int *errCode, boolean_T *toplevel);

extern void petscKSPAppendOptionsPrefix_initialize(void);

extern void petscKSPAppendOptionsPrefix_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
