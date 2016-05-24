#include "mpi_Abort.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(void);
static void b_m2c_error(const emxArray_char_T *varargin_3)
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

static void m2c_error(void)
{
  M2C_error("MMPI:MPI_Abort", "MPI_Abort was called");
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

int mpi_Abort(const struct0_T *comm, int errorcode)
{
  int info;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data;
  MPI_Comm c_comm;
  info = 0;
  if (emlrtIsMATLABThread(emlrtRootTLSGlobal)) {
    m2c_error();
  } else {
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
        b_comm->data[b_comm->size[0] * i0] = comm->type->data[comm->type->size[0]
          * i0];
      }

      b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
      b_m2c_error(b_comm);
      emxFree_char_T(&b_comm);
    }

    emxInit_uint8_T(&data, 1);
    i0 = data->size[0];
    data->size[0] = comm->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
    k = comm->data->size[0];
    for (i0 = 0; i0 < k; i0++) {
      data->data[i0] = comm->data->data[i0];
    }

    c_comm = *(MPI_Comm*)(&data->data[0]);
    info = MPI_Abort(c_comm, errorcode);
    emxFree_uint8_T(&data);
  }

  return info;
}

void mpi_Abort_initialize(void)
{
}

void mpi_Abort_terminate(void)
{
}
