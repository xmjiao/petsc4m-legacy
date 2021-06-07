#include "petscGetSizeof.h"
#include "petscGetSizeof_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void m2c_error(const emxArray_char_T *varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error("petscGetSizeof:UnknownType", "Unknonw data type %s.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscGetSizeof(const emxArray_char_T *name, int *sz, boolean_T *toplevel)
{
  static const char cv2[11] = {'P', 'e', 't', 's', 'c', 'O',
                               'b', 'j', 'e', 'c', 't'};
  static const char cv[8] = {'P', 'e', 't', 's', 'c', 'V', 'e', 'c'};
  static const char cv1[8] = {'P', 'e', 't', 's', 'c', 'M', 'a', 't'};
  emxArray_char_T *b_name;
  int exitg1;
  int i;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (name->size[1] == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (name->data[kstr] != cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    kstr = 0;
  } else {
    b_bool = false;
    if (name->size[1] == 8) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 8) {
          if (name->data[kstr] != cv1[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      kstr = 1;
    } else {
      b_bool = false;
      if (name->size[1] == 11) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 11) {
            if (name->data[kstr] != cv2[kstr]) {
              exitg1 = 1;
            } else {
              kstr++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        kstr = 2;
      } else {
        kstr = -1;
      }
    }
  }
  switch (kstr) {
  case 0:
    *sz = sizeof(Vec);
    *toplevel = false;
    break;
  case 1:
    *sz = sizeof(Mat);
    *toplevel = false;
    break;
  case 2:
    *sz = sizeof(PetscObject);
    *toplevel = false;
    break;
  default:
    emxInit_char_T(&b_name, 2);
    *toplevel = true;
    *sz = MIN_int32_T;
    i = b_name->size[0] * b_name->size[1];
    b_name->size[0] = 1;
    b_name->size[1] = name->size[1] + 1;
    emxEnsureCapacity_char_T(b_name, i);
    kstr = name->size[1];
    for (i = 0; i < kstr; i++) {
      b_name->data[i] = name->data[i];
    }
    b_name->data[name->size[1]] = '\x00';
    m2c_error(b_name);
    emxFree_char_T(&b_name);
    break;
  }
}

void petscGetSizeof_initialize(void)
{
}

void petscGetSizeof_terminate(void)
{
}
