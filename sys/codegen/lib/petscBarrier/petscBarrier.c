#include "petscBarrier.h"
#include "petscBarrier_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static int b_petscBarrier(void *obj);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "petscBarirer returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static int b_petscBarrier(void *obj)
{
  PetscObject t_obj;
  int errCode;
  t_obj = (PetscObject)(obj);
  errCode = PetscBarrier(t_obj);
  if (errCode != 0) {
    b_m2c_error(errCode);
  }
  return errCode;
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  const char *varargin_3_data;
  char *b_varargin_3_data;
  varargin_3_data = varargin_3->data;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "PetscObject:WrongType";
  fmt = "Incorrect data type %s. Expected PetscObject.";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  b_varargin_3_data = b_varargin_3->data;
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3_data[i] = varargin_3_data[i];
  }
  M2C_error(msgid, fmt, &b_varargin_3_data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscBarrier(const M2C_OpaqueType *obj, int *errCode, boolean_T *toplevel)
{
  static const char cv[11] = {'P', 'e', 't', 's', 'c', 'O',
                              'b', 'j', 'e', 'c', 't'};
  static const char cv1[3] = {'M', 'a', 't'};
  static const char cv2[3] = {'V', 'e', 'c'};
  static const char cv3[3] = {'K', 'S', 'P'};
  static const char cv4[2] = {'P', 'C'};
  PetscObject t_obj;
  emxArray_char_T *b_obj;
  int i;
  int k;
  char *obj_data;
  boolean_T exitg1;
  boolean_T p;
  p = (obj->type->size[1] == 11);
  if (p && (obj->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (obj->type->data[k] != cv[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  emxInit_char_T(&b_obj, 2);
  if (!p) {
    p = (obj->type->size[1] == 3);
    if (p && (obj->type->size[1] != 0)) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (obj->type->data[k] != cv1[k]) {
          p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (!p) {
      p = (obj->type->size[1] == 3);
      if (p && (obj->type->size[1] != 0)) {
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 3)) {
          if (obj->type->data[k] != cv2[k]) {
            p = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (!p) {
        p = (obj->type->size[1] == 3);
        if (p && (obj->type->size[1] != 0)) {
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k < 3)) {
            if (obj->type->data[k] != cv3[k]) {
              p = false;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (!p) {
          p = (obj->type->size[1] == 2);
          if (p && (obj->type->size[1] != 0)) {
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 2)) {
              if (obj->type->data[k] != cv4[k]) {
                p = false;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }
          if (!p) {
            i = b_obj->size[0] * b_obj->size[1];
            b_obj->size[0] = 1;
            b_obj->size[1] = obj->type->size[1] + 1;
            emxEnsureCapacity_char_T(b_obj, i);
            obj_data = b_obj->data;
            k = obj->type->size[1];
            for (i = 0; i < k; i++) {
              obj_data[i] = obj->type->data[i];
            }
            obj_data[obj->type->size[1]] = '\x00';
            m2c_error(b_obj);
          }
        }
      }
    }
  }
  emxFree_char_T(&b_obj);
  t_obj = *(PetscObject *)(&obj->data->data[0]);
  *errCode = PetscBarrier(t_obj);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscBarrier0(int *errCode, boolean_T *topLevel)
{
  *errCode = b_petscBarrier(NULL);
  *topLevel = true;
}

void petscBarrier_initialize(void)
{
}

void petscBarrier_terminate(void)
{
}
