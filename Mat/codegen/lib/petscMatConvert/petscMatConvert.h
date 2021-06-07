#ifndef PETSCMATCONVERT_H
#define PETSCMATCONVERT_H

#include "petscMatConvert_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatConvert(const M2C_OpaqueType *mat_in,
                            const emxArray_char_T *newtype, int reuse,
                            M2C_OpaqueType *mat_out, int *errCode,
                            boolean_T *toplevel);

extern void petscMatConvert_initialize(void);

extern void petscMatConvert_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
