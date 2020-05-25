#include "petscPCSetOperators.h"
#include "m2c.h"
#include "petsc4m.h"

static Mat b_m2c_castdata(const emxArray_uint8_T *data);
static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static PC m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static Mat b_m2c_castdata(const emxArray_uint8_T *data)
{
  return *(Mat*)(&data->data[0]);
}

static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Mat.\n";
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

static void c_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "PCSetOperators returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static PC m2c_castdata(const emxArray_uint8_T *data)
{
  return *(PC*)(&data->data[0]);
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
  fmt = "Incorrect data type %s. Expected PC.\n";
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

void petscPCSetOperators(const struct0_T *pc, const struct0_T *Amat, const
  struct0_T *Pmat, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_pc;
  int i;
  static const char cv[2] = { 'P', 'C' };

  PC t_pc;
  Mat t_Amat;
  static const char cv1[3] = { 'M', 'a', 't' };

  Mat t_Pmat;
  p = (pc->type->size[1] == 2);
  if (p && (pc->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!(pc->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_pc, 2);
  if (!b_p) {
    i = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = pc->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_pc, i);
    k = pc->type->size[1];
    for (i = 0; i < k; i++) {
      b_pc->data[i] = pc->type->data[i];
    }

    b_pc->data[pc->type->size[1]] = '\x00';
    m2c_error(b_pc);
  }

  t_pc = m2c_castdata(pc->data);
  p = (Amat->type->size[1] == 3);
  if (p && (Amat->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Amat->type->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = Amat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_pc, i);
    k = Amat->type->size[1];
    for (i = 0; i < k; i++) {
      b_pc->data[i] = Amat->type->data[i];
    }

    b_pc->data[Amat->type->size[1]] = '\x00';
    b_m2c_error(b_pc);
  }

  t_Amat = b_m2c_castdata(Amat->data);
  p = (Pmat->type->size[1] == 3);
  if (p && (Pmat->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Pmat->type->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = Pmat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_pc, i);
    k = Pmat->type->size[1];
    for (i = 0; i < k; i++) {
      b_pc->data[i] = Pmat->type->data[i];
    }

    b_pc->data[Pmat->type->size[1]] = '\x00';
    b_m2c_error(b_pc);
  }

  emxFree_char_T(&b_pc);
  t_Pmat = b_m2c_castdata(Pmat->data);
  *errCode = PCSetOperators(t_pc, t_Amat, t_Pmat);
  *toplevel = true;
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscPCSetOperators_AforP(const struct0_T *ksp, const struct0_T *Amat, int *
  errCode, boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  int i;
  static const char cv[2] = { 'P', 'C' };

  PC t_pc;
  static const char cv1[3] = { 'M', 'a', 't' };

  Mat t_Amat;
  p = (ksp->type->size[1] == 2);
  if (p && (ksp->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!(ksp->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_ksp, 2);
  if (!b_p) {
    i = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, i);
    k = ksp->type->size[1];
    for (i = 0; i < k; i++) {
      b_ksp->data[i] = ksp->type->data[i];
    }

    b_ksp->data[ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
  }

  t_pc = m2c_castdata(ksp->data);
  p = (Amat->type->size[1] == 3);
  if (p && (Amat->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Amat->type->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = Amat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, i);
    k = Amat->type->size[1];
    for (i = 0; i < k; i++) {
      b_ksp->data[i] = Amat->type->data[i];
    }

    b_ksp->data[Amat->type->size[1]] = '\x00';
    b_m2c_error(b_ksp);
  }

  emxFree_char_T(&b_ksp);
  t_Amat = b_m2c_castdata(Amat->data);
  *errCode = PCSetOperators(t_pc, t_Amat, t_Amat);
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
