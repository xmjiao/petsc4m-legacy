#include "petscPCSetOperators.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Mat.\n";
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "PCSetOperators returned error code %d\n";
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
  fmt = "Incorrect data type %s. Expected PC.\n";
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscPCSetOperators(const struct0_T *pc, const struct0_T *Amat, const
  struct0_T *Pmat, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_pc;
  static const char cv0[2] = { 'P', 'C' };

  emxArray_uint8_T *data;
  int loop_ub;
  PC t_pc;
  emxArray_char_T *b_Amat;
  static const char cv1[3] = { 'M', 'a', 't' };

  Mat t_Amat;
  emxArray_char_T *b_Pmat;
  Mat t_Pmat;
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
    emxEnsureCapacity((emxArray__common *)b_pc, k, sizeof(char));
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
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = pc->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = pc->data->data[k];
  }

  t_pc = *(PC*)(&data->data[0]);
  p = false;
  b_p = false;
  if (Amat->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(Amat->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Amat->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_Amat, 2);
    k = b_Amat->size[0] * b_Amat->size[1];
    b_Amat->size[0] = 1;
    b_Amat->size[1] = Amat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_Amat, k, sizeof(char));
    loop_ub = Amat->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_Amat->data[b_Amat->size[0] * k] = Amat->type->data[Amat->type->size[0] *
        k];
    }

    b_Amat->data[b_Amat->size[0] * Amat->type->size[1]] = '\x00';
    b_m2c_error(b_Amat);
    emxFree_char_T(&b_Amat);
  }

  k = data->size[0];
  data->size[0] = Amat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = Amat->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = Amat->data->data[k];
  }

  t_Amat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  if (Pmat->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(Pmat->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Pmat->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_Pmat, 2);
    k = b_Pmat->size[0] * b_Pmat->size[1];
    b_Pmat->size[0] = 1;
    b_Pmat->size[1] = Pmat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_Pmat, k, sizeof(char));
    loop_ub = Pmat->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_Pmat->data[b_Pmat->size[0] * k] = Pmat->type->data[Pmat->type->size[0] *
        k];
    }

    b_Pmat->data[b_Pmat->size[0] * Pmat->type->size[1]] = '\x00';
    b_m2c_error(b_Pmat);
    emxFree_char_T(&b_Pmat);
  }

  k = data->size[0];
  data->size[0] = Pmat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = Pmat->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = Pmat->data->data[k];
  }

  t_Pmat = *(Mat*)(&data->data[0]);
  *errCode = PCSetOperators(t_pc, t_Amat, t_Pmat);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscPCSetOperators_AforP(const struct0_T *ksp, const struct0_T *Amat, int *
  errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv2[2] = { 'P', 'C' };

  emxArray_uint8_T *data;
  int loop_ub;
  PC t_pc;
  emxArray_char_T *b_Amat;
  static const char cv3[3] = { 'M', 'a', 't' };

  Mat t_Amat;
  p = false;
  b_p = false;
  if (ksp->type->size[1] == 2) {
    b_p = true;
  }

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!(ksp->type->data[k] == cv2[k])) {
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
    emxInit_char_T(&b_ksp, 2);
    k = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, k, sizeof(char));
    loop_ub = ksp->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_ksp->data[b_ksp->size[0] * k] = ksp->type->data[ksp->type->size[0] * k];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = ksp->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = ksp->data->data[k];
  }

  t_pc = *(PC*)(&data->data[0]);
  p = false;
  b_p = false;
  if (Amat->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(Amat->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Amat->type->data[k] == cv3[k])) {
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
    emxInit_char_T(&b_Amat, 2);
    k = b_Amat->size[0] * b_Amat->size[1];
    b_Amat->size[0] = 1;
    b_Amat->size[1] = Amat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_Amat, k, sizeof(char));
    loop_ub = Amat->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_Amat->data[b_Amat->size[0] * k] = Amat->type->data[Amat->type->size[0] *
        k];
    }

    b_Amat->data[b_Amat->size[0] * Amat->type->size[1]] = '\x00';
    b_m2c_error(b_Amat);
    emxFree_char_T(&b_Amat);
  }

  k = data->size[0];
  data->size[0] = Amat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, sizeof(unsigned char));
  loop_ub = Amat->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = Amat->data->data[k];
  }

  t_Amat = *(Mat*)(&data->data[0]);
  *errCode = PCSetOperators(t_pc, t_Amat, t_Amat);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscPCSetOperators_initialize(void)
{
}

void petscPCSetOperators_terminate(void)
{
}
