#ifndef PETSCVECSETOPTION_H
#define PETSCVECSETOPTION_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscVecSetOption_types.h"

extern void petscVecSetOption(const struct0_T *vec, int op, int flg, int
  *errCode, boolean_T *toplevel);
extern void petscVecSetOption_initialize(void);
extern void petscVecSetOption_terminate(void);

#endif
