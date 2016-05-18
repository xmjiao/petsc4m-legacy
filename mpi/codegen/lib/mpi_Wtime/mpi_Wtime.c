#include "mpi_Wtime.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

double mpi_Wtime(void)
{
  return MPI_Wtime();
}

void mpi_Wtime_initialize(void)
{
}

void mpi_Wtime_terminate(void)
{
}
