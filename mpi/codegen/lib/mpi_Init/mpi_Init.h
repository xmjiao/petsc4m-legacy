#ifndef MPI_INIT_H
#define MPI_INIT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Init_types.h"

extern void mpi_Init(int *info, boolean_T *toplevel);
extern void mpi_Init_initialize(void);
extern void mpi_Init_terminate(void);

#endif
