#include "petscPCApply.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("PetscVec:WrongType", "Incorrect data type %s. Expected Vec.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCApply returned error code %d\n", varargin_3);
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("PetscPC:WrongType", "Incorrect data type %s. Expected PC.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscPCApply(const struct0_T *pc, const struct0_T *b, const struct0_T *x,
                  int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg6;
  int i0;
  boolean_T exitg5;
  emxArray_char_T *b_pc;
  static const char cv0[2] = { 'P', 'C' };

  emxArray_uint8_T *data;
  PC t_pc;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *b_b;
  static const char cv1[3] = { 'V', 'e', 'c' };

  Vec t_b;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_x;
  Vec t_x;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg6 = 0;
    if (k < 2) {
      i0 = pc->type->size[k];
      if (i0 != k + 1) {
        exitg6 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg6 = 1;
    }
  } while (exitg6 == 0);

  if (b_p && (!(pc->type->size[1] == 0))) {
    k = 0;
    exitg5 = false;
    while ((!exitg5) && (k < 2)) {
      if (!(pc->type->data[k] == cv0[k])) {
        b_p = false;
        exitg5 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_pc, 2);
    i0 = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = pc->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_pc, i0, (int)sizeof(char));
    k = pc->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_pc->data[b_pc->size[0] * i0] = pc->type->data[pc->type->size[0] * i0];
    }

    b_pc->data[b_pc->size[0] * pc->type->size[1]] = '\x00';
    m2c_error(b_pc);
    emxFree_char_T(&b_pc);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = pc->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = pc->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = pc->data->data[i0];
  }

  t_pc = *(PC*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i0 = b->type->size[k];
      if (i0 != (k << 1) + 1) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(b->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(b->type->data[k] == cv1[k])) {
        b_p = false;
        exitg3 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_b, 2);
    i0 = b_b->size[0] * b_b->size[1];
    b_b->size[0] = 1;
    b_b->size[1] = b->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_b, i0, (int)sizeof(char));
    k = b->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_b->data[b_b->size[0] * i0] = b->type->data[b->type->size[0] * i0];
    }

    b_b->data[b_b->size[0] * b->type->size[1]] = '\x00';
    b_m2c_error(b_b);
    emxFree_char_T(&b_b);
  }

  i0 = data->size[0];
  data->size[0] = b->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = b->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = b->data->data[i0];
  }

  t_b = *(Vec*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = x->type->size[k];
      if (i0 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(x->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(x->type->data[k] == cv1[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_x, 2);
    i0 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_x, i0, (int)sizeof(char));
    k = x->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_x->data[b_x->size[0] * i0] = x->type->data[x->type->size[0] * i0];
    }

    b_x->data[b_x->size[0] * x->type->size[1]] = '\x00';
    b_m2c_error(b_x);
    emxFree_char_T(&b_x);
  }

  i0 = data->size[0];
  data->size[0] = x->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = x->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = x->data->data[i0];
  }

  t_x = *(Vec*)(&data->data[0]);
  *errCode = PCApply(t_pc, t_b, t_x);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscPCApply_2args(const struct0_T *ksp, const struct0_T *b, int *errCode,
  boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg4;
  int i3;
  boolean_T exitg3;
  emxArray_char_T *b_ksp;
  static const char cv2[2] = { 'P', 'C' };

  emxArray_uint8_T *data;
  PC t_pc;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_b;
  static const char cv3[3] = { 'V', 'e', 'c' };

  Vec t_b;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i3 = ksp->type->size[k];
      if (i3 != k + 1) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 2)) {
      if (!(ksp->type->data[k] == cv2[k])) {
        b_p = false;
        exitg3 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_ksp, 2);
    i3 = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, i3, (int)sizeof(char));
    k = ksp->type->size[1];
    for (i3 = 0; i3 < k; i3++) {
      b_ksp->data[b_ksp->size[0] * i3] = ksp->type->data[ksp->type->size[0] * i3];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  i3 = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i3, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (i3 = 0; i3 < k; i3++) {
    data->data[i3] = ksp->data->data[i3];
  }

  t_pc = *(PC*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i3 = b->type->size[k];
      if (i3 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(b->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(b->type->data[k] == cv3[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_b, 2);
    i3 = b_b->size[0] * b_b->size[1];
    b_b->size[0] = 1;
    b_b->size[1] = b->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_b, i3, (int)sizeof(char));
    k = b->type->size[1];
    for (i3 = 0; i3 < k; i3++) {
      b_b->data[b_b->size[0] * i3] = b->type->data[b->type->size[0] * i3];
    }

    b_b->data[b_b->size[0] * b->type->size[1]] = '\x00';
    b_m2c_error(b_b);
    emxFree_char_T(&b_b);
  }

  i3 = data->size[0];
  data->size[0] = b->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i3, (int)sizeof(unsigned char));
  k = b->data->size[0];
  for (i3 = 0; i3 < k; i3++) {
    data->data[i3] = b->data->data[i3];
  }

  t_b = *(Vec*)(&data->data[0]);
  *errCode = PCApply(t_pc, t_b, t_b);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscPCApply_initialize(void)
{
}

void petscPCApply_terminate(void)
{
}
