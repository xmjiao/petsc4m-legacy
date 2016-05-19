#include "mpi_Finalized.h"
#include "mpi.h"
#include "mpetsc.h"
#include "m2c.h"

static void m2c_error(int varargin_3);
static void m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Finalized returned error code %d\n",
            varargin_3);
}

void mpi_Finalized(int *flag, int *info, boolean_T *toplevel)
{
  *info = MPI_Finalized(flag);
  *toplevel = true;
  if (*info != 0) {
    m2c_error(*info);
  }
}

void mpi_Finalized_initialize(void)
{
}

void mpi_Finalized_terminate(void)
{
}
