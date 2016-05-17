#ifndef PETSCINITIALIZE_H
#define PETSCINITIALIZE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscInitialize_types.h"

extern void petscInitialize(int *errCode, boolean_T *toplevel);
extern void petscInitialize_initialize(void);
extern void petscInitialize_terminate(void);

#endif
