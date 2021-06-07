#include "petscOptionsSetInt.h"
#include "petscOptionsSetInt_types.h"
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
  msgid = "Petsc4m:petscOptionsSetInt:InputError";
  fmt = "Argument name must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

void petscOptionsSetInt(const emxArray_char_T *iname, int value, int *errCode,
                        boolean_T *toplevel)
{
  PetscOptions obj;
  int i;
  char str[20];
  signed char t_str[20];
  char *ptr;
  *toplevel = true;
  if ((iname->size[1] != 0) && (iname->data[iname->size[1] - 1] != '\x00')) {
    m2c_error();
  }
  ptr = (char *)(&t_str[0]);
  sprintf(ptr, "%d", value);
  for (i = 0; i < 20; i++) {
    str[i] = t_str[i];
  }
  obj = NULL;
  *errCode = PetscOptionsSetValue(obj, &iname->data[0], &str[0]);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscOptionsSetInt_initialize(void)
{
}

void petscOptionsSetInt_terminate(void)
{
}
