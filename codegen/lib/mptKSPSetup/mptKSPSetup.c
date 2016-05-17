#include "mptKSPSetup.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void c_m2c_error(int varargin_3);
static void d_m2c_error(const emxArray_char_T *varargin_3);
static void e_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void f_m2c_error(int varargin_3);
static void g_m2c_error(void);
static void h_m2c_error(int varargin_3);
static void i_m2c_error(int varargin_3);
static boolean_T isequal(const emxArray_char_T *varargin_1);
static void j_m2c_error(void);
static void k_m2c_error(int varargin_3);
static void l_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m_m2c_error(int varargin_3);
static void petscKSPSetOperators(KSP ksp, const emxArray_uint8_T *Amat_data,
  const emxArray_char_T *Amat_type);
static MPI_Comm petscObjectGetComm(const emxArray_uint8_T *obj_data, const
  emxArray_char_T *obj_type);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscObjectGetComm returned error code %d\n",
            varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPCreate returned error code %d\n",
            varargin_3);
}

static void d_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i3;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i3 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i3, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_varargin_3->data[i3] = varargin_3->data[i3];
  }

  M2C_error("PetscMat:WrongType", "Incorrect data type %s. Expected Mat.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void e_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetOperators returned error code %d\n",
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
  M2C_error("petsc:RuntimeError", "KSPGetPC returned error code %d\n",
            varargin_3);
}

static void g_m2c_error(void)
{
  M2C_error("runtime:Error", "PC type must be a null-terminated string.");
}

static void h_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCSetType returned error code %d\n",
            varargin_3);
}

static void i_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "petscPCFactorSetMatSolverPackage returned error code %d\n",
            varargin_3);
}

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i1;
  boolean_T exitg1;
  static const char cv5[3] = { 'M', 'a', 't' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i1 = varargin_1->size[k];
      if (i1 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv5[k])) {
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

  return p;
}

static void j_m2c_error(void)
{
  M2C_error("runtime:Error", "KSP type must be a null-terminated string.");
}

static void k_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetType returned error code %d\n",
            varargin_3);
}

static void l_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetFromOptions returned error code %d\n",
            varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("PetscObject:WrongType",
            "Incorrect data type %s. Expected PetscObject.", &b_varargin_3->
            data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetUp returned error code %d\n",
            varargin_3);
}

static void petscKSPSetOperators(KSP ksp, const emxArray_uint8_T *Amat_data,
  const emxArray_char_T *Amat_type)
{
  emxArray_char_T *b_Amat_type;
  emxArray_uint8_T *data;
  int flag;
  int loop_ub;
  Mat t_Amat;
  int errCode;
  if (!isequal(Amat_type)) {
    emxInit_char_T(&b_Amat_type, 2);
    flag = b_Amat_type->size[0] * b_Amat_type->size[1];
    b_Amat_type->size[0] = 1;
    b_Amat_type->size[1] = Amat_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_Amat_type, flag, (int)sizeof(char));
    loop_ub = Amat_type->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      b_Amat_type->data[b_Amat_type->size[0] * flag] = Amat_type->data
        [Amat_type->size[0] * flag];
    }

    b_Amat_type->data[b_Amat_type->size[0] * Amat_type->size[1]] = '\x00';
    d_m2c_error(b_Amat_type);
    emxFree_char_T(&b_Amat_type);
  }

  emxInit_uint8_T(&data, 1);
  flag = data->size[0];
  data->size[0] = Amat_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, flag, (int)sizeof(unsigned char));
  loop_ub = Amat_data->size[0];
  for (flag = 0; flag < loop_ub; flag++) {
    data->data[flag] = Amat_data->data[flag];
  }

  t_Amat = *(Mat*)(&data->data[0]);
  errCode = KSPSetOperators(ksp, t_Amat, t_Amat);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      e_m2c_error(errCode);
    }
  }
}

