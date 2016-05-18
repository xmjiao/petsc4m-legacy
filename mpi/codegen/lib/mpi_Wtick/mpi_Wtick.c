#include "mpi_Wtick.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

double mpi_Wtick(void)
{
  return MPI_Wtick();
}

void mpi_Wtick_initialize(void)
{
}

void mpi_Wtick_terminate(void)
{
}
