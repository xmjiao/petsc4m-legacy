#ifndef PETSCPCDESTROY_H
#define PETSCPCDESTROY_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscPCDestroy_types.h"

extern void petscPCDestroy(struct0_T *pc, int *errCode, boolean_T *toplevel);
extern void petscPCDestroy_initialize(void);
extern void petscPCDestroy_terminate(void);

#endif
