#ifndef PETSCMATGETVALUES_H
#define PETSCMATGETVALUES_H

#include "petscMatGetValues_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatGetValues(const M2C_OpaqueType *mat, int ni,
                              const emxArray_int32_T *ix, int nj,
                              const emxArray_int32_T *jx, emxArray_real_T *v,
                              int *errCode, boolean_T *toplevel);

extern void petscMatGetValues_Alloc(const M2C_OpaqueType *mat, int ni,
                                    const emxArray_int32_T *ix, int nj,
                                    const emxArray_int32_T *jx,
                                    emxArray_real_T *v, int *errCode,
                                    boolean_T *toplevel);

extern void petscMatGetValues_initialize(void);

extern void petscMatGetValues_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
