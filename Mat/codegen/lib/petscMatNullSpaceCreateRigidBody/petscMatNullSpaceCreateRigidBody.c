#include "petscMatNullSpaceCreateRigidBody.h"
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
  fmt = "MatNullSpaceCreateRigidBody returned error code %d\n";
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

void petscMatNullSpaceCreateRigidBody(const struct0_T *coords, struct0_T *nullsp,
  int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_coords;
  emxArray_uint8_T *data0;
  int i;
  static const char cv[3] = { 'V', 'e', 'c' };

  Vec t_coords;
  MatNullSpace arg;
  static const char t0_type[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p',
    'a', 'c', 'e' };

  char * ptr;
  p = (coords->type->size[1] == 3);
  if (p && (coords->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 3)) {
      if (!(coords->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_coords, 2);
    i = b_coords->size[0] * b_coords->size[1];
    b_coords->size[0] = 1;
    b_coords->size[1] = coords->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_coords, i);
    sizepe = coords->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_coords->data[i] = coords->type->data[i];
    }

    b_coords->data[coords->type->size[1]] = '\x00';
    m2c_error(b_coords);
    emxFree_char_T(&b_coords);
  }

  emxInit_uint8_T(&data0, 1);
  t_coords = m2c_castdata(coords->data);
  *errCode = MatNullSpaceCreateRigidBody(t_coords, &arg);
  sizepe = sizeof(MatNullSpace);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = nullsp->data->size[0];
  nullsp->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(nullsp->data, i);
  for (i = 0; i < sizepe; i++) {
    nullsp->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = nullsp->type->size[0] * nullsp->type->size[1];
  nullsp->type->size[0] = 1;
  nullsp->type->size[1] = 12;
  emxEnsureCapacity_char_T(nullsp->type, i);
  for (i = 0; i < 12; i++) {
    nullsp->type->data[i] = t0_type[i];
  }

  nullsp->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    nullsp->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscMatNullSpaceCreateRigidBody_initialize(void)
{
}

void petscMatNullSpaceCreateRigidBody_terminate(void)
{
}
