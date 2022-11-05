#include "petscGetObject.h"
#include "petscGetObject_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_opaque_obj(void *arg, emxArray_uint8_T *obj_data,
                             char obj_type_data[], int obj_type_size[2],
                             int *obj_nitems);

static void c_m2c_opaque_obj(PetscOptions arg, emxArray_uint8_T *obj_data,
                             char obj_type_data[], int obj_type_size[2],
                             int *obj_nitems);

static void d_m2c_opaque_obj(Mat arg, emxArray_uint8_T *obj_data,
                             char obj_type_data[], int obj_type_size[2],
                             int *obj_nitems);

static void e_m2c_opaque_obj(Vec arg, emxArray_uint8_T *obj_data,
                             char obj_type_data[], int obj_type_size[2],
                             int *obj_nitems);

static void f_m2c_opaque_obj(int *arg, emxArray_uint8_T *obj_data,
                             char obj_type_data[], int obj_type_size[2],
                             int *obj_nitems);

static void g_m2c_opaque_obj(PetscReal *arg, emxArray_uint8_T *obj_data,
                             char obj_type_data[], int obj_type_size[2],
                             int *obj_nitems);

static void m2c_error(const emxArray_char_T *varargin_3);

static void m2c_opaque_obj(MPI_Comm arg, emxArray_uint8_T *obj_data,
                           char obj_type_data[], int obj_type_size[2],
                           int *obj_nitems);

static void b_m2c_opaque_obj(void *arg, emxArray_uint8_T *obj_data,
                             char obj_type_data[], int obj_type_size[2],
                             int *obj_nitems)
{
  static const char cv[6] = {'v', 'o', 'i', 'd', ' ', '*'};
  char *ptr;
  int i;
  int sizepe;
  unsigned char *obj_data_data;
  sizepe = sizeof(void *);
  i = obj_data->size[0];
  obj_data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(obj_data, i);
  obj_data_data = obj_data->data;
  obj_type_size[0] = 1;
  obj_type_size[1] = 6;
  for (i = 0; i < 6; i++) {
    obj_type_data[i] = cv[i];
  }
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    obj_data_data[i] = *(ptr);
    ptr = ptr + 1;
  }
  *obj_nitems = 1;
}

static void c_m2c_opaque_obj(PetscOptions arg, emxArray_uint8_T *obj_data,
                             char obj_type_data[], int obj_type_size[2],
                             int *obj_nitems)
{
  static const char cv[12] = {'P', 'e', 't', 's', 'c', 'O',
                              'p', 't', 'i', 'o', 'n', 's'};
  char *ptr;
  int i;
  int sizepe;
  unsigned char *obj_data_data;
  sizepe = sizeof(PetscOptions);
  i = obj_data->size[0];
  obj_data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(obj_data, i);
  obj_data_data = obj_data->data;
  obj_type_size[0] = 1;
  obj_type_size[1] = 12;
  for (i = 0; i < 12; i++) {
    obj_type_data[i] = cv[i];
  }
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    obj_data_data[i] = *(ptr);
    ptr = ptr + 1;
  }
  *obj_nitems = 1;
}

static void d_m2c_opaque_obj(Mat arg, emxArray_uint8_T *obj_data,
                             char obj_type_data[], int obj_type_size[2],
                             int *obj_nitems)
{
  char *ptr;
  int i;
  int sizepe;
  unsigned char *obj_data_data;
  sizepe = sizeof(Mat);
  i = obj_data->size[0];
  obj_data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(obj_data, i);
  obj_data_data = obj_data->data;
  obj_type_size[0] = 1;
  obj_type_size[1] = 3;
  obj_type_data[0] = 'M';
  obj_type_data[1] = 'a';
  obj_type_data[2] = 't';
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    obj_data_data[i] = *(ptr);
    ptr = ptr + 1;
  }
  *obj_nitems = 1;
}

static void e_m2c_opaque_obj(Vec arg, emxArray_uint8_T *obj_data,
                             char obj_type_data[], int obj_type_size[2],
                             int *obj_nitems)
{
  char *ptr;
  int i;
  int sizepe;
  unsigned char *obj_data_data;
  sizepe = sizeof(Vec);
  i = obj_data->size[0];
  obj_data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(obj_data, i);
  obj_data_data = obj_data->data;
  obj_type_size[0] = 1;
  obj_type_size[1] = 3;
  obj_type_data[0] = 'V';
  obj_type_data[1] = 'e';
  obj_type_data[2] = 'c';
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    obj_data_data[i] = *(ptr);
    ptr = ptr + 1;
  }
  *obj_nitems = 1;
}

