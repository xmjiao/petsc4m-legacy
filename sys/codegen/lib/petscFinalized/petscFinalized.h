#ifndef PETSCFINALIZED_H
#define PETSCFINALIZED_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscFinalized_types.h"

extern void petscFinalized(int *finalized, int *errCode, boolean_T *toplevel);
extern void petscFinalized_initialize(void);
extern void petscFinalized_terminate(void);

#endif
