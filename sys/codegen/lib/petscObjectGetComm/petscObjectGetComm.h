#ifndef PETSCOBJECTGETCOMM_H
#define PETSCOBJECTGETCOMM_H

#include "petscObjectGetComm_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscObjectGetComm(const M2C_OpaqueType *obj, M2C_OpaqueType *comm,
                               int *errCode, boolean_T *toplevel);

extern void petscObjectGetComm_initialize(void);

extern void petscObjectGetComm_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
