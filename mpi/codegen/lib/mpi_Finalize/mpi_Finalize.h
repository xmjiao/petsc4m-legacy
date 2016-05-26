#ifndef MPI_FINALIZE_H
#define MPI_FINALIZE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Finalize_types.h"

extern void mpi_Finalize(int *info, boolean_T *toplevel);
extern void mpi_Finalize_initialize(void);
extern void mpi_Finalize_terminate(void);

#endif
