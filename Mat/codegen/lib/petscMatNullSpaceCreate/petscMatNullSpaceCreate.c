#include "petscMatNullSpaceCreate.h"
#include "petscMatNullSpaceCreate_types.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static const char cv[12] = {'M', 'a', 't', 'N', 'u', 'l',
                            'l', 'S', 'p', 'a', 'c', 'e'};

static void b_m2c_error(const emxArray_char_T *varargin_3);

static void c_m2c_error(int varargin_3);

static boolean_T isequal(const emxArray_char_T *varargin_1);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  char varargin_4[4];
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_array:TypeMismatch";
  fmt = "Incorrect data type &s. Expected %s.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  varargin_4[0] = 'V';
  varargin_4[1] = 'e';
  varargin_4[2] = 'c';
  varargin_4[3] = '\x00';
  M2C_error(msgid, fmt, &b_varargin_3->data[0], &varargin_4[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "MatNullSpaceCreate returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  static const char b_cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }
  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == b_cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return b_p || p;
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected MPI_Comm.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscMatNullSpaceCreate(const M2C_OpaqueType *comm, int has_cnst, int n,
                             const M2C_OpaqueType *vecs, M2C_OpaqueType *nullsp,
                             int *errCode, boolean_T *toplevel)
{
  static const char b_cv[3] = {'V', 'e', 'c'};
  MPI_Comm t_comm;
  MatNullSpace arg;
  Vec *ptr;
  char *b_ptr;
  emxArray_char_T *b_comm;
  int i;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  emxInit_char_T(&b_comm, 2);
  if (!isequal(comm->type)) {
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
  t_comm = *(MPI_Comm *)(&comm->data->data[0]);
  p = false;
  if (vecs->type->size[1] == 3) {
    p = true;
  }
  if (p && (vecs->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 3)) {
      if (!(vecs->type->data[sizepe] == b_cv[sizepe])) {
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
  ptr = (Vec *)(&vecs->data->data[0]);
  *errCode = MatNullSpaceCreate(t_comm, has_cnst, n, ptr, &arg);
  sizepe = sizeof(MatNullSpace);
  i = nullsp->data->size[0];
  nullsp->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(nullsp->data, i);
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

void petscMatNullSpaceCreate_2args(const M2C_OpaqueType *comm, int has_cnst,
                                   M2C_OpaqueType *nullsp, int *errCode,
                                   boolean_T *toplevel)
{
  MPI_Comm t_comm;
  MatNullSpace arg;
  Vec *ptr;
  char *b_ptr;
  emxArray_char_T *b_comm;
  int i;
  int sizepe;
  if (!isequal(comm->type)) {
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
  t_comm = *(MPI_Comm *)(&comm->data->data[0]);
  ptr = NULL;
  *errCode = MatNullSpaceCreate(t_comm, has_cnst, 0, ptr, &arg);
  sizepe = sizeof(MatNullSpace);
  i = nullsp->data->size[0];
  nullsp->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(nullsp->data, i);
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
