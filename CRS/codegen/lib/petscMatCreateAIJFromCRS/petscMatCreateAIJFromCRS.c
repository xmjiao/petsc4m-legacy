#include "petscMatCreateAIJFromCRS.h"
#include "petscMatCreateAIJFromCRS_emxutil.h"
#include "petscMatCreateAIJFromCRS_types.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

void petscMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr,
                              const emxArray_int32_T *col_ind,
                              const emxArray_real_T *val, int ncols,
                              emxArray_char_T *prefix, struct0_T *mat,
                              boolean_T *toplevel)
{
  MPI_Comm t_comm;
  Mat t_mat;
  char *ptr;
  emxArray_int32_T *jidx;
  emxArray_int32_T *nnz;
  emxArray_real_T *rowval;
  int b_i;
  int first_row;
  int i;
  int i1;
  int iroa;
  int last_row;
  int n;
  emxInit_int32_T(&nnz, 1);
  n = row_ptr->size[0] - 1;
  i = nnz->size[0];
  nnz->size[0] = row_ptr->size[0] - 1;
  emxEnsureCapacity_int32_T(nnz, i);
  for (b_i = 0; b_i < n; b_i++) {
    nnz->data[b_i] = row_ptr->data[b_i + 1] - row_ptr->data[b_i];
  }
  t_comm = PETSC_COMM_WORLD;
  MatCreate(t_comm, &t_mat);
  if ((prefix->size[1] != 0) && (prefix->data[prefix->size[1] - 1] != '\x00')) {
    i = prefix->size[1];
    last_row = prefix->size[0] * prefix->size[1];
    prefix->size[1]++;
    emxEnsureCapacity_char_T(prefix, last_row);
    prefix->data[i] = '\x00';
  }
  MatSetOptionsPrefix(t_mat, &prefix->data[0]);
  MatSetFromOptions(t_mat);
  last_row = (PETSC_DECIDE);
  iroa = (PETSC_DETERMINE);
  MatSetSizes(t_mat, row_ptr->size[0] - 1, last_row, iroa, ncols);
  MatGetOwnershipRange(t_mat, &first_row, &last_row);
  emxInit_int32_T(&jidx, 1);
  emxInit_real_T(&rowval, 1);
  for (b_i = 0; b_i < n; b_i++) {
    i = row_ptr->data[b_i + 1] - 1;
    if (row_ptr->data[b_i] > i) {
      last_row = 0;
      i1 = 0;
    } else {
      last_row = row_ptr->data[b_i] - 1;
      i1 = i;
    }
    iroa = i1 - last_row;
    i1 = jidx->size[0];
    jidx->size[0] = iroa;
    emxEnsureCapacity_int32_T(jidx, i1);
    for (i1 = 0; i1 < iroa; i1++) {
      jidx->data[i1] = col_ind->data[last_row + i1] - 1;
    }
    if (row_ptr->data[b_i] > i) {
      last_row = 0;
      i = 0;
    } else {
      last_row = row_ptr->data[b_i] - 1;
    }
    iroa = i - last_row;
    i = rowval->size[0];
    rowval->size[0] = iroa;
    emxEnsureCapacity_real_T(rowval, i);
    for (i = 0; i < iroa; i++) {
      rowval->data[i] = val->data[last_row + i];
    }
    last_row = b_i + first_row;
    iroa = (INSERT_VALUES);
    MatSetValues(t_mat, 1, &last_row, nnz->data[b_i], &jidx->data[0],
                 &rowval->data[0], iroa);
  }
  emxFree_real_T(&rowval);
  emxFree_int32_T(&jidx);
  emxFree_int32_T(&nnz);
  last_row = (MAT_FINAL_ASSEMBLY);
  MatAssemblyBegin(t_mat, last_row);
  last_row = (MAT_FINAL_ASSEMBLY);
  MatAssemblyEnd(t_mat, last_row);
  iroa = sizeof(Mat);
  i = mat->data->size[0];
  mat->data->size[0] = iroa;
  emxEnsureCapacity_uint8_T(mat->data, i);
  mat->type.size[0] = 1;
  mat->type.size[1] = 3;
  mat->type.data[0] = 'M';
  mat->type.data[1] = 'a';
  mat->type.data[2] = 't';
  mat->nitems = 1;
  ptr = (char *)(&t_mat);
  for (b_i = 0; b_i < iroa; b_i++) {
    mat->data->data[b_i] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }
  *toplevel = true;
}

