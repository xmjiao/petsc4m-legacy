#include "petscOptionsGetString.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(void);
static void c_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(void)
{
  const char * msgid;
  const char * fmt;
  msgid = "Petsc4m:petscOptionsGetString:InputError";
  fmt = "Argument name must be a null-terminated character string.";
  M2C_error(msgid, fmt);
}

static void c_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "PetscOptionsGetString returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(void)
{
  const char * msgid;
  const char * fmt;
  msgid = "Petsc4m:petscOptionsGetString:InputError";
  fmt = "Argument pre must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

void petscOptionsGetString(const emxArray_char_T *pre, const emxArray_char_T
  *name, char str_data[], int str_size[2], int *found, int *errCode, boolean_T
  *toplevel)
{
  PetscOptions obj;
  char str0[21];
  PetscBool b_flag;
  int i;
  boolean_T exitg1;
  *toplevel = true;
  if ((!(pre->size[1] == 0)) && (pre->data[pre->size[1] - 1] != '\x00')) {
    m2c_error();
  }

  if ((!(name->size[1] == 0)) && (name->data[name->size[1] - 1] != '\x00')) {
    b_m2c_error();
  }

  obj = NULL;
  *errCode = PetscOptionsGetString(obj, &pre->data[0], &name->data[0], str0, 20,
    &b_flag);
  *found = (int)(b_flag);
  str_size[0] = 1;
  str_size[1] = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 21)) {
    if ((unsigned char)str0[i] == 0) {
      str_size[0] = 1;
      str_size[1] = i + 1;
      memcpy(&str_data[0], &str0[0], (unsigned int)((i + 1) * (int)sizeof(char)));
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscOptionsGetString_initialize(void)
{
}

void petscOptionsGetString_terminate(void)
{
}
