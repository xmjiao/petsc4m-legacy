#include "petscVecCreate.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecCreate returned error code %d\n",
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

void petscVecCreate(const struct0_T *comm, struct0_T *vec, int *errCode,
                    boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data0;
  MPI_Comm t_comm;
  Vec t_vec;
  int sizepe;
  char t1_type[3];
  static const char cv1[3] = { 'V', 'e', 'c' };

  char * ptr;
  int i;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = comm->type->size[k];
      if (i0 != 7 * k + 1) {
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
      if (!(comm->type->data[k] == cv0[k])) {
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

  emxInit_uint8_T(&data0, 1);
  i0 = data0->size[0];
  data0->size[0] = comm->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  k = comm->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data0->data[i0] = comm->data->data[i0];
  }

  t_comm = *(MPI_Comm*)(&data0->data[0]);
  *errCode = VecCreate(t_comm, &t_vec);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  sizepe = sizeof(Vec);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 3; i0++) {
    t1_type[i0] = cv1[i0];
  }

  i0 = vec->data->size[0];
  vec->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)vec->data, i0, (int)sizeof(unsigned char));
  k = data0->size[0];
  for (i0 = 0; i0 < k; i0++) {
    vec->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = vec->type->size[0] * vec->type->size[1];
  vec->type->size[0] = 1;
  vec->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)vec->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 3; i0++) {
    vec->type->data[i0] = t1_type[i0];
  }

  vec->nitems = 1;
  ptr = (char *)(&t_vec);
  for (i = 1; i <= sizepe; i++) {
    vec->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }
}

void petscVecCreate_World(struct0_T *vec, int *errCode, boolean_T *topleve)
{
  Vec t_vec;
  int b_errCode;
  emxArray_uint8_T *data0;
  int sizepe;
  int i2;
  char t0_type[3];
  static const char cv2[3] = { 'V', 'e', 'c' };

  int loop_ub;
  char * ptr;
  int i;
  b_errCode = VecCreate(PETSC_COMM_WORLD, &t_vec);
  if (b_errCode != 0) {
    b_m2c_error(b_errCode);
  }

  emxInit_uint8_T(&data0, 1);
  sizepe = sizeof(Vec);
  i2 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i2, (int)sizeof(unsigned char));
  for (i2 = 0; i2 < 3; i2++) {
    t0_type[i2] = cv2[i2];
  }

  i2 = vec->data->size[0];
  vec->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)vec->data, i2, (int)sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    vec->data->data[i2] = data0->data[i2];
  }

  emxFree_uint8_T(&data0);
  i2 = vec->type->size[0] * vec->type->size[1];
  vec->type->size[0] = 1;
  vec->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)vec->type, i2, (int)sizeof(char));
  for (i2 = 0; i2 < 3; i2++) {
    vec->type->data[i2] = t0_type[i2];
  }

  vec->nitems = 1;
  ptr = (char *)(&t_vec);
  for (i = 1; i <= sizepe; i++) {
    vec->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  *errCode = b_errCode;
  *topleve = true;
}

void petscVecCreate_initialize(void)
{
}

void petscVecCreate_terminate(void)
{
}
