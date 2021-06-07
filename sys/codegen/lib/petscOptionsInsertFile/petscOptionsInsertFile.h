#ifndef PETSCOPTIONSINSERTFILE_H
#define PETSCOPTIONSINSERTFILE_H

#include "petscOptionsInsertFile_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscOptionsInsertFile(const M2C_OpaqueType *comm,
                                   const emxArray_char_T *file, int req,
                                   int *errCode, boolean_T *toplevel);

extern void petscOptionsInsertFile_initialize(void);

extern void petscOptionsInsertFile_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
