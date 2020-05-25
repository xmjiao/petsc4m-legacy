#include "petscMatNullSpaceCreate.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static const char cv[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
  'c', 'e' };

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static MPI_Comm m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i;
  int loop_ub;
  char varargin_4[4];
  static const char b_varargin_4[4] = "Vec";
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_array:TypeMismatch";
  fmt = "Incorrect data type &s. Expected %s.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  varargin_4[0] = b_varargin_4[0];
  varargin_4[1] = b_varargin_4[1];
  varargin_4[2] = b_varargin_4[2];
  varargin_4[3] = b_varargin_4[3];
  M2C_error(msgid, fmt, &b_varargin_3->data[0], varargin_4);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatNullSpaceCreate returned error code %d\n";
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

void petscMatNullSpaceCreate(const struct0_T *comm, int has_cnst, int n, const
  struct0_T *vecs, struct0_T *nullsp, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  int i;
  static const char b_cv[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm t_comm;
  static const char cv1[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data0;
  Vec * ptr;
  MatNullSpace arg;
  char * b_ptr;
  p = (comm->type->size[1] == 8);
  if (p && (comm->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(comm->type->data[sizepe] == b_cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_comm, 2);
  if (!b_p) {
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
  }

  t_comm = m2c_castdata(comm->data);
  p = (vecs->type->size[1] == 3);
  if (p && (vecs->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 3)) {
      if (!(vecs->type->data[sizepe] == cv1[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }

  b_p = (int)p;
  if (!b_p) {
    i = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = vecs->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, i);
    sizepe = vecs->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_comm->data[i] = vecs->type->data[i];
    }

    b_comm->data[vecs->type->size[1]] = '\x00';
    b_m2c_error(b_comm);
  }

  emxFree_char_T(&b_comm);
  emxInit_uint8_T(&data0, 1);
  ptr = (Vec *)(&vecs->data->data[0]);
  *errCode = MatNullSpaceCreate(t_comm, has_cnst, n, ptr, &arg);
  sizepe = sizeof(MatNullSpace);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = nullsp->data->size[0];
  nullsp->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(nullsp->data, i);
  for (i = 0; i < sizepe; i++) {
    nullsp->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = nullsp->type->size[0] * nullsp->type->size[1];
  nullsp->type->size[0] = 1;
  nullsp->type->size[1] = 12;
  emxEnsureCapacity_char_T(nullsp->type, i);
  for (i = 0; i < 12; i++) {
    nullsp->type->data[i] = cv[i];
  }

  nullsp->nitems = 1;
  b_ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    nullsp->data->data[i] = *(b_ptr);
    b_ptr = b_ptr + 1;
  }

  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscMatNullSpaceCreate_2args(const struct0_T *comm, int has_cnst,
  struct0_T *nullsp, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  emxArray_uint8_T *data0;
  int i;
  static const char b_cv[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Comm t_comm;
  Vec * ptr;
  MatNullSpace arg;
  char * b_ptr;
  p = (comm->type->size[1] == 8);
  if (p && (comm->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 8)) {
      if (!(comm->type->data[sizepe] == b_cv[sizepe])) {
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
  ptr = NULL;
  *errCode = MatNullSpaceCreate(t_comm, has_cnst, 0, ptr, &arg);
  sizepe = sizeof(MatNullSpace);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  i = nullsp->data->size[0];
  nullsp->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(nullsp->data, i);
  for (i = 0; i < sizepe; i++) {
    nullsp->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = nullsp->type->size[0] * nullsp->type->size[1];
  nullsp->type->size[0] = 1;
  nullsp->type->size[1] = 12;
  emxEnsureCapacity_char_T(nullsp->type, i);
  for (i = 0; i < 12; i++) {
    nullsp->type->data[i] = cv[i];
  }

  nullsp->nitems = 1;
  b_ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    nullsp->data->data[i] = *(b_ptr);
    b_ptr = b_ptr + 1;
  }

  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscMatNullSpaceCreate_initialize(void)
{
}

void petscMatNullSpaceCreate_terminate(void)
{
}
