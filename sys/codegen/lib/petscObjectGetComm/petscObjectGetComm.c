#include "petscObjectGetComm.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscObjectGetComm returned error code %d\n",
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

  M2C_error("PetscObject:WrongType",
            "Incorrect data type %s. Expected PetscObject.", &b_varargin_3->
            data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscObjectGetComm(const struct0_T *obj, struct0_T *comm, int *errCode,
  boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg10;
  int i0;
  boolean_T exitg9;
  emxArray_char_T *b_obj;
  static const char cv0[11] = { 'P', 'e', 't', 's', 'c', 'O', 'b', 'j', 'e', 'c',
    't' };

  emxArray_uint8_T *data0;
  int exitg8;
  PetscObject t_obj;
  MPI_Comm t_comm;
  boolean_T exitg7;
  int sizepe;
  static const char cv1[3] = { 'M', 'a', 't' };

  char t0_type[8];
  int exitg6;
  static const char cv2[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  boolean_T exitg5;
  static const char cv3[3] = { 'V', 'e', 'c' };

  int exitg4;
  char * ptr;
  int i;
  boolean_T exitg3;
  static const char cv4[3] = { 'K', 'S', 'P' };

  int exitg2;
  boolean_T exitg1;
  static const char cv5[2] = { 'P', 'C' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg10 = 0;
    if (k < 2) {
      i0 = obj->type->size[k];
      if (i0 != 10 * k + 1) {
        exitg10 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg10 = 1;
    }
  } while (exitg10 == 0);

  if (b_p && (!(obj->type->size[1] == 0))) {
    k = 0;
    exitg9 = false;
    while ((!exitg9) && (k < 11)) {
      if (!(obj->type->data[k] == cv0[k])) {
        b_p = false;
        exitg9 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  emxInit_char_T(&b_obj, 2);
  if (!p) {
    p = false;
    b_p = false;
    k = 0;
    do {
      exitg8 = 0;
      if (k < 2) {
        i0 = obj->type->size[k];
        if (i0 != (k << 1) + 1) {
          exitg8 = 1;
        } else {
          k++;
        }
      } else {
        b_p = true;
        exitg8 = 1;
      }
    } while (exitg8 == 0);

    if (b_p && (!(obj->type->size[1] == 0))) {
      k = 0;
      exitg7 = false;
      while ((!exitg7) && (k < 3)) {
        if (!(obj->type->data[k] == cv1[k])) {
          b_p = false;
          exitg7 = true;
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
      p = false;
      b_p = false;
      k = 0;
      do {
        exitg6 = 0;
        if (k < 2) {
          i0 = obj->type->size[k];
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

      if (b_p && (!(obj->type->size[1] == 0))) {
        k = 0;
        exitg5 = false;
        while ((!exitg5) && (k < 3)) {
          if (!(obj->type->data[k] == cv3[k])) {
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
        p = false;
        b_p = false;
        k = 0;
        do {
          exitg4 = 0;
          if (k < 2) {
            i0 = obj->type->size[k];
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

        if (b_p && (!(obj->type->size[1] == 0))) {
          k = 0;
          exitg3 = false;
          while ((!exitg3) && (k < 3)) {
            if (!(obj->type->data[k] == cv4[k])) {
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
          p = false;
          b_p = false;
          k = 0;
          do {
            exitg2 = 0;
            if (k < 2) {
              i0 = obj->type->size[k];
              if (i0 != k + 1) {
                exitg2 = 1;
              } else {
                k++;
              }
            } else {
              b_p = true;
              exitg2 = 1;
            }
          } while (exitg2 == 0);

          if (b_p && (!(obj->type->size[1] == 0))) {
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 2)) {
              if (!(obj->type->data[k] == cv5[k])) {
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
            i0 = b_obj->size[0] * b_obj->size[1];
            b_obj->size[0] = 1;
            b_obj->size[1] = obj->type->size[1] + 1;
            emxEnsureCapacity((emxArray__common *)b_obj, i0, (int)sizeof(char));
            k = obj->type->size[1];
            for (i0 = 0; i0 < k; i0++) {
              b_obj->data[b_obj->size[0] * i0] = obj->type->data[obj->type->
                size[0] * i0];
            }

            b_obj->data[b_obj->size[0] * obj->type->size[1]] = '\x00';
            m2c_error(b_obj);
          }
        }
      }
    }
  }

  emxFree_char_T(&b_obj);
  emxInit_uint8_T(&data0, 1);
  i0 = data0->size[0];
  data0->size[0] = obj->data->size[0];
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  k = obj->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data0->data[i0] = obj->data->data[i0];
  }

  t_obj = *(PetscObject*)(&data0->data[0]);
  *errCode = PetscObjectGetComm(t_obj, &t_comm);
  *toplevel = true;
  sizepe = sizeof(MPI_Comm);
  i0 = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i0, (int)sizeof(unsigned char));
  for (i0 = 0; i0 < 8; i0++) {
    t0_type[i0] = cv2[i0];
  }

  i0 = comm->data->size[0];
  comm->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)comm->data, i0, (int)sizeof(unsigned
    char));
  k = data0->size[0];
  for (i0 = 0; i0 < k; i0++) {
    comm->data->data[i0] = data0->data[i0];
  }

  emxFree_uint8_T(&data0);
  i0 = comm->type->size[0] * comm->type->size[1];
  comm->type->size[0] = 1;
  comm->type->size[1] = 8;
  emxEnsureCapacity((emxArray__common *)comm->type, i0, (int)sizeof(char));
  for (i0 = 0; i0 < 8; i0++) {
    comm->type->data[i0] = t0_type[i0];
  }

  comm->nitems = 1;
  ptr = (char *)(&t_comm);
  for (i = 1; i <= sizepe; i++) {
    comm->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscObjectGetComm_initialize(void)
{
}

void petscObjectGetComm_terminate(void)
{
}
