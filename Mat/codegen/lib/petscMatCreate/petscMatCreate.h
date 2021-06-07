#ifndef PETSCMATCREATE_H
#define PETSCMATCREATE_H

#include "petscMatCreate_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatCreate(const M2C_OpaqueType *comm, M2C_OpaqueType *mat,
                           int *errCode, boolean_T *toplevel);

extern void petscMatCreate_World(M2C_OpaqueType *mat, int *errCode,
                                 boolean_T *topleve);

extern void petscMatCreate_initialize(void);

extern void petscMatCreate_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
