#ifndef PETSCMATNULLSPACECREATE_H
#define PETSCMATNULLSPACECREATE_H

#include "petscMatNullSpaceCreate_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatNullSpaceCreate(const M2C_OpaqueType *comm, int has_cnst,
                                    int n, const M2C_OpaqueType *vecs,
                                    M2C_OpaqueType *nullsp, int *errCode,
                                    boolean_T *toplevel);

extern void petscMatNullSpaceCreate_2args(const M2C_OpaqueType *comm,
                                          int has_cnst, M2C_OpaqueType *nullsp,
                                          int *errCode, boolean_T *toplevel);

extern void petscMatNullSpaceCreate_initialize(void);

extern void petscMatNullSpaceCreate_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
