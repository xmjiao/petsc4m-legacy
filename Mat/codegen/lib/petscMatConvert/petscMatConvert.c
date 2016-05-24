#include "petscMatConvert.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatConvert returned error code %d\n",
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
            "Incorrect data type %s. Expected Mat.\n", &b_varargin_3->data[0]);
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

void petscMatConvert(const struct0_T *mat_in, const emxArray_char_T *newtype,
                     int reuse, struct0_T *mat_out, int *errCode, boolean_T
                     *toplevel)
{
  Mat t_mat_out;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i0;
  boolean_T exitg1;
  emxArray_char_T *b_mat_in;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data0;
  Mat mat;
  int sizepe;
  char t0_type[3];
  static const char x2[3] = { 'M', 'a', 't' };

  char * ptr;
  int i;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i0 = mat_in->type->size[k];
      if (i0 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(mat_in->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(mat_in->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_mat_in, 2);
    i0 = b_mat_in->size[0] * b_mat_in->size[1];
    b_mat_in->size[0] = 1;
    b_mat_in->size[1] = mat_in->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mat_in, i0, (int)sizeof(char));
    k = mat_in->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_mat_in->data[b_mat_in->size[0] * i0] = mat_in->type->data[mat_in->
        type->size[0] * i0];
    }

    b_mat_in->data[b_mat_in->size[0] * mat_in->type->size[1]] = '\x00';
    m2c_error(b_mat_in);
    emxFree_char_T(&b_mat_in);
  }

  emxInit_uint8_T(&data0, 1);
  i0 = data0->size[0];
  data0->size[0] = mat_in->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  k = mat_in->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data0->data[i0] = mat_in->data->data[i0];
  }

  mat = *(Mat*)(&data0->data[0]);
  *errCode = MatConvert(mat, &newtype->data[0], reuse, &t_mat_out);
  *toplevel = true;
  sizepe = sizeof(Mat);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 3; i0++) {
    t0_type[i0] = x2[i0];
  }

  i0 = mat_out->data->size[0];
  mat_out->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)mat_out->data, i0, (int)sizeof(unsigned
    char));
  k = data0->size[0];
  for (i0 = 0; i0 < k; i0++) {
    mat_out->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = mat_out->type->size[0] * mat_out->type->size[1];
  mat_out->type->size[0] = 1;
  mat_out->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)mat_out->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 3; i0++) {
    mat_out->type->data[i0] = t0_type[i0];
  }

  mat_out->nitems = 1;
  ptr = (char *)(&t_mat_out);
  for (i = 1; i <= sizepe; i++) {
    mat_out->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscMatConvert_initialize(void)
{
}

void petscMatConvert_terminate(void)
{
}
