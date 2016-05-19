#include "petscOptionsGetBool.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(void);
static void c_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsGetBool:InputError",
            "Argument name must be a null-terminated character string.");
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscOptionsGetBool returned error code %d\n",
            varargin_3);
}

static void m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsGetBool:InputError",
            "Argument prefix must be a null-terminated string.");
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void petscOptionsGetBool(const emxArray_char_T *pre, const emxArray_char_T *name,
  int *value, int *found, int *errCode, boolean_T *toplevel)
{
  PetscBool b_value;
  PetscBool b_flag;
  *toplevel = true;
  if ((!(pre->size[1] == 0)) && (pre->data[pre->size[1] - 1] != '\x00')) {
    m2c_error();
  }

  if ((!(name->size[1] == 0)) && (name->data[name->size[1] - 1] != '\x00')) {
    b_m2c_error();
  }

  *errCode = PetscOptionsGetBool(NULL, &pre->data[0], &name->data[0], &b_value,
    &b_flag);
  *value = (int)(b_value);
  *found = (int)(b_flag);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscOptionsGetBool_initialize(void)
{
}

void petscOptionsGetBool_terminate(void)
{
}
