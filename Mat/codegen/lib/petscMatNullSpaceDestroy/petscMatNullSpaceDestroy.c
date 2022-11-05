#include "petscMatNullSpaceDestroy.h"
#include "petscMatNullSpaceDestroy_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "MatNullSpaceDestroy returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  const char *varargin_3_data;
  char *b_varargin_3_data;
  varargin_3_data = varargin_3->data;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected MatNullSpace.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  b_varargin_3_data = b_varargin_3->data;
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3_data[i] = varargin_3_data[i];
  }
  M2C_error(msgid, fmt, &b_varargin_3_data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscMatNullSpaceDestroy(M2C_OpaqueType *matNull, int *errCode,
                              boolean_T *toplevel)
{
  static const char cv[12] = {'M', 'a', 't', 'N', 'u', 'l',
                              'l', 'S', 'p', 'a', 'c', 'e'};
  static const char x2[12] = {'M', 'a', 't', 'N', 'u', 'l',
                              'l', 'S', 'p', 'a', 'c', 'e'};
  MatNullSpace arg;
  char *ptr;
  emxArray_char_T *b_matNull;
  int i;
  int sizepe;
  char *matNull_data;
  boolean_T p;
  p = (matNull->type->size[1] == 12);
  if (p && (matNull->type->size[1] != 0)) {
    boolean_T exitg1;
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 12)) {
      if (matNull->type->data[sizepe] != cv[sizepe]) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  if (!p) {
    emxInit_char_T(&b_matNull, 2);
    i = b_matNull->size[0] * b_matNull->size[1];
    b_matNull->size[0] = 1;
    b_matNull->size[1] = matNull->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_matNull, i);
    matNull_data = b_matNull->data;
    sizepe = matNull->type->size[1];
    for (i = 0; i < sizepe; i++) {
      matNull_data[i] = matNull->type->data[i];
    }
    matNull_data[matNull->type->size[1]] = '\x00';
    m2c_error(b_matNull);
    emxFree_char_T(&b_matNull);
  }
  arg = *(MatNullSpace *)(&matNull->data->data[0]);
  *errCode = MatNullSpaceDestroy(&arg);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
  sizepe = sizeof(MatNullSpace);
  i = matNull->data->size[0];
  matNull->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(matNull->data, i);
  i = matNull->type->size[0] * matNull->type->size[1];
  matNull->type->size[0] = 1;
  matNull->type->size[1] = 12;
  emxEnsureCapacity_char_T(matNull->type, i);
  for (i = 0; i < 12; i++) {
    matNull->type->data[i] = x2[i];
  }
  matNull->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    matNull->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }
}

void petscMatNullSpaceDestroy_initialize(void)
{
}

void petscMatNullSpaceDestroy_terminate(void)
{
}
