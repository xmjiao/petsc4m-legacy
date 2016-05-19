#ifndef MPTKSPSETUP_H
#define MPTKSPSETUP_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mptKSPSetup_types.h"

extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_uint8_T *emxCreateND_uint8_T(int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_uint8_T *emxCreateWrapperND_uint8_T(unsigned char *data, int
  numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_uint8_T *emxCreateWrapper_uint8_T(unsigned char *data, int rows,
  int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern emxArray_uint8_T *emxCreate_uint8_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxDestroyArray_uint8_T(emxArray_uint8_T *emxArray);
extern void emxDestroy_struct0_T(struct0_T emxArray);
extern void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern void emxInit_struct0_T(struct0_T *pStruct);
extern void mptKSPSetup(const struct0_T *Amat, const emxArray_char_T *ksptype,
  const emxArray_char_T *pctype, const emxArray_char_T *solpack, struct0_T *ksp,
  double *time, boolean_T *toplevel);
extern void mptKSPSetup_1arg(const struct0_T *Amat, struct0_T *ksp, double *time,
  boolean_T *toplevel);
extern void mptKSPSetup_2args(const struct0_T *Amat, const emxArray_char_T
  *ksptype, struct0_T *ksp, double *time, boolean_T *toplevel);
extern void mptKSPSetup_3args(const struct0_T *Amat, const emxArray_char_T
  *ksptype, const emxArray_char_T *pctype, struct0_T *ksp, double *time,
  boolean_T *toplevel);
extern void mptKSPSetup_initialize(void);
extern void mptKSPSetup_terminate(void);

#endif
