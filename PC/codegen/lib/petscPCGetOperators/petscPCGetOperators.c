#include "petscPCGetOperators.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCGetOperators returned error code %d\n",
            varargin_3);
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
  emxEnsureCapacity_char_T(b_varargin_3, i0);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected PC.\n", &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscPCGetOperators(const M2C_OpaqueType *pc, struct0_T *Amat, struct0_T
  *Pmat, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_pc;
  static const char cv0[2] = { 'P', 'C' };

  emxArray_uint8_T *data;
  int loop_ub;
  emxArray_uint8_T *data0;
  PC c_pc;
  Mat Amat_t;
  Mat Pmat_t;
  int sizepe;
  char t0_type[3];
  static const char cv1[3] = { 'M', 'a', 't' };

  char * ptr;
  int i;
  p = false;
  b_p = false;
  if (pc->type->size[1] == 2) {
    b_p = true;
  }

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

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_pc, 2);
    k = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = pc->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_pc, k);
    loop_ub = pc->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_pc->data[b_pc->size[0] * k] = pc->type->data[pc->type->size[0] * k];
    }

    b_pc->data[b_pc->size[0] * pc->type->size[1]] = '\x00';
    m2c_error(b_pc);
    emxFree_char_T(&b_pc);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = pc->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = pc->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = pc->data->data[k];
  }

  emxInit_uint8_T(&data0, 1);
  c_pc = *(PC*)(&data->data[0]);
  *errCode = PCGetOperators(c_pc, &Amat_t, &Pmat_t);
  sizepe = sizeof(Mat);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, k);
  emxFree_uint8_T(&data);
  for (k = 0; k < 3; k++) {
    t0_type[k] = cv1[k];
  }

  k = Amat->data->size[0];
  Amat->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(Amat->data, k);
  loop_ub = data0->size[0];
  for (k = 0; k < loop_ub; k++) {
    Amat->data->data[k] = data0->data[k];
  }

  k = Amat->type->size[0] * Amat->type->size[1];
  Amat->type->size[0] = 1;
  Amat->type->size[1] = 3;
  emxEnsureCapacity_char_T(Amat->type, k);
  for (k = 0; k < 3; k++) {
    Amat->type->data[k] = t0_type[k];
  }

  Amat->nitems = 1;
  ptr = (char *)(&Amat_t);
  for (i = 1; i <= sizepe; i++) {
    Amat->data->data[i - 1] = *(ptr);
    ptr = ptr + 1;
  }

  sizepe = sizeof(Mat);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, k);
  for (k = 0; k < 3; k++) {
    t0_type[k] = cv1[k];
  }

  k = Pmat->data->size[0];
  Pmat->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(Pmat->data, k);
  loop_ub = data0->size[0];
  for (k = 0; k < loop_ub; k++) {
    Pmat->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = Pmat->type->size[0] * Pmat->type->size[1];
  Pmat->type->size[0] = 1;
  Pmat->type->size[1] = 3;
  emxEnsureCapacity_char_T(Pmat->type, k);
  for (k = 0; k < 3; k++) {
    Pmat->type->data[k] = t0_type[k];
  }

  Pmat->nitems = 1;
  ptr = (char *)(&Pmat_t);
  for (i = 1; i <= sizepe; i++) {
    Pmat->data->data[i - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscPCGetOperators_initialize(void)
{
}

void petscPCGetOperators_terminate(void)
{
}
