#include "petscOptionsSetReal.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(int varargin_3)
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
  msgid = "Petsc4m:petscOptionsSetReal:InputError";
  fmt = "Argument name must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

void petscOptionsSetReal(const emxArray_char_T *iname, double value, int
  *errCode, boolean_T *toplevel)
{
  char * ptr;
  unsigned char t_str[32];
  int i0;
  char str[32];
  PetscOptions obj;
  *toplevel = true;
  if ((!(iname->size[1] == 0)) && (iname->data[iname->size[1] - 1] != '\x00')) {
    m2c_error();
  }

  ptr = (char *)(t_str);
  sprintf(ptr, "%.17g", value);
  for (i0 = 0; i0 < 32; i0++) {
    str[i0] = (signed char)t_str[i0];
  }

  obj = NULL;
  *errCode = PetscOptionsSetValue(obj, &iname->data[0], str);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscOptionsSetReal_initialize(void)
{
}

void petscOptionsSetReal_terminate(void)
{
}
