#include "petscPCGetType.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static PC m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "PCGetType returned error code %d\n";
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

void petscPCGetType(const struct0_T *pc, emxArray_char_T *type, int *errCode,
                    boolean_T *toplevel)
{
  boolean_T p;
  int empty;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_pc;
  PC c_pc;
  int i;
  static const char cv[2] = { 'P', 'C' };

  PCType str_in;
  const char * str;
  emxArray_uint8_T *str1;
  int n;
  char * ptr;
  p = (pc->type->size[1] == 2);
  if (p && (pc->type->size[1] != 0)) {
    empty = 0;
    exitg1 = false;
    while ((!exitg1) && (empty < 2)) {
      if (!(pc->type->data[empty] == cv[empty])) {
        p = false;
        exitg1 = true;
      } else {
        empty++;
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
    empty = pc->type->size[1];
    for (i = 0; i < empty; i++) {
      b_pc->data[i] = pc->type->data[i];
    }

    b_pc->data[pc->type->size[1]] = '\x00';
    m2c_error(b_pc);
    emxFree_char_T(&b_pc);
  }

  c_pc = m2c_castdata(pc->data);
  *errCode = PCGetType(c_pc, &str_in);
  str = (str_in);
  empty = !(str);
  emxInit_uint8_T(&str1, 2);
  if (empty == 0) {
    n = strlen(str);
    i = str1->size[0] * str1->size[1];
    str1->size[0] = 1;
    str1->size[1] = n + 1;
    emxEnsureCapacity_uint8_T(str1, i);
    empty = n + 1;
    for (i = 0; i < empty; i++) {
      str1->data[i] = 0U;
    }

    ptr = (char *)(str);
    for (empty = 0; empty <= n; empty++) {
      str1->data[empty] = *(ptr);
      ptr = ptr + 1;
    }
  } else {
    str1->size[0] = 1;
    str1->size[1] = 0;
  }

  i = type->size[0] * type->size[1];
  type->size[0] = 1;
  type->size[1] = str1->size[1];
  emxEnsureCapacity_char_T(type, i);
  empty = str1->size[1];
  for (i = 0; i < empty; i++) {
    type->data[i] = (signed char)str1->data[i];
  }

  emxFree_uint8_T(&str1);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscPCGetType_initialize(void)
{
}

void petscPCGetType_terminate(void)
{
}
