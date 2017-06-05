#include "petscMatAssemblyEnd.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatAssemblyEnd returned error code %d\n";
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

void petscMatAssemblyEnd(const struct0_T *mat, int type, int *errCode, boolean_T
  *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  int loop_ub;
  Mat t_mat;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      if (mat->type->size[k] != 1 + (k << 1)) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(mat->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(mat->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_mat, 2);
    k = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mat, k, (int)sizeof(char));
    loop_ub = mat->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_mat->data[b_mat->size[0] * k] = mat->type->data[mat->type->size[0] * k];
    }

    b_mat->data[b_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = mat->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = mat->data->data[k];
  }

  t_mat = *(Mat*)(&data->data[0]);
  *errCode = MatAssemblyEnd(t_mat, type);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscMatAssemblyEnd_Final(const struct0_T *mat, int *errCode, boolean_T
  *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int type;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  static const char cv1[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  int loop_ub;
  Mat t_mat;
  p = false;
  b_p = false;
  type = 0;
  do {
    exitg2 = 0;
    if (type < 2) {
      if (mat->type->size[type] != 1 + (type << 1)) {
        exitg2 = 1;
      } else {
        type++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(mat->type->size[1] == 0))) {
    type = 0;
    exitg1 = false;
    while ((!exitg1) && (type < 3)) {
      if (!(mat->type->data[type] == cv1[type])) {
        b_p = false;
        exitg1 = true;
      } else {
        type++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_mat, 2);
    type = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mat, type, (int)sizeof(char));
    loop_ub = mat->type->size[1];
    for (type = 0; type < loop_ub; type++) {
      b_mat->data[b_mat->size[0] * type] = mat->type->data[mat->type->size[0] *
        type];
    }

    b_mat->data[b_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  emxInit_uint8_T(&data, 1);
  type = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, type, (int)sizeof(unsigned char));
  loop_ub = mat->data->size[0];
  for (type = 0; type < loop_ub; type++) {
    data->data[type] = mat->data->data[type];
  }

  t_mat = *(Mat*)(&data->data[0]);
  type = (MAT_FINAL_ASSEMBLY);
  *errCode = MatAssemblyEnd(t_mat, type);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscMatAssemblyEnd_initialize(void)
{
}

void petscMatAssemblyEnd_terminate(void)
{
}
