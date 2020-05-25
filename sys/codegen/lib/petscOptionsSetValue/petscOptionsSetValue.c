#include "petscOptionsSetValue.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(void);
static void c_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(void)
{
  const char * msgid;
  const char * fmt;
  msgid = "Petsc4m:petscOptionsSetValue:InputError";
  fmt = "Argument value must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

static void c_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "PetscOptionsSetValue returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(void)
{
  const char * msgid;
  const char * fmt;
  msgid = "Petsc4m:petscOptionsSetValue:InputError";
  fmt = "Argument name must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

void petscOptionsSetValue(const emxArray_char_T *iname, const emxArray_char_T
  *value, int *errCode, boolean_T *toplevel)
{
  PetscOptions obj;
  if ((iname->size[1] != 0) && (iname->data[iname->size[1] - 1] != '\x00')) {
    m2c_error();
  }

  if ((value->size[1] != 0) && (value->data[value->size[1] - 1] != '\x00')) {
    b_m2c_error();
  }

  obj = NULL;
  *errCode = PetscOptionsSetValue(obj, &iname->data[0], &value->data[0]);
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
