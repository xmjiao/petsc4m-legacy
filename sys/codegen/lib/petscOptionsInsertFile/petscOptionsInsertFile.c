#include "petscOptionsInsertFile.h"
#include "petscOptionsInsertFile_types.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(int varargin_3);

static void m2c_error(void);

static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  const char *varargin_3_data;
  char *b_varargin_3_data;
  varargin_3_data = varargin_3->data;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected MPI_Comm.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  b_varargin_3_data = b_varargin_3->data;
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3_data[i] = varargin_3_data[i];
  }
  M2C_error(msgid, fmt, &b_varargin_3_data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "PetscOptionsInsertFile returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(void)
{
  const char *fmt;
  const char *msgid;
  msgid = "Petsc4m:petscOptionsInsertFile:InputError";
  fmt = "Argument file must be a null-terminated string.";
  M2C_error(msgid, fmt);
}

void petscOptionsInsertFile(const M2C_OpaqueType *comm,
                            const emxArray_char_T *file, int req, int *errCode,
                            boolean_T *toplevel)
{
  static const char cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  MPI_Comm c_comm;
  PetscOptions obj;
  emxArray_char_T *b_comm;
  int i;
  int k;
  const char *file_data;
  char *comm_data;
  boolean_T p;
  file_data = file->data;
  *toplevel = true;
  if ((file->size[1] != 0) && (file_data[file->size[1] - 1] != '\x00')) {
    m2c_error();
  }
  p = (comm->type->size[1] == 8);
  if (p && (comm->type->size[1] != 0)) {
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (comm->type->data[k] != cv[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (!p) {
    emxInit_char_T(&b_comm, 2);
    i = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, i);
    comm_data = b_comm->data;
    k = comm->type->size[1];
    for (i = 0; i < k; i++) {
      comm_data[i] = comm->type->data[i];
    }
    comm_data[comm->type->size[1]] = '\x00';
    b_m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }
  c_comm = *(MPI_Comm *)(&comm->data->data[0]);
  obj = NULL;
  *errCode = PetscOptionsInsertFile(c_comm, obj, &file_data[0], req);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscOptionsInsertFile_initialize(void)
{
}

void petscOptionsInsertFile_terminate(void)
{
}
