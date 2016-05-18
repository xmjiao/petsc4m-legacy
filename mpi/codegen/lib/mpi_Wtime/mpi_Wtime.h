#ifndef MPI_WTIME_H
#define MPI_WTIME_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Wtime_types.h"

extern double mpi_Wtime(void);
extern void mpi_Wtime_initialize(void);
extern void mpi_Wtime_terminate(void);

#endif
