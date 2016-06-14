#include "petscMatNullSpaceCreate.h"
#include "m2c.h"
#include "mpetsc.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i1;
  int loop_ub;
  char varargin_4[4];
  static const char b_varargin_4[4] = { 'V', 'e', 'c', '\x00' };

  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_array:TypeMismatch";
  fmt = "Incorrect data type &s. Expected %s.\n";
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  for (i1 = 0; i1 < 4; i1++) {
    varargin_4[i1] = b_varargin_4[i1];
  }

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

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscMatNullSpaceCreate(const struct0_T *comm, int has_cnst, int n, const
  struct0_T *vecs, struct0_T *nullsp, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *t_vecs;
  int loop_ub;
  MPI_Comm t_comm;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_vecs;
  static const char cv1[3] = { 'V', 'e', 'c' };

  MatNullSpace t_nullsp;
  Vec * ptr;
  int sizepe;
  char t1_type[12];
  static const char cv2[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  char * b_ptr;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      if (comm->type->size[k] != 1 + 7 * k) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(comm->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 8)) {
      if (!(comm->type->data[k] == cv0[k])) {
        b_p = false;
        exitg3 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_comm, 2);
    k = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_comm, k, (int)sizeof(char));
    loop_ub = comm->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_comm->data[b_comm->size[0] * k] = comm->type->data[comm->type->size[0] *
        k];
    }

    b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
    m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }

  emxInit_uint8_T(&t_vecs, 1);
  k = t_vecs->size[0];
  t_vecs->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)t_vecs, k, (int)sizeof(unsigned char));
  loop_ub = comm->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    t_vecs->data[k] = comm->data->data[k];
  }

  t_comm = *(MPI_Comm*)(&t_vecs->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      if (vecs->type->size[k] != 1 + (k << 1)) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(vecs->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(vecs->type->data[k] == cv1[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_vecs, 2);
    k = b_vecs->size[0] * b_vecs->size[1];
    b_vecs->size[0] = 1;
    b_vecs->size[1] = vecs->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_vecs, k, (int)sizeof(char));
    loop_ub = vecs->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_vecs->data[b_vecs->size[0] * k] = vecs->type->data[vecs->type->size[0] *
        k];
    }

    b_vecs->data[b_vecs->size[0] * vecs->type->size[1]] = '\x00';
    b_m2c_error(b_vecs);
    emxFree_char_T(&b_vecs);
  }

  k = t_vecs->size[0];
  t_vecs->size[0] = vecs->data->size[0];
  emxEnsureCapacity((emxArray__common *)t_vecs, k, (int)sizeof(unsigned char));
  loop_ub = vecs->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    t_vecs->data[k] = vecs->data->data[k];
  }

  ptr = (Vec *)(&t_vecs->data[0]);
  *errCode = MatNullSpaceCreate(t_comm, has_cnst, n, ptr, &t_nullsp);
  *toplevel = true;
  sizepe = sizeof(MatNullSpace);
  k = t_vecs->size[0];
  t_vecs->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)t_vecs, k, (int)sizeof(unsigned char));
  for (k = 0; k < 12; k++) {
    t1_type[k] = cv2[k];
  }

  k = nullsp->data->size[0];
  nullsp->data->size[0] = t_vecs->size[0];
  emxEnsureCapacity((emxArray__common *)nullsp->data, k, (int)sizeof(unsigned
    char));
  loop_ub = t_vecs->size[0];
  for (k = 0; k < loop_ub; k++) {
    nullsp->data->data[k] = t_vecs->data[k];
  }

  emxFree_uint8_T(&t_vecs);
  k = nullsp->type->size[0] * nullsp->type->size[1];
  nullsp->type->size[0] = 1;
  nullsp->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)nullsp->type, k, (int)sizeof(char));
  for (k = 0; k < 12; k++) {
    nullsp->type->data[k] = t1_type[k];
  }

  nullsp->nitems = 1;
  b_ptr = (char *)(&t_nullsp);
  for (k = 1; k <= sizepe; k++) {
    nullsp->data->data[k - 1] = *(b_ptr);
    b_ptr = b_ptr+1;
  }

  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscMatNullSpaceCreate_2args(const struct0_T *comm, int has_cnst,
  struct0_T *nullsp, int *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv3[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data0;
  int loop_ub;
  MPI_Comm t_comm;
  Vec * t_vecs;
  MatNullSpace t_nullsp;
  int b_errCode;
  int sizepe;
  char t0_type[12];
  static const char cv4[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  char * ptr;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      if (comm->type->size[k] != 1 + 7 * k) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(comm->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(comm->type->data[k] == cv3[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_comm, 2);
    k = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_comm, k, (int)sizeof(char));
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
  emxEnsureCapacity((emxArray__common *)data0, k, (int)sizeof(unsigned char));
  loop_ub = comm->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data0->data[k] = comm->data->data[k];
  }

  t_comm = *(MPI_Comm*)(&data0->data[0]);
  t_vecs = NULL;
  b_errCode = MatNullSpaceCreate(t_comm, has_cnst, 0, t_vecs, &t_nullsp);
  sizepe = sizeof(MatNullSpace);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, k, (int)sizeof(unsigned char));
  for (k = 0; k < 12; k++) {
    t0_type[k] = cv4[k];
  }

  k = nullsp->data->size[0];
  nullsp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)nullsp->data, k, (int)sizeof(unsigned
    char));
  loop_ub = data0->size[0];
  for (k = 0; k < loop_ub; k++) {
    nullsp->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = nullsp->type->size[0] * nullsp->type->size[1];
  nullsp->type->size[0] = 1;
  nullsp->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)nullsp->type, k, (int)sizeof(char));
  for (k = 0; k < 12; k++) {
    nullsp->type->data[k] = t0_type[k];
  }

  nullsp->nitems = 1;
  ptr = (char *)(&t_nullsp);
  for (k = 1; k <= sizepe; k++) {
    nullsp->data->data[k - 1] = *(ptr);
    ptr = ptr+1;
  }

  if (b_errCode != 0) {
    c_m2c_error(b_errCode);
  }

  *errCode = b_errCode;
  *toplevel = true;
}

void petscMatNullSpaceCreate_initialize(void)
{
}

void petscMatNullSpaceCreate_terminate(void)
{
}
