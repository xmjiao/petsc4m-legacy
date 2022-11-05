#include "petscMatGetValues.h"
#include "petscMatGetValues_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "MatGetValues returned error code %d\n";
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

void petscMatGetValues(const M2C_OpaqueType *mat, int ni,
                       const emxArray_int32_T *ix, int nj,
                       const emxArray_int32_T *jx, emxArray_real_T *v,
                       int *errCode, boolean_T *toplevel)
{
  static const char cv[3] = {'M', 'a', 't'};
  Mat t_mat;
  emxArray_char_T *b_mat;
  double *v_data;
  const int *ix_data;
  const int *jx_data;
  int i;
  int k;
  const char *varargin_1_data;
  char *mat_data;
  boolean_T p;
  v_data = v->data;
  jx_data = jx->data;
  ix_data = ix->data;
  varargin_1_data = mat->type->data;
  p = (mat->type->size[1] == 3);
  if (p && (mat->type->size[1] != 0)) {
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (varargin_1_data[k] != cv[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (!p) {
    emxInit_char_T(&b_mat, 2);
    i = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat, i);
    mat_data = b_mat->data;
    k = mat->type->size[1];
    for (i = 0; i < k; i++) {
      mat_data[i] = mat->type->data[i];
    }
    mat_data[mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }
  t_mat = *(Mat *)(&mat->data->data[0]);
  *errCode = MatGetValues(t_mat, ni, &ix_data[0], nj, &jx_data[0], &v_data[0]);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscMatGetValues_Alloc(const M2C_OpaqueType *mat, int ni,
                             const emxArray_int32_T *ix, int nj,
                             const emxArray_int32_T *jx, emxArray_real_T *v,
                             int *errCode, boolean_T *toplevel)
{
  static const char cv[3] = {'M', 'a', 't'};
  Mat t_mat;
  emxArray_char_T *b_mat;
  double *v_data;
  const int *ix_data;
  const int *jx_data;
  int i;
  int k;
  const char *varargin_1_data;
  char *mat_data;
  boolean_T p;
  jx_data = jx->data;
  ix_data = ix->data;
  varargin_1_data = mat->type->data;
  p = (mat->type->size[1] == 3);
  if (p && (mat->type->size[1] != 0)) {
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (varargin_1_data[k] != cv[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (!p) {
    emxInit_char_T(&b_mat, 2);
    i = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat, i);
    mat_data = b_mat->data;
    k = mat->type->size[1];
    for (i = 0; i < k; i++) {
      mat_data[i] = mat->type->data[i];
    }
    mat_data[mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }
  t_mat = *(Mat *)(&mat->data->data[0]);
  i = v->size[0];
  v->size[0] = ni * nj;
  emxEnsureCapacity_real_T(v, i);
  v_data = v->data;
  *errCode = MatGetValues(t_mat, ni, &ix_data[0], nj, &jx_data[0], &v_data[0]);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
  *toplevel = true;
}

void petscMatGetValues_initialize(void)
{
}

void petscMatGetValues_terminate(void)
{
}
