#ifndef PETSCINITIALIZED_H
#define PETSCINITIALIZED_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscInitialized_types.h"

extern void petscInitialized(int *initialized, int *errCode, boolean_T *toplevel);
extern void petscInitialized_initialize(void);
extern void petscInitialized_terminate(void);

#endif
