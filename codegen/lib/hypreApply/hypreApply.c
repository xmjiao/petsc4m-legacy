#include "hypreApply.h"
#include "hypreApply_types.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static void m2c_error(const emxArray_char_T *varargin_3);

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

void hypreApply(const M2C_OpaqueType *pc, const emxArray_real32_T *x,
                emxArray_real32_T *y)
{
  static const char cv[2] = {'P', 'C'};
  MPI_Comm comm;
  PC t_pc;
  Vec xVec;
  Vec yVec;
  emxArray_char_T *b_pc;
  emxArray_int32_T *b_y;
  emxArray_int32_T *idx;
  int b_n;
  int k;
  int n;
  int yk;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  emxInit_int32_T(&b_y, 2);
  comm = PETSC_COMM_SELF;
  VecCreateSeq(comm, x->size[0], &xVec);
  if (x->size[0] - 1 < 0) {
    n = 0;
  } else {
    n = x->size[0];
  }
  k = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = n;
  emxEnsureCapacity_int32_T(b_y, k);
  if (n > 0) {
    b_y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= n; k++) {
      yk++;
      b_y->data[k - 1] = yk;
    }
  }
  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = b_y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  yk = b_y->size[1];
  for (k = 0; k < yk; k++) {
    idx->data[k] = b_y->data[k];
  }
  yk = (INSERT_VALUES);
  VecSetValues(xVec, x->size[0], &idx->data[0], &x->data[0], yk);
  VecAssemblyBegin(xVec);
  VecAssemblyEnd(xVec);
  VecDuplicate(xVec, &yVec);
  p = false;
  if (pc->type->size[1] == 2) {
    p = true;
  }
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
  if (!b_p) {
    emxInit_char_T(&b_pc, 2);
    k = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = pc->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_pc, k);
    yk = pc->type->size[1];
    for (k = 0; k < yk; k++) {
      b_pc->data[k] = pc->type->data[k];
    }
    b_pc->data[pc->type->size[1]] = '\x00';
    m2c_error(b_pc);
    emxFree_char_T(&b_pc);
  }
  t_pc = *(PC *)(&pc->data->data[0]);
  PCApply(t_pc, xVec, yVec);
  VecGetLocalSize(yVec, &n);
  k = y->size[0];
  y->size[0] = n;
  emxEnsureCapacity_real32_T(y, k);
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }
  k = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = b_n;
  emxEnsureCapacity_int32_T(b_y, k);
  if (b_n > 0) {
    b_y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      b_y->data[k - 1] = yk;
    }
  }
  k = idx->size[0];
  idx->size[0] = b_y->size[1];
  emxEnsureCapacity_int32_T(idx, k);
  yk = b_y->size[1];
  for (k = 0; k < yk; k++) {
    idx->data[k] = b_y->data[k];
  }
  emxFree_int32_T(&b_y);
  VecGetValues(yVec, n, &idx->data[0], &y->data[0]);
  VecDestroy(&xVec);
  VecDestroy(&yVec);
  emxFree_int32_T(&idx);
}

void hypreApply_initialize(void)
{
}

void hypreApply_terminate(void)
{
}
