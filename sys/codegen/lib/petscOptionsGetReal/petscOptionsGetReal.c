#include "petscOptionsGetReal.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(void);
static void c_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(void)
{
  const char * msgid;
  const char * fmt;
  msgid = "Petsc4m:petscOptionsGetInt:InputError";
  fmt = "Argument name must be a null-terminated character string.";
  M2C_error(msgid, fmt);
}

static void c_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "PetscOptionsGetReal returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(void)
{
  const char * msgid;
  const char * fmt;
  msgid = "Petsc4m:petscOptionsGetInt:InputError";
  fmt = "Argument prefix must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void petscOptionsGetReal(const emxArray_char_T *pre, const emxArray_char_T *name,
  double *value, int *found, int *errCode, boolean_T *toplevel)
{
  PetscBool b_flag;
  PetscOptions obj;
  *toplevel = true;
  if ((!(pre->size[1] == 0)) && (pre->data[pre->size[1] - 1] != '\x00')) {
    m2c_error();
  }

  if ((!(name->size[1] == 0)) && (name->data[name->size[1] - 1] != '\x00')) {
    b_m2c_error();
  }

  obj = NULL;
  *errCode = PetscOptionsGetReal(obj, &pre->data[0], &name->data[0], value,
    &b_flag);
  *found = (int)(b_flag);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscOptionsGetReal_initialize(void)
{
}

void petscOptionsGetReal_terminate(void)
{
}
