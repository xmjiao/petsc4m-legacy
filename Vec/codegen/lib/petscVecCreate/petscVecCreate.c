#include "petscVecCreate.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static MPI_Comm m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "VecCreate returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static MPI_Comm m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Comm*)(&data->data[0]);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected MPI_Comm.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscVecCreate(const struct0_T *comm, struct0_T *vec, int *errCode,
                    boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  MPI_Comm t_comm;
  int i;
  static const char cv[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  Vec arg;
  emxArray_uint8_T *data0;
  char * ptr;
  p = (comm->type->size[1] == 8);
  if (p && (comm->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(comm->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_comm, 2);
    i = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, i);
    sizepe = comm->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_comm->data[i] = comm->type->data[i];
    }

    b_comm->data[comm->type->size[1]] = '\x00';
    m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }

  t_comm = m2c_castdata(comm->data);
  *errCode = VecCreate(t_comm, &arg);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  emxInit_uint8_T(&data0, 1);
  sizepe = sizeof(Vec);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = vec->data->size[0];
  vec->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(vec->data, i);
  for (i = 0; i < sizepe; i++) {
    vec->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = vec->type->size[0] * vec->type->size[1];
  vec->type->size[0] = 1;
  vec->type->size[1] = 3;
  emxEnsureCapacity_char_T(vec->type, i);
  vec->type->data[0] = 'V';
  vec->type->data[1] = 'e';
  vec->type->data[2] = 'c';
  vec->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    vec->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  *toplevel = true;
}

void petscVecCreate_World(struct0_T *vec, int *errCode, boolean_T *topleve)
{
  MPI_Comm t_comm;
  Vec arg;
  emxArray_uint8_T *data0;
  int sizepe;
  int i;
  char * ptr;
  t_comm = PETSC_COMM_WORLD;
  *errCode = VecCreate(t_comm, &arg);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  emxInit_uint8_T(&data0, 1);
  sizepe = sizeof(Vec);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = vec->data->size[0];
  vec->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(vec->data, i);
  for (i = 0; i < sizepe; i++) {
    vec->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = vec->type->size[0] * vec->type->size[1];
  vec->type->size[0] = 1;
  vec->type->size[1] = 3;
  emxEnsureCapacity_char_T(vec->type, i);
  vec->type->data[0] = 'V';
  vec->type->data[1] = 'e';
  vec->type->data[2] = 'c';
  vec->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    vec->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  *topleve = true;
}

void petscVecCreate_initialize(void)
{
}

void petscVecCreate_terminate(void)
{
}