static MPI_Comm petscObjectGetComm(const emxArray_uint8_T *obj_data, const
  emxArray_char_T *obj_type)
{
  MPI_Comm comm;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg8;
  int i0;
  boolean_T exitg7;
  emxArray_char_T *b_obj_type;
  static const char cv1[11] = { 'P', 'e', 't', 's', 'c', 'O', 'b', 'j', 'e', 'c',
    't' };

  emxArray_uint8_T *data;
  int exitg6;
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  boolean_T exitg5;
  static const char cv2[3] = { 'V', 'e', 'c' };

  int exitg4;
  boolean_T exitg3;
  static const char cv3[3] = { 'K', 'S', 'P' };

  int exitg2;
  boolean_T exitg1;
  static const char cv4[2] = { 'P', 'C' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg8 = 0;
    if (k < 2) {
      i0 = obj_type->size[k];
      if (i0 != 10 * k + 1) {
        exitg8 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg8 = 1;
    }
  } while (exitg8 == 0);

  if (b_p && (!(obj_type->size[1] == 0))) {
    k = 0;
    exitg7 = false;
    while ((!exitg7) && (k < 11)) {
      if (!(obj_type->data[k] == cv1[k])) {
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

  emxInit_char_T(&b_obj_type, 2);
  if ((!p) && (!isequal(obj_type))) {
    p = false;
    b_p = false;
    k = 0;
    do {
      exitg6 = 0;
      if (k < 2) {
        i0 = obj_type->size[k];
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

    if (b_p && (!(obj_type->size[1] == 0))) {
      k = 0;
      exitg5 = false;
      while ((!exitg5) && (k < 3)) {
        if (!(obj_type->data[k] == cv2[k])) {
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
          i0 = obj_type->size[k];
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

      if (b_p && (!(obj_type->size[1] == 0))) {
        k = 0;
        exitg3 = false;
        while ((!exitg3) && (k < 3)) {
          if (!(obj_type->data[k] == cv3[k])) {
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
            i0 = obj_type->size[k];
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

        if (b_p && (!(obj_type->size[1] == 0))) {
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k < 2)) {
            if (!(obj_type->data[k] == cv4[k])) {
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
          i0 = b_obj_type->size[0] * b_obj_type->size[1];
          b_obj_type->size[0] = 1;
          b_obj_type->size[1] = obj_type->size[1] + 1;
          emxEnsureCapacity((emxArray__common *)b_obj_type, i0, (int)sizeof(char));
          k = obj_type->size[1];
          for (i0 = 0; i0 < k; i0++) {
            b_obj_type->data[b_obj_type->size[0] * i0] = obj_type->data
              [obj_type->size[0] * i0];
          }

          b_obj_type->data[b_obj_type->size[0] * obj_type->size[1]] = '\x00';
          m2c_error(b_obj_type);
        }
      }
    }
  }

  emxFree_char_T(&b_obj_type);
  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = obj_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = obj_data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = obj_data->data[i0];
  }

  t_obj = *(PetscObject*)(&data->data[0]);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  comm = t_comm;
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      b_m2c_error(errCode);
    }
  }

  return comm;
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

void mptKSPSetup(const struct0_T *Amat, const emxArray_char_T *ksptype, const
                 emxArray_char_T *pctype, const emxArray_char_T *solpack,
                 struct0_T *ksp, boolean_T *toplevel)
{
  MPI_Comm arg;
  KSP t_ksp;
  int errCode;
  int flag;
  boolean_T hasPC;
  boolean_T b0;
  PC t_pc;
  emxArray_uint8_T *data0;
  int sizepe;
  char t3_type[3];
  static const char cv0[3] = { 'K', 'S', 'P' };

  int loop_ub;
  char * ptr;
  int i;
  arg = petscObjectGetComm(Amat->data, Amat->type);
  errCode = KSPCreate(arg, &t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      c_m2c_error(errCode);
    }
  }

  petscKSPSetOperators(t_ksp, Amat->data, Amat->type);
  hasPC = !(pctype->size[1] == 0);
  b0 = !(solpack->size[1] == 0);
  if (hasPC || b0) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      flag = (M2C_DEBUG);
      if (flag != 0) {
        f_m2c_error(errCode);
      }
    }

    if (hasPC) {
      if ((unsigned char)pctype->data[pctype->size[1] - 1] != 0) {
        g_m2c_error();
      }

      errCode = PCSetType(t_pc, &pctype->data[0]);
      if (errCode != 0) {
        flag = (M2C_DEBUG);
        if (flag != 0) {
          h_m2c_error(errCode);
        }
      }
    }

    if (b0) {
      errCode = PCFactorSetMatSolverPackage(t_pc, &solpack->data[0]);
      if (errCode != 0) {
        flag = (M2C_DEBUG);
        if (flag != 0) {
          i_m2c_error(errCode);
        }
      }
    }
  }

  if ((unsigned char)ksptype->data[ksptype->size[1] - 1] != 0) {
    j_m2c_error();
  }

  errCode = KSPSetType(t_ksp, &ksptype->data[0]);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      k_m2c_error(errCode);
    }
  }

  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      m_m2c_error(errCode);
    }
  }

  emxInit_uint8_T(&data0, 1);
  *toplevel = true;
  sizepe = sizeof(KSP);
  flag = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, flag, (int)sizeof(unsigned char));
  for (flag = 0; flag < 3; flag++) {
    t3_type[flag] = cv0[flag];
  }

  flag = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, flag, (int)sizeof(unsigned
    char));
  loop_ub = data0->size[0];
  for (flag = 0; flag < loop_ub; flag++) {
    ksp->data->data[flag] = data0->data[flag];
  }

  emxFree_uint8_T(&data0);
  flag = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, flag, (int)sizeof(char));
  for (flag = 0; flag < 3; flag++) {
    ksp->type->data[flag] = t3_type[flag];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (i = 1; i <= sizepe; i++) {
    ksp->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }
}

