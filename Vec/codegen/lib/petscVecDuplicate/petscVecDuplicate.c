#include "petscVecDuplicate.h"
#include "petscVecDuplicate_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "VecDuplicate returned error code %d\n";
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
  fmt = "Incorrect data type %s. Expected Vec.\n";
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

void petscVecDuplicate(const M2C_OpaqueType *vec_in, M2C_OpaqueType *vec_out,
                       int *errCode, boolean_T *toplevel)
{
  static const char cv[3] = {'V', 'e', 'c'};
  Vec arg;
  Vec vec;
  char *ptr;
  emxArray_char_T *b_vec_in;
  int i;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (vec_in->type->size[1] == 3) {
    p = true;
  }
  if (p && (vec_in->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 3)) {
      if (!(vec_in->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_vec_in, 2);
    i = b_vec_in->size[0] * b_vec_in->size[1];
    b_vec_in->size[0] = 1;
    b_vec_in->size[1] = vec_in->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_vec_in, i);
    sizepe = vec_in->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_vec_in->data[i] = vec_in->type->data[i];
    }
    b_vec_in->data[vec_in->type->size[1]] = '\x00';
    m2c_error(b_vec_in);
    emxFree_char_T(&b_vec_in);
  }
  vec = *(Vec *)(&vec_in->data->data[0]);
  *errCode = VecDuplicate(vec, &arg);
  sizepe = sizeof(Vec);
  i = vec_out->data->size[0];
  vec_out->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(vec_out->data, i);
  i = vec_out->type->size[0] * vec_out->type->size[1];
  vec_out->type->size[0] = 1;
  vec_out->type->size[1] = 3;
  emxEnsureCapacity_char_T(vec_out->type, i);
  vec_out->type->data[0] = 'V';
  vec_out->type->data[1] = 'e';
  vec_out->type->data[2] = 'c';
  vec_out->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    vec_out->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
  *toplevel = true;
}

void petscVecDuplicate_initialize(void)
{
}

void petscVecDuplicate_terminate(void)
{
}
