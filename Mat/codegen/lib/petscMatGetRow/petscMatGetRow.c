#include "petscMatGetRow.h"
#include "petscMatGetRow_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void c_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "MatGetRow returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "MatRestoreRow returned error code %d\n";
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
  fmt = "Incorrect data type %s. Expected Mat.\n";
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

void petscMatGetRow(const M2C_OpaqueType *mat, int row, int *ncols,
                    emxArray_int32_T *cols, emxArray_real32_T *vals,
                    int *errCode, boolean_T *toplevel)
{
  static const char cv[3] = {'M', 'a', 't'};
  Mat t_mat;
  const PetscScalar *t_vals;
  const int *t_cols;
  emxArray_char_T *b_mat;
  int i;
  int t_ncols;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (mat->type->size[1] == 3) {
    p = true;
  }
  if (p && (mat->type->size[1] != 0)) {
    t_ncols = 0;
    exitg1 = false;
    while ((!exitg1) && (t_ncols < 3)) {
      if (!(mat->type->data[t_ncols] == cv[t_ncols])) {
        p = false;
        exitg1 = true;
      } else {
        t_ncols++;
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
    t_ncols = mat->type->size[1];
    for (i = 0; i < t_ncols; i++) {
      b_mat->data[i] = mat->type->data[i];
    }
    b_mat->data[mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }
  t_mat = *(Mat *)(&mat->data->data[0]);
  t_ncols = 0;
  *errCode = MatGetRow(t_mat, row, &t_ncols, &t_cols, &t_vals);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
  *ncols = t_ncols;
  i = cols->size[0];
  cols->size[0] = t_ncols;
  emxEnsureCapacity_int32_T(cols, i);
  i = vals->size[0];
  vals->size[0] = t_ncols;
  emxEnsureCapacity_real32_T(vals, i);
  memcpy(&cols->data[0], t_cols, t_ncols << 2);
  memcpy(&vals->data[0], t_vals, t_ncols << 2);
  *errCode = MatRestoreRow(t_mat, row, &t_ncols, &t_cols, &t_vals);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
  *toplevel = true;
}

void petscMatGetRow_initialize(void)
{
}

void petscMatGetRow_terminate(void)
{
}