static void f_m2c_opaque_obj(int *arg, emxArray_uint8_T *obj_data,
                             char obj_type_data[], int obj_type_size[2],
                             int *obj_nitems)
{
  static const char cv[5] = {'i', 'n', 't', ' ', '*'};
  char *ptr;
  int i;
  int sizepe;
  unsigned char *obj_data_data;
  sizepe = sizeof(int *);
  i = obj_data->size[0];
  obj_data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(obj_data, i);
  obj_data_data = obj_data->data;
  obj_type_size[0] = 1;
  obj_type_size[1] = 5;
  for (i = 0; i < 5; i++) {
    obj_type_data[i] = cv[i];
  }
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    obj_data_data[i] = *(ptr);
    ptr = ptr + 1;
  }
  *obj_nitems = 1;
}

static void g_m2c_opaque_obj(PetscReal *arg, emxArray_uint8_T *obj_data,
                             char obj_type_data[], int obj_type_size[2],
                             int *obj_nitems)
{
  static const char cv[11] = {'P', 'e', 't', 's', 'c', 'R',
                              'e', 'a', 'l', ' ', '*'};
  char *ptr;
  int i;
  int sizepe;
  unsigned char *obj_data_data;
  sizepe = sizeof(PetscReal *);
  i = obj_data->size[0];
  obj_data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(obj_data, i);
  obj_data_data = obj_data->data;
  obj_type_size[0] = 1;
  obj_type_size[1] = 11;
  for (i = 0; i < 11; i++) {
    obj_type_data[i] = cv[i];
  }
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    obj_data_data[i] = *(ptr);
    ptr = ptr + 1;
  }
  *obj_nitems = 1;
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
  msgid = "petscGetNum:UnknownConstant";
  fmt = "Unknonw constant %s.";
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

static void m2c_opaque_obj(MPI_Comm arg, emxArray_uint8_T *obj_data,
                           char obj_type_data[], int obj_type_size[2],
                           int *obj_nitems)
{
  static const char cv[8] = {'M', 'P', 'I', '_', 'C', 'o', 'm', 'm'};
  char *ptr;
  int i;
  int sizepe;
  unsigned char *obj_data_data;
  sizepe = sizeof(MPI_Comm);
  i = obj_data->size[0];
  obj_data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(obj_data, i);
  obj_data_data = obj_data->data;
  obj_type_size[0] = 1;
  obj_type_size[1] = 8;
  for (i = 0; i < 8; i++) {
    obj_type_data[i] = cv[i];
  }
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    obj_data_data[i] = *(ptr);
    ptr = ptr + 1;
  }
  *obj_nitems = 1;
}

