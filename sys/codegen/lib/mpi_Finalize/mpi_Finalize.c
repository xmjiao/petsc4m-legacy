#include "mpi_Finalize.h"
#include "mpi.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(int varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Finalize returned error code %d\n",
            varargin_3);
}

static void m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Finalized returned error code %d\n",
            varargin_3);
}

void mpi_Finalize(int *info, boolean_T *toplevel)
{
  int flag;
  int b_info;
  int b_flag;
  *info = 0;
  b_info = MPI_Finalized(&flag);
  if (b_info != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      m2c_error(b_info);
    }
  }

  if (!(flag != 0)) {
    *info = MPI_Finalize();
  }

  *toplevel = true;
  if (*info != 0) {
    b_m2c_error(*info);
  }
}

void mpi_Finalize_initialize(void)
{
}

void mpi_Finalize_terminate(void)
{
}
