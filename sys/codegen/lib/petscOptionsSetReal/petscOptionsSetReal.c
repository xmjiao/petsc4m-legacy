#include "petscOptionsSetReal.h"
#include "petscOptionsSetReal_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(void);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "PetscOptionsSetValue returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(void)
{
  const char *fmt;
  const char *msgid;
  msgid = "Petsc4m:petscOptionsSetReal:InputError";
  fmt = "Argument name must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

void petscOptionsSetReal(const emxArray_char_T *iname, double value,
                         int *errCode, boolean_T *toplevel)
{
  int i;
  char str[32];
  unsigned char t_str[32];
  const char *iname_data;
  char *ptr;
  iname_data = iname->data;
  *toplevel = true;
  if ((iname->size[1] != 0) && (iname_data[iname->size[1] - 1] != '\x00')) {
    m2c_error();
  }
  ptr = (char *)(&t_str[0]);
  sprintf(ptr, "%.17g", value);
  for (i = 0; i < 32; i++) {
    str[i] = (signed char)t_str[i];
  }
  PetscOptions obj;
  obj = NULL;
  *errCode = PetscOptionsSetValue(obj, &iname_data[0], &str[0]);
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