void petscGetObject(const emxArray_char_T *name, struct0_T *obj,
                    boolean_T *toplevel)
{
  static const char cv5[18] = {'P', 'E', 'T', 'S', 'C', '_', 'N', 'U', 'L',
                               'L', '_', 'O', 'P', 'T', 'I', 'O', 'N', 'S'};
  static const char cv3[16] = {'P', 'E', 'T', 'S', 'C', '_', 'C', 'O',
                               'M', 'M', '_', 'W', 'O', 'R', 'L', 'D'};
  static const char cv2[15] = {'P', 'E', 'T', 'S', 'C', '_', 'C', 'O',
                               'M', 'M', '_', 'S', 'E', 'L', 'F'};
  static const char cv9[15] = {'P', 'E', 'T', 'S', 'C', '_', 'N', 'U',
                               'L', 'L', '_', 'R', 'E', 'A', 'L'};
  static const char cv1[14] = {'M', 'P', 'I', '_', 'C', 'O', 'M',
                               'M', '_', 'W', 'O', 'R', 'L', 'D'};
  static const char cv6[14] = {'P', 'E', 'T', 'S', 'C', '_', 'N',
                               'U', 'L', 'L', '_', 'M', 'A', 'T'};
  static const char cv7[14] = {'P', 'E', 'T', 'S', 'C', '_', 'N',
                               'U', 'L', 'L', '_', 'V', 'E', 'C'};
  static const char cv8[14] = {'P', 'E', 'T', 'S', 'C', '_', 'N',
                               'U', 'L', 'L', '_', 'I', 'N', 'T'};
  static const char cv[13] = {'M', 'P', 'I', '_', 'C', 'O', 'M',
                              'M', '_', 'S', 'E', 'L', 'F'};
  static const char cv4[12] = {'P', 'E', 'T', 'S', 'C', '_',
                               'I', 'G', 'N', 'O', 'R', 'E'};
  emxArray_char_T *b_name;
  int exitg1;
  int i;
  int kstr;
  const char *name_data;
  char *b_name_data;
  boolean_T b_bool;
  name_data = name->data;
  b_bool = false;
  if (name->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 13) {
        if (name_data[kstr] != cv[kstr]) {
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
    if (name->size[1] == 14) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 14) {
          if (name_data[kstr] != cv1[kstr]) {
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
      if (name->size[1] == 15) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 15) {
            if (name_data[kstr] != cv2[kstr]) {
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
        b_bool = false;
        if (name->size[1] == 16) {
          kstr = 0;
          do {
            exitg1 = 0;
            if (kstr < 16) {
              if (name_data[kstr] != cv3[kstr]) {
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
          kstr = 3;
        } else {
          b_bool = false;
          if (name->size[1] == 12) {
            kstr = 0;
            do {
              exitg1 = 0;
              if (kstr < 12) {
                if (name_data[kstr] != cv4[kstr]) {
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
            kstr = 4;
          } else {
            b_bool = false;
            if (name->size[1] == 18) {
              kstr = 0;
              do {
                exitg1 = 0;
                if (kstr < 18) {
                  if (name_data[kstr] != cv5[kstr]) {
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
              kstr = 5;
            } else {
              b_bool = false;
              if (name->size[1] == 14) {
                kstr = 0;
                do {
                  exitg1 = 0;
                  if (kstr < 14) {
                    if (name_data[kstr] != cv6[kstr]) {
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
                kstr = 6;
              } else {
                b_bool = false;
                if (name->size[1] == 14) {
                  kstr = 0;
                  do {
                    exitg1 = 0;
                    if (kstr < 14) {
                      if (name_data[kstr] != cv7[kstr]) {
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
                  kstr = 7;
                } else {
                  b_bool = false;
                  if (name->size[1] == 14) {
                    kstr = 0;
                    do {
                      exitg1 = 0;
                      if (kstr < 14) {
                        if (name_data[kstr] != cv8[kstr]) {
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
                    kstr = 8;
                  } else {
                    b_bool = false;
                    if (name->size[1] == 15) {
                      kstr = 0;
                      do {
                        exitg1 = 0;
                        if (kstr < 15) {
                          if (name_data[kstr] != cv9[kstr]) {
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
                      kstr = 9;
                    } else {
                      kstr = -1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  switch (kstr) {
  case 0:
    m2c_opaque_obj(MPI_COMM_SELF, obj->data, obj->type.data, obj->type.size,
                   &obj->nitems);
    break;
  case 1:
    m2c_opaque_obj(MPI_COMM_WORLD, obj->data, obj->type.data, obj->type.size,
                   &obj->nitems);
    break;
  case 2:
    m2c_opaque_obj(PETSC_COMM_SELF, obj->data, obj->type.data, obj->type.size,
                   &obj->nitems);
    break;
  case 3:
    m2c_opaque_obj(PETSC_COMM_WORLD, obj->data, obj->type.data, obj->type.size,
                   &obj->nitems);
    break;
  case 4:
    b_m2c_opaque_obj(PETSC_IGNORE, obj->data, obj->type.data, obj->type.size,
                     &obj->nitems);
    break;
  case 5:
    c_m2c_opaque_obj(NULL, obj->data, obj->type.data, obj->type.size,
                     &obj->nitems);
    break;
  case 6:
    d_m2c_opaque_obj(NULL, obj->data, obj->type.data, obj->type.size,
                     &obj->nitems);
    break;
  case 7:
    e_m2c_opaque_obj(NULL, obj->data, obj->type.data, obj->type.size,
                     &obj->nitems);
    break;
  case 8:
    f_m2c_opaque_obj(NULL, obj->data, obj->type.data, obj->type.size,
                     &obj->nitems);
    break;
  case 9:
    g_m2c_opaque_obj(NULL, obj->data, obj->type.data, obj->type.size,
                     &obj->nitems);
    break;
  default:
    emxInit_char_T(&b_name, 2);
    i = b_name->size[0] * b_name->size[1];
    b_name->size[0] = 1;
    b_name->size[1] = name->size[1] + 1;
    emxEnsureCapacity_char_T(b_name, i);
    b_name_data = b_name->data;
    kstr = name->size[1];
    for (i = 0; i < kstr; i++) {
      b_name_data[i] = name_data[i];
    }
    b_name_data[name->size[1]] = '\x00';
    m2c_error(b_name);
    b_m2c_opaque_obj(NULL, obj->data, obj->type.data, obj->type.size,
                     &obj->nitems);
    emxFree_char_T(&b_name);
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
