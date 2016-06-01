#include "petscMatNullSpaceCreate.h"
#include "m2c.h"
#include "mpetsc.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  char varargin_4[4];
  static const char b_varargin_4[4] = { 'V', 'e', 'c', '\x00' };

  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  for (i2 = 0; i2 < 4; i2++) {
    varargin_4[i2] = b_varargin_4[i2];
  }

  M2C_error("m2c_opaque_array:TypeMismatch",
            "Incorrect data type &s. Expected %s.\n", &b_varargin_3->data[0],
            varargin_4);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatNullSpaceCreate returned error code %d\n",
            varargin_3);
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
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Comm.\n", &b_varargin_3->data
            [0]);
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
  int i0;
  boolean_T exitg3;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *t_vecs;
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
  int i;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i0 = comm->type->size[k];
      if (i0 != 7 * k + 1) {
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
    i0 = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_comm, i0, (int)sizeof(char));
    k = comm->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_comm->data[b_comm->size[0] * i0] = comm->type->data[comm->type->size[0] *
        i0];
    }

    b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
    m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }

  emxInit_uint8_T(&t_vecs, 1);
  i0 = t_vecs->size[0];
  t_vecs->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)t_vecs, i0, (int)sizeof(unsigned char));
  k = comm->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    t_vecs->data[i0] = comm->data->data[i0];
  }

  t_comm = *(MPI_Comm*)(&t_vecs->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = vecs->type->size[k];
      if (i0 != (k << 1) + 1) {
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
    i0 = b_vecs->size[0] * b_vecs->size[1];
    b_vecs->size[0] = 1;
    b_vecs->size[1] = vecs->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_vecs, i0, (int)sizeof(char));
    k = vecs->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_vecs->data[b_vecs->size[0] * i0] = vecs->type->data[vecs->type->size[0] *
        i0];
    }

    b_vecs->data[b_vecs->size[0] * vecs->type->size[1]] = '\x00';
    b_m2c_error(b_vecs);
    emxFree_char_T(&b_vecs);
  }

  i0 = t_vecs->size[0];
  t_vecs->size[0] = vecs->data->size[0];
  emxEnsureCapacity((emxArray__common *)t_vecs, i0, (int)sizeof(unsigned char));
  k = vecs->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    t_vecs->data[i0] = vecs->data->data[i0];
  }

  ptr = (Vec *)(&t_vecs->data[0]);
  *errCode = MatNullSpaceCreate(t_comm, has_cnst, n, ptr, &t_nullsp);
  *toplevel = true;
  sizepe = sizeof(MatNullSpace);
  i0 = t_vecs->size[0];
  t_vecs->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)t_vecs, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 12; i0++) {
    t1_type[i0] = cv2[i0];
  }

  i0 = nullsp->data->size[0];
  nullsp->data->size[0] = t_vecs->size[0];
  emxEnsureCapacity((emxArray__common *)nullsp->data, i0, (int)sizeof(unsigned
    char));
  k = t_vecs->size[0];
  for (i0 = 0; i0 < k; i0++) {
    nullsp->data->data[i0] = t_vecs->data[i0];
  }

  emxFree_uint8_T(&t_vecs);
  i0 = nullsp->type->size[0] * nullsp->type->size[1];
  nullsp->type->size[0] = 1;
  nullsp->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)nullsp->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 12; i0++) {
    nullsp->type->data[i0] = t1_type[i0];
  }

  nullsp->nitems = 1;
  b_ptr = (char *)(&t_nullsp);
  for (i = 1; i <= sizepe; i++) {
    nullsp->data->data[i - 1] = *(b_ptr);
    b_ptr = M2C_OFFSET_PTR(b_ptr, 1);
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
  int i3;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv3[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data0;
  MPI_Comm t_comm;
  MatNullSpace t_nullsp;
  int b_errCode;
  int sizepe;
  char t0_type[12];
  static const char cv4[12] = { 'M', 'a', 't', 'N', 'u', 'l', 'l', 'S', 'p', 'a',
    'c', 'e' };

  char * ptr;
  int i;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i3 = comm->type->size[k];
      if (i3 != 7 * k + 1) {
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
    i3 = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_comm, i3, (int)sizeof(char));
    k = comm->type->size[1];
    for (i3 = 0; i3 < k; i3++) {
      b_comm->data[b_comm->size[0] * i3] = comm->type->data[comm->type->size[0] *
        i3];
    }

    b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
    m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }

  emxInit_uint8_T(&data0, 1);
  i3 = data0->size[0];
  data0->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i3, (int)sizeof(unsigned char));
  k = comm->data->size[0];
  for (i3 = 0; i3 < k; i3++) {
    data0->data[i3] = comm->data->data[i3];
  }

  t_comm = *(MPI_Comm*)(&data0->data[0]);
  b_errCode = MatNullSpaceCreate(t_comm, has_cnst, 0, NULL, &t_nullsp);
  sizepe = sizeof(MatNullSpace);
  i3 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i3, (int)sizeof(unsigned char));
  for (i3 = 0; i3 < 12; i3++) {
    t0_type[i3] = cv4[i3];
  }

  i3 = nullsp->data->size[0];
  nullsp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)nullsp->data, i3, (int)sizeof(unsigned
    char));
  k = data0->size[0];
  for (i3 = 0; i3 < k; i3++) {
    nullsp->data->data[i3] = data0->data[i3];
  }

  emxFree_uint8_T(&data0);
  i3 = nullsp->type->size[0] * nullsp->type->size[1];
  nullsp->type->size[0] = 1;
  nullsp->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)nullsp->type, i3, (int)sizeof(char));
  for (i3 = 0; i3 < 12; i3++) {
    nullsp->type->data[i3] = t0_type[i3];
  }

  nullsp->nitems = 1;
  ptr = (char *)(&t_nullsp);
  for (i = 1; i <= sizepe; i++) {
    nullsp->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
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
