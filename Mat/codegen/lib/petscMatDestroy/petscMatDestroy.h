#ifndef PETSCMATDESTROY_H
#define PETSCMATDESTROY_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscMatDestroy_types.h"

extern void petscMatDestroy(struct0_T *mat, int *errCode, boolean_T *toplevel);
extern void petscMatDestroy_initialize(void);
extern void petscMatDestroy_terminate(void);

#endif
