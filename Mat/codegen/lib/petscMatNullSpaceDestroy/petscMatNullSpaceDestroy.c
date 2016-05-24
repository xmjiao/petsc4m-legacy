#include "petscMatNullSpaceDestroy.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatNullSpaceDestroy returned error code %d\n",
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
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MatNullSpace.\n",
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

void petscMatNullSpaceDestroy(struct0_T *matNull, int *errCode, boolean_T
  *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i1;
  boolean_T exitg1;
  emxArray_char_T *b_matNull;
  static const char cv0[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  emxArray_uint8_T *data0;
  MatNullSpace t_mat;
  int sizepe;
  char t0_type[12];
  static const char x2[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  char * ptr;
  int i;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i1 = matNull->type->size[k];
      if (i1 != 11 * k + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(matNull->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(matNull->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_matNull, 2);
    i1 = b_matNull->size[0] * b_matNull->size[1];
    b_matNull->size[0] = 1;
    b_matNull->size[1] = matNull->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_matNull, i1, (int)sizeof(char));
    k = matNull->type->size[1];
    for (i1 = 0; i1 < k; i1++) {
      b_matNull->data[b_matNull->size[0] * i1] = matNull->type->data
        [matNull->type->size[0] * i1];
    }

    b_matNull->data[b_matNull->size[0] * matNull->type->size[1]] = '\x00';
    m2c_error(b_matNull);
    emxFree_char_T(&b_matNull);
  }

  emxInit_uint8_T(&data0, 1);
  i1 = data0->size[0];
  data0->size[0] = matNull->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i1, (int)sizeof(unsigned char));
  k = matNull->data->size[0];
  for (i1 = 0; i1 < k; i1++) {
    data0->data[i1] = matNull->data->data[i1];
  }

  t_mat = *(MatNullSpace*)(&data0->data[0]);
  *errCode = MatNullSpaceDestroy(&t_mat);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  sizepe = sizeof(MatNullSpace);
  i1 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i1, (int)sizeof(unsigned char));
  for (i1 = 0; i1 < 12; i1++) {
    t0_type[i1] = x2[i1];
  }

  i1 = matNull->data->size[0];
  matNull->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)matNull->data, i1, (int)sizeof(unsigned
    char));
  k = data0->size[0];
  for (i1 = 0; i1 < k; i1++) {
    matNull->data->data[i1] = data0->data[i1];
  }

  emxFree_uint8_T(&data0);
  i1 = matNull->type->size[0] * matNull->type->size[1];
  matNull->type->size[0] = 1;
  matNull->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)matNull->type, i1, (int)sizeof(char));
  for (i1 = 0; i1 < 12; i1++) {
    matNull->type->data[i1] = t0_type[i1];
  }

  matNull->nitems = 1;
  ptr = (char *)(&t_mat);
  for (i = 1; i <= sizepe; i++) {
    matNull->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }
}

void petscMatNullSpaceDestroy_initialize(void)
{
}

void petscMatNullSpaceDestroy_terminate(void)
{
}
