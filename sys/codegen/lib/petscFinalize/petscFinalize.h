#ifndef PETSCFINALIZE_H
#define PETSCFINALIZE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscFinalize_types.h"

extern void petscFinalize(int *errCode, boolean_T *toplevel);
extern void petscFinalize_initialize(void);
extern void petscFinalize_terminate(void);

#endif
