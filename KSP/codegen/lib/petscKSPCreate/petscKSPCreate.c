#include "petscKSPCreate.h"
#include "m2c.h"
#include "mpetsc.h"
#include "mpi.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "KSPCreate returned error code %d\n";
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

void petscKSPCreate(const struct0_T *comm, struct0_T *ksp, int *errCode,
                    boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data0;
  int loop_ub;
  MPI_Comm t_comm;
  KSP t_ksp;
  int sizepe;
  char t1_type[3];
  static const char cv1[3] = { 'K', 'S', 'P' };

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
  *errCode = KSPCreate(t_comm, &t_ksp);
  *toplevel = true;
  sizepe = sizeof(KSP);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, k, (int)sizeof(unsigned char));
  for (k = 0; k < 3; k++) {
    t1_type[k] = cv1[k];
  }

  k = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, k, (int)sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (k = 0; k < loop_ub; k++) {
    ksp->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, k, (int)sizeof(char));
  for (k = 0; k < 3; k++) {
    ksp->type->data[k] = t1_type[k];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (k = 1; k <= sizepe; k++) {
    ksp->data->data[k - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscKSPCreate_World(struct0_T *ksp, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  MPI_Comm obj;
  KSP t_ksp;
  int b_errCode;
  int sizepe;
  int i;
  char t0_type[3];
  static const char cv2[3] = { 'K', 'S', 'P' };

  int loop_ub;
  char * ptr;
  emxInit_uint8_T(&data0, 1);
  obj = PETSC_COMM_WORLD;
  b_errCode = KSPCreate(obj, &t_ksp);
  sizepe = sizeof(KSP);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i, (int)sizeof(unsigned char));
  for (i = 0; i < 3; i++) {
    t0_type[i] = cv2[i];
  }

  i = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, i, (int)sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (i = 0; i < loop_ub; i++) {
    ksp->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, i, (int)sizeof(char));
  for (i = 0; i < 3; i++) {
    ksp->type->data[i] = t0_type[i];
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
