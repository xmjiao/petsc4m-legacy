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
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected MatNullSpace.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
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
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (matNull->type->size[1] == 12) {
    p = true;
  }
  if (p && (matNull->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 12)) {
      if (!(matNull->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_matNull, 2);
    i = b_matNull->size[0] * b_matNull->size[1];
    b_matNull->size[0] = 1;
    b_matNull->size[1] = matNull->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_matNull, i);
    sizepe = matNull->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_matNull->data[i] = matNull->type->data[i];
    }
    b_matNull->data[matNull->type->size[1]] = '\x00';
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
