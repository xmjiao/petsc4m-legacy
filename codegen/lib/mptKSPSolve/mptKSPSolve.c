#include "mptKSPSolve.h"
#include "petscksp.h"
#include "petscsys.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void b_m2c_printf(double varargin_2, int varargin_3);
static void c_m2c_error(const emxArray_char_T *varargin_3);
static void c_m2c_printf(double varargin_2, double varargin_3);
static void d_m2c_error(int varargin_3);
static void d_m2c_printf(int varargin_2, double varargin_3);
static void e_m2c_error(int varargin_3);
static void e_m2c_printf(void);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void f_m2c_error(int varargin_3);
static void g_m2c_error(int varargin_3);
static void h_m2c_error(int varargin_3);
static void i_m2c_error(int varargin_3);
static void j_m2c_error(int varargin_3);
static void k_m2c_error(int varargin_3);
static void l_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_printf(KSPType varargin_2, PCType varargin_3, int varargin_4);
static void m_m2c_error(int varargin_3);
static void petscKSPSolve(KSP ksp, const emxArray_uint8_T *b_data, const
  emxArray_char_T *b_type, const emxArray_uint8_T *x_data, const emxArray_char_T
  *x_type);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetTolerances returned error code %d\n",
            varargin_3);
}

static void b_m2c_printf(double varargin_2, int varargin_3)
{
  M2C_printf("### The relative residual was %g after %d iterations.\n",
             varargin_2, varargin_3);
}

static void c_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("PetscVec:WrongType", "Incorrect data type %s. Expected Vec.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void c_m2c_printf(double varargin_2, double varargin_3)
{
  M2C_printf("### The relative and absolute tolerances were %g and %g.\n",
             varargin_2, varargin_3);
}

static void d_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecCopy returned error code %d\n", varargin_3);
}

static void d_m2c_printf(int varargin_2, double varargin_3)
{
  M2C_printf("### The divergence and max-iter tolerances were %d and %g.\n",
             varargin_2, varargin_3);
}

static void e_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPSetInitialGuessNonzero returned error code %d\n", varargin_3);
}

static void e_m2c_printf(void)
{
  M2C_printf("### For explanation of the flag, see http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPConvergedReason.html.\n");
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
  M2C_error("petsc:RuntimeError", "KSPSolve returned error code %d\n",
            varargin_3);
}

static void g_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetConvergedReason returned error code %d\n", varargin_3);
}

static void h_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetResidualNorm returned error code %d\n",
            varargin_3);
}

static void i_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetIterationNumber returned error code %d\n", varargin_3);
}

static void j_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetTolerances returned error code %d\n",
            varargin_3);
}

static void k_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetPC returned error code %d\n",
            varargin_3);
}

static void l_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetType returned error code %d\n",
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

  M2C_error("PetscKSP:WrongType", "Incorrect data type %s. Expected KSP.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void m2c_printf(KSPType varargin_2, PCType varargin_3, int varargin_4)
{
  M2C_printf("### %s with %s preconditioner stopped with flag %d.\n", varargin_2,
             varargin_3, varargin_4);
}

static void m_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCGetType returned error code %d\n",
            varargin_3);
}

