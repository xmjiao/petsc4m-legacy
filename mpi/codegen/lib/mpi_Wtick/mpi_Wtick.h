#ifndef MPI_WTICK_H
#define MPI_WTICK_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Wtick_types.h"

extern double mpi_Wtick(void);
extern void mpi_Wtick_initialize(void);
extern void mpi_Wtick_terminate(void);

#endif
