#ifndef PETSCSOLVECRS_H
#define PETSCSOLVECRS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "petscSolveCRS_types.h"

extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_int32_T *emxCreateND_int32_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_int32_T *emxCreateWrapperND_int32_T(int *data, int numDimensions,
  int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_int32_T *emxCreateWrapper_int32_T(int *data, int rows, int cols);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern emxArray_int32_T *emxCreate_int32_T(int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxDestroyArray_int32_T(emxArray_int32_T *emxArray);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void petscSolveCRS(int *flag, double *relres, int *iter, double times[2]);
extern void petscSolveCRS_10args(const emxArray_int32_T *Arows, const
  emxArray_int32_T *Acols, const emxArray_real_T *Avals, const emxArray_real_T
  *b, const emxArray_char_T *solver, double rtol, int maxiter, const
  emxArray_char_T *pctype, const emxArray_char_T *solpack, const emxArray_real_T
  *x0, emxArray_real_T *x, int *flag, double *relres, int *iter, emxArray_real_T
  *reshis, double times[2]);
extern void petscSolveCRS_11args(const emxArray_int32_T *Arows, const
  emxArray_int32_T *Acols, const emxArray_real_T *Avals, const emxArray_real_T
  *b, const emxArray_char_T *solver, double rtol, int maxiter, const
  emxArray_char_T *pctype, const emxArray_char_T *solpack, const emxArray_real_T
  *x0, const emxArray_char_T *opts, emxArray_real_T *x, int *flag, double
  *relres, int *iter, emxArray_real_T *reshis, double times[2]);
extern void petscSolveCRS_4args(const emxArray_int32_T *Arows, const
  emxArray_int32_T *Acols, const emxArray_real_T *Avals, const emxArray_real_T
  *b, emxArray_real_T *x, int *flag, double *relres, int *iter, emxArray_real_T *
  reshis, double times[2]);
extern void petscSolveCRS_5args(const emxArray_int32_T *Arows, const
  emxArray_int32_T *Acols, const emxArray_real_T *Avals, const emxArray_real_T
  *b, const emxArray_char_T *solver, emxArray_real_T *x, int *flag, double
  *relres, int *iter, emxArray_real_T *reshis, double times[2]);
extern void petscSolveCRS_6args(const emxArray_int32_T *Arows, const
  emxArray_int32_T *Acols, const emxArray_real_T *Avals, const emxArray_real_T
  *b, const emxArray_char_T *solver, double rtol, emxArray_real_T *x, int *flag,
  double *relres, int *iter, emxArray_real_T *reshis, double times[2]);
extern void petscSolveCRS_7args(const emxArray_int32_T *Arows, const
  emxArray_int32_T *Acols, const emxArray_real_T *Avals, const emxArray_real_T
  *b, const emxArray_char_T *solver, double rtol, int maxiter, emxArray_real_T
  *x, int *flag, double *relres, int *iter, emxArray_real_T *reshis, double
  times[2]);
extern void petscSolveCRS_8args(const emxArray_int32_T *Arows, const
  emxArray_int32_T *Acols, const emxArray_real_T *Avals, const emxArray_real_T
  *b, const emxArray_char_T *solver, double rtol, int maxiter, const
  emxArray_char_T *pctype, emxArray_real_T *x, int *flag, double *relres, int
  *iter, emxArray_real_T *reshis, double times[2]);
extern void petscSolveCRS_9args(const emxArray_int32_T *Arows, const
  emxArray_int32_T *Acols, const emxArray_real_T *Avals, const emxArray_real_T
  *b, const emxArray_char_T *solver, double rtol, int maxiter, const
  emxArray_char_T *pctype, const emxArray_char_T *solpack, emxArray_real_T *x,
  int *flag, double *relres, int *iter, emxArray_real_T *reshis, double times[2]);
extern void petscSolveCRS_initialize(void);
extern void petscSolveCRS_terminate(void);

#endif
