#include "petscMatNullSpaceCreateRigidBody.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatNullSpaceCreateRigidBody returned error code %d\n";
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
  fmt = "Incorrect data type %s. Expected Vec.\n";
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

void petscMatNullSpaceCreateRigidBody(const struct0_T *coords, struct0_T *nullsp,
  int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_coords;
  static const char cv0[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data0;
  int loop_ub;
  Vec t_coords;
  MatNullSpace t_nullsp;
  int sizepe;
  char t0_type[12];
  static const char cv1[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  char * ptr;
  p = false;
  b_p = false;
  if (coords->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(coords->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(coords->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_coords, 2);
    k = b_coords->size[0] * b_coords->size[1];
    b_coords->size[0] = 1;
    b_coords->size[1] = coords->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_coords, k);
    loop_ub = coords->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_coords->data[b_coords->size[0] * k] = coords->type->data[coords->
        type->size[0] * k];
    }

    b_coords->data[b_coords->size[0] * coords->type->size[1]] = '\x00';
    m2c_error(b_coords);
    emxFree_char_T(&b_coords);
  }

  emxInit_uint8_T(&data0, 1);
  k = data0->size[0];
  data0->size[0] = coords->data->size[0];
  emxEnsureCapacity_uint8_T(data0, k);
  loop_ub = coords->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data0->data[k] = coords->data->data[k];
  }

  t_coords = *(Vec*)(&data0->data[0]);
  *errCode = MatNullSpaceCreateRigidBody(t_coords, &t_nullsp);
  sizepe = sizeof(MatNullSpace);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, k);
  for (k = 0; k < 12; k++) {
    t0_type[k] = cv1[k];
  }

  k = nullsp->data->size[0];
  nullsp->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(nullsp->data, k);
  loop_ub = data0->size[0];
  for (k = 0; k < loop_ub; k++) {
    nullsp->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = nullsp->type->size[0] * nullsp->type->size[1];
  nullsp->type->size[0] = 1;
  nullsp->type->size[1] = 12;
  emxEnsureCapacity_char_T(nullsp->type, k);
  for (k = 0; k < 12; k++) {
    nullsp->type->data[k] = t0_type[k];
  }

  nullsp->nitems = 1;
  ptr = (char *)(&t_nullsp);
  for (k = 1; k <= sizepe; k++) {
    nullsp->data->data[k - 1] = *(ptr);
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