void petscMatCreateAIJFromCRS_3args(const emxArray_int32_T *row_ptr,
                                    const emxArray_int32_T *col_ind,
                                    const emxArray_real_T *val, struct0_T *mat,
                                    boolean_T *toplevel)
{
  MPI_Comm comm;
  Mat t_mat;
  char *ptr;
  emxArray_int32_T *jidx;
  emxArray_int32_T *nnz;
  emxArray_real_T *rowval;
  int b_i;
  int i;
  int i1;
  int iroa;
  int loop_ub;
  int n;
  emxInit_int32_T(&nnz, 1);
  n = row_ptr->size[0] - 1;
  i = nnz->size[0];
  nnz->size[0] = row_ptr->size[0] - 1;
  emxEnsureCapacity_int32_T(nnz, i);
  for (b_i = 0; b_i < n; b_i++) {
    nnz->data[b_i] = row_ptr->data[b_i + 1] - row_ptr->data[b_i];
  }
  iroa = (PETSC_DEFAULT);
  comm = PETSC_COMM_SELF;
  MatCreateSeqAIJ(comm, row_ptr->size[0] - 1, row_ptr->size[0] - 1, iroa,
                  &nnz->data[0], &t_mat);
  emxInit_int32_T(&jidx, 1);
  emxInit_real_T(&rowval, 1);
  for (b_i = 0; b_i < n; b_i++) {
    i = row_ptr->data[b_i + 1] - 1;
    if (row_ptr->data[b_i] > i) {
      iroa = 0;
      i1 = 0;
    } else {
      iroa = row_ptr->data[b_i] - 1;
      i1 = i;
    }
    loop_ub = i1 - iroa;
    i1 = jidx->size[0];
    jidx->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(jidx, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      jidx->data[i1] = col_ind->data[iroa + i1] - 1;
    }
    if (row_ptr->data[b_i] > i) {
      iroa = 0;
      i = 0;
    } else {
      iroa = row_ptr->data[b_i] - 1;
    }
    loop_ub = i - iroa;
    i = rowval->size[0];
    rowval->size[0] = loop_ub;
    emxEnsureCapacity_real_T(rowval, i);
    for (i = 0; i < loop_ub; i++) {
      rowval->data[i] = val->data[iroa + i];
    }
    iroa = (INSERT_VALUES);
    MatSetValues(t_mat, 1, &b_i, nnz->data[b_i], &jidx->data[0],
                 &rowval->data[0], iroa);
  }
  emxFree_real_T(&rowval);
  emxFree_int32_T(&jidx);
  emxFree_int32_T(&nnz);
  iroa = (MAT_FINAL_ASSEMBLY);
  MatAssemblyBegin(t_mat, iroa);
  iroa = (MAT_FINAL_ASSEMBLY);
  MatAssemblyEnd(t_mat, iroa);
  iroa = sizeof(Mat);
  i = mat->data->size[0];
  mat->data->size[0] = iroa;
  emxEnsureCapacity_uint8_T(mat->data, i);
  mat->type.size[0] = 1;
  mat->type.size[1] = 3;
  mat->type.data[0] = 'M';
  mat->type.data[1] = 'a';
  mat->type.data[2] = 't';
  mat->nitems = 1;
  ptr = (char *)(&t_mat);
  for (b_i = 0; b_i < iroa; b_i++) {
    mat->data->data[b_i] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }
  *toplevel = true;
}

void petscMatCreateAIJFromCRS_4args(const emxArray_int32_T *row_ptr,
                                    const emxArray_int32_T *col_ind,
                                    const emxArray_real_T *val, int ncols,
                                    struct0_T *mat, boolean_T *toplevel)
{
  MPI_Comm comm;
  Mat t_mat;
  char *ptr;
  emxArray_int32_T *jidx;
  emxArray_int32_T *nnz;
  emxArray_real_T *rowval;
  int b_i;
  int i;
  int i1;
  int iroa;
  int loop_ub;
  int n;
  emxInit_int32_T(&nnz, 1);
  n = row_ptr->size[0] - 1;
  i = nnz->size[0];
  nnz->size[0] = row_ptr->size[0] - 1;
  emxEnsureCapacity_int32_T(nnz, i);
  for (b_i = 0; b_i < n; b_i++) {
    nnz->data[b_i] = row_ptr->data[b_i + 1] - row_ptr->data[b_i];
  }
  iroa = (PETSC_DEFAULT);
  comm = PETSC_COMM_SELF;
  MatCreateSeqAIJ(comm, row_ptr->size[0] - 1, ncols, iroa, &nnz->data[0],
                  &t_mat);
  emxInit_int32_T(&jidx, 1);
  emxInit_real_T(&rowval, 1);
  for (b_i = 0; b_i < n; b_i++) {
    i = row_ptr->data[b_i + 1] - 1;
    if (row_ptr->data[b_i] > i) {
      iroa = 0;
      i1 = 0;
    } else {
      iroa = row_ptr->data[b_i] - 1;
      i1 = i;
    }
    loop_ub = i1 - iroa;
    i1 = jidx->size[0];
    jidx->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(jidx, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      jidx->data[i1] = col_ind->data[iroa + i1] - 1;
    }
    if (row_ptr->data[b_i] > i) {
      iroa = 0;
      i = 0;
    } else {
      iroa = row_ptr->data[b_i] - 1;
    }
    loop_ub = i - iroa;
    i = rowval->size[0];
    rowval->size[0] = loop_ub;
    emxEnsureCapacity_real_T(rowval, i);
    for (i = 0; i < loop_ub; i++) {
      rowval->data[i] = val->data[iroa + i];
    }
    iroa = (INSERT_VALUES);
    MatSetValues(t_mat, 1, &b_i, nnz->data[b_i], &jidx->data[0],
                 &rowval->data[0], iroa);
  }
  emxFree_real_T(&rowval);
  emxFree_int32_T(&jidx);
  emxFree_int32_T(&nnz);
  iroa = (MAT_FINAL_ASSEMBLY);
  MatAssemblyBegin(t_mat, iroa);
  iroa = (MAT_FINAL_ASSEMBLY);
  MatAssemblyEnd(t_mat, iroa);
  iroa = sizeof(Mat);
  i = mat->data->size[0];
  mat->data->size[0] = iroa;
  emxEnsureCapacity_uint8_T(mat->data, i);
  mat->type.size[0] = 1;
  mat->type.size[1] = 3;
  mat->type.data[0] = 'M';
  mat->type.data[1] = 'a';
  mat->type.data[2] = 't';
  mat->nitems = 1;
  ptr = (char *)(&t_mat);
  for (b_i = 0; b_i < iroa; b_i++) {
    mat->data->data[b_i] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }
  *toplevel = true;
}

void petscMatCreateAIJFromCRS_initialize(void)
{
}

void petscMatCreateAIJFromCRS_terminate(void)
{
}
