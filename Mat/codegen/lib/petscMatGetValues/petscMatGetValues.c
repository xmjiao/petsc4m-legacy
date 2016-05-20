#include "petscMatGetValues.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatGetValues returned error code %d\n",
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
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("PetscMat:WrongType", "Incorrect data type %s. Expected Mat.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

int petscMatGetValues(const struct0_T *mat, int ni, const emxArray_int32_T *ix,
                      int nj, const emxArray_int32_T *jx, emxArray_real_T *v)
{
  int errCode;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i3;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  static const char cv1[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  Mat t_mat;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i3 = mat->type->size[k];
      if (i3 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(mat->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(mat->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_mat, 2);
    i3 = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mat, i3, (int)sizeof(char));
    k = mat->type->size[1];
    for (i3 = 0; i3 < k; i3++) {
      b_mat->data[b_mat->size[0] * i3] = mat->type->data[mat->type->size[0] * i3];
    }

    b_mat->data[b_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  emxInit_uint8_T(&data, 1);
  i3 = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i3, (int)sizeof(unsigned char));
  k = mat->data->size[0];
  for (i3 = 0; i3 < k; i3++) {
    data->data[i3] = mat->data->data[i3];
  }

  t_mat = *(Mat*)(&data->data[0]);
  errCode = MatGetValues(t_mat, ni, &ix->data[0], nj, &jx->data[0], &v->data[0]);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    b_m2c_error(errCode);
  }

  return errCode;
}

void petscMatGetValues_Alloc(const struct0_T *mat, int ni, const
  emxArray_int32_T *ix, int nj, const emxArray_int32_T *jx, emxArray_real_T *v,
  int *errCode)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i1;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  Mat t_mat;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i1 = mat->type->size[k];
      if (i1 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(mat->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(mat->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_mat, 2);
    i1 = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mat, i1, (int)sizeof(char));
    k = mat->type->size[1];
    for (i1 = 0; i1 < k; i1++) {
      b_mat->data[b_mat->size[0] * i1] = mat->type->data[mat->type->size[0] * i1];
    }

    b_mat->data[b_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  emxInit_uint8_T(&data, 1);
  i1 = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i1, (int)sizeof(unsigned char));
  k = mat->data->size[0];
  for (i1 = 0; i1 < k; i1++) {
    data->data[i1] = mat->data->data[i1];
  }

  t_mat = *(Mat*)(&data->data[0]);
  i1 = v->size[0];
  v->size[0] = ni * nj;
  emxEnsureCapacity((emxArray__common *)v, i1, (int)sizeof(double));
  k = MatGetValues(t_mat, ni, &ix->data[0], nj, &jx->data[0], &v->data[0]);
  emxFree_uint8_T(&data);
  if (k != 0) {
    b_m2c_error(k);
  }

  *errCode = k;
}

void petscMatGetValues_initialize(void)
{
}

void petscMatGetValues_terminate(void)
{
}