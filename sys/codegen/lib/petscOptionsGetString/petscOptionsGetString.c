#include "petscOptionsGetString.h"
#include "m2c.h"
#include "mpetsc.h"

static void b_m2c_error(void);
static void c_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsGetString:InputError",
            "Argument name must be a null-terminated character string.");
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "PetscOptionsGetString returned error code %d\n", varargin_3);
}

static void m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsGetString:InputError",
            "Argument pre must be a null-terminated string.");
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void petscOptionsGetString(const emxArray_char_T *pre, const emxArray_char_T
  *name, emxArray_char_T *str, int *found, int *errCode, boolean_T *toplevel)
{
  char str0[21];
  PetscBool b_flag;
  int i0;
  int i;
  boolean_T exitg1;
  int loop_ub;
  *toplevel = true;
  if ((!(pre->size[1] == 0)) && (pre->data[pre->size[1] - 1] != '\x00')) {
    m2c_error();
  }

  if ((!(name->size[1] == 0)) && (name->data[name->size[1] - 1] != '\x00')) {
    b_m2c_error();
  }

  *errCode = PetscOptionsGetString(NULL, &pre->data[0], &name->data[0], str0, 20,
    &b_flag);
  *found = (int)(b_flag);
  i0 = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = 0;
  emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 21)) {
    if ((unsigned char)str0[i] == 0) {
      loop_ub = i + 1;
      i0 = str->size[0] * str->size[1];
      str->size[0] = 1;
      str->size[1] = i + 1;
      emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
      for (i0 = 0; i0 < loop_ub; i0++) {
        str->data[str->size[0] * i0] = str0[i0];
      }

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
