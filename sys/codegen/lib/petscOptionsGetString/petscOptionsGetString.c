#include "petscOptionsGetString.h"
#include "petscOptionsGetString_types.h"
#include "m2c.h"
#include "petsc4m.h"
#include <string.h>

static void b_m2c_error(void);

static void c_m2c_error(int varargin_3);

static void m2c_error(void);

static void b_m2c_error(void)
{
  const char *fmt;
  const char *msgid;
  msgid = "Petsc4m:petscOptionsGetString:InputError";
  fmt = "Argument name must be a null-terminated character string.";
  M2C_error(msgid, fmt);
}

static void c_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "PetscOptionsGetString returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(void)
{
  const char *fmt;
  const char *msgid;
  msgid = "Petsc4m:petscOptionsGetString:InputError";
  fmt = "Argument pre must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

void petscOptionsGetString(const emxArray_char_T *pre,
                           const emxArray_char_T *name, char str_data[],
                           int str_size[2], int *found, int *errCode,
                           boolean_T *toplevel)
{
  PetscBool b_flag;
  PetscOptions obj;
  int i;
  char str0[21];
  const char *name_data;
  const char *pre_data;
  boolean_T exitg1;
  name_data = name->data;
  pre_data = pre->data;
  *toplevel = true;
  if ((pre->size[1] != 0) && (pre_data[pre->size[1] - 1] != '\x00')) {
    m2c_error();
  }
  if ((name->size[1] != 0) && (name_data[name->size[1] - 1] != '\x00')) {
    b_m2c_error();
  }
  obj = NULL;
  *errCode = PetscOptionsGetString(obj, &pre_data[0], &name_data[0], &str0[0],
                                   20, &b_flag);
  *found = (int)(b_flag);
  str_size[0] = 1;
  str_size[1] = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 21)) {
    if ((unsigned char)str0[i] == 0) {
      str_size[0] = 1;
      str_size[1] = i + 1;
      memcpy(&str_data[0], &str0[0], (i + 1) * sizeof(char));
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
