#include "petscGetObject.h"
#include "m2c.h"
#include "mpetsc.h"

static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);

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

  M2C_error("petscGetNum:UnknownConstant", "Unknonw constant %s.",
            &b_varargin_3->data[0]);
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

void petscGetObject(const emxArray_char_T *name, struct0_T *obj, boolean_T
                    *toplevel)
{
  boolean_T b_bool;
  int kstr;
  int exitg10;
  static const char cv0[13] = { 'M', 'P', 'I', '_', 'C', 'O', 'M', 'M', '_', 'S',
    'E', 'L', 'F' };

  emxArray_uint8_T *data0;
  int exitg9;
  emxArray_char_T *b_name;
  MPI_Comm arg;
  void * b_arg;
  PetscOptions c_arg;
  Mat d_arg;
  Vec e_arg;
  int * f_arg;
  double * g_arg;
  int sizepe;
  static const char cv1[14] = { 'M', 'P', 'I', '_', 'C', 'O', 'M', 'M', '_', 'W',
    'O', 'R', 'L', 'D' };

  int exitg8;
  static const char cv2[15] = { 'P', 'E', 'T', 'S', 'C', '_', 'C', 'O', 'M', 'M',
    '_', 'S', 'E', 'L', 'F' };

  int loop_ub;
  char t1_type[8];
  char t0_type[6];
  char t2_type[12];
  char t3_type[3];
  char t4_type[5];
  int exitg7;
  static const char cv3[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  static const char cv4[6] = { 'v', 'o', 'i', 'd', ' ', '*' };

  static const char cv5[12] = { 'P', 'e', 't', 's', 'c', 'O', 'p', 't', 'i', 'o',
    'n', 's' };

  static const char cv6[3] = { 'M', 'a', 't' };

  static const char cv7[3] = { 'V', 'e', 'c' };

  static const char cv8[5] = { 'i', 'n', 't', ' ', '*' };

  static const char cv9[8] = { 'd', 'o', 'u', 'b', 'l', 'e', ' ', '*' };

  static const char cv10[16] = { 'P', 'E', 'T', 'S', 'C', '_', 'C', 'O', 'M',
    'M', '_', 'W', 'O', 'R', 'L', 'D' };

  int exitg6;
  static const char cv11[12] = { 'P', 'E', 'T', 'S', 'C', '_', 'I', 'G', 'N',
    'O', 'R', 'E' };

  int exitg5;
  static const char cv12[18] = { 'P', 'E', 'T', 'S', 'C', '_', 'N', 'U', 'L',
    'L', '_', 'O', 'P', 'T', 'I', 'O', 'N', 'S' };

  int exitg4;
  static const char cv13[14] = { 'P', 'E', 'T', 'S', 'C', '_', 'N', 'U', 'L',
    'L', '_', 'M', 'A', 'T' };

  char * ptr;
  int exitg3;
  static const char cv14[14] = { 'P', 'E', 'T', 'S', 'C', '_', 'N', 'U', 'L',
    'L', '_', 'V', 'E', 'C' };

  int exitg2;
  static const char cv15[14] = { 'P', 'E', 'T', 'S', 'C', '_', 'N', 'U', 'L',
    'L', '_', 'I', 'N', 'T' };

  int exitg1;
  static const char cv16[15] = { 'P', 'E', 'T', 'S', 'C', '_', 'N', 'U', 'L',
    'L', '_', 'R', 'E', 'A', 'L' };

  b_bool = false;
  if (name->size[1] != 13) {
  } else {
    kstr = 0;
    do {
      exitg10 = 0;
      if (kstr + 1 < 14) {
        if (name->data[kstr] != cv0[kstr]) {
          exitg10 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg10 = 1;
      }
    } while (exitg10 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    b_bool = false;
    if (name->size[1] != 14) {
    } else {
      kstr = 0;
      do {
        exitg9 = 0;
        if (kstr + 1 < 15) {
          if (name->data[kstr] != cv1[kstr]) {
            exitg9 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg9 = 1;
        }
      } while (exitg9 == 0);
    }

    if (b_bool) {
      kstr = 1;
    } else {
      b_bool = false;
      if (name->size[1] != 15) {
      } else {
        kstr = 0;
        do {
          exitg8 = 0;
          if (kstr + 1 < 16) {
            if (name->data[kstr] != cv2[kstr]) {
              exitg8 = 1;
            } else {
              kstr++;
            }
          } else {
            b_bool = true;
            exitg8 = 1;
          }
        } while (exitg8 == 0);
      }

      if (b_bool) {
        kstr = 2;
      } else {
        b_bool = false;
        if (name->size[1] != 16) {
        } else {
          kstr = 0;
          do {
            exitg7 = 0;
            if (kstr + 1 < 17) {
              if (name->data[kstr] != cv10[kstr]) {
                exitg7 = 1;
              } else {
                kstr++;
              }
            } else {
              b_bool = true;
              exitg7 = 1;
            }
          } while (exitg7 == 0);
        }

        if (b_bool) {
          kstr = 3;
        } else {
          b_bool = false;
          if (name->size[1] != 12) {
          } else {
            kstr = 0;
            do {
              exitg6 = 0;
              if (kstr + 1 < 13) {
                if (name->data[kstr] != cv11[kstr]) {
                  exitg6 = 1;
                } else {
                  kstr++;
                }
              } else {
                b_bool = true;
                exitg6 = 1;
              }
            } while (exitg6 == 0);
          }

          if (b_bool) {
            kstr = 4;
          } else {
            b_bool = false;
            if (name->size[1] != 18) {
            } else {
              kstr = 0;
              do {
                exitg5 = 0;
                if (kstr + 1 < 19) {
                  if (name->data[kstr] != cv12[kstr]) {
                    exitg5 = 1;
                  } else {
                    kstr++;
                  }
                } else {
                  b_bool = true;
                  exitg5 = 1;
                }
              } while (exitg5 == 0);
            }

            if (b_bool) {
              kstr = 5;
            } else {
              b_bool = false;
              if (name->size[1] != 14) {
              } else {
                kstr = 0;
                do {
                  exitg4 = 0;
                  if (kstr + 1 < 15) {
                    if (name->data[kstr] != cv13[kstr]) {
                      exitg4 = 1;
                    } else {
                      kstr++;
                    }
                  } else {
                    b_bool = true;
                    exitg4 = 1;
                  }
                } while (exitg4 == 0);
              }

              if (b_bool) {
                kstr = 6;
              } else {
                b_bool = false;
                if (name->size[1] != 14) {
                } else {
                  kstr = 0;
                  do {
                    exitg3 = 0;
                    if (kstr + 1 < 15) {
                      if (name->data[kstr] != cv14[kstr]) {
                        exitg3 = 1;
                      } else {
                        kstr++;
                      }
                    } else {
                      b_bool = true;
                      exitg3 = 1;
                    }
                  } while (exitg3 == 0);
                }

                if (b_bool) {
                  kstr = 7;
                } else {
                  b_bool = false;
                  if (name->size[1] != 14) {
                  } else {
                    kstr = 0;
                    do {
                      exitg2 = 0;
                      if (kstr + 1 < 15) {
                        if (name->data[kstr] != cv15[kstr]) {
                          exitg2 = 1;
                        } else {
                          kstr++;
                        }
                      } else {
                        b_bool = true;
                        exitg2 = 1;
                      }
                    } while (exitg2 == 0);
                  }

                  if (b_bool) {
                    kstr = 8;
                  } else {
                    b_bool = false;
                    if (name->size[1] != 15) {
                    } else {
                      kstr = 0;
                      do {
                        exitg1 = 0;
                        if (kstr + 1 < 16) {
                          if (name->data[kstr] != cv16[kstr]) {
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

  emxInit_uint8_T(&data0, 1);
  switch (kstr) {
   case 0:
    arg = MPI_COMM_SELF;
    sizepe = sizeof(MPI_Comm);
    kstr = data0->size[0];
    data0->size[0] = sizepe;
    emxEnsureCapacity((emxArray__common *)data0, kstr, (int)sizeof(unsigned char));
    for (kstr = 0; kstr < 8; kstr++) {
      t1_type[kstr] = cv3[kstr];
    }

    kstr = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity((emxArray__common *)obj->data, kstr, (int)sizeof(unsigned
      char));
    loop_ub = data0->size[0];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      obj->data->data[kstr] = data0->data[kstr];
    }

    kstr = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 8;
    emxEnsureCapacity((emxArray__common *)obj->type, kstr, (int)sizeof(char));
    for (kstr = 0; kstr < 8; kstr++) {
      obj->type->data[kstr] = t1_type[kstr];
    }

    obj->nitems = 1;
    ptr = (char *)(&arg);
    for (kstr = 1; kstr <= sizepe; kstr++) {
      obj->data->data[kstr - 1] = *(ptr);
      ptr = ptr + 1;
    }

    *toplevel = true;
    break;

   case 1:
    arg = MPI_COMM_WORLD;
    sizepe = sizeof(MPI_Comm);
    kstr = data0->size[0];
    data0->size[0] = sizepe;
    emxEnsureCapacity((emxArray__common *)data0, kstr, (int)sizeof(unsigned char));
    for (kstr = 0; kstr < 8; kstr++) {
      t1_type[kstr] = cv3[kstr];
    }

    kstr = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity((emxArray__common *)obj->data, kstr, (int)sizeof(unsigned
      char));
    loop_ub = data0->size[0];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      obj->data->data[kstr] = data0->data[kstr];
    }

    kstr = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 8;
    emxEnsureCapacity((emxArray__common *)obj->type, kstr, (int)sizeof(char));
    for (kstr = 0; kstr < 8; kstr++) {
      obj->type->data[kstr] = t1_type[kstr];
    }

    obj->nitems = 1;
    ptr = (char *)(&arg);
    for (kstr = 1; kstr <= sizepe; kstr++) {
      obj->data->data[kstr - 1] = *(ptr);
      ptr = ptr + 1;
    }

    *toplevel = true;
    break;

   case 2:
    arg = PETSC_COMM_SELF;
    sizepe = sizeof(MPI_Comm);
    kstr = data0->size[0];
    data0->size[0] = sizepe;
    emxEnsureCapacity((emxArray__common *)data0, kstr, (int)sizeof(unsigned char));
    for (kstr = 0; kstr < 8; kstr++) {
      t1_type[kstr] = cv3[kstr];
    }

    kstr = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity((emxArray__common *)obj->data, kstr, (int)sizeof(unsigned
      char));
    loop_ub = data0->size[0];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      obj->data->data[kstr] = data0->data[kstr];
    }

    kstr = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 8;
    emxEnsureCapacity((emxArray__common *)obj->type, kstr, (int)sizeof(char));
    for (kstr = 0; kstr < 8; kstr++) {
      obj->type->data[kstr] = t1_type[kstr];
    }

    obj->nitems = 1;
    ptr = (char *)(&arg);
    for (kstr = 1; kstr <= sizepe; kstr++) {
      obj->data->data[kstr - 1] = *(ptr);
      ptr = ptr + 1;
    }

    *toplevel = true;
    break;

   case 3:
    arg = PETSC_COMM_WORLD;
    sizepe = sizeof(MPI_Comm);
    kstr = data0->size[0];
    data0->size[0] = sizepe;
    emxEnsureCapacity((emxArray__common *)data0, kstr, (int)sizeof(unsigned char));
    for (kstr = 0; kstr < 8; kstr++) {
      t1_type[kstr] = cv3[kstr];
    }

    kstr = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity((emxArray__common *)obj->data, kstr, (int)sizeof(unsigned
      char));
    loop_ub = data0->size[0];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      obj->data->data[kstr] = data0->data[kstr];
    }

    kstr = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 8;
    emxEnsureCapacity((emxArray__common *)obj->type, kstr, (int)sizeof(char));
    for (kstr = 0; kstr < 8; kstr++) {
      obj->type->data[kstr] = t1_type[kstr];
    }

    obj->nitems = 1;
    ptr = (char *)(&arg);
    for (kstr = 1; kstr <= sizepe; kstr++) {
      obj->data->data[kstr - 1] = *(ptr);
      ptr = ptr + 1;
    }

    *toplevel = true;
    break;

   case 4:
    b_arg = PETSC_IGNORE;
    sizepe = sizeof(void *);
    kstr = data0->size[0];
    data0->size[0] = sizepe;
    emxEnsureCapacity((emxArray__common *)data0, kstr, (int)sizeof(unsigned char));
    for (kstr = 0; kstr < 6; kstr++) {
      t0_type[kstr] = cv4[kstr];
    }

    kstr = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity((emxArray__common *)obj->data, kstr, (int)sizeof(unsigned
      char));
    loop_ub = data0->size[0];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      obj->data->data[kstr] = data0->data[kstr];
    }

    kstr = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 6;
    emxEnsureCapacity((emxArray__common *)obj->type, kstr, (int)sizeof(char));
    for (kstr = 0; kstr < 6; kstr++) {
      obj->type->data[kstr] = t0_type[kstr];
    }

    obj->nitems = 1;
    ptr = (char *)(&b_arg);
    for (kstr = 1; kstr <= sizepe; kstr++) {
      obj->data->data[kstr - 1] = *(ptr);
      ptr = ptr + 1;
    }

    *toplevel = true;
    break;

   case 5:
    c_arg = NULL;
    sizepe = sizeof(PetscOptions);
    kstr = data0->size[0];
    data0->size[0] = sizepe;
    emxEnsureCapacity((emxArray__common *)data0, kstr, (int)sizeof(unsigned char));
    for (kstr = 0; kstr < 12; kstr++) {
      t2_type[kstr] = cv5[kstr];
    }

    kstr = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity((emxArray__common *)obj->data, kstr, (int)sizeof(unsigned
      char));
    loop_ub = data0->size[0];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      obj->data->data[kstr] = data0->data[kstr];
    }

    kstr = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 12;
    emxEnsureCapacity((emxArray__common *)obj->type, kstr, (int)sizeof(char));
    for (kstr = 0; kstr < 12; kstr++) {
      obj->type->data[kstr] = t2_type[kstr];
    }

    obj->nitems = 1;
    ptr = (char *)(&c_arg);
    for (kstr = 1; kstr <= sizepe; kstr++) {
      obj->data->data[kstr - 1] = *(ptr);
      ptr = ptr + 1;
    }

    *toplevel = true;
    break;

   case 6:
    d_arg = NULL;
    sizepe = sizeof(Mat);
    kstr = data0->size[0];
    data0->size[0] = sizepe;
    emxEnsureCapacity((emxArray__common *)data0, kstr, (int)sizeof(unsigned char));
    for (kstr = 0; kstr < 3; kstr++) {
      t3_type[kstr] = cv6[kstr];
    }

    kstr = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity((emxArray__common *)obj->data, kstr, (int)sizeof(unsigned
      char));
    loop_ub = data0->size[0];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      obj->data->data[kstr] = data0->data[kstr];
    }

    kstr = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)obj->type, kstr, (int)sizeof(char));
    for (kstr = 0; kstr < 3; kstr++) {
      obj->type->data[kstr] = t3_type[kstr];
    }

    obj->nitems = 1;
    ptr = (char *)(&d_arg);
    for (kstr = 1; kstr <= sizepe; kstr++) {
      obj->data->data[kstr - 1] = *(ptr);
      ptr = ptr + 1;
    }

    *toplevel = true;
    break;

   case 7:
    e_arg = NULL;
    sizepe = sizeof(Vec);
    kstr = data0->size[0];
    data0->size[0] = sizepe;
    emxEnsureCapacity((emxArray__common *)data0, kstr, (int)sizeof(unsigned char));
    for (kstr = 0; kstr < 3; kstr++) {
      t3_type[kstr] = cv7[kstr];
    }

    kstr = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity((emxArray__common *)obj->data, kstr, (int)sizeof(unsigned
      char));
    loop_ub = data0->size[0];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      obj->data->data[kstr] = data0->data[kstr];
    }

    kstr = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)obj->type, kstr, (int)sizeof(char));
    for (kstr = 0; kstr < 3; kstr++) {
      obj->type->data[kstr] = t3_type[kstr];
    }

    obj->nitems = 1;
    ptr = (char *)(&e_arg);
    for (kstr = 1; kstr <= sizepe; kstr++) {
      obj->data->data[kstr - 1] = *(ptr);
      ptr = ptr + 1;
    }

    *toplevel = true;
    break;

   case 8:
    f_arg = NULL;
    sizepe = sizeof(int *);
    kstr = data0->size[0];
    data0->size[0] = sizepe;
    emxEnsureCapacity((emxArray__common *)data0, kstr, (int)sizeof(unsigned char));
    for (kstr = 0; kstr < 5; kstr++) {
      t4_type[kstr] = cv8[kstr];
    }

    kstr = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity((emxArray__common *)obj->data, kstr, (int)sizeof(unsigned
      char));
    loop_ub = data0->size[0];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      obj->data->data[kstr] = data0->data[kstr];
    }

    kstr = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 5;
    emxEnsureCapacity((emxArray__common *)obj->type, kstr, (int)sizeof(char));
    for (kstr = 0; kstr < 5; kstr++) {
      obj->type->data[kstr] = t4_type[kstr];
    }

    obj->nitems = 1;
    ptr = (char *)(&f_arg);
    for (kstr = 1; kstr <= sizepe; kstr++) {
      obj->data->data[kstr - 1] = *(ptr);
      ptr = ptr + 1;
    }

    *toplevel = true;
    break;

   case 9:
    g_arg = NULL;
    sizepe = sizeof(double *);
    kstr = data0->size[0];
    data0->size[0] = sizepe;
    emxEnsureCapacity((emxArray__common *)data0, kstr, (int)sizeof(unsigned char));
    for (kstr = 0; kstr < 8; kstr++) {
      t1_type[kstr] = cv9[kstr];
    }

    kstr = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity((emxArray__common *)obj->data, kstr, (int)sizeof(unsigned
      char));
    loop_ub = data0->size[0];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      obj->data->data[kstr] = data0->data[kstr];
    }

    kstr = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 8;
    emxEnsureCapacity((emxArray__common *)obj->type, kstr, (int)sizeof(char));
    for (kstr = 0; kstr < 8; kstr++) {
      obj->type->data[kstr] = t1_type[kstr];
    }

    obj->nitems = 1;
    ptr = (char *)(&g_arg);
    for (kstr = 1; kstr <= sizepe; kstr++) {
      obj->data->data[kstr - 1] = *(ptr);
      ptr = ptr + 1;
    }

    *toplevel = true;
    break;

   default:
    emxInit_char_T(&b_name, 2);
    kstr = b_name->size[0] * b_name->size[1];
    b_name->size[0] = 1;
    b_name->size[1] = name->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_name, kstr, (int)sizeof(char));
    loop_ub = name->size[1];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      b_name->data[b_name->size[0] * kstr] = name->data[name->size[0] * kstr];
    }

    b_name->data[b_name->size[0] * name->size[1]] = '\x00';
    m2c_error(b_name);
    b_arg = NULL;
    sizepe = sizeof(void *);
    kstr = data0->size[0];
    data0->size[0] = sizepe;
    emxEnsureCapacity((emxArray__common *)data0, kstr, (int)sizeof(unsigned char));
    emxFree_char_T(&b_name);
    for (kstr = 0; kstr < 6; kstr++) {
      t0_type[kstr] = cv4[kstr];
    }

    kstr = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity((emxArray__common *)obj->data, kstr, (int)sizeof(unsigned
      char));
    loop_ub = data0->size[0];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      obj->data->data[kstr] = data0->data[kstr];
    }

    kstr = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 6;
    emxEnsureCapacity((emxArray__common *)obj->type, kstr, (int)sizeof(char));
    for (kstr = 0; kstr < 6; kstr++) {
      obj->type->data[kstr] = t0_type[kstr];
    }

    obj->nitems = 1;
    ptr = (char *)(&b_arg);
    for (kstr = 1; kstr <= sizepe; kstr++) {
      obj->data->data[kstr - 1] = *(ptr);
      ptr = ptr + 1;
    }

    *toplevel = true;
    break;
  }

  emxFree_uint8_T(&data0);
}

void petscGetObject_initialize(void)
{
}

void petscGetObject_terminate(void)
{
}