static void petscKSPSolve(KSP ksp, const emxArray_uint8_T *b_data, const
  emxArray_char_T *b_type, const emxArray_uint8_T *x_data, const emxArray_char_T
  *x_type)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg4;
  int i2;
  boolean_T exitg3;
  emxArray_char_T *b_b_type;
  static const char cv2[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  Vec t_b;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_x_type;
  Vec t_x;
  int errCode;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i2 = b_type->size[k];
      if (i2 != (k << 1) + 1) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(b_type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(b_type->data[k] == cv2[k])) {
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
    emxInit_char_T(&b_b_type, 2);
    i2 = b_b_type->size[0] * b_b_type->size[1];
    b_b_type->size[0] = 1;
    b_b_type->size[1] = b_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_b_type, i2, (int)sizeof(char));
    k = b_type->size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_b_type->data[b_b_type->size[0] * i2] = b_type->data[b_type->size[0] * i2];
    }

    b_b_type->data[b_b_type->size[0] * b_type->size[1]] = '\x00';
    c_m2c_error(b_b_type);
    emxFree_char_T(&b_b_type);
  }

  emxInit_uint8_T(&data, 1);
  i2 = data->size[0];
  data->size[0] = b_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i2, (int)sizeof(unsigned char));
  k = b_data->size[0];
  for (i2 = 0; i2 < k; i2++) {
    data->data[i2] = b_data->data[i2];
  }

  t_b = *(Vec*)(&data->data[0]);
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i2 = x_type->size[k];
      if (i2 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(x_type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(x_type->data[k] == cv2[k])) {
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
    emxInit_char_T(&b_x_type, 2);
    i2 = b_x_type->size[0] * b_x_type->size[1];
    b_x_type->size[0] = 1;
    b_x_type->size[1] = x_type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_x_type, i2, (int)sizeof(char));
    k = x_type->size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_x_type->data[b_x_type->size[0] * i2] = x_type->data[x_type->size[0] * i2];
    }

    b_x_type->data[b_x_type->size[0] * x_type->size[1]] = '\x00';
    c_m2c_error(b_x_type);
    emxFree_char_T(&b_x_type);
  }

  i2 = data->size[0];
  data->size[0] = x_data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i2, (int)sizeof(unsigned char));
  k = x_data->size[0];
  for (i2 = 0; i2 < k; i2++) {
    data->data[i2] = x_data->data[i2];
  }

  t_x = *(Vec*)(&data->data[0]);
  errCode = KSPSolve(ksp, t_b, t_x);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      f_m2c_error(errCode);
    }
  }
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void mptKSPSolve(const struct0_T *ksp, const struct0_T *b, const struct0_T *x,
                 double rtol, int maxits, const struct0_T *x0, int *flag, double
                 *relres, int *iter, double *time)
{
  double t;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg7;
  int val;
  boolean_T exitg6;
  emxArray_char_T *b_ksp;
  static const char cv0[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int errCode;
  boolean_T exitg5;
  int exitg4;
  double b_t;
  boolean_T exitg3;
  emxArray_char_T *b_x0;
  static const char cv1[3] = { 'V', 'e', 'c' };

  double b_rtol;
  double abstol;
  Vec vec;
  double dtol;
  int b_maxits;
  int exitg2;
  PC t_pc;
  KSPType t_type;
  boolean_T exitg1;
  PCType b_t_type;
  emxArray_char_T *b_x;
  Vec b_vec;
  t = M2C_wtime();
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg7 = 0;
    if (k < 2) {
      val = ksp->type->size[k];
      if (val != (k << 1) + 1) {
        exitg7 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg7 = 1;
    }
  } while (exitg7 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg6 = false;
    while ((!exitg6) && (k < 3)) {
      if (!(ksp->type->data[k] == cv0[k])) {
        b_p = false;
        exitg6 = true;
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
    emxInit_char_T(&b_ksp, 2);
    val = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, val, (int)sizeof(char));
    k = ksp->type->size[1];
    for (val = 0; val < k; val++) {
      b_ksp->data[b_ksp->size[0] * val] = ksp->type->data[ksp->type->size[0] *
        val];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  val = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (val = 0; val < k; val++) {
    data->data[val] = ksp->data->data[val];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  if (rtol == 0.0) {
    k = (PETSC_DEFAULT);
    rtol = k;
  }

  if (maxits == 0) {
    maxits = (PETSC_DEFAULT);
  }

  k = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  errCode = KSPSetTolerances(t_ksp, rtol, (double)k, (double)val, maxits);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      b_m2c_error(errCode);
    }
  }

  p = false;
  k = 1;
  exitg5 = false;
  while ((!exitg5) && (k <= x0->data->size[0])) {
    b_p = (x0->data->data[k - 1] == 0);
    if (!b_p) {
      p = true;
      exitg5 = true;
    } else {
      k++;
    }
  }

  if (!!p) {
    p = false;
    b_p = false;
    k = 0;
    do {
      exitg4 = 0;
      if (k < 2) {
        val = x0->type->size[k];
        if (val != (k << 1) + 1) {
          exitg4 = 1;
        } else {
          k++;
        }
      } else {
        b_p = true;
        exitg4 = 1;
      }
    } while (exitg4 == 0);

    if (b_p && (!(x0->type->size[1] == 0))) {
      k = 0;
      exitg3 = false;
      while ((!exitg3) && (k < 3)) {
        if (!(x0->type->data[k] == cv1[k])) {
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
      emxInit_char_T(&b_x0, 2);
      val = b_x0->size[0] * b_x0->size[1];
      b_x0->size[0] = 1;
      b_x0->size[1] = x0->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_x0, val, (int)sizeof(char));
      k = x0->type->size[1];
      for (val = 0; val < k; val++) {
        b_x0->data[b_x0->size[0] * val] = x0->type->data[x0->type->size[0] * val];
      }

      b_x0->data[b_x0->size[0] * x0->type->size[1]] = '\x00';
      c_m2c_error(b_x0);
      emxFree_char_T(&b_x0);
    }

    val = data->size[0];
    data->size[0] = x0->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
    k = x0->data->size[0];
    for (val = 0; val < k; val++) {
      data->data[val] = x0->data->data[val];
    }

    vec = *(Vec*)(&data->data[0]);
    p = false;
    b_p = false;
    k = 0;
    do {
      exitg2 = 0;
      if (k < 2) {
        val = x->type->size[k];
        if (val != (k << 1) + 1) {
          exitg2 = 1;
        } else {
          k++;
        }
      } else {
        b_p = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (b_p && (!(x->type->size[1] == 0))) {
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (!(x->type->data[k] == cv1[k])) {
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
      emxInit_char_T(&b_x, 2);
      val = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = x->type->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_x, val, (int)sizeof(char));
      k = x->type->size[1];
      for (val = 0; val < k; val++) {
        b_x->data[b_x->size[0] * val] = x->type->data[x->type->size[0] * val];
      }

      b_x->data[b_x->size[0] * x->type->size[1]] = '\x00';
      c_m2c_error(b_x);
      emxFree_char_T(&b_x);
    }

    val = data->size[0];
    data->size[0] = x->data->size[0];
    emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
    k = x->data->size[0];
    for (val = 0; val < k; val++) {
      data->data[val] = x->data->data[val];
    }

    b_vec = *(Vec*)(&data->data[0]);
    errCode = VecCopy(vec, b_vec);
    if (errCode != 0) {
      *flag = (M2C_DEBUG);
      if (*flag != 0) {
        d_m2c_error(errCode);
      }
    }

    k = (PETSC_TRUE);
    errCode = KSPSetInitialGuessNonzero(t_ksp, k);
    if (errCode != 0) {
      *flag = (M2C_DEBUG);
      if (*flag != 0) {
        e_m2c_error(errCode);
      }
    }
  } else {
    k = (PETSC_FALSE);
    errCode = KSPSetInitialGuessNonzero(t_ksp, k);
    if (errCode != 0) {
      *flag = (M2C_DEBUG);
      if (*flag != 0) {
        e_m2c_error(errCode);
      }
    }
  }

  emxFree_uint8_T(&data);
  petscKSPSolve(t_ksp, b->data, b->type, x->data, x->type);
  b_t = M2C_wtime();
  *time = b_t - t;
  errCode = KSPGetConvergedReason(t_ksp, flag);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      g_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(t_ksp, relres);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      h_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(t_ksp, iter);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPGetTolerances(t_ksp, &b_rtol, &abstol, &dtol, &b_maxits);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      j_m2c_error(errCode);
    }
  }

  if ((*flag < 0) || (*relres > b_rtol)) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        k_m2c_error(errCode);
      }
    }

    errCode = KSPGetType(t_ksp, &t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        l_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(b_maxits, dtol);
    e_m2c_printf();
  }
}

void mptKSPSolve_2args(const struct0_T *ksp, const struct0_T *b, int *flag,
  double *relres, int *iter, double *time)
{
  double t;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg4;
  int i3;
  boolean_T exitg3;
  emxArray_char_T *b_ksp;
  static const char cv3[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int errCode;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_b;
  static const char cv4[3] = { 'V', 'e', 'c' };

  Vec t_b;
  double b_t;
  double rtol;
  double abstol;
  double dtol;
  int maxits;
  PC t_pc;
  KSPType t_type;
  PCType b_t_type;
  t = M2C_wtime();
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg4 = 0;
    if (k < 2) {
      i3 = ksp->type->size[k];
      if (i3 != (k << 1) + 1) {
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 3)) {
      if (!(ksp->type->data[k] == cv3[k])) {
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
    emxInit_char_T(&b_ksp, 2);
    i3 = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, i3, (int)sizeof(char));
    k = ksp->type->size[1];
    for (i3 = 0; i3 < k; i3++) {
      b_ksp->data[b_ksp->size[0] * i3] = ksp->type->data[ksp->type->size[0] * i3];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  i3 = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i3, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (i3 = 0; i3 < k; i3++) {
    data->data[i3] = ksp->data->data[i3];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  k = (PETSC_FALSE);
  errCode = KSPSetInitialGuessNonzero(t_ksp, k);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      e_m2c_error(errCode);
    }
  }

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i3 = b->type->size[k];
      if (i3 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(b->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(b->type->data[k] == cv4[k])) {
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
    emxInit_char_T(&b_b, 2);
    i3 = b_b->size[0] * b_b->size[1];
    b_b->size[0] = 1;
    b_b->size[1] = b->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_b, i3, (int)sizeof(char));
    k = b->type->size[1];
    for (i3 = 0; i3 < k; i3++) {
      b_b->data[b_b->size[0] * i3] = b->type->data[b->type->size[0] * i3];
    }

    b_b->data[b_b->size[0] * b->type->size[1]] = '\x00';
    c_m2c_error(b_b);
    emxFree_char_T(&b_b);
  }

  i3 = data->size[0];
  data->size[0] = b->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i3, (int)sizeof(unsigned char));
  k = b->data->size[0];
  for (i3 = 0; i3 < k; i3++) {
    data->data[i3] = b->data->data[i3];
  }

  t_b = *(Vec*)(&data->data[0]);
  errCode = KSPSolve(t_ksp, t_b, t_b);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      f_m2c_error(errCode);
    }
  }

  b_t = M2C_wtime();
  errCode = KSPGetConvergedReason(t_ksp, flag);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      g_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(t_ksp, relres);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      h_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(t_ksp, iter);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPGetTolerances(t_ksp, &rtol, &abstol, &dtol, &maxits);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      j_m2c_error(errCode);
    }
  }

  if ((*flag < 0) || (*relres > rtol)) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        k_m2c_error(errCode);
      }
    }

    errCode = KSPGetType(t_ksp, &t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        l_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  *time = b_t - t;
}

