#include "petscOptionsGetInt.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(void);
static void c_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsGetInt:InputError",
            "Argument name must be a null-terminated character string.");
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscOptionsGetInt returned error code %d\n",
            varargin_3);
}

static void m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsGetInt:InputError",
            "Argument prefix must be a null-terminated string.");
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void petscOptionsGetInt(const emxArray_char_T *pre, const emxArray_char_T *name,
  int *ivalue, int *found, int *errCode, boolean_T *toplevel)
{
  PetscBool b_flag;
  *toplevel = true;
  if ((!(pre->size[1] == 0)) && (pre->data[pre->size[1] - 1] != '\x00')) {
    m2c_error();
  }

  if ((!(name->size[1] == 0)) && (name->data[name->size[1] - 1] != '\x00')) {
    b_m2c_error();
  }

  *errCode = PetscOptionsGetInt(NULL, &pre->data[0], &name->data[0], ivalue,
    &b_flag);
  *found = (int)(b_flag);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscOptionsGetInt_initialize(void)
{
}

void petscOptionsGetInt_terminate(void)
{
}