void mptKSPSetup_1arg(const struct0_T *Amat, struct0_T *ksp, boolean_T *toplevel)
{
  MPI_Comm arg;
  KSP t_ksp;
  int errCode;
  int flag;
  emxArray_uint8_T *data0;
  int sizepe;
  char t2_type[3];
  static const char cv6[3] = { 'K', 'S', 'P' };

  int loop_ub;
  char * ptr;
  int i;
  arg = petscObjectGetComm(Amat->data, Amat->type);
  errCode = KSPCreate(arg, &t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      c_m2c_error(errCode);
    }
  }

  petscKSPSetOperators(t_ksp, Amat->data, Amat->type);
  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      m_m2c_error(errCode);
    }
  }

  emxInit_uint8_T(&data0, 1);
  sizepe = sizeof(KSP);
  flag = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, flag, (int)sizeof(unsigned char));
  for (flag = 0; flag < 3; flag++) {
    t2_type[flag] = cv6[flag];
  }

  flag = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, flag, (int)sizeof(unsigned
    char));
  loop_ub = data0->size[0];
  for (flag = 0; flag < loop_ub; flag++) {
    ksp->data->data[flag] = data0->data[flag];
  }

  emxFree_uint8_T(&data0);
  flag = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, flag, (int)sizeof(char));
  for (flag = 0; flag < 3; flag++) {
    ksp->type->data[flag] = t2_type[flag];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (i = 1; i <= sizepe; i++) {
    ksp->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  *toplevel = true;
}

void mptKSPSetup_2args(const struct0_T *Amat, const emxArray_char_T *ksptype,
  struct0_T *ksp, boolean_T *toplevel)
{
  MPI_Comm arg;
  KSP t_ksp;
  int errCode;
  int flag;
  emxArray_uint8_T *data0;
  int sizepe;
  char t1_type[3];
  static const char cv7[3] = { 'K', 'S', 'P' };

  int loop_ub;
  char * ptr;
  int i;
  arg = petscObjectGetComm(Amat->data, Amat->type);
  errCode = KSPCreate(arg, &t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      c_m2c_error(errCode);
    }
  }

  petscKSPSetOperators(t_ksp, Amat->data, Amat->type);
  if ((unsigned char)ksptype->data[ksptype->size[1] - 1] != 0) {
    j_m2c_error();
  }

  errCode = KSPSetType(t_ksp, &ksptype->data[0]);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      k_m2c_error(errCode);
    }
  }

  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      m_m2c_error(errCode);
    }
  }

  emxInit_uint8_T(&data0, 1);
  sizepe = sizeof(KSP);
  flag = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, flag, (int)sizeof(unsigned char));
  for (flag = 0; flag < 3; flag++) {
    t1_type[flag] = cv7[flag];
  }

  flag = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, flag, (int)sizeof(unsigned
    char));
  loop_ub = data0->size[0];
  for (flag = 0; flag < loop_ub; flag++) {
    ksp->data->data[flag] = data0->data[flag];
  }

  emxFree_uint8_T(&data0);
  flag = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, flag, (int)sizeof(char));
  for (flag = 0; flag < 3; flag++) {
    ksp->type->data[flag] = t1_type[flag];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (i = 1; i <= sizepe; i++) {
    ksp->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  *toplevel = true;
}

void mptKSPSetup_3args(const struct0_T *Amat, const emxArray_char_T *ksptype,
  const emxArray_char_T *pctype, struct0_T *ksp, boolean_T *toplevel)
{
  MPI_Comm arg;
  KSP t_ksp;
  int errCode;
  int flag;
  boolean_T hasPC;
  PC t_pc;
  emxArray_uint8_T *data0;
  int sizepe;
  char t0_type[3];
  static const char cv8[3] = { 'K', 'S', 'P' };

  int loop_ub;
  char * ptr;
  int i;
  arg = petscObjectGetComm(Amat->data, Amat->type);
  errCode = KSPCreate(arg, &t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      c_m2c_error(errCode);
    }
  }

  petscKSPSetOperators(t_ksp, Amat->data, Amat->type);
  hasPC = !(pctype->size[1] == 0);
  if (hasPC) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      flag = (M2C_DEBUG);
      if (flag != 0) {
        f_m2c_error(errCode);
      }
    }

    if ((unsigned char)pctype->data[pctype->size[1] - 1] != 0) {
      g_m2c_error();
    }

    errCode = PCSetType(t_pc, &pctype->data[0]);
    if (errCode != 0) {
      flag = (M2C_DEBUG);
      if (flag != 0) {
        h_m2c_error(errCode);
      }
    }
  }

  if ((unsigned char)ksptype->data[ksptype->size[1] - 1] != 0) {
    j_m2c_error();
  }

  errCode = KSPSetType(t_ksp, &ksptype->data[0]);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      k_m2c_error(errCode);
    }
  }

  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      m_m2c_error(errCode);
    }
  }

  emxInit_uint8_T(&data0, 1);
  sizepe = sizeof(KSP);
  flag = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, flag, (int)sizeof(unsigned char));
  for (flag = 0; flag < 3; flag++) {
    t0_type[flag] = cv8[flag];
  }

  flag = ksp->data->size[0];
  ksp->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)ksp->data, flag, (int)sizeof(unsigned
    char));
  loop_ub = data0->size[0];
  for (flag = 0; flag < loop_ub; flag++) {
    ksp->data->data[flag] = data0->data[flag];
  }

  emxFree_uint8_T(&data0);
  flag = ksp->type->size[0] * ksp->type->size[1];
  ksp->type->size[0] = 1;
  ksp->type->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)ksp->type, flag, (int)sizeof(char));
  for (flag = 0; flag < 3; flag++) {
    ksp->type->data[flag] = t0_type[flag];
  }

  ksp->nitems = 1;
  ptr = (char *)(&t_ksp);
  for (i = 1; i <= sizepe; i++) {
    ksp->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  *toplevel = true;
}

void mptKSPSetup_initialize(void)
{
}

void mptKSPSetup_terminate(void)
{
}
