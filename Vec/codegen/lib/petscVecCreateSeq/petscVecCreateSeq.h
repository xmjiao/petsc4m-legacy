#ifndef PETSCVECCREATESEQ_H
#define PETSCVECCREATESEQ_H

#include "petscVecCreateSeq_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscVecCreateSeq(int n, struct0_T *vec, int *errCode,
                              boolean_T *toplevel);

extern void petscVecCreateSeq_initialize(void);

extern void petscVecCreateSeq_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