void mptKSPSolve_3args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, int *flag, double *relres, int *iter, double *time)
{
  double t;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i4;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv5[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int errCode;
  double b_t;
  double rtol;
  double abstol;
  double dtol;
  int maxits;
  PC t_pc;
  KSPType t_type;
  PCType b_t_type;
  t = M2C_wtime();
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i4 = ksp->type->size[k];
      if (i4 != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp->type->data[k] == cv5[k])) {
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
    emxInit_char_T(&b_ksp, 2);
    i4 = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, i4, (int)sizeof(char));
    k = ksp->type->size[1];
    for (i4 = 0; i4 < k; i4++) {
      b_ksp->data[b_ksp->size[0] * i4] = ksp->type->data[ksp->type->size[0] * i4];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  i4 = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i4, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (i4 = 0; i4 < k; i4++) {
    data->data[i4] = ksp->data->data[i4];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  k = (PETSC_FALSE);
  errCode = KSPSetInitialGuessNonzero(t_ksp, k);
  emxFree_uint8_T(&data);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      e_m2c_error(errCode);
    }
  }

  petscKSPSolve(t_ksp, b->data, b->type, x->data, x->type);
  b_t = M2C_wtime();
  errCode = KSPGetConvergedReason(t_ksp, flag);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      g_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(t_ksp, relres);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      h_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(t_ksp, iter);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPGetTolerances(t_ksp, &rtol, &abstol, &dtol, &maxits);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      j_m2c_error(errCode);
    }
  }

  if ((*flag < 0) || (*relres > rtol)) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        k_m2c_error(errCode);
      }
    }

    errCode = KSPGetType(t_ksp, &t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        l_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  *time = b_t - t;
}

