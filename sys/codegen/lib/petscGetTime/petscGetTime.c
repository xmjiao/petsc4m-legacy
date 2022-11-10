#include "petscGetTime.h"
#include "m2c.h"
#include "petsc4m.h"

static void m2c_error(int varargin_3);

static void m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "petscGetTime returned error code %d\n",
            varargin_3);
}

void petscGetTime(double *t, int *errCode, boolean_T *toplevel)
{
  *errCode = PetscGetTime(t);
  *toplevel = true;
  if (*errCode != 0) {
    m2c_error(*errCode);
  }
}

void petscGetTime_initialize(void)
{
}

void petscGetTime_terminate(void)
{
}
