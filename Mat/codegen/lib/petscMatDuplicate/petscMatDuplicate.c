#include "petscMatDuplicate.h"
#include "petscMatDuplicate_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "Petsc4m:petscMatDuplicate:RuntimeError";
  fmt = "MatDuplicate returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  const char *varargin_3_data;
  char *b_varargin_3_data;
  varargin_3_data = varargin_3->data;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Mat.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  b_varargin_3_data = b_varargin_3->data;
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3_data[i] = varargin_3_data[i];
  }
  M2C_error(msgid, fmt, &b_varargin_3_data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscMatDuplicate(const M2C_OpaqueType *mat_in, int op,
                       M2C_OpaqueType *mat_out, int *errCode,
                       boolean_T *toplevel)
{
  static const char cv[3] = {'M', 'a', 't'};
  Mat arg;
  Mat mat;
  char *ptr;
  emxArray_char_T *b_mat_in;
  int i;
  int sizepe;
  char *mat_in_data;
  boolean_T p;
  p = (mat_in->type->size[1] == 3);
  if (p && (mat_in->type->size[1] != 0)) {
    boolean_T exitg1;
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 3)) {
      if (mat_in->type->data[sizepe] != cv[sizepe]) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  if (!p) {
    emxInit_char_T(&b_mat_in, 2);
    i = b_mat_in->size[0] * b_mat_in->size[1];
    b_mat_in->size[0] = 1;
    b_mat_in->size[1] = mat_in->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat_in, i);
    mat_in_data = b_mat_in->data;
    sizepe = mat_in->type->size[1];
    for (i = 0; i < sizepe; i++) {
      mat_in_data[i] = mat_in->type->data[i];
    }
    mat_in_data[mat_in->type->size[1]] = '\x00';
    m2c_error(b_mat_in);
    emxFree_char_T(&b_mat_in);
  }
  mat = *(Mat *)(&mat_in->data->data[0]);
  *errCode = MatDuplicate(mat, op, &arg);
  sizepe = sizeof(Mat);
  i = mat_out->data->size[0];
  mat_out->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(mat_out->data, i);
  i = mat_out->type->size[0] * mat_out->type->size[1];
  mat_out->type->size[0] = 1;
  mat_out->type->size[1] = 3;
  emxEnsureCapacity_char_T(mat_out->type, i);
  mat_out->type->data[0] = 'M';
  mat_out->type->data[1] = 'a';
  mat_out->type->data[2] = 't';
  mat_out->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    mat_out->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
  *toplevel = true;
}

void petscMatDuplicate_initialize(void)
{
}

void petscMatDuplicate_terminate(void)
{
}
