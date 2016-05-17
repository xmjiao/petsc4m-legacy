#include "petscOptionsInsertString.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "PetscOptionsInsertString returned error code %d\n", varargin_3);
}

static void m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsInsertString:InputError",
            "The argument must be a null-terminated string.");
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void petscOptionsInsertString(const emxArray_char_T *in_str, int *errCode,
  boolean_T *toplevel)
{
  *toplevel = true;
  if ((!(in_str->size[1] == 0)) && (in_str->data[in_str->size[1] - 1] != '\x00'))
  {
    m2c_error();
  }

  *errCode = PetscOptionsInsertString(NULL, &in_str->data[0]);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscOptionsInsertString_initialize(void)
{
}

void petscOptionsInsertString_terminate(void)
{
}
