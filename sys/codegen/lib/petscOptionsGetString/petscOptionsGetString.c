#include "petscOptionsGetString.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

static void b_m2c_error(void);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void d_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(void);
static void b_m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsGetString:InputError",
            "Argument name must be a null-terminated character string.");
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("PetscOptions:WrongType",
            "Incorrect data type %s. Expected PetscOptions.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void d_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "PetscOptionsGetString returned error code %d\n", varargin_3);
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
  M2C_error("MPETSc:petscOptionsGetString:InputError",
            "Argument pre must be a null-terminated string.");
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

void petscOptionsGetString(const struct0_T *opts, const emxArray_char_T *pre,
  const emxArray_char_T *name, emxArray_char_T *str, int *found, int *errCode,
  boolean_T *toplevel)
{
  char str0[21];
  PetscBool b_flag;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg3;
  int i0;
  boolean_T exitg2;
  emxArray_char_T *b_opts;
  static const char cv0[12] = { 'P', 'e', 't', 's', 'c', 'O', 'p', 't', 'i', 'o',
    'n', 's' };

  emxArray_uint8_T *data;
  PetscOptions c_opts;
  int i;
  boolean_T exitg1;
  *toplevel = true;
  if ((!(pre->size[1] == 0)) && (pre->data[pre->size[1] - 1] != '\x00')) {
    m2c_error();
  }

  if ((!(name->size[1] == 0)) && (name->data[name->size[1] - 1] != '\x00')) {
    b_m2c_error();
  }

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg3 = 0;
    if (k < 2) {
      i0 = opts->type->size[k];
      if (i0 != 11 * k + 1) {
        exitg3 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg3 = 1;
    }
  } while (exitg3 == 0);

  if (b_p && (!(opts->type->size[1] == 0))) {
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 12)) {
      if (!(opts->type->data[k] == cv0[k])) {
        b_p = false;
        exitg2 = true;
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

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = opts->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = opts->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = opts->data->data[i0];
  }

  c_opts = *(PetscOptions*)(&data->data[0]);
  *errCode = PetscOptionsGetString(c_opts, &pre->data[0], &name->data[0], str0,
    20, &b_flag);
  *found = (int)(b_flag);
  i0 = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = 0;
  emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
  i = 0;
  emxFree_uint8_T(&data);
  exitg1 = false;
  while ((!exitg1) && (i < 21)) {
    if ((unsigned char)str0[i] == 0) {
      k = i + 1;
      i0 = str->size[0] * str->size[1];
      str->size[0] = 1;
      str->size[1] = i + 1;
      emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
      for (i0 = 0; i0 < k; i0++) {
        str->data[str->size[0] * i0] = str0[i0];
      }

      exitg1 = true;
    } else {
      i++;
    }
  }

  if (*errCode != 0) {
    d_m2c_error(*errCode);
  }
}

void petscOptionsGetString_initialize(void)
{
}

void petscOptionsGetString_terminate(void)
{
}
