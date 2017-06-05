#include "petscMatMultHermitianTransposeAdd.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
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
  fmt = "Incorrect data type %s. Expected Vec.\n";
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
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
  fmt = "MatMultHermitianTransposeAdd returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
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
  const char * msgid;
  const char * fmt;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Mat.\n";
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
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

void petscMatMultHermitianTransposeAdd(const struct0_T *A, const struct0_T *v1,
  const struct0_T *v2, const struct0_T *v3, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg8;
  boolean_T exitg7;
  emxArray_char_T *b_A;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  int loop_ub;
  Mat mat;
  int exitg6;
  boolean_T exitg5;
  emxArray_char_T *b_v1;
  static const char cv1[3] = { 'V', 'e', 'c' };

  Vec vec;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *b_v2;
  Vec b_vec;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_v3;
  Vec c_vec;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg8 = 0;
    if (k < 2) {
      if (A->type->size[k] != 1 + (k << 1)) {
        exitg8 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg8 = 1;
    }
  } while (exitg8 == 0);

  if (b_p && (!(A->type->size[1] == 0))) {
    k = 0;
    exitg7 = false;
    while ((!exitg7) && (k < 3)) {
      if (!(A->type->data[k] == cv0[k])) {
        b_p = false;
        exitg7 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_A, 2);
    k = b_A->size[0] * b_A->size[1];
    b_A->size[0] = 1;
    b_A->size[1] = A->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_A, k, (int)sizeof(char));
    loop_ub = A->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_A->data[b_A->size[0] * k] = A->type->data[A->type->size[0] * k];
    }

    b_A->data[b_A->size[0] * A->type->size[1]] = '\x00';
    m2c_error(b_A);
    emxFree_char_T(&b_A);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = A->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = A->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = A->data->data[k];
  }

  mat = *(Mat*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg6 = 0;
    if (k < 2) {
      if (v1->type->size[k] != 1 + (k << 1)) {
        exitg6 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg6 = 1;
    }
  } while (exitg6 == 0);

  if (b_p && (!(v1->type->size[1] == 0))) {
    k = 0;
    exitg5 = false;
    while ((!exitg5) && (k < 3)) {
      if (!(v1->type->data[k] == cv1[k])) {
        b_p = false;
        exitg5 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_v1, 2);
    k = b_v1->size[0] * b_v1->size[1];
    b_v1->size[0] = 1;
    b_v1->size[1] = v1->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_v1, k, (int)sizeof(char));
    loop_ub = v1->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_v1->data[b_v1->size[0] * k] = v1->type->data[v1->type->size[0] * k];
    }

    b_v1->data[b_v1->size[0] * v1->type->size[1]] = '\x00';
    b_m2c_error(b_v1);
    emxFree_char_T(&b_v1);
  }

  k = data->size[0];
  data->size[0] = v1->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = v1->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = v1->data->data[k];
  }

  vec = *(Vec*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      if (v2->type->size[k] != 1 + (k << 1)) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(v2->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(v2->type->data[k] == cv1[k])) {
        b_p = false;
        exitg3 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_v2, 2);
    k = b_v2->size[0] * b_v2->size[1];
    b_v2->size[0] = 1;
    b_v2->size[1] = v2->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_v2, k, (int)sizeof(char));
    loop_ub = v2->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_v2->data[b_v2->size[0] * k] = v2->type->data[v2->type->size[0] * k];
    }

    b_v2->data[b_v2->size[0] * v2->type->size[1]] = '\x00';
    b_m2c_error(b_v2);
    emxFree_char_T(&b_v2);
  }

  k = data->size[0];
  data->size[0] = v2->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = v2->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = v2->data->data[k];
  }

  b_vec = *(Vec*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      if (v3->type->size[k] != 1 + (k << 1)) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(v3->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(v3->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_v3, 2);
    k = b_v3->size[0] * b_v3->size[1];
    b_v3->size[0] = 1;
    b_v3->size[1] = v3->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_v3, k, (int)sizeof(char));
    loop_ub = v3->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_v3->data[b_v3->size[0] * k] = v3->type->data[v3->type->size[0] * k];
    }

    b_v3->data[b_v3->size[0] * v3->type->size[1]] = '\x00';
    b_m2c_error(b_v3);
    emxFree_char_T(&b_v3);
  }

  k = data->size[0];
  data->size[0] = v3->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = v3->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = v3->data->data[k];
  }

  c_vec = *(Vec*)(&data->data[0]);
  *errCode = MatMultHermitianTransposeAdd(mat, vec, b_vec, c_vec);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscMatMultHermitianTransposeAdd_initialize(void)
{
}

void petscMatMultHermitianTransposeAdd_terminate(void)
{
}
