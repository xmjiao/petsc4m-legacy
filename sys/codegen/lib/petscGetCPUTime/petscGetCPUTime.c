#include "petscGetCPUTime.h"
#include "m2c.h"
#include "petsc4m.h"

static void m2c_error(int varargin_3);

static void m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "petscGetCPUTime returned error code %d\n",
            varargin_3);
}

void petscGetCPUTime(double *t, int *errCode, boolean_T *toplevel)
{
  *errCode = PetscGetCPUTime(t);
  *toplevel = true;
  if (*errCode != 0) {
    m2c_error(*errCode);
  }
}

void petscGetCPUTime_initialize(void)
{
}

void petscGetCPUTime_terminate(void)
{
}
