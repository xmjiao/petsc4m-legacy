#include "petscMatGetInfo.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void c_m2c_error(int varargin_3, unsigned int varargin_4);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "petscMatGetInfo returned error code %d\n",
            varargin_3);
}

static void c_m2c_error(int varargin_3, unsigned int varargin_4)
{
  M2C_error("petscMatGetInfo:WrongSize",
            "There are %d fields in PetscMatInfo but %d fields in MatInfo.",
            varargin_3, varargin_4);
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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected Mat.\n", &b_varargin_3->data[0]);
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

void petscMatGetInfo(const struct0_T *mat, int flag, MPetscMatInfo *info, int
                     *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  Mat t_mat;
  MatInfo t_info;
  unsigned int nbytes;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = mat->type->size[k];
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

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_mat, 2);
    i0 = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mat, i0, (int)sizeof(char));
    k = mat->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_mat->data[b_mat->size[0] * i0] = mat->type->data[mat->type->size[0] * i0];
    }

    b_mat->data[b_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = mat->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = mat->data->data[i0];
  }

  t_mat = *(Mat*)(&data->data[0]);
  *errCode = MatGetInfo(t_mat, flag, &t_info);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  nbytes = sizeof(t_info);
  if (80U < nbytes) {
    k = (M2C_DEBUG);
    if (k != 0) {
      c_m2c_error(10, nbytes >> 3U);
    }
  }

  memcpy(info, &t_info, nbytes);
}

void petscMatGetInfo_Local(const struct0_T *mat, MPetscMatInfo *info, int
  *errCode)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i2;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  static const char cv1[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  Mat t_mat;
  int flag;
  MatInfo t_info;
  unsigned int nbytes;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i2 = mat->type->size[k];
      if (i2 != (k << 1) + 1) {
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
      if (!(mat->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_mat, 2);
    i2 = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mat, i2, (int)sizeof(char));
    k = mat->type->size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_mat->data[b_mat->size[0] * i2] = mat->type->data[mat->type->size[0] * i2];
    }

    b_mat->data[b_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  emxInit_uint8_T(&data, 1);
  i2 = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i2, (int)sizeof(unsigned char));
  k = mat->data->size[0];
  for (i2 = 0; i2 < k; i2++) {
    data->data[i2] = mat->data->data[i2];
  }

  t_mat = *(Mat*)(&data->data[0]);
  flag = (MAT_LOCAL);
  *errCode = MatGetInfo(t_mat, flag, &t_info);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      b_m2c_error(*errCode);
    }
  }

  nbytes = sizeof(t_info);
  if (80U < nbytes) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      c_m2c_error(10, nbytes >> 3U);
    }
  }

  memcpy(info, &t_info, nbytes);
}

void petscMatGetInfo_initialize(void)
{
}

void petscMatGetInfo_terminate(void)
{
}
