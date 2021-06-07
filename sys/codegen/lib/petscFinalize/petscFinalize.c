#include "petscFinalize.h"
#include "m2c.h"
#include "petsc4m.h"

static void m2c_error(int varargin_3);

static void m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscFinalize returned error code %d\n",
            varargin_3);
}

void petscFinalize(int *errCode, boolean_T *toplevel)
{
  *errCode = PetscFinalize();
  *toplevel = true;
  if (*errCode != 0) {
    m2c_error(*errCode);
  }
}

void petscFinalize_initialize(void)
{
}

void petscFinalize_terminate(void)
{
}
