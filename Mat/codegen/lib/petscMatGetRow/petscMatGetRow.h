#ifndef PETSCMATGETROW_H
#define PETSCMATGETROW_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatGetRow_types.h"

extern void petscMatGetRow(const struct0_T *mat, int row, int *ncols,
  emxArray_int32_T *cols, emxArray_real_T *vals, int *errCode, boolean_T
  *toplevel);
extern void petscMatGetRow_initialize(void);
extern void petscMatGetRow_terminate(void);

#endif
