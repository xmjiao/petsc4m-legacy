#include "petscMatGetInfo.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static Mat m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "petscMatGetInfo returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static Mat m2c_castdata(const emxArray_uint8_T *data)
{
  return *(Mat*)(&data->data[0]);
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

void petscMatGetInfo(const struct0_T *mat, int flag, PetscMatInfo *info, int
                     *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  Mat t_mat;
  int i;
  static const char cv[3] = { 'M', 'a', 't' };

  MatInfo t_info;
  unsigned int nbytes;
  p = (mat->type->size[1] == 3);
  if (p && (mat->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(mat->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_mat, 2);
    i = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat, i);
    k = mat->type->size[1];
    for (i = 0; i < k; i++) {
      b_mat->data[i] = mat->type->data[i];
    }

    b_mat->data[mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  t_mat = m2c_castdata(mat->data);
  *errCode = MatGetInfo(t_mat, flag, &t_info);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  nbytes = sizeof(t_info);
  memcpy(info, &t_info, nbytes);
}

void petscMatGetInfo_Local(const struct0_T *mat, PetscMatInfo *info, int
  *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int flag;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  Mat t_mat;
  int i;
  static const char cv[3] = { 'M', 'a', 't' };

  MatInfo t_info;
  unsigned int nbytes;
  p = (mat->type->size[1] == 3);
  if (p && (mat->type->size[1] != 0)) {
    flag = 0;
    exitg1 = false;
    while ((!exitg1) && (flag < 3)) {
      if (!(mat->type->data[flag] == cv[flag])) {
        p = false;
        exitg1 = true;
      } else {
        flag++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_mat, 2);
    i = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat, i);
    flag = mat->type->size[1];
    for (i = 0; i < flag; i++) {
      b_mat->data[i] = mat->type->data[i];
    }

    b_mat->data[mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  t_mat = m2c_castdata(mat->data);
  flag = (MAT_LOCAL);
  *errCode = MatGetInfo(t_mat, flag, &t_info);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  nbytes = sizeof(t_info);
  memcpy(info, &t_info, nbytes);
  *toplevel = true;
}

void petscMatGetInfo_initialize(void)
{
}

void petscMatGetInfo_terminate(void)
{
}
