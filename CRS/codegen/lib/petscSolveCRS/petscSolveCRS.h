#ifndef PETSCSOLVECRS_H
#define PETSCSOLVECRS_H

#include "petscSolveCRS_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscSolveCRS(int *flag, double *relres, int *iter,
                          double times[2]);

extern void petscSolveCRS_10args(
    const emxArray_int32_T *Arows, const emxArray_int32_T *Acols,
    const emxArray_real32_T *Avals, const emxArray_real32_T *b,
    const emxArray_char_T *solver, float rtol, int maxiter,
    const emxArray_char_T *pctype, const emxArray_char_T *solpack,
    const emxArray_real32_T *x0, emxArray_real32_T *x, int *flag, float *relres,
    int *iter, emxArray_real32_T *reshis, double times[2]);

extern void petscSolveCRS_11args(
    const emxArray_int32_T *Arows, const emxArray_int32_T *Acols,
    const emxArray_real32_T *Avals, const emxArray_real32_T *b,
    const emxArray_char_T *solver, float rtol, int maxiter,
    const emxArray_char_T *pctype, const emxArray_char_T *solpack,
    const emxArray_real32_T *x0, const emxArray_char_T *opts,
    emxArray_real32_T *x, int *flag, float *relres, int *iter,
    emxArray_real32_T *reshis, double times[2]);

extern void petscSolveCRS_4args(const emxArray_int32_T *Arows,
                                const emxArray_int32_T *Acols,
                                const emxArray_real32_T *Avals,
                                const emxArray_real32_T *b,
                                emxArray_real32_T *x, int *flag, float *relres,
                                int *iter, emxArray_real32_T *reshis,
                                double times[2]);

extern void petscSolveCRS_5args(
    const emxArray_int32_T *Arows, const emxArray_int32_T *Acols,
    const emxArray_real32_T *Avals, const emxArray_real32_T *b,
    const emxArray_char_T *solver, emxArray_real32_T *x, int *flag,
    float *relres, int *iter, emxArray_real32_T *reshis, double times[2]);

extern void petscSolveCRS_6args(
    const emxArray_int32_T *Arows, const emxArray_int32_T *Acols,
    const emxArray_real32_T *Avals, const emxArray_real32_T *b,
    const emxArray_char_T *solver, float rtol, emxArray_real32_T *x, int *flag,
    float *relres, int *iter, emxArray_real32_T *reshis, double times[2]);

extern void petscSolveCRS_7args(const emxArray_int32_T *Arows,
                                const emxArray_int32_T *Acols,
                                const emxArray_real32_T *Avals,
                                const emxArray_real32_T *b,
                                const emxArray_char_T *solver, float rtol,
                                int maxiter, emxArray_real32_T *x, int *flag,
                                float *relres, int *iter,
                                emxArray_real32_T *reshis, double times[2]);

extern void petscSolveCRS_8args(
    const emxArray_int32_T *Arows, const emxArray_int32_T *Acols,
    const emxArray_real32_T *Avals, const emxArray_real32_T *b,
    const emxArray_char_T *solver, float rtol, int maxiter,
    const emxArray_char_T *pctype, emxArray_real32_T *x, int *flag,
    float *relres, int *iter, emxArray_real32_T *reshis, double times[2]);

extern void petscSolveCRS_9args(
    const emxArray_int32_T *Arows, const emxArray_int32_T *Acols,
    const emxArray_real32_T *Avals, const emxArray_real32_T *b,
    const emxArray_char_T *solver, float rtol, int maxiter,
    const emxArray_char_T *pctype, const emxArray_char_T *solpack,
    emxArray_real32_T *x, int *flag, float *relres, int *iter,
    emxArray_real32_T *reshis, double times[2]);

extern void petscSolveCRS_initialize(void);

extern void petscSolveCRS_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
