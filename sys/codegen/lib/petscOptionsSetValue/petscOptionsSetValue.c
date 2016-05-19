#include "petscOptionsSetValue.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(void);
static void c_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsSetValue:InputError",
            "Argument value must be a null-terminated string.");
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "PetscOptionsSetValue returned error code %d\n", varargin_3);
}

static void m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsSetValue:InputError",
            "Argument name must be a null-terminated string.");
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void petscOptionsSetValue(const emxArray_char_T *iname, const emxArray_char_T
  *value, int *errCode, boolean_T *toplevel)
{
  if ((!(iname->size[1] == 0)) && (iname->data[iname->size[1] - 1] != '\x00')) {
    m2c_error();
  }

  if ((!(value->size[1] == 0)) && (value->data[value->size[1] - 1] != '\x00')) {
    b_m2c_error();
  }

  *errCode = PetscOptionsSetValue(NULL, &iname->data[0], &value->data[0]);
  *toplevel = true;
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscOptionsSetValue_initialize(void)
{
}

void petscOptionsSetValue_terminate(void)
{
}
