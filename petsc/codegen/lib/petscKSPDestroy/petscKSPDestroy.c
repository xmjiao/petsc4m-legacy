#include "petscKSPDestroy.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPDestroy returned error code %d\n",
            varargin_3);
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("PetscKSP:WrongType", "Incorrect data type %s. Expected KSP.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscKSPDestroy(const struct0_T *ksp, struct0_T *ksp_out, int *errCode,
                     boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv0[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data0;
  KSP t_ksp;
  int sizepe;
  char t0_type[3];
  static const char x2[3] = { 'K', 'S', 'P' };

  char * ptr;
  int i;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = ksp->type->size[k];
      if (i0 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp->type->data[k] == cv0[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_ksp, 2);
    i0 = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, i0, (int)sizeof(char));
    k = ksp->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_ksp->data[b_ksp->size[0] * i0] = ksp->type->data[ksp->type->size[0] * i0];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data0, 1);
  i0 = data0->size[0];
  data0->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data0->data[i0] = ksp->data->data[i0];
  }

  t_ksp = *(KSP*)(&data0->data[0]);
  *errCode = KSPDestroy(&t_ksp);
  *toplevel = true;
  sizepe = sizeof(KSP);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 3; i0++) {
    t0_type[i0] = x2[i0];
  }

  i0 = ksp_out->data->size[0];
  ksp_out->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp_out->data, i0, (int)sizeof(unsigned
    char));
  k = data0->size[0];
  for (i0 = 0; i0 < k; i0++) {
    ksp_out->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = ksp_out->type->size[0] * ksp_out->type->size[1];
  ksp_out->type->size[0] = 1;
  ksp_out->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp_out->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 3; i0++) {
    ksp_out->type->data[i0] = t0_type[i0];
  }

  ksp_out->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (i = 1; i <= sizepe; i++) {
    ksp_out->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscKSPDestroy_initialize(void)
{
}

void petscKSPDestroy_terminate(void)
{
}
