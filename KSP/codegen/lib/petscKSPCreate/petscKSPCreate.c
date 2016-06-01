#include "petscKSPCreate.h"
#include "m2c.h"
#include "mpetsc.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPCreate returned error code %d\n",
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

void petscKSPCreate(const struct0_T *comm, struct0_T *ksp, int *errCode,
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
  KSP t_ksp;
  int sizepe;
  char t1_type[3];
  static const char cv1[3] = { 'K', 'S', 'P' };

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
  *errCode = KSPCreate(t_comm, &t_ksp);
  *toplevel = true;
  sizepe = sizeof(KSP);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 3; i0++) {
    t1_type[i0] = cv1[i0];
  }

  i0 = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, i0, (int)sizeof(unsigned char));
  k = data0->size[0];
  for (i0 = 0; i0 < k; i0++) {
    ksp->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 3; i0++) {
    ksp->type->data[i0] = t1_type[i0];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (i = 1; i <= sizepe; i++) {
    ksp->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscKSPCreate_World(struct0_T *ksp, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  KSP t_ksp;
  int b_errCode;
  int sizepe;
  int i2;
  char t0_type[3];
  static const char cv2[3] = { 'K', 'S', 'P' };

  int loop_ub;
  char * ptr;
  int i;
  emxInit_uint8_T(&data0, 1);
  b_errCode = KSPCreate(PETSC_COMM_WORLD, &t_ksp);
  sizepe = sizeof(KSP);
  i2 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i2, (int)sizeof(unsigned char));
  for (i2 = 0; i2 < 3; i2++) {
    t0_type[i2] = cv2[i2];
  }

  i2 = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, i2, (int)sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    ksp->data->data[i2] = data0->data[i2];
  }

  emxFree_uint8_T(&data0);
  i2 = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, i2, (int)sizeof(char));
  for (i2 = 0; i2 < 3; i2++) {
    ksp->type->data[i2] = t0_type[i2];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (i = 1; i <= sizepe; i++) {
    ksp->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (b_errCode != 0) {
    b_m2c_error(b_errCode);
  }

  *errCode = b_errCode;
  *toplevel = true;
}

void petscKSPCreate_initialize(void)
{
}

void petscKSPCreate_terminate(void)
{
}
