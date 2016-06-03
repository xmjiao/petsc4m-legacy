#include "mptMatAIJToCRS.h"
#include "m2c.h"
#include "mpetsc.h"

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

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected Mat.\n", &b_varargin_3->data[0]);
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
  int flag;
  int exitg6;
  int errCode;
  boolean_T exitg5;
  emxArray_char_T *b_mat;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  Mat t_mat;
  int first_row;
  int nrows;
  int exitg4;
  boolean_T exitg3;
  emxArray_char_T *c_mat;
  MatInfo t_info;
  unsigned int nbytes;
  MPetscMatInfo info;
  int ind;
  int row;
  emxArray_int32_T *row_cols;
  emxArray_real_T *row_vals;
  emxArray_char_T *d_mat;
  int b_row;
  int exitg2;
  boolean_T exitg1;
  const int * t_cols;
  const double * t_vals;
  int ncols;
  p = false;
  b_p = false;
  flag = 0;
  do {
    exitg6 = 0;
    if (flag < 2) {
      errCode = mat->type->size[flag];
      if (errCode != (flag << 1) + 1) {
        exitg6 = 1;
      } else {
        flag++;
      }
    } else {
      b_p = true;
      exitg6 = 1;
    }
  } while (exitg6 == 0);

  if (b_p && (!(mat->type->size[1] == 0))) {
    flag = 0;
    exitg5 = false;
    while ((!exitg5) && (flag < 3)) {
      if (!(mat->type->data[flag] == cv0[flag])) {
        b_p = false;
        exitg5 = true;
      } else {
        flag++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_mat, 2);
    errCode = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mat, errCode, (int)sizeof(char));
    flag = mat->type->size[1];
    for (errCode = 0; errCode < flag; errCode++) {
      b_mat->data[b_mat->size[0] * errCode] = mat->type->data[mat->type->size[0]
        * errCode];
    }

    b_mat->data[b_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  emxInit_uint8_T(&data, 1);
  errCode = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, errCode, (int)sizeof(unsigned char));
  flag = mat->data->size[0];
  for (errCode = 0; errCode < flag; errCode++) {
    data->data[errCode] = mat->data->data[errCode];
  }

  t_mat = *(Mat*)(&data->data[0]);
  errCode = MatGetOwnershipRange(t_mat, &first_row, &flag);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      b_m2c_error(errCode);
    }
  }

  nrows = flag - first_row;
  p = false;
  b_p = false;
  flag = 0;
  do {
    exitg4 = 0;
    if (flag < 2) {
      errCode = mat->type->size[flag];
      if (errCode != (flag << 1) + 1) {
        exitg4 = 1;
      } else {
        flag++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(mat->type->size[1] == 0))) {
    flag = 0;
    exitg3 = false;
    while ((!exitg3) && (flag < 3)) {
      if (!(mat->type->data[flag] == cv0[flag])) {
        b_p = false;
        exitg3 = true;
      } else {
        flag++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&c_mat, 2);
    errCode = c_mat->size[0] * c_mat->size[1];
    c_mat->size[0] = 1;
    c_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)c_mat, errCode, (int)sizeof(char));
    flag = mat->type->size[1];
    for (errCode = 0; errCode < flag; errCode++) {
      c_mat->data[c_mat->size[0] * errCode] = mat->type->data[mat->type->size[0]
        * errCode];
    }

    c_mat->data[c_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(c_mat);
    emxFree_char_T(&c_mat);
  }

  errCode = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, errCode, (int)sizeof(unsigned char));
  flag = mat->data->size[0];
  for (errCode = 0; errCode < flag; errCode++) {
    data->data[errCode] = mat->data->data[errCode];
  }

  t_mat = *(Mat*)(&data->data[0]);
  flag = (MAT_LOCAL);
  errCode = MatGetInfo(t_mat, flag, &t_info);
  if (errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      c_m2c_error(errCode);
    }
  }

  nbytes = sizeof(t_info);
  if (80U < nbytes) {
    p = (M2C_DEBUG);
    if (p) {
      d_m2c_error(10, nbytes >> 3U);
    }
  }

  memcpy(&info, &t_info, nbytes);
  flag = (int)rt_roundd(info.nz_used);
  errCode = row_ptr->size[0];
  row_ptr->size[0] = nrows + 1;
  emxEnsureCapacity((emxArray__common *)row_ptr, errCode, (int)sizeof(int));
  errCode = col_ind->size[0];
  col_ind->size[0] = flag;
  emxEnsureCapacity((emxArray__common *)col_ind, errCode, (int)sizeof(int));
  errCode = val->size[0];
  val->size[0] = flag;
  emxEnsureCapacity((emxArray__common *)val, errCode, (int)sizeof(double));
  ind = 1;
  row = 0;
  emxInit_int32_T(&row_cols, 1);
  emxInit_real_T(&row_vals, 1);
  emxInit_char_T(&d_mat, 2);
  while (row + 1 <= nrows) {
    b_row = row + first_row;
    p = false;
    b_p = false;
    flag = 0;
    do {
      exitg2 = 0;
      if (flag < 2) {
        errCode = mat->type->size[flag];
        if (errCode != (flag << 1) + 1) {
          exitg2 = 1;
        } else {
          flag++;
        }
      } else {
        b_p = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (b_p && (!(mat->type->size[1] == 0))) {
      flag = 0;
      exitg1 = false;
      while ((!exitg1) && (flag < 3)) {
        if (!(mat->type->data[flag] == cv0[flag])) {
          b_p = false;
          exitg1 = true;
        } else {
          flag++;
        }
      }
    }

    if (!b_p) {
    } else {
      p = true;
    }

    if (!p) {
      errCode = d_mat->size[0] * d_mat->size[1];
      d_mat->size[0] = 1;
      d_mat->size[1] = mat->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)d_mat, errCode, (int)sizeof(char));
      flag = mat->type->size[1];
      for (errCode = 0; errCode < flag; errCode++) {
        d_mat->data[d_mat->size[0] * errCode] = mat->type->data[mat->type->size
          [0] * errCode];
      }

      d_mat->data[d_mat->size[0] * mat->type->size[1]] = '\x00';
      m2c_error(d_mat);
    }

    errCode = data->size[0];
    data->size[0] = mat->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, errCode, (int)sizeof(unsigned
      char));
    flag = mat->data->size[0];
    for (errCode = 0; errCode < flag; errCode++) {
      data->data[errCode] = mat->data->data[errCode];
    }

    t_mat = *(Mat*)(&data->data[0]);
    flag = 0;
    errCode = MatGetRow(t_mat, b_row, &flag, &t_cols, &t_vals);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        e_m2c_error(errCode);
      }
    }

    ncols = flag;
    errCode = row_cols->size[0];
    row_cols->size[0] = flag;
    emxEnsureCapacity((emxArray__common *)row_cols, errCode, (int)sizeof(int));
    errCode = row_vals->size[0];
    row_vals->size[0] = flag;
    emxEnsureCapacity((emxArray__common *)row_vals, errCode, (int)sizeof(double));
    memcpy(&row_cols->data[0], t_cols, flag << 2);
    memcpy(&row_vals->data[0], t_vals, flag << 3);
    errCode = MatRestoreRow(t_mat, b_row, &flag, &t_cols, &t_vals);
    if (errCode != 0) {
      p = (M2C_DEBUG);
      if (p) {
        f_m2c_error(errCode);
      }
    }

    for (flag = 1; flag <= ncols; flag++) {
      col_ind->data[(flag + ind) - 2] = row_cols->data[flag - 1] + 1;
      val->data[(flag + ind) - 2] = row_vals->data[flag - 1];
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
