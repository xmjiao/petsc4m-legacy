#include "petscMatNullSpaceDestroy.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatNullSpaceDestroy returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected MatNullSpace.\n";
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i0);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscMatNullSpaceDestroy(struct0_T *matNull, int *errCode, boolean_T
  *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_matNull;
  static const char cv0[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  emxArray_uint8_T *data0;
  int loop_ub;
  MatNullSpace t_mat;
  int sizepe;
  char t0_type[12];
  static const char x2[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  char * ptr;
  p = false;
  b_p = false;
  if (matNull->type->size[1] == 12) {
    b_p = true;
  }

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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_matNull, 2);
    k = b_matNull->size[0] * b_matNull->size[1];
    b_matNull->size[0] = 1;
    b_matNull->size[1] = matNull->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_matNull, k);
    loop_ub = matNull->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_matNull->data[b_matNull->size[0] * k] = matNull->type->data
        [matNull->type->size[0] * k];
    }

    b_matNull->data[b_matNull->size[0] * matNull->type->size[1]] = '\x00';
    m2c_error(b_matNull);
    emxFree_char_T(&b_matNull);
  }

  emxInit_uint8_T(&data0, 1);
  k = data0->size[0];
  data0->size[0] = matNull->data->size[0];
  emxEnsureCapacity_uint8_T(data0, k);
  loop_ub = matNull->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data0->data[k] = matNull->data->data[k];
  }

  t_mat = *(MatNullSpace*)(&data0->data[0]);
  *errCode = MatNullSpaceDestroy(&t_mat);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  sizepe = sizeof(MatNullSpace);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, k);
  for (k = 0; k < 12; k++) {
    t0_type[k] = x2[k];
  }

  k = matNull->data->size[0];
  matNull->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(matNull->data, k);
  loop_ub = data0->size[0];
  for (k = 0; k < loop_ub; k++) {
    matNull->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = matNull->type->size[0] * matNull->type->size[1];
  matNull->type->size[0] = 1;
  matNull->type->size[1] = 12;
  emxEnsureCapacity_char_T(matNull->type, k);
  for (k = 0; k < 12; k++) {
    matNull->type->data[k] = t0_type[k];
  }

  matNull->nitems = 1;
  ptr = (char *)(&t_mat);
  for (k = 1; k <= sizepe; k++) {
    matNull->data->data[k - 1] = *(ptr);
    ptr = ptr + 1;
  }
}

void petscMatNullSpaceDestroy_initialize(void)
{
}

void petscMatNullSpaceDestroy_terminate(void)
{
}