void mptKSPSolve_4args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, double rtol, int *flag, double *relres, int *iter, double *time)
{
  double b_rtol;
  double t;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int val;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv6[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int maxits;
  int errCode;
  double b_t;
  double abstol;
  double dtol;
  PC t_pc;
  KSPType t_type;
  PCType b_t_type;
  b_rtol = rtol;
  t = M2C_wtime();
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      val = ksp->type->size[k];
      if (val != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp->type->data[k] == cv6[k])) {
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
    emxInit_char_T(&b_ksp, 2);
    val = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, val, (int)sizeof(char));
    k = ksp->type->size[1];
    for (val = 0; val < k; val++) {
      b_ksp->data[b_ksp->size[0] * val] = ksp->type->data[ksp->type->size[0] *
        val];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  val = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (val = 0; val < k; val++) {
    data->data[val] = ksp->data->data[val];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  emxFree_uint8_T(&data);
  if (rtol == 0.0) {
    k = (PETSC_DEFAULT);
    b_rtol = k;
  }

  maxits = (PETSC_DEFAULT);
  k = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  errCode = KSPSetTolerances(t_ksp, b_rtol, (double)k, (double)val, maxits);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      b_m2c_error(errCode);
    }
  }

  k = (PETSC_FALSE);
  errCode = KSPSetInitialGuessNonzero(t_ksp, k);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      e_m2c_error(errCode);
    }
  }

  petscKSPSolve(t_ksp, b->data, b->type, x->data, x->type);
  b_t = M2C_wtime();
  errCode = KSPGetConvergedReason(t_ksp, flag);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      g_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(t_ksp, relres);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      h_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(t_ksp, iter);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPGetTolerances(t_ksp, &b_rtol, &abstol, &dtol, &maxits);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      j_m2c_error(errCode);
    }
  }

  if ((*flag < 0) || (*relres > b_rtol)) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        k_m2c_error(errCode);
      }
    }

    errCode = KSPGetType(t_ksp, &t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        l_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  *time = b_t - t;
}

