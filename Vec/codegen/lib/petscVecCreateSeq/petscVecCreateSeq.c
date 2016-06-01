#include "petscVecCreateSeq.h"
#include "m2c.h"
#include "mpetsc.h"

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
  M2C_error("petsc:RuntimeError", "VecCreateSeq returned error code %d\n",
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

void petscVecCreateSeq(int n, struct0_T *vec, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  Vec t_vec;
  int sizepe;
  int i0;
  char t0_type[3];
  static const char cv0[3] = { 'V', 'e', 'c' };

  int loop_ub;
  char * ptr;
  int i;
  emxInit_uint8_T(&data0, 1);
  *errCode = VecCreateSeq(PETSC_COMM_SELF, n, &t_vec);
  *toplevel = true;
  sizepe = sizeof(Vec);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 3; i0++) {
    t0_type[i0] = cv0[i0];
  }

  i0 = vec->data->size[0];
  vec->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)vec->data, i0, (int)sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    vec->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = vec->type->size[0] * vec->type->size[1];
  vec->type->size[0] = 1;
  vec->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)vec->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 3; i0++) {
    vec->type->data[i0] = t0_type[i0];
  }

  vec->nitems = 1;
  ptr = (char *)(&t_vec);
  for (i = 1; i <= sizepe; i++) {
    vec->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (*errCode != 0) {
    m2c_error(*errCode);
  }
}

void petscVecCreateSeq_initialize(void)
{
}

void petscVecCreateSeq_terminate(void)
{
}
