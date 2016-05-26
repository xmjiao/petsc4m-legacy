#ifndef MPI_INITIALIZED_H
#define MPI_INITIALIZED_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Initialized_types.h"

extern void mpi_Initialized(int *flag, int *info, boolean_T *toplevel);
extern void mpi_Initialized_initialize(void);
extern void mpi_Initialized_terminate(void);

#endif
