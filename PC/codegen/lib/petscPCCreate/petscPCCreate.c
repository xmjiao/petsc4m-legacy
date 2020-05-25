#include "petscPCCreate.h"
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
  fmt = "PCCreate returned error code %d\n";
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

void petscPCCreate(const struct0_T *comm, struct0_T *pc, int *errCode, boolean_T
                   *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  emxArray_uint8_T *data0;
  int i;
  static const char cv[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm t_comm;
  PC arg;
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

  emxInit_uint8_T(&data0, 1);
  t_comm = m2c_castdata(comm->data);
  *errCode = PCCreate(t_comm, &arg);
  sizepe = sizeof(PC);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = pc->data->size[0];
  pc->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(pc->data, i);
  for (i = 0; i < sizepe; i++) {
    pc->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = pc->type->size[0] * pc->type->size[1];
  pc->type->size[0] = 1;
  pc->type->size[1] = 2;
  emxEnsureCapacity_char_T(pc->type, i);
  pc->type->data[0] = 'P';
  pc->type->data[1] = 'C';
  pc->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    pc->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscPCCreate_World(struct0_T *ksp, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  MPI_Comm t_comm;
  PC arg;
  int sizepe;
  int i;
  char * ptr;
  emxInit_uint8_T(&data0, 1);
  t_comm = PETSC_COMM_WORLD;
  *errCode = PCCreate(t_comm, &arg);
  sizepe = sizeof(PC);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = ksp->data->size[0];
  ksp->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(ksp->data, i);
  for (i = 0; i < sizepe; i++) {
    ksp->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 2;
  emxEnsureCapacity_char_T(ksp->type, i);
  ksp->type->data[0] = 'P';
  ksp->type->data[1] = 'C';
  ksp->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    ksp->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscPCCreate_initialize(void)
{
}

void petscPCCreate_terminate(void)
{
}
