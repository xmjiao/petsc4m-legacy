#include "petscInitialized.h"
#include "m2c.h"
#include "petsc4m.h"

static void m2c_error(int varargin_3);

static void m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscInitialized returned error code %d\n",
            varargin_3);
}

void petscInitialized(int *initialized, int *errCode, boolean_T *toplevel)
{
  PetscBool b;
  *errCode = PetscInitialized(&b);
  *initialized = (b);
  *toplevel = true;
  if (*errCode != 0) {
    m2c_error(*errCode);
  }
}

void petscInitialized_initialize(void)
{
}

void petscInitialized_terminate(void)
{
}