void mptKSPSolve_5args(const struct0_T *ksp, const struct0_T *b, const struct0_T
  *x, double rtol, int maxiter, int *flag, double *relres, int *iter, double
  *time)
{
  double b_rtol;
  int maxits;
  double t;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int val;
  boolean_T exitg1;
  emxArray_char_T *b_ksp;
  static const char cv7[3] = { 'K', 'S', 'P' };

  emxArray_uint8_T *data;
  KSP t_ksp;
  int errCode;
  double b_t;
  double abstol;
  double dtol;
  PC t_pc;
  KSPType t_type;
  PCType b_t_type;
  b_rtol = rtol;
  maxits = maxiter;
  t = M2C_wtime();
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      val = ksp->type->size[k];
      if (val != (k << 1) + 1) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(ksp->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(ksp->type->data[k] == cv7[k])) {
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
    emxInit_char_T(&b_ksp, 2);
    val = b_ksp->size[0] * b_ksp->size[1];
    b_ksp->size[0] = 1;
    b_ksp->size[1] = ksp->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_ksp, val, (int)sizeof(char));
    k = ksp->type->size[1];
    for (val = 0; val < k; val++) {
      b_ksp->data[b_ksp->size[0] * val] = ksp->type->data[ksp->type->size[0] *
        val];
    }

    b_ksp->data[b_ksp->size[0] * ksp->type->size[1]] = '\x00';
    m2c_error(b_ksp);
    emxFree_char_T(&b_ksp);
  }

  emxInit_uint8_T(&data, 1);
  val = data->size[0];
  data->size[0] = ksp->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, val, (int)sizeof(unsigned char));
  k = ksp->data->size[0];
  for (val = 0; val < k; val++) {
    data->data[val] = ksp->data->data[val];
  }

  t_ksp = *(KSP*)(&data->data[0]);
  emxFree_uint8_T(&data);
  if (rtol == 0.0) {
    k = (PETSC_DEFAULT);
    b_rtol = k;
  }

  if (maxiter == 0) {
    maxits = (PETSC_DEFAULT);
  }

  k = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  errCode = KSPSetTolerances(t_ksp, b_rtol, (double)k, (double)val, maxits);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      b_m2c_error(errCode);
    }
  }

  k = (PETSC_FALSE);
  errCode = KSPSetInitialGuessNonzero(t_ksp, k);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      e_m2c_error(errCode);
    }
  }

  petscKSPSolve(t_ksp, b->data, b->type, x->data, x->type);
  b_t = M2C_wtime();
  errCode = KSPGetConvergedReason(t_ksp, flag);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      g_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(t_ksp, relres);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      h_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(t_ksp, iter);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      i_m2c_error(errCode);
    }
  }

  errCode = KSPGetTolerances(t_ksp, &b_rtol, &abstol, &dtol, &maxits);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      j_m2c_error(errCode);
    }
  }

  if ((*flag < 0) || (*relres > b_rtol)) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        k_m2c_error(errCode);
      }
    }

    errCode = KSPGetType(t_ksp, &t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        l_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        m_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  *time = b_t - t;
}

void mptKSPSolve_initialize(void)
{
}

void mptKSPSolve_terminate(void)
{
}
