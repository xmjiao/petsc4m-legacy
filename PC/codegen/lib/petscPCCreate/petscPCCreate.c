#include "petscPCCreate.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "PCCreate returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected MPI_Comm.\n";
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i0);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscPCCreate(const struct0_T *comm, struct0_T *pc, int *errCode, boolean_T
                   *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data0;
  int loop_ub;
  MPI_Comm t_comm;
  PC t_pc;
  int sizepe;
  char t1_type[2];
  static const char cv1[2] = { 'P', 'C' };

  char * ptr;
  p = false;
  b_p = false;
  if (comm->type->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(comm->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(comm->type->data[k] == cv0[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_comm, 2);
    k = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, k);
    loop_ub = comm->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_comm->data[b_comm->size[0] * k] = comm->type->data[comm->type->size[0] *
        k];
    }

    b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
    m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }

  emxInit_uint8_T(&data0, 1);
  k = data0->size[0];
  data0->size[0] = comm->data->size[0];
  emxEnsureCapacity_uint8_T(data0, k);
  loop_ub = comm->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data0->data[k] = comm->data->data[k];
  }

  t_comm = *(MPI_Comm*)(&data0->data[0]);
  *errCode = PCCreate(t_comm, &t_pc);
  sizepe = sizeof(PC);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, k);
  for (k = 0; k < 2; k++) {
    t1_type[k] = cv1[k];
  }

  k = pc->data->size[0];
  pc->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(pc->data, k);
  loop_ub = data0->size[0];
  for (k = 0; k < loop_ub; k++) {
    pc->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = pc->type->size[0] * pc->type->size[1];
  pc->type->size[0] = 1;
  pc->type->size[1] = 2;
  emxEnsureCapacity_char_T(pc->type, k);
  for (k = 0; k < 2; k++) {
    pc->type->data[k] = t1_type[k];
  }

  pc->nitems = 1;
  ptr = (char *)(&t_pc);
  for (k = 1; k <= sizepe; k++) {
    pc->data->data[k - 1] = *(ptr);
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
  MPI_Comm obj;
  PC t_pc;
  int sizepe;
  int i;
  char t0_type[2];
  static const char cv2[2] = { 'P', 'C' };

  int loop_ub;
  char * ptr;
  emxInit_uint8_T(&data0, 1);
  obj = PETSC_COMM_WORLD;
  *errCode = PCCreate(obj, &t_pc);
  sizepe = sizeof(PC);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  for (i = 0; i < 2; i++) {
    t0_type[i] = cv2[i];
  }

  i = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(ksp->data, i);
  loop_ub = data0->size[0];
  for (i = 0; i < loop_ub; i++) {
    ksp->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 2;
  emxEnsureCapacity_char_T(ksp->type, i);
  for (i = 0; i < 2; i++) {
    ksp->type->data[i] = t0_type[i];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_pc);
  for (i = 1; i <= sizepe; i++) {
    ksp->data->data[i - 1] = *(ptr);
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
