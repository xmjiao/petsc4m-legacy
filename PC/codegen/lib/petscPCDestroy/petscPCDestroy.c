#include "petscPCDestroy.h"
#include "petscPCDestroy_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "PCDestroy returned error code %d\n";
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

void petscPCDestroy(M2C_OpaqueType *pc, int *errCode, boolean_T *toplevel)
{
  static const char cv[2] = {'P', 'C'};
  PC arg;
  char *ptr;
  emxArray_char_T *b_pc;
  int i;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (pc->type->size[1] == 2) {
    p = true;
  }
  if (p && (pc->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 2)) {
      if (!(pc->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_pc, 2);
    i = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = pc->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_pc, i);
    sizepe = pc->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_pc->data[i] = pc->type->data[i];
    }
    b_pc->data[pc->type->size[1]] = '\x00';
    m2c_error(b_pc);
    emxFree_char_T(&b_pc);
  }
  arg = *(PC *)(&pc->data->data[0]);
  *errCode = PCDestroy(&arg);
  *toplevel = true;
  sizepe = sizeof(PC);
  i = pc->data->size[0];
  pc->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(pc->data, i);
  i = pc->type->size[0] * pc->type->size[1];
  pc->type->size[0] = 1;
  pc->type->size[1] = 2;
  emxEnsureCapacity_char_T(pc->type, i);
  pc->type->data[0] = 'P';
  pc->type->data[1] = 'C';
  pc->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    pc->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscPCDestroy_initialize(void)
{
}

void petscPCDestroy_terminate(void)
{
}
