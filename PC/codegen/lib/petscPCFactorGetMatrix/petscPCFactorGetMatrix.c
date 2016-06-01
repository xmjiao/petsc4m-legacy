#include "petscPCFactorGetMatrix.h"
#include "m2c.h"
#include "mpetsc.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCFactorGetMatrix returned error code %d\n",
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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected PC.\n", &b_varargin_3->data[0]);
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

void petscPCFactorGetMatrix(const struct0_T *pc, struct0_T *mat, int *errCode,
  boolean_T *toplevel)
{
  Mat t_mat;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_pc;
  static const char cv0[2] = { 'P', 'C' };

  emxArray_uint8_T *data0;
  PC c_pc;
  int sizepe;
  char t0_type[3];
  static const char cv1[3] = { 'M', 'a', 't' };

  char * ptr;
  int i;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = pc->type->size[k];
      if (i0 != k + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(pc->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!(pc->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_pc, 2);
    i0 = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = pc->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_pc, i0, (int)sizeof(char));
    k = pc->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_pc->data[b_pc->size[0] * i0] = pc->type->data[pc->type->size[0] * i0];
    }

    b_pc->data[b_pc->size[0] * pc->type->size[1]] = '\x00';
    m2c_error(b_pc);
    emxFree_char_T(&b_pc);
  }

  emxInit_uint8_T(&data0, 1);
  i0 = data0->size[0];
  data0->size[0] = pc->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  k = pc->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data0->data[i0] = pc->data->data[i0];
  }

  c_pc = *(PC*)(&data0->data[0]);
  *errCode = PCFactorGetMatrix(c_pc, &t_mat);
  *toplevel = true;
  sizepe = sizeof(Mat);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 3; i0++) {
    t0_type[i0] = cv1[i0];
  }

  i0 = mat->data->size[0];
  mat->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)mat->data, i0, (int)sizeof(unsigned char));
  k = data0->size[0];
  for (i0 = 0; i0 < k; i0++) {
    mat->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = mat->type->size[0] * mat->type->size[1];
  mat->type->size[0] = 1;
  mat->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)mat->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 3; i0++) {
    mat->type->data[i0] = t0_type[i0];
  }

  mat->nitems = 1;
  ptr = (char *)(&t_mat);
  for (i = 1; i <= sizepe; i++) {
    mat->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscPCFactorGetMatrix_initialize(void)
{
}

void petscPCFactorGetMatrix_terminate(void)
{
}
