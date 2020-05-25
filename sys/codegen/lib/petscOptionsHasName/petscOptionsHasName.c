#include "petscOptionsHasName.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(void);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(int varargin_3);
static PetscOptions m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(void);
static void b_m2c_error(void)
{
  const char * msgid;
  const char * fmt;
  msgid = "Petsc4m:petscOptionsHasName:InputError";
  fmt = "Argument name must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected PetscOptions.\n";
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

static void d_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "PetscOptionsHasName returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static PetscOptions m2c_castdata(const emxArray_uint8_T *data)
{
  return *(PetscOptions*)(&data->data[0]);
}

static void m2c_error(void)
{
  const char * msgid;
  const char * fmt;
  msgid = "Petsc4m:petscOptionsHasName:InputError";
  fmt = "Argument pre must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

void petscOptionsHasName(const struct0_T *options, const emxArray_char_T *pre,
  const emxArray_char_T *name, int *found, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_options;
  PetscOptions opts;
  int i;
  static const char cv[12] = { 'P', 'e', 't', 's', 'c', 'O', 'p', 't', 'i', 'o',
    'n', 's' };

  PetscBool b_flag;
  *toplevel = true;
  if ((pre->size[1] != 0) && (pre->data[pre->size[1] - 1] != '\x00')) {
    m2c_error();
  }

  if ((name->size[1] != 0) && (name->data[name->size[1] - 1] != '\x00')) {
    b_m2c_error();
  }

  p = (options->type->size[1] == 12);
  if (p && (options->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(options->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_options, 2);
    i = b_options->size[0] * b_options->size[1];
    b_options->size[0] = 1;
    b_options->size[1] = options->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_options, i);
    k = options->type->size[1];
    for (i = 0; i < k; i++) {
      b_options->data[i] = options->type->data[i];
    }

    b_options->data[options->type->size[1]] = '\x00';
    c_m2c_error(b_options);
    emxFree_char_T(&b_options);
  }

  opts = m2c_castdata(options->data);
  *errCode = PetscOptionsHasName(opts, &pre->data[0], &name->data[0], &b_flag);
  *found = (int)(b_flag);
  if (*errCode != 0) {
    d_m2c_error(*errCode);
  }
}

void petscOptionsHasName_initialize(void)
{
}

void petscOptionsHasName_terminate(void)
{
}
