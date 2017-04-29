#ifndef PETSCMATCONVERT_H
#define PETSCMATCONVERT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatConvert_types.h"

extern void petscMatConvert(const struct0_T *mat_in, const emxArray_char_T
  *newtype, int reuse, struct0_T *mat_out, int *errCode, boolean_T *toplevel);
extern void petscMatConvert_initialize(void);
extern void petscMatConvert_terminate(void);

#endif
