#include "petscPCSetOperators.h"
#include "petscPCSetOperators_types.h"
#include "m2c.h"
#include "petsc4m.h"

static boolean_T b_isequal(const emxArray_char_T *varargin_1);

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(int varargin_3);

static boolean_T isequal(const emxArray_char_T *varargin_1);

static void m2c_error(const emxArray_char_T *varargin_3);

static boolean_T b_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[3] = {'M', 'a', 't'};
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }
  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return b_p || p;
}

static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Mat.\n";
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

static void c_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "PCSetOperators returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[2] = {'P', 'C'};
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 2) {
    b_p = true;
  }
  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return b_p || p;
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
  fmt = "Incorrect data type %s. Expected PC.\n";
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

void petscPCSetOperators(const M2C_OpaqueType *pc, const M2C_OpaqueType *Amat,
                         const M2C_OpaqueType *Pmat, int *errCode,
                         boolean_T *toplevel)
{
  Mat t_Amat;
  Mat t_Pmat;
  PC t_pc;
  emxArray_char_T *b_pc;
  int i;
  int loop_ub;
  emxInit_char_T(&b_pc, 2);
  if (!isequal(pc->type)) {
    i = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = pc->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_pc, i);
    loop_ub = pc->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_pc->data[i] = pc->type->data[i];
    }
    b_pc->data[pc->type->size[1]] = '\x00';
    m2c_error(b_pc);
  }
  t_pc = *(PC *)(&pc->data->data[0]);
  if (!b_isequal(Amat->type)) {
    i = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = Amat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_pc, i);
    loop_ub = Amat->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_pc->data[i] = Amat->type->data[i];
    }
    b_pc->data[Amat->type->size[1]] = '\x00';
    b_m2c_error(b_pc);
  }
  t_Amat = *(Mat *)(&Amat->data->data[0]);
  if (!b_isequal(Pmat->type)) {
    i = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = Pmat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_pc, i);
    loop_ub = Pmat->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_pc->data[i] = Pmat->type->data[i];
    }
    b_pc->data[Pmat->type->size[1]] = '\x00';
    b_m2c_error(b_pc);
  }
  emxFree_char_T(&b_pc);
  t_Pmat = *(Mat *)(&Pmat->data->data[0]);
  *errCode = PCSetOperators(t_pc, t_Amat, t_Pmat);
  *toplevel = true;
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscPCSetOperators_AforP(const M2C_OpaqueType *ksp,
                               const M2C_OpaqueType *Amat, int *errCode,
                               boolean_T *toplevel)
{
  Mat t_Amat;
  PC t_pc;
  emxArray_char_T *b_ksp;
  int i;
  int loop_ub;
  emxInit_char_T(&b_ksp, 2);
  if (!isequal(ksp->type)) {
    i = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, i);
    loop_ub = ksp->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_ksp->data[i] = ksp->type->data[i];
    }
    b_ksp->data[ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
  }
  t_pc = *(PC *)(&ksp->data->data[0]);
  if (!b_isequal(Amat->type)) {
    i = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = Amat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_ksp, i);
    loop_ub = Amat->type->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_ksp->data[i] = Amat->type->data[i];
    }
    b_ksp->data[Amat->type->size[1]] = '\x00';
    b_m2c_error(b_ksp);
  }
  emxFree_char_T(&b_ksp);
  t_Amat = *(Mat *)(&Amat->data->data[0]);
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
