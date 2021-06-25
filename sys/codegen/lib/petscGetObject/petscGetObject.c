#include "petscGetObject.h"
#include "petscGetObject_types.h"
#include "m2c.h"
#include "petsc4m.h"

static boolean_T b_strcmp(const emxArray_char_T *a);

static boolean_T c_strcmp(const emxArray_char_T *a);

static boolean_T d_strcmp(const emxArray_char_T *a);

static boolean_T e_strcmp(const emxArray_char_T *a);

static void m2c_error(const emxArray_char_T *varargin_3);

static boolean_T b_strcmp(const emxArray_char_T *a)
{
  static const char cv[14] = {'P', 'E', 'T', 'S', 'C', '_', 'N',
                              'U', 'L', 'L', '_', 'M', 'A', 'T'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 14) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 14) {
        if (a->data[kstr] != cv[kstr]) {
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
  return b_bool;
}

static boolean_T c_strcmp(const emxArray_char_T *a)
{
  static const char cv[14] = {'P', 'E', 'T', 'S', 'C', '_', 'N',
                              'U', 'L', 'L', '_', 'V', 'E', 'C'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 14) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 14) {
        if (a->data[kstr] != cv[kstr]) {
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
  return b_bool;
}

static boolean_T d_strcmp(const emxArray_char_T *a)
{
  static const char cv[14] = {'P', 'E', 'T', 'S', 'C', '_', 'N',
                              'U', 'L', 'L', '_', 'I', 'N', 'T'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 14) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 14) {
        if (a->data[kstr] != cv[kstr]) {
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
  return b_bool;
}

static boolean_T e_strcmp(const emxArray_char_T *a)
{
  static const char cv[15] = {'P', 'E', 'T', 'S', 'C', '_', 'N', 'U',
                              'L', 'L', '_', 'R', 'E', 'A', 'L'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 15) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 15) {
        if (a->data[kstr] != cv[kstr]) {
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
  return b_bool;
}

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
  M2C_error("petscGetNum:UnknownConstant", "Unknonw constant %s.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscGetObject(const emxArray_char_T *name, struct0_T *obj,
                    boolean_T *toplevel)
{
  static const char cv10[18] = {'P', 'E', 'T', 'S', 'C', '_', 'N', 'U', 'L',
                                'L', '_', 'O', 'P', 'T', 'I', 'O', 'N', 'S'};
  static const char cv3[16] = {'P', 'E', 'T', 'S', 'C', '_', 'C', 'O',
                               'M', 'M', '_', 'W', 'O', 'R', 'L', 'D'};
  static const char cv2[15] = {'P', 'E', 'T', 'S', 'C', '_', 'C', 'O',
                               'M', 'M', '_', 'S', 'E', 'L', 'F'};
  static const char cv1[14] = {'M', 'P', 'I', '_', 'C', 'O', 'M',
                               'M', '_', 'W', 'O', 'R', 'L', 'D'};
  static const char cv[13] = {'M', 'P', 'I', '_', 'C', 'O', 'M',
                              'M', '_', 'S', 'E', 'L', 'F'};
  static const char cv6[12] = {'P', 'e', 't', 's', 'c', 'O',
                               'p', 't', 'i', 'o', 'n', 's'};
  static const char cv9[12] = {'P', 'E', 'T', 'S', 'C', '_',
                               'I', 'G', 'N', 'O', 'R', 'E'};
  static const char cv8[11] = {'P', 'e', 't', 's', 'c', 'R',
                               'e', 'a', 'l', ' ', '*'};
  static const char cv4[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  static const char cv5[6] = {'v', 'o', 'i', 'd', ' ', '*'};
  static const char cv7[5] = {'i', 'n', 't', ' ', '*'};
  MPI_Comm arg;
  Mat d_arg;
  PetscOptions c_arg;
  PetscReal *g_arg;
  Vec e_arg;
  char *ptr;
  int *f_arg;
  void *b_arg;
  emxArray_char_T *b_name;
  int exitg1;
  int i;
  int sizepe;
  boolean_T b_bool;
  b_bool = false;
  if (name->size[1] == 13) {
    sizepe = 0;
    do {
      exitg1 = 0;
      if (sizepe < 13) {
        if (name->data[sizepe] != cv[sizepe]) {
          exitg1 = 1;
        } else {
          sizepe++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    sizepe = 0;
  } else {
    b_bool = false;
    if (name->size[1] == 14) {
      sizepe = 0;
      do {
        exitg1 = 0;
        if (sizepe < 14) {
          if (name->data[sizepe] != cv1[sizepe]) {
            exitg1 = 1;
          } else {
            sizepe++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      sizepe = 1;
    } else {
      b_bool = false;
      if (name->size[1] == 15) {
        sizepe = 0;
        do {
          exitg1 = 0;
          if (sizepe < 15) {
            if (name->data[sizepe] != cv2[sizepe]) {
              exitg1 = 1;
            } else {
              sizepe++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        sizepe = 2;
      } else {
        b_bool = false;
        if (name->size[1] == 16) {
          sizepe = 0;
          do {
            exitg1 = 0;
            if (sizepe < 16) {
              if (name->data[sizepe] != cv3[sizepe]) {
                exitg1 = 1;
              } else {
                sizepe++;
              }
            } else {
              b_bool = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }
        if (b_bool) {
          sizepe = 3;
        } else {
          b_bool = false;
          if (name->size[1] == 12) {
            sizepe = 0;
            do {
              exitg1 = 0;
              if (sizepe < 12) {
                if (name->data[sizepe] != cv9[sizepe]) {
                  exitg1 = 1;
                } else {
                  sizepe++;
                }
              } else {
                b_bool = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }
          if (b_bool) {
            sizepe = 4;
          } else {
            b_bool = false;
            if (name->size[1] == 18) {
              sizepe = 0;
              do {
                exitg1 = 0;
                if (sizepe < 18) {
                  if (name->data[sizepe] != cv10[sizepe]) {
                    exitg1 = 1;
                  } else {
                    sizepe++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }
            if (b_bool) {
              sizepe = 5;
            } else if (b_strcmp(name)) {
              sizepe = 6;
            } else if (c_strcmp(name)) {
              sizepe = 7;
            } else if (d_strcmp(name)) {
              sizepe = 8;
            } else if (e_strcmp(name)) {
              sizepe = 9;
            } else {
              sizepe = -1;
            }
          }
        }
      }
    }
  }
  switch (sizepe) {
  case 0:
    arg = MPI_COMM_SELF;
    sizepe = sizeof(MPI_Comm);
    i = obj->data->size[0];
    obj->data->size[0] = sizepe;
    emxEnsureCapacity_uint8_T(obj->data, i);
    i = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 8;
    emxEnsureCapacity_char_T(obj->type, i);
    for (i = 0; i < 8; i++) {
      obj->type->data[i] = cv4[i];
    }
    obj->nitems = 1;
    ptr = (char *)(&arg);
    for (i = 0; i < sizepe; i++) {
      obj->data->data[i] = *(ptr);
      ptr = ptr + 1;
    }
    break;
  case 1:
    arg = MPI_COMM_WORLD;
    sizepe = sizeof(MPI_Comm);
    i = obj->data->size[0];
    obj->data->size[0] = sizepe;
    emxEnsureCapacity_uint8_T(obj->data, i);
    i = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 8;
    emxEnsureCapacity_char_T(obj->type, i);
    for (i = 0; i < 8; i++) {
      obj->type->data[i] = cv4[i];
    }
    obj->nitems = 1;
    ptr = (char *)(&arg);
    for (i = 0; i < sizepe; i++) {
      obj->data->data[i] = *(ptr);
      ptr = ptr + 1;
    }
    break;
  case 2:
    arg = PETSC_COMM_SELF;
    sizepe = sizeof(MPI_Comm);
    i = obj->data->size[0];
    obj->data->size[0] = sizepe;
    emxEnsureCapacity_uint8_T(obj->data, i);
    i = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 8;
    emxEnsureCapacity_char_T(obj->type, i);
    for (i = 0; i < 8; i++) {
      obj->type->data[i] = cv4[i];
    }
    obj->nitems = 1;
    ptr = (char *)(&arg);
    for (i = 0; i < sizepe; i++) {
      obj->data->data[i] = *(ptr);
      ptr = ptr + 1;
    }
    break;
  case 3:
    arg = PETSC_COMM_WORLD;
    sizepe = sizeof(MPI_Comm);
    i = obj->data->size[0];
    obj->data->size[0] = sizepe;
    emxEnsureCapacity_uint8_T(obj->data, i);
    i = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 8;
    emxEnsureCapacity_char_T(obj->type, i);
    for (i = 0; i < 8; i++) {
      obj->type->data[i] = cv4[i];
    }
    obj->nitems = 1;
    ptr = (char *)(&arg);
    for (i = 0; i < sizepe; i++) {
      obj->data->data[i] = *(ptr);
      ptr = ptr + 1;
    }
    break;
  case 4:
    b_arg = PETSC_IGNORE;
    sizepe = sizeof(void *);
    i = obj->data->size[0];
    obj->data->size[0] = sizepe;
    emxEnsureCapacity_uint8_T(obj->data, i);
    i = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 6;
    emxEnsureCapacity_char_T(obj->type, i);
    for (i = 0; i < 6; i++) {
      obj->type->data[i] = cv5[i];
    }
    obj->nitems = 1;
    ptr = (char *)(&b_arg);
    for (i = 0; i < sizepe; i++) {
      obj->data->data[i] = *(ptr);
      ptr = ptr + 1;
    }
    break;
  case 5:
    c_arg = NULL;
    sizepe = sizeof(PetscOptions);
    i = obj->data->size[0];
    obj->data->size[0] = sizepe;
    emxEnsureCapacity_uint8_T(obj->data, i);
    i = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 12;
    emxEnsureCapacity_char_T(obj->type, i);
    for (i = 0; i < 12; i++) {
      obj->type->data[i] = cv6[i];
    }
    obj->nitems = 1;
    ptr = (char *)(&c_arg);
    for (i = 0; i < sizepe; i++) {
      obj->data->data[i] = *(ptr);
      ptr = ptr + 1;
    }
    break;
  case 6:
    d_arg = NULL;
    sizepe = sizeof(Mat);
    i = obj->data->size[0];
    obj->data->size[0] = sizepe;
    emxEnsureCapacity_uint8_T(obj->data, i);
    i = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 3;
    emxEnsureCapacity_char_T(obj->type, i);
    obj->type->data[0] = 'M';
    obj->type->data[1] = 'a';
    obj->type->data[2] = 't';
    obj->nitems = 1;
    ptr = (char *)(&d_arg);
    for (i = 0; i < sizepe; i++) {
      obj->data->data[i] = *(ptr);
      ptr = ptr + 1;
    }
    break;
  case 7:
    e_arg = NULL;
    sizepe = sizeof(Vec);
    i = obj->data->size[0];
    obj->data->size[0] = sizepe;
    emxEnsureCapacity_uint8_T(obj->data, i);
    i = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 3;
    emxEnsureCapacity_char_T(obj->type, i);
    obj->type->data[0] = 'V';
    obj->type->data[1] = 'e';
    obj->type->data[2] = 'c';
    obj->nitems = 1;
    ptr = (char *)(&e_arg);
    for (i = 0; i < sizepe; i++) {
      obj->data->data[i] = *(ptr);
      ptr = ptr + 1;
    }
    break;
  case 8:
    f_arg = NULL;
    sizepe = sizeof(int *);
    i = obj->data->size[0];
    obj->data->size[0] = sizepe;
    emxEnsureCapacity_uint8_T(obj->data, i);
    i = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 5;
    emxEnsureCapacity_char_T(obj->type, i);
    for (i = 0; i < 5; i++) {
      obj->type->data[i] = cv7[i];
    }
    obj->nitems = 1;
    ptr = (char *)(&f_arg);
    for (i = 0; i < sizepe; i++) {
      obj->data->data[i] = *(ptr);
      ptr = ptr + 1;
    }
    break;
  case 9:
    g_arg = NULL;
    sizepe = sizeof(PetscReal *);
    i = obj->data->size[0];
    obj->data->size[0] = sizepe;
    emxEnsureCapacity_uint8_T(obj->data, i);
    i = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 11;
    emxEnsureCapacity_char_T(obj->type, i);
    for (i = 0; i < 11; i++) {
      obj->type->data[i] = cv8[i];
    }
    obj->nitems = 1;
    ptr = (char *)(&g_arg);
    for (i = 0; i < sizepe; i++) {
      obj->data->data[i] = *(ptr);
      ptr = ptr + 1;
    }
    break;
  default:
    emxInit_char_T(&b_name, 2);
    i = b_name->size[0] * b_name->size[1];
    b_name->size[0] = 1;
    b_name->size[1] = name->size[1] + 1;
    emxEnsureCapacity_char_T(b_name, i);
    sizepe = name->size[1];
    for (i = 0; i < sizepe; i++) {
      b_name->data[i] = name->data[i];
    }
    b_name->data[name->size[1]] = '\x00';
    m2c_error(b_name);
    b_arg = NULL;
    sizepe = sizeof(void *);
    i = obj->data->size[0];
    obj->data->size[0] = sizepe;
    emxEnsureCapacity_uint8_T(obj->data, i);
    i = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 6;
    emxEnsureCapacity_char_T(obj->type, i);
    emxFree_char_T(&b_name);
    for (i = 0; i < 6; i++) {
      obj->type->data[i] = cv5[i];
    }
    obj->nitems = 1;
    ptr = (char *)(&b_arg);
    for (i = 0; i < sizepe; i++) {
      obj->data->data[i] = *(ptr);
      ptr = ptr + 1;
    }
    break;
  }
  *toplevel = true;
}

void petscGetObject_initialize(void)
{
}

void petscGetObject_terminate(void)
{
}
