#include "petscInitialize.h"
#include "m2c.h"
#include "petsc4m.h"

static void m2c_error(int varargin_3);

static void m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "PetscInitializeNoPointers returned error code %d\n", varargin_3);
}

void petscInitialize(int *errCode, boolean_T *toplevel)
{
  *errCode = PetscInitializeNoPointers(0, NULL, NULL, NULL);
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
