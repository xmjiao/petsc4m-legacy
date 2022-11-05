#include "petscMatCreate.h"
#include "petscMatCreate_types.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "MatCreate returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
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

void petscMatCreate(const M2C_OpaqueType *comm, M2C_OpaqueType *mat,
                    int *errCode, boolean_T *toplevel)
{
  static const char cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  MPI_Comm t_comm;
  Mat arg;
  char *ptr;
  emxArray_char_T *b_comm;
  int i;
  int sizepe;
  char *comm_data;
  boolean_T p;
  p = (comm->type->size[1] == 8);
  if (p && (comm->type->size[1] != 0)) {
    boolean_T exitg1;
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (comm->type->data[sizepe] != cv[sizepe]) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
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
    sizepe = comm->type->size[1];
    for (i = 0; i < sizepe; i++) {
      comm_data[i] = comm->type->data[i];
    }
    comm_data[comm->type->size[1]] = '\x00';
    m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }
  t_comm = *(MPI_Comm *)(&comm->data->data[0]);
  *errCode = MatCreate(t_comm, &arg);
  sizepe = sizeof(Mat);
  i = mat->data->size[0];
  mat->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(mat->data, i);
  i = mat->type->size[0] * mat->type->size[1];
  mat->type->size[0] = 1;
  mat->type->size[1] = 3;
  emxEnsureCapacity_char_T(mat->type, i);
  mat->type->data[0] = 'M';
  mat->type->data[1] = 'a';
  mat->type->data[2] = 't';
  mat->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    mat->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
  *toplevel = true;
}

void petscMatCreate_World(M2C_OpaqueType *mat, int *errCode, boolean_T *topleve)
{
  MPI_Comm t_comm;
  Mat arg;
  char *ptr;
  int i;
  int sizepe;
  t_comm = PETSC_COMM_WORLD;
  *errCode = MatCreate(t_comm, &arg);
  sizepe = sizeof(Mat);
  i = mat->data->size[0];
  mat->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(mat->data, i);
  i = mat->type->size[0] * mat->type->size[1];
  mat->type->size[0] = 1;
  mat->type->size[1] = 3;
  emxEnsureCapacity_char_T(mat->type, i);
  mat->type->data[0] = 'M';
  mat->type->data[1] = 'a';
  mat->type->data[2] = 't';
  mat->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    mat->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
  *topleve = true;
}

void petscMatCreate_initialize(void)
{
}

void petscMatCreate_terminate(void)
{
}
