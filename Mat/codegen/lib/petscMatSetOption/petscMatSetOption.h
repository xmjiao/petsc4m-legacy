#ifndef PETSCMATSETOPTION_H
#define PETSCMATSETOPTION_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscMatSetOption_types.h"

extern void petscMatSetOption(const struct0_T *mat, int op, int flg, int
  *errCode, boolean_T *toplevel);
extern void petscMatSetOption_initialize(void);
extern void petscMatSetOption_terminate(void);

#endif
