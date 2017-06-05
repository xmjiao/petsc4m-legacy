#include "petscOptionsInsertString.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "PetscOptionsInsertString returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(void)
{
  const char * msgid;
  const char * fmt;
  msgid = "Petsc4m:petscOptionsInsertString:InputError";
  fmt = "The argument must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void petscOptionsInsertString(const emxArray_char_T *in_str, int *errCode,
  boolean_T *toplevel)
{
  PetscOptions obj;
  *toplevel = true;
  if ((!(in_str->size[1] == 0)) && (in_str->data[in_str->size[1] - 1] != '\x00'))
  {
    m2c_error();
  }

  obj = NULL;
  *errCode = PetscOptionsInsertString(obj, &in_str->data[0]);
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
