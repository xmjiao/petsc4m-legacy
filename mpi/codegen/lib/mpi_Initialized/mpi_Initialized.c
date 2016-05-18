#include "mpi_Initialized.h"
#include "mpi.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

static void m2c_error(int varargin_3);
static void m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Initialized returned error code %d\n",
            varargin_3);
}

void mpi_Initialized(int *flag, int *info, boolean_T *toplevel)
{
  *info = MPI_Initialized(flag);
  *toplevel = true;
  if (*info != 0) {
    m2c_error(*info);
  }
}

void mpi_Initialized_initialize(void)
{
}

void mpi_Initialized_terminate(void)
{
}
