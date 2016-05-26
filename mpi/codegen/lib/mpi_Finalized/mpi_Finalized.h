#ifndef MPI_FINALIZED_H
#define MPI_FINALIZED_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Finalized_types.h"

extern void mpi_Finalized(int *flag, int *info, boolean_T *toplevel);
extern void mpi_Finalized_initialize(void);
extern void mpi_Finalized_terminate(void);

#endif
