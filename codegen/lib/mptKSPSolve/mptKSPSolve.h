#ifndef MPTKSPSOLVE_H
#define MPTKSPSOLVE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mptKSPSolve_types.h"

extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_uint8_T *emxCreateND_uint8_T(int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_uint8_T *emxCreateWrapperND_uint8_T(unsigned char *data, int
  numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_uint8_T *emxCreateWrapper_uint8_T(unsigned char *data, int rows,
  int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern emxArray_uint8_T *emxCreate_uint8_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxDestroyArray_uint8_T(emxArray_uint8_T *emxArray);
extern void emxDestroy_struct0_T(struct0_T emxArray);
extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_struct0_T(struct0_T *pStruct);
extern void mptKSPSolve(const struct0_T *ksp, const struct0_T *b, const
  struct0_T *x, double rtol, int maxits, const struct0_T *x0, int *flag, double *
  relres, int *iter, emxArray_real_T *reshis, double *time);
extern void mptKSPSolve_2args(const struct0_T *ksp, const struct0_T *b, int
  *flag, double *relres, int *iter, emxArray_real_T *reshis, double *time);
extern void mptKSPSolve_3args(const struct0_T *ksp, const struct0_T *b, const
  struct0_T *x, int *flag, double *relres, int *iter, emxArray_real_T *reshis,
  double *time);
extern void mptKSPSolve_4args(const struct0_T *ksp, const struct0_T *b, const
  struct0_T *x, double rtol, int *flag, double *relres, int *iter,
  emxArray_real_T *reshis, double *time);
extern void mptKSPSolve_5args(const struct0_T *ksp, const struct0_T *b, const
  struct0_T *x, double rtol, int maxiter, int *flag, double *relres, int *iter,
  emxArray_real_T *reshis, double *time);
extern void mptKSPSolve_initialize(void);
extern void mptKSPSolve_terminate(void);

#endif
