#include "petscPCGetType.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void emxInit_uint8_T1(emxArray_uint8_T **pEmxArray, int numDimensions);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCGetType returned error code %d\n",
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

static void emxInit_uint8_T1(emxArray_uint8_T **pEmxArray, int numDimensions)
{
  emxArray_uint8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint8_T *)malloc(sizeof(emxArray_uint8_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
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

  M2C_error("PetscPC:WrongType", "Incorrect data type %s. Expected PC.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
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

void petscPCGetType(const struct0_T *pc, emxArray_char_T *type, int *errCode,
                    boolean_T *toplevel)
{
  PCType t_type;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_pc;
  static const char cv0[2] = { 'P', 'C' };

  emxArray_uint8_T *data;
  PC c_pc;
  const char * str;
  int empty;
  emxArray_uint8_T *str1;
  int n;
  unsigned int uv0[2];
  char * ptr;
  int i;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = pc->type->size[k];
      if (i0 != k + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(pc->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!(pc->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_pc, 2);
    i0 = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = pc->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_pc, i0, (int)sizeof(char));
    k = pc->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_pc->data[b_pc->size[0] * i0] = pc->type->data[pc->type->size[0] * i0];
    }

    b_pc->data[b_pc->size[0] * pc->type->size[1]] = '\x00';
    m2c_error(b_pc);
    emxFree_char_T(&b_pc);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = pc->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = pc->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = pc->data->data[i0];
  }

  c_pc = *(PC*)(&data->data[0]);
  *errCode = PCGetType(c_pc, &t_type);
  *toplevel = true;
  str = (t_type);
  empty = !(str);
  emxFree_uint8_T(&data);
  emxInit_uint8_T1(&str1, 2);
  if (!(empty != 0)) {
    n = strlen(str) + 1;
    i0 = str1->size[0] * str1->size[1];
    str1->size[0] = 1;
    str1->size[1] = n;
    emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    for (i0 = 0; i0 < n; i0++) {
      str1->data[i0] = 0;
    }

    ptr = (char *)(str);
    for (i = 1; i <= n; i++) {
      str1->data[i - 1] = *(ptr);
      ptr = M2C_OFFSET_PTR(ptr, 1);
    }
  } else {
    i0 = str1->size[0] * str1->size[1];
    str1->size[0] = 1;
    str1->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
  }

  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (unsigned int)str1->size[i0];
  }

  i0 = type->size[0] * type->size[1];
  type->size[0] = 1;
  type->size[1] = (int)uv0[1];
  emxEnsureCapacity((emxArray__common *)type, i0, (int)sizeof(char));
  k = (int)uv0[1];
  for (i0 = 0; i0 < k; i0++) {
    type->data[i0] = (signed char)str1->data[i0];
  }

  emxFree_uint8_T(&str1);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscPCGetType_initialize(void)
{
}

void petscPCGetType_terminate(void)
{
}
