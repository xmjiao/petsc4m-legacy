#ifndef PETSCVECCREATESEQ_H
#define PETSCVECCREATESEQ_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscVecCreateSeq_types.h"

extern void petscVecCreateSeq(int n, struct0_T *vec, int *errCode, boolean_T
  *toplevel);
extern void petscVecCreateSeq_initialize(void);
extern void petscVecCreateSeq_terminate(void);

#endif
