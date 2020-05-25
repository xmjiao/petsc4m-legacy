#include "petscVecDestroy.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static Vec m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "VecDestroy returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static Vec m2c_castdata(const emxArray_uint8_T *data)
{
  return *(Vec*)(&data->data[0]);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Vec.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscVecDestroy(struct0_T *vec, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_vec;
  emxArray_uint8_T *data0;
  int i;
  static const char cv[3] = { 'V', 'e', 'c' };

  Vec arg;
  char * ptr;
  p = (vec->type->size[1] == 3);
  if (p && (vec->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 3)) {
      if (!(vec->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_vec, 2);
    i = b_vec->size[0] * b_vec->size[1];
    b_vec->size[0] = 1;
    b_vec->size[1] = vec->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_vec, i);
    sizepe = vec->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_vec->data[i] = vec->type->data[i];
    }

    b_vec->data[vec->type->size[1]] = '\x00';
    m2c_error(b_vec);
    emxFree_char_T(&b_vec);
  }

  emxInit_uint8_T(&data0, 1);
  arg = m2c_castdata(vec->data);
  *errCode = VecDestroy(&arg);
  *toplevel = true;
  sizepe = sizeof(Vec);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = vec->data->size[0];
  vec->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(vec->data, i);
  for (i = 0; i < sizepe; i++) {
    vec->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = vec->type->size[0] * vec->type->size[1];
  vec->type->size[0] = 1;
  vec->type->size[1] = 3;
  emxEnsureCapacity_char_T(vec->type, i);
  vec->type->data[0] = 'V';
  vec->type->data[1] = 'e';
  vec->type->data[2] = 'c';
  vec->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    vec->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscVecDestroy_initialize(void)
{
}

void petscVecDestroy_terminate(void)
{
}
