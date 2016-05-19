#include "petscInitialize.h"
#include "mpetsc.h"
#include "m2c.h"

static void m2c_error(int varargin_3);
static void m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "PetscInitializeNoArguments returned error code %d\n", varargin_3);
}

void petscInitialize(int *errCode, boolean_T *toplevel)
{
  *errCode = PetscInitializeNoArguments();
  *toplevel = true;
  if (*errCode != 0) {
    m2c_error(*errCode);
  }
}

void petscInitialize_initialize(void)
{
}

void petscInitialize_terminate(void)
{
}
