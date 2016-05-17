#include "petscOptionsCreate.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(int varargin_3);

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

static void m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscOptionsCreate returned error code %d\n",
            varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscOptionsCreate(struct0_T *opts, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  PetscOptions t_opts;
  int sizepe;
  int i0;
  char t0_type[12];
  static const char cv0[12] = { 'P', 'e', 't', 's', 'c', 'O', 'p', 't', 'i', 'o',
    'n', 's' };

  int loop_ub;
  char * ptr;
  int i;
  emxInit_uint8_T(&data0, 1);
  *errCode = PetscOptionsCreate(&t_opts);
  *toplevel = true;
  sizepe = sizeof(PetscOptions);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 12; i0++) {
    t0_type[i0] = cv0[i0];
  }

  i0 = opts->data->size[0];
  opts->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)opts->data, i0, (int)sizeof(unsigned
    char));
  loop_ub = data0->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    opts->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = opts->type->size[0] * opts->type->size[1];
  opts->type->size[0] = 1;
  opts->type->size[1] = 12;
  emxEnsureCapacity((emxArray__common *)opts->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 12; i0++) {
    opts->type->data[i0] = t0_type[i0];
  }

  opts->nitems = 1;
  ptr = (char *)(&t_opts);
  for (i = 1; i <= sizepe; i++) {
    opts->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (*errCode != 0) {
    m2c_error(*errCode);
  }
}

void petscOptionsCreate_initialize(void)
{
}

void petscOptionsCreate_terminate(void)
{
}
