#include "mpi_Init.h"
#include "mpi.h"
#include "mpetsc.h"
#include "m2c.h"

static void m2c_error(int varargin_3);
static void m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Init returned error code %d\n", varargin_3);
}

void mpi_Init(int *info, boolean_T *toplevel)
{
  *info = MPI_Init(NULL, NULL);
  *toplevel = true;
  if (*info != 0) {
    m2c_error(*info);
  }
}

void mpi_Init_initialize(void)
{
}

void mpi_Init_terminate(void)
{
}
