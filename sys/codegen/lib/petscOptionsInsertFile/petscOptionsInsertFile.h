#ifndef PETSCOPTIONSINSERTFILE_H
#define PETSCOPTIONSINSERTFILE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "petscOptionsInsertFile_types.h"

extern void petscOptionsInsertFile(const struct0_T *comm, const emxArray_char_T *
  file, int req, int *errCode, boolean_T *toplevel);
extern void petscOptionsInsertFile_initialize(void);
extern void petscOptionsInsertFile_terminate(void);

#endif
