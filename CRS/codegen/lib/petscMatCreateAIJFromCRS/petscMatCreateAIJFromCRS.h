#ifndef PETSCMATCREATEAIJFROMCRS_H
#define PETSCMATCREATEAIJFROMCRS_H

#include "petscMatCreateAIJFromCRS_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr,
                                     const emxArray_int32_T *col_ind,
                                     const emxArray_real32_T *val, int ncols,
                                     emxArray_char_T *prefix, struct0_T *mat,
                                     boolean_T *toplevel);

extern void petscMatCreateAIJFromCRS_3args(const emxArray_int32_T *row_ptr,
                                           const emxArray_int32_T *col_ind,
                                           const emxArray_real32_T *val,
                                           struct0_T *mat, boolean_T *toplevel);

extern void petscMatCreateAIJFromCRS_4args(const emxArray_int32_T *row_ptr,
                                           const emxArray_int32_T *col_ind,
                                           const emxArray_real32_T *val,
                                           int ncols, struct0_T *mat,
                                           boolean_T *toplevel);

extern void petscMatCreateAIJFromCRS_initialize(void);

extern void petscMatCreateAIJFromCRS_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
