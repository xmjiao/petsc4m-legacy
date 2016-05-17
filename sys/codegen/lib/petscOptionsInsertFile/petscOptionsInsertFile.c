#include "petscOptionsInsertFile.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(int varargin_3);
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

  M2C_error("MPI_Comm:WrongType", "Incorrect data type %s. Expected MPI_Comm.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("PetscOptions:WrongType",
            "Incorrect data type %s. Expected PetscOptions.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void d_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "PetscOptionsInsertFile returned error code %d\n", varargin_3);
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
  M2C_error("MPETSc:petscOptionsInsertFile:InputError",
            "Argument file must be a null-terminated string.");
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscOptionsInsertFile(const struct0_T *comm, const struct0_T *opts, const
  emxArray_char_T *file, int req, int *errCode, boolean_T *toplevel)
{
  emxArray_char_T *b_file;
  int i0;
  int k;
  boolean_T p;
  boolean_T b_p;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data;
  MPI_Comm c_comm;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_opts;
  static const char cv1[12] = { 'P', 'e', 't', 's', 'c', 'O', 'p', 't', 'i', 'o',
    'n', 's' };

  PetscOptions c_opts;
  *toplevel = true;
  if ((!(file->size[1] == 0)) && (file->data[file->size[1] - 1] != '\x00')) {
    m2c_error();
  }

  emxInit_char_T(&b_file, 2);
  i0 = b_file->size[0] * b_file->size[1];
  b_file->size[0] = 1;
  b_file->size[1] = file->size[1];
  emxEnsureCapacity((emxArray__common *)b_file, i0, (int)sizeof(char));
  k = file->size[0] * file->size[1];
  for (i0 = 0; i0 < k; i0++) {
    b_file->data[i0] = file->data[i0];
  }

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
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = opts->type->size[k];
      if (i0 != 11 * k + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(opts->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(opts->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_opts, 2);
    i0 = b_opts->size[0] * b_opts->size[1];
    b_opts->size[0] = 1;
    b_opts->size[1] = opts->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_opts, i0, (int)sizeof(char));
    k = opts->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_opts->data[b_opts->size[0] * i0] = opts->type->data[opts->type->size[0] *
        i0];
    }

    b_opts->data[b_opts->size[0] * opts->type->size[1]] = '\x00';
    c_m2c_error(b_opts);
    emxFree_char_T(&b_opts);
  }

  i0 = data->size[0];
  data->size[0] = opts->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = opts->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = opts->data->data[i0];
  }

  c_opts = *(PetscOptions*)(&data->data[0]);
  *errCode = PetscOptionsInsertFile(c_comm, c_opts, &b_file->data[0], req);
  emxFree_uint8_T(&data);
  emxFree_char_T(&b_file);
  if (*errCode != 0) {
    d_m2c_error(*errCode);
  }
}

void petscOptionsInsertFile_initialize(void)
{
}

void petscOptionsInsertFile_terminate(void)
{
}
