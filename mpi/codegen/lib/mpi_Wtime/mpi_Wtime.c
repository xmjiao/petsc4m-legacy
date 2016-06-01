#include "mpi_Wtime.h"
#include "mpetsc.h"

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
