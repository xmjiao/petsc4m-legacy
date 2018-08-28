#include "petscGetSizeof.h"
#include "m2c.h"
#include "petsc4m.h"

static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i0);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("petscGetSizeof:UnknownType", "Unknonw data type %s.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscGetSizeof(const emxArray_char_T *name, int *sz, boolean_T *toplevel)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv0[8] = { 'P', 'e', 't', 's', 'c', 'V', 'e', 'c' };

  emxArray_char_T *b_name;
  static const char cv1[8] = { 'P', 'e', 't', 's', 'c', 'M', 'a', 't' };

  static const char cv2[11] = { 'P', 'e', 't', 's', 'c', 'O', 'b', 'j', 'e', 'c',
    't' };

  int loop_ub;
  b_bool = false;
  if (name->size[1] == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 9) {
        if (name->data[kstr] != cv0[kstr]) {
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
        if (kstr + 1 < 9) {
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
          if (kstr + 1 < 12) {
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
    kstr = b_name->size[0] * b_name->size[1];
    b_name->size[0] = 1;
    b_name->size[1] = name->size[1] + 1;
    emxEnsureCapacity_char_T(b_name, kstr);
    loop_ub = name->size[1];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      b_name->data[b_name->size[0] * kstr] = name->data[name->size[0] * kstr];
    }

    b_name->data[b_name->size[0] * name->size[1]] = '\x00';
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
