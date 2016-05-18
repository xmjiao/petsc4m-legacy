#include "mptMatAIJToCRS.h"
#include "petscksp.h"
#include "petscsys.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void c_m2c_error(int varargin_3);
static void d_m2c_error(int varargin_3, unsigned int varargin_4);
static void e_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void f_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static double rt_roundd(double u);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "MatGetOwnershipRange returned error code %d\first_row", varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "petscMatGetInfo returned error code %d\n",
            varargin_3);
}

static void d_m2c_error(int varargin_3, unsigned int varargin_4)
{
  M2C_error("petscMatGetInfo:WrongSize",
            "There are %d fields in PetscMatInfo but %d fields in MatInfo.",
            varargin_3, varargin_4);
}

static void e_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatGetRow returned error code %d\n",
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

static void f_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatRestoreRow returned error code %d\n",
            varargin_3);
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

  M2C_error("PetscMat:WrongType", "Incorrect data type %s. Expected Mat.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static double rt_roundd(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
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

void mptMatAIJToCRS(const struct0_T *mat, emxArray_int32_T *row_ptr,
                    emxArray_int32_T *col_ind, emxArray_real_T *val)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg6;
  int i0;
  boolean_T exitg5;
  emxArray_char_T *b_mat;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  Mat t_mat;
  int first_row;
  int last_row;
  int errCode;
  int nrows;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *c_mat;
  MatInfo t_info;
  unsigned int nbytes;
  MPetscMatInfo info;
  int nnz;
  int ind;
  int row;
  emxArray_int32_T *row_cols;
  emxArray_real_T *row_vals;
  emxArray_char_T *d_mat;
  int b_row;
  int exitg2;
  boolean_T exitg1;
  int t_ncols;
  const int * t_cols;
  const double * t_vals;
  int ncols;
  int j;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg6 = 0;
    if (k < 2) {
      i0 = mat->type->size[k];
      if (i0 != (k << 1) + 1) {
        exitg6 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg6 = 1;
    }
  } while (exitg6 == 0);

  if (b_p && (!(mat->type->size[1] == 0))) {
    k = 0;
    exitg5 = false;
    while ((!exitg5) && (k < 3)) {
      if (!(mat->type->data[k] == cv0[k])) {
        b_p = false;
        exitg5 = true;
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
    i0 = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mat, i0, (int)sizeof(char));
    k = mat->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_mat->data[b_mat->size[0] * i0] = mat->type->data[mat->type->size[0] * i0];
    }

    b_mat->data[b_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = mat->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = mat->data->data[i0];
  }

  t_mat = *(Mat*)(&data->data[0]);
  errCode = MatGetOwnershipRange(t_mat, &first_row, &last_row);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      b_m2c_error(errCode);
    }
  }

  nrows = last_row - first_row;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i0 = mat->type->size[k];
      if (i0 != (k << 1) + 1) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(mat->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(mat->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&c_mat, 2);
    i0 = c_mat->size[0] * c_mat->size[1];
    c_mat->size[0] = 1;
    c_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)c_mat, i0, (int)sizeof(char));
    k = mat->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      c_mat->data[c_mat->size[0] * i0] = mat->type->data[mat->type->size[0] * i0];
    }

    c_mat->data[c_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(c_mat);
    emxFree_char_T(&c_mat);
  }

  i0 = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = mat->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = mat->data->data[i0];
  }

  t_mat = *(Mat*)(&data->data[0]);
  k = (MAT_LOCAL);
  errCode = MatGetInfo(t_mat, k, &t_info);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      c_m2c_error(errCode);
    }
  }

  nbytes = sizeof(t_info);
  if (80U < nbytes) {
    k = (M2C_DEBUG);
    if (k != 0) {
      d_m2c_error(10, nbytes >> 3U);
    }
  }

  memcpy(&info, &t_info, nbytes);
  nnz = (int)rt_roundd(info.nz_used);
  i0 = row_ptr->size[0];
  row_ptr->size[0] = nrows + 1;
  emxEnsureCapacity((emxArray__common *)row_ptr, i0, (int)sizeof(int));
  i0 = col_ind->size[0];
  col_ind->size[0] = nnz;
  emxEnsureCapacity((emxArray__common *)col_ind, i0, (int)sizeof(int));
  i0 = val->size[0];
  val->size[0] = nnz;
  emxEnsureCapacity((emxArray__common *)val, i0, (int)sizeof(double));
  ind = 1;
  row = 0;
  emxInit_int32_T(&row_cols, 1);
  emxInit_real_T(&row_vals, 1);
  emxInit_char_T(&d_mat, 2);
  while (row + 1 <= nrows) {
    b_row = row + first_row;
    p = false;
    b_p = false;
    k = 0;
    do {
      exitg2 = 0;
      if (k < 2) {
        i0 = mat->type->size[k];
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
      i0 = d_mat->size[0] * d_mat->size[1];
      d_mat->size[0] = 1;
      d_mat->size[1] = mat->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)d_mat, i0, (int)sizeof(char));
      k = mat->type->size[1];
      for (i0 = 0; i0 < k; i0++) {
        d_mat->data[d_mat->size[0] * i0] = mat->type->data[mat->type->size[0] *
          i0];
      }

      d_mat->data[d_mat->size[0] * mat->type->size[1]] = '\x00';
      m2c_error(d_mat);
    }

    i0 = data->size[0];
    data->size[0] = mat->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
    k = mat->data->size[0];
    for (i0 = 0; i0 < k; i0++) {
      data->data[i0] = mat->data->data[i0];
    }

    t_mat = *(Mat*)(&data->data[0]);
    t_ncols = 0;
    errCode = MatGetRow(t_mat, b_row, &t_ncols, &t_cols, &t_vals);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        e_m2c_error(errCode);
      }
    }

    ncols = t_ncols;
    i0 = row_cols->size[0];
    row_cols->size[0] = t_ncols;
    emxEnsureCapacity((emxArray__common *)row_cols, i0, (int)sizeof(int));
    i0 = row_vals->size[0];
    row_vals->size[0] = t_ncols;
    emxEnsureCapacity((emxArray__common *)row_vals, i0, (int)sizeof(double));
    memcpy(&row_cols->data[0], t_cols, t_ncols << 2);
    memcpy(&row_vals->data[0], t_vals, t_ncols << 3);
    errCode = MatRestoreRow(t_mat, b_row, &t_ncols, &t_cols, &t_vals);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        f_m2c_error(errCode);
      }
    }

    for (j = 1; j <= ncols; j++) {
      col_ind->data[(j + ind) - 2] = row_cols->data[j - 1] + 1;
      val->data[(j + ind) - 2] = row_vals->data[j - 1];
    }

    row_ptr->data[row] = ind;
    ind += ncols;
    row++;
  }

  emxFree_char_T(&d_mat);
  emxFree_uint8_T(&data);
  emxFree_real_T(&row_vals);
  emxFree_int32_T(&row_cols);
  row_ptr->data[nrows] = ind;
}

void mptMatAIJToCRS_initialize(void)
{
}

void mptMatAIJToCRS_terminate(void)
{
}
