#include "mptSolveCRS.h"
#include "mpetsc.h"
#include "m2c.h"

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T

struct emxArray_uint8_T
{
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif

#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T

typedef struct emxArray_uint8_T emxArray_uint8_T;

#endif

static void ab_m2c_error(int varargin_3);
static void b_m2c_error(int varargin_3);
static void b_m2c_printf(double varargin_2, int varargin_3);
static void b_mptKSPSetup(Mat Amat, const emxArray_char_T *ksptype, const
  emxArray_char_T *pctype, const emxArray_char_T *pcopt, KSP *ksp, double *time);
static void b_mptKSPSolve(KSP ksp, Vec b, Vec x, double rtol, int maxits, Vec x0,
  int *flag, double *relres, int *iter, emxArray_real_T *reshis, double *time);
static void bb_m2c_error(int varargin_3);
static void c_m2c_error(int varargin_3);
static void c_m2c_printf(double varargin_2, double varargin_3);
static void cb_m2c_error(int varargin_3);
static void d_m2c_error(int varargin_3);
static void d_m2c_printf(int varargin_2, double varargin_3);
static void db_m2c_error(int varargin_3);
static void e_m2c_error(int varargin_3);
static void e_m2c_printf(void);
static void eb_m2c_error(int varargin_3);
static void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);
static void emxInit_int32_T1(emxArray_int32_T **pEmxArray, int numDimensions);
static void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions);
static void f_m2c_error(int varargin_3);
static void fb_m2c_error(int varargin_3);
static void g_m2c_error(int varargin_3);
static void gb_m2c_error(int varargin_3);
static void h_m2c_error(int varargin_3);
static void hb_m2c_error(int varargin_3);
static void i_m2c_error(int varargin_3);
static void ib_m2c_error(int varargin_3);
static void j_m2c_error(int varargin_3);
static void jb_m2c_error(int varargin_3);
static void k_m2c_error(int varargin_3);
static void kb_m2c_error(int varargin_3);
static void l_m2c_error(int varargin_3);
static void lb_m2c_error(void);
static void m2c_error(int varargin_3);
static void m2c_printf(KSPType varargin_2, PCType varargin_3, const
  emxArray_char_T *varargin_4, int varargin_5);
static void m_m2c_error(const emxArray_char_T *varargin_3);
static void mb_m2c_error(int varargin_3);
static void mpi_Barrier(MPI_Comm comm);
static void mptKSPSetup(Mat Amat, const emxArray_char_T *ksptype, KSP *ksp,
  double *time);
static void mptKSPSolve(KSP ksp, Vec b, Vec x, Vec x0, int *flag, double *relres,
  int *iter, emxArray_real_T *reshis, double *time);
static Mat mptMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val);
static void mptSolve(Mat A, Vec b, Vec x, const emxArray_char_T *solver, double
                     rtol, int maxit, const emxArray_char_T *pctype, const
                     emxArray_char_T *pcopt, Vec x0, int *flag, double *relres,
                     int *iter, emxArray_real_T *reshis, double times[2]);
static Vec mptVecCreateFromArray(const emxArray_real_T *arr);
static void mptVecToArray(Vec vec, emxArray_real_T *arr);
static void n_m2c_error(int varargin_3);
static void nb_m2c_error(int varargin_3);
static void o_m2c_error(int varargin_3);
static void ob_m2c_error(int varargin_3);
static void p_m2c_error(int varargin_3);
static void pb_m2c_error(int varargin_3);
static void q_m2c_error(int varargin_3);
static void qb_m2c_error(void);
static void r_m2c_error(int varargin_3);
static void rb_m2c_error(int varargin_3);
static void s_m2c_error(int varargin_3);
static void t_m2c_error(int varargin_3);
static void u_m2c_error(int varargin_3);
static void v_m2c_error(int varargin_3);
static void w_m2c_error(int varargin_3);
static void x_m2c_error(int varargin_3);
static void y_m2c_error(int varargin_3);
static void ab_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetIterationNumber returned error code %d\n", varargin_3);
}

static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatSetValues returned error code %d\n",
            varargin_3);
}

static void b_m2c_printf(double varargin_2, int varargin_3)
{
  M2C_printf("### The relative residual was %g after %d iterations.\n",
             varargin_2, varargin_3);
}

static void b_mptKSPSetup(Mat Amat, const emxArray_char_T *ksptype, const
  emxArray_char_T *pctype, const emxArray_char_T *pcopt, KSP *ksp, double *time)
{
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  int k;
  KSP t_ksp;
  double t;
  boolean_T p;
  boolean_T b_p;
  emxArray_char_T *pctype0;
  PC t_pc;
  int i4;
  int exitg6;
  boolean_T exitg5;
  double secs;
  static const char cv9[4] = { 'l', 'e', 'f', 't' };

  int exitg4;
  boolean_T exitg3;
  static const char cv10[5] = { 'r', 'i', 'g', 'h', 't' };

  int exitg2;
  boolean_T exitg1;
  static const char cv11[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  t_obj = (PetscObject)(Amat);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      j_m2c_error(errCode);
    }
  }

  errCode = KSPCreate(t_comm, &t_ksp);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      k_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(t_ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      j_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  t = MPI_Wtime();
  errCode = KSPSetOperators(t_ksp, Amat, Amat);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      n_m2c_error(errCode);
    }
  }

  p = !(pctype->size[1] == 0);
  b_p = !(pcopt->size[1] == 0);
  emxInit_char_T(&pctype0, 2);
  if (p || b_p) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        cb_m2c_error(errCode);
      }
    }

    if (p) {
      if (pctype->data[pctype->size[1] - 1] != '\x00') {
        i4 = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1] + 1;
        emxEnsureCapacity((emxArray__common *)pctype0, i4, (int)sizeof(char));
        k = pctype->size[1];
        for (i4 = 0; i4 < k; i4++) {
          pctype0->data[pctype0->size[0] * i4] = pctype->data[pctype->size[0] *
            i4];
        }

        pctype0->data[pctype0->size[0] * pctype->size[1]] = '\x00';
      } else {
        i4 = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1];
        emxEnsureCapacity((emxArray__common *)pctype0, i4, (int)sizeof(char));
        k = pctype->size[0] * pctype->size[1];
        for (i4 = 0; i4 < k; i4++) {
          pctype0->data[i4] = pctype->data[i4];
        }
      }

      errCode = PCSetType(t_pc, &pctype0->data[0]);
      if (errCode != 0) {
        k = (M2C_DEBUG);
        if (k != 0) {
          ob_m2c_error(errCode);
        }
      }
    }

    if (b_p) {
      p = false;
      b_p = false;
      k = 0;
      do {
        exitg6 = 0;
        if (k < 2) {
          i4 = pcopt->size[k];
          if (i4 != 3 * k + 1) {
            exitg6 = 1;
          } else {
            k++;
          }
        } else {
          b_p = true;
          exitg6 = 1;
        }
      } while (exitg6 == 0);

      if (b_p && (!(pcopt->size[1] == 0))) {
        k = 0;
        exitg5 = false;
        while ((!exitg5) && (k < 4)) {
          if (!(pcopt->data[k] == cv9[k])) {
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

      if (p) {
        k = (PC_LEFT);
        errCode = KSPSetPCSide(t_ksp, k);
        if (errCode != 0) {
          k = (M2C_DEBUG);
          if (k != 0) {
            o_m2c_error(errCode);
          }
        }
      } else {
        p = false;
        b_p = false;
        k = 0;
        do {
          exitg4 = 0;
          if (k < 2) {
            i4 = pcopt->size[k];
            if (i4 != (k << 2) + 1) {
              exitg4 = 1;
            } else {
              k++;
            }
          } else {
            b_p = true;
            exitg4 = 1;
          }
        } while (exitg4 == 0);

        if (b_p && (!(pcopt->size[1] == 0))) {
          k = 0;
          exitg3 = false;
          while ((!exitg3) && (k < 5)) {
            if (!(pcopt->data[k] == cv10[k])) {
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

        if (p) {
          k = (PC_RIGHT);
          errCode = KSPSetPCSide(t_ksp, k);
          if (errCode != 0) {
            k = (M2C_DEBUG);
            if (k != 0) {
              o_m2c_error(errCode);
            }
          }
        } else {
          p = false;
          b_p = false;
          k = 0;
          do {
            exitg2 = 0;
            if (k < 2) {
              i4 = pcopt->size[k];
              if (i4 != (k << 3) + 1) {
                exitg2 = 1;
              } else {
                k++;
              }
            } else {
              b_p = true;
              exitg2 = 1;
            }
          } while (exitg2 == 0);

          if (b_p && (!(pcopt->size[1] == 0))) {
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 9)) {
              if (!(pcopt->data[k] == cv11[k])) {
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

          if (p) {
            k = (PC_SYMMETRIC);
            errCode = KSPSetPCSide(t_ksp, k);
            if (errCode != 0) {
              k = (M2C_DEBUG);
              if (k != 0) {
                o_m2c_error(errCode);
              }
            }
          } else {
            if (pcopt->data[pcopt->size[1] - 1] != '\x00') {
              i4 = pctype0->size[0] * pctype0->size[1];
              pctype0->size[0] = 1;
              pctype0->size[1] = pcopt->size[1] + 1;
              emxEnsureCapacity((emxArray__common *)pctype0, i4, (int)sizeof
                                (char));
              k = pcopt->size[1];
              for (i4 = 0; i4 < k; i4++) {
                pctype0->data[pctype0->size[0] * i4] = pcopt->data[pcopt->size[0]
                  * i4];
              }

              pctype0->data[pctype0->size[0] * pcopt->size[1]] = '\x00';
            } else {
              i4 = pctype0->size[0] * pctype0->size[1];
              pctype0->size[0] = 1;
              pctype0->size[1] = pcopt->size[1];
              emxEnsureCapacity((emxArray__common *)pctype0, i4, (int)sizeof
                                (char));
              k = pcopt->size[0] * pcopt->size[1];
              for (i4 = 0; i4 < k; i4++) {
                pctype0->data[i4] = pcopt->data[i4];
              }
            }

            errCode = PCFactorSetMatSolverPackage(t_pc, &pctype0->data[0]);
            if (errCode != 0) {
              k = (M2C_DEBUG);
              if (k != 0) {
                pb_m2c_error(errCode);
              }
            }
          }
        }
      }
    }
  }

  if ((!(ksptype->size[1] == 0)) && ((unsigned char)ksptype->data[ksptype->size
       [1] - 1] != 0)) {
    i4 = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)pctype0, i4, (int)sizeof(char));
    k = ksptype->size[1];
    for (i4 = 0; i4 < k; i4++) {
      pctype0->data[pctype0->size[0] * i4] = ksptype->data[ksptype->size[0] * i4];
    }

    pctype0->data[pctype0->size[0] * ksptype->size[1]] = '\x00';
  } else {
    i4 = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = ksptype->size[1];
    emxEnsureCapacity((emxArray__common *)pctype0, i4, (int)sizeof(char));
    k = ksptype->size[0] * ksptype->size[1];
    for (i4 = 0; i4 < k; i4++) {
      pctype0->data[i4] = ksptype->data[i4];
    }
  }

  if (!(pctype0->size[1] == 0)) {
    errCode = KSPSetType(t_ksp, &pctype0->data[0]);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        nb_m2c_error(errCode);
      }
    }
  }

  emxFree_char_T(&pctype0);
  if (pcopt->size[1] == 0) {
    k = (PC_RIGHT);
    errCode = KSPSetPCSide(t_ksp, k);
    if (errCode != 0) {
      k = (M2C_DEBUG);
      if (k != 0) {
        o_m2c_error(errCode);
      }
    }
  }

  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      p_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    k = (M2C_DEBUG);
    if (k != 0) {
      q_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  secs = MPI_Wtime();
  *time = secs - t;
  *ksp = t_ksp;
}

static void b_mptKSPSolve(KSP ksp, Vec b, Vec x, double rtol, int maxits, Vec x0,
  int *flag, double *relres, int *iter, emxArray_real_T *reshis, double *time)
{
  int val;
  double bnrm;
  int errCode;
  PetscObject t_obj;
  MPI_Comm t_comm;
  double t;
  int b_val;
  boolean_T b2;
  double secs;
  double res;
  double b_rtol;
  double abstol;
  double dtol;
  int b_maxits;
  emxArray_char_T *side;
  PC t_pc;
  PetscReal * a;
  int na;
  int b_side;
  static const char cv6[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  static const char cv7[4] = { 'l', 'e', 'f', 't' };

  static const char cv8[5] = { 'r', 'i', 'g', 'h', 't' };

  KSPType t_type;
  PCType b_t_type;
  val = (NORM_2);
  errCode = VecNorm(b, val, &bnrm);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      r_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      j_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  t = MPI_Wtime();
  if (maxits == 0) {
    maxits = (PETSC_DEFAULT);
  }

  if (rtol == 0.0) {
    val = (PETSC_DEFAULT);
    rtol = val;
  }

  val = (PETSC_DEFAULT);
  b_val = (PETSC_DEFAULT);
  errCode = KSPSetTolerances(ksp, rtol, (double)val, (double)b_val, maxits);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      s_m2c_error(errCode);
    }
  }

  val = !(x0);
  b2 = !(val != 0);
  if (b2) {
    errCode = VecCopy(x0, x);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        t_m2c_error(errCode);
      }
    }
  }

  val = (PETSC_TRUE);
  errCode = KSPSetResidualHistory(ksp, NULL, maxits, val);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      u_m2c_error(errCode);
    }
  }

  errCode = KSPSetInitialGuessNonzero(ksp, (int)b2);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      v_m2c_error(errCode);
    }
  }

  errCode = KSPSolve(ksp, b, x);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      w_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  secs = MPI_Wtime();
  *time = secs - t;
  errCode = KSPGetConvergedReason(ksp, flag);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      x_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(ksp, &res);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      y_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(ksp, iter);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      ab_m2c_error(errCode);
    }
  }

  *relres = res / bnrm;
  errCode = KSPGetTolerances(ksp, &b_rtol, &abstol, &dtol, &b_maxits);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      bb_m2c_error(errCode);
    }
  }

  emxInit_char_T(&side, 2);
  if ((*flag < 0) || (*relres > b_rtol)) {
    errCode = KSPGetPC(ksp, &t_pc);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        cb_m2c_error(errCode);
      }
    }

    errCode = KSPGetPCSide(ksp, &b_side);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        db_m2c_error(errCode);
      }
    }

    val = (PC_LEFT);
    b_val = (PC_RIGHT);
    if (val == b_side) {
      val = 0;
    } else if (b_val == b_side) {
      val = 1;
    } else {
      val = -1;
    }

    switch (val) {
     case 0:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 4; val++) {
        side->data[val] = cv7[val];
      }
      break;

     case 1:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 5; val++) {
        side->data[val] = cv8[val];
      }
      break;

     default:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 9; val++) {
        side->data[val] = cv6[val];
      }
      break;
    }

    errCode = KSPGetType(ksp, &t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        eb_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        fb_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, side, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(b_maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  errCode = KSPGetResidualHistory(ksp, &a, &na);
  val = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity((emxArray__common *)reshis, val, (int)sizeof(double));
  for (val = 0; val < na; val++) {
    reshis->data[val] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      gb_m2c_error(errCode);
    }
  }
}

static void bb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetTolerances returned error code %d\n",
            varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatAssemblyBegin returned error code %d\n",
            varargin_3);
}

static void c_m2c_printf(double varargin_2, double varargin_3)
{
  M2C_printf("### The relative and absolute tolerances were %g and %g.\n",
             varargin_2, varargin_3);
}

static void cb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetPC returned error code %d\n",
            varargin_3);
}

static void d_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatAssemblyEnd returned error code %d\n",
            varargin_3);
}

static void d_m2c_printf(int varargin_2, double varargin_3)
{
  M2C_printf("### The divergence and max-iter tolerances were %d and %g.\n",
             varargin_2, varargin_3);
}

static void db_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetPCSide returned error code %d\n",
            varargin_3);
}

static void e_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecCreateSeq returned error code %d\n",
            varargin_3);
}

static void e_m2c_printf(void)
{
  M2C_printf("### For explanation of the flag, see http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPConvergedReason.html.\n");
}

static void eb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetType returned error code %d\n",
            varargin_3);
}

static void emxFree_uint8_T(emxArray_uint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned char *)NULL) && (*pEmxArray)
        ->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_uint8_T *)NULL;
  }
}

static void emxInit_int32_T1(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions)
{
  emxArray_uint8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint8_T *)malloc(sizeof(emxArray_uint8_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void f_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecSetValues returned error code %d\n",
            varargin_3);
}

static void fb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCGetType returned error code %d\n",
            varargin_3);
}

static void g_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecAssemblyBegin returned error code %d\n",
            varargin_3);
}

static void gb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetResidualHistory returned error code %d\n", varargin_3);
}

static void h_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecAssemblyEnd returned error code %d\n",
            varargin_3);
}

static void hb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPDestroy returned error code %d\n",
            varargin_3);
}

static void i_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecDuplicate returned error code %d\n",
            varargin_3);
}

static void ib_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatDestroy returned error code %d\n",
            varargin_3);
}

static void j_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscObjectGetComm returned error code %d\n",
            varargin_3);
}

static void jb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecDestroy returned error code %d\n",
            varargin_3);
}

static void k_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPCreate returned error code %d\n",
            varargin_3);
}

static void kb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecGetLocalSize returned error code %d\n",
            varargin_3);
}

static void l_m2c_error(int varargin_3)
{
  M2C_error("MPI:RuntimeError", "MPI_Error_string with error code %d\n",
            varargin_3);
}

static void lb_m2c_error(void)
{
  M2C_error("runtime:Error", "Output array y is too small.");
}

static void m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatCreateSeqAIJ returned error code %d\n",
            varargin_3);
}

static void m2c_printf(KSPType varargin_2, PCType varargin_3, const
  emxArray_char_T *varargin_4, int varargin_5)
{
  emxArray_char_T *b_varargin_4;
  int i3;
  int loop_ub;
  emxInit_char_T(&b_varargin_4, 2);
  i3 = b_varargin_4->size[0] * b_varargin_4->size[1];
  b_varargin_4->size[0] = 1;
  b_varargin_4->size[1] = varargin_4->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_4, i3, (int)sizeof(char));
  loop_ub = varargin_4->size[0] * varargin_4->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_varargin_4->data[i3] = varargin_4->data[i3];
  }

  M2C_printf("### %s with %s as %s preconditioner stopped with flag %d.\n",
             varargin_2, varargin_3, &b_varargin_4->data[0], varargin_5);
  emxFree_char_T(&b_varargin_4);
}

static void m_m2c_error(const emxArray_char_T *varargin_3)
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

  M2C_error("MPI:RuntimeError", "MPI_Barrier failed with error message %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void mb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecGetValues returned error code %d\n",
            varargin_3);
}

static void mpi_Barrier(MPI_Comm comm)
{
  int info;
  emxArray_uint8_T *varargin_1;
  emxArray_char_T *b_varargin_1;
  int flag;
  unsigned char msg0[1024];
  char * ptr;
  int resultlen;
  int loop_ub;
  info = MPI_Barrier(comm);
  emxInit_uint8_T(&varargin_1, 2);
  emxInit_char_T(&b_varargin_1, 2);
  if (info != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      memset(&msg0[0], 0, sizeof(unsigned char) << 10);
      ptr = (char *)(msg0);
      resultlen = 0;
      info = MPI_Error_string(info, ptr, &resultlen);
      if (1 > resultlen) {
        loop_ub = 0;
      } else {
        loop_ub = resultlen;
      }

      flag = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = 1;
      varargin_1->size[1] = loop_ub;
      emxEnsureCapacity((emxArray__common *)varargin_1, flag, (int)sizeof
                        (unsigned char));
      for (flag = 0; flag < loop_ub; flag++) {
        varargin_1->data[varargin_1->size[0] * flag] = msg0[flag];
      }

      if (info != 0) {
        flag = (M2C_DEBUG);
        if (flag != 0) {
          l_m2c_error(info);
        }
      }

      flag = b_varargin_1->size[0] * b_varargin_1->size[1];
      b_varargin_1->size[0] = 1;
      b_varargin_1->size[1] = (short)loop_ub;
      emxEnsureCapacity((emxArray__common *)b_varargin_1, flag, (int)sizeof(char));
      loop_ub = (short)loop_ub;
      for (flag = 0; flag < loop_ub; flag++) {
        b_varargin_1->data[flag] = (signed char)varargin_1->data[flag];
      }

      m_m2c_error(b_varargin_1);
    }
  }

  emxFree_char_T(&b_varargin_1);
  emxFree_uint8_T(&varargin_1);
}

static void mptKSPSetup(Mat Amat, const emxArray_char_T *ksptype, KSP *ksp,
  double *time)
{
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  int flag;
  KSP t_ksp;
  double t;
  emxArray_char_T *ksptype0;
  int loop_ub;
  double secs;
  t_obj = (PetscObject)(Amat);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      j_m2c_error(errCode);
    }
  }

  errCode = KSPCreate(t_comm, &t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      k_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(t_ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      j_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  t = MPI_Wtime();
  errCode = KSPSetOperators(t_ksp, Amat, Amat);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      n_m2c_error(errCode);
    }
  }

  emxInit_char_T(&ksptype0, 2);
  if ((!(ksptype->size[1] == 0)) && ((unsigned char)ksptype->data[ksptype->size
       [1] - 1] != 0)) {
    flag = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)ksptype0, flag, (int)sizeof(char));
    loop_ub = ksptype->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      ksptype0->data[ksptype0->size[0] * flag] = ksptype->data[ksptype->size[0] *
        flag];
    }

    ksptype0->data[ksptype0->size[0] * ksptype->size[1]] = '\x00';
  } else {
    flag = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1];
    emxEnsureCapacity((emxArray__common *)ksptype0, flag, (int)sizeof(char));
    loop_ub = ksptype->size[0] * ksptype->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      ksptype0->data[flag] = ksptype->data[flag];
    }
  }

  if (!(ksptype0->size[1] == 0)) {
    errCode = KSPSetType(t_ksp, &ksptype0->data[0]);
    if (errCode != 0) {
      flag = (M2C_DEBUG);
      if (flag != 0) {
        nb_m2c_error(errCode);
      }
    }
  }

  emxFree_char_T(&ksptype0);
  flag = (PC_RIGHT);
  errCode = KSPSetPCSide(t_ksp, flag);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      o_m2c_error(errCode);
    }
  }

  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      p_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      q_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  secs = MPI_Wtime();
  *time = secs - t;
  *ksp = t_ksp;
}

static void mptKSPSolve(KSP ksp, Vec b, Vec x, Vec x0, int *flag, double *relres,
  int *iter, emxArray_real_T *reshis, double *time)
{
  int val;
  double bnrm;
  int errCode;
  int b_flag;
  PetscObject t_obj;
  MPI_Comm t_comm;
  double t;
  int maxits;
  int b_val;
  boolean_T b0;
  double secs;
  double res;
  double rtol;
  double abstol;
  double dtol;
  emxArray_char_T *side;
  PC t_pc;
  PetscReal * a;
  int na;
  int b_side;
  static const char cv0[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  static const char cv1[4] = { 'l', 'e', 'f', 't' };

  static const char cv2[5] = { 'r', 'i', 'g', 'h', 't' };

  KSPType t_type;
  PCType b_t_type;
  val = (NORM_2);
  errCode = VecNorm(b, val, &bnrm);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      r_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      j_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  t = MPI_Wtime();
  maxits = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  b_val = (PETSC_DEFAULT);
  b_flag = (PETSC_DEFAULT);
  errCode = KSPSetTolerances(ksp, (double)val, (double)b_val, (double)b_flag,
    maxits);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      s_m2c_error(errCode);
    }
  }

  b_flag = !(x0);
  b0 = !(b_flag != 0);
  if (b0) {
    errCode = VecCopy(x0, x);
    if (errCode != 0) {
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        t_m2c_error(errCode);
      }
    }
  }

  val = (PETSC_TRUE);
  errCode = KSPSetResidualHistory(ksp, NULL, maxits, val);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      u_m2c_error(errCode);
    }
  }

  errCode = KSPSetInitialGuessNonzero(ksp, (int)b0);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      v_m2c_error(errCode);
    }
  }

  errCode = KSPSolve(ksp, b, x);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      w_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  secs = MPI_Wtime();
  *time = secs - t;
  errCode = KSPGetConvergedReason(ksp, flag);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      x_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(ksp, &res);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      y_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(ksp, iter);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      ab_m2c_error(errCode);
    }
  }

  *relres = res / bnrm;
  errCode = KSPGetTolerances(ksp, &rtol, &abstol, &dtol, &maxits);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      bb_m2c_error(errCode);
    }
  }

  emxInit_char_T(&side, 2);
  if ((*flag < 0) || (*relres > rtol)) {
    errCode = KSPGetPC(ksp, &t_pc);
    if (errCode != 0) {
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        cb_m2c_error(errCode);
      }
    }

    errCode = KSPGetPCSide(ksp, &b_side);
    if (errCode != 0) {
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        db_m2c_error(errCode);
      }
    }

    val = (PC_LEFT);
    b_val = (PC_RIGHT);
    if (val == b_side) {
      b_flag = 0;
    } else if (b_val == b_side) {
      b_flag = 1;
    } else {
      b_flag = -1;
    }

    switch (b_flag) {
     case 0:
      b_flag = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity((emxArray__common *)side, b_flag, (int)sizeof(char));
      for (b_flag = 0; b_flag < 4; b_flag++) {
        side->data[b_flag] = cv1[b_flag];
      }
      break;

     case 1:
      b_flag = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity((emxArray__common *)side, b_flag, (int)sizeof(char));
      for (b_flag = 0; b_flag < 5; b_flag++) {
        side->data[b_flag] = cv2[b_flag];
      }
      break;

     default:
      b_flag = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity((emxArray__common *)side, b_flag, (int)sizeof(char));
      for (b_flag = 0; b_flag < 9; b_flag++) {
        side->data[b_flag] = cv0[b_flag];
      }
      break;
    }

    errCode = KSPGetType(ksp, &t_type);
    if (errCode != 0) {
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        eb_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        fb_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, side, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  errCode = KSPGetResidualHistory(ksp, &a, &na);
  b_flag = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity((emxArray__common *)reshis, b_flag, (int)sizeof(double));
  for (b_flag = 0; b_flag < na; b_flag++) {
    reshis->data[b_flag] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      gb_m2c_error(errCode);
    }
  }
}

static Mat mptMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val)
{
  emxArray_int32_T *nnz;
  int n;
  int i0;
  int i;
  int b_val;
  Mat t_mat;
  int errCode;
  emxArray_int32_T *jidx;
  emxArray_real_T *rowval;
  int i1;
  int type;
  int iroa;
  emxInit_int32_T(&nnz, 1);
  n = row_ptr->size[0] - 1;
  i0 = nnz->size[0];
  nnz->size[0] = n;
  emxEnsureCapacity((emxArray__common *)nnz, i0, (int)sizeof(int));
  for (i = 1; i <= n; i++) {
    nnz->data[i - 1] = row_ptr->data[i] - row_ptr->data[i - 1];
  }

  b_val = (PETSC_DEFAULT);
  errCode = MatCreateSeqAIJ(PETSC_COMM_SELF, n, n, b_val, &nnz->data[0], &t_mat);
  if (errCode != 0) {
    b_val = (M2C_DEBUG);
    if (b_val != 0) {
      m2c_error(errCode);
    }
  }

  i = 0;
  emxInit_int32_T(&jidx, 1);
  emxInit_real_T(&rowval, 1);
  while (i + 1 <= n) {
    i0 = row_ptr->data[i + 1] - 1;
    if (row_ptr->data[i] > i0) {
      i1 = 0;
      i0 = 0;
    } else {
      i1 = row_ptr->data[i] - 1;
    }

    b_val = jidx->size[0];
    jidx->size[0] = i0 - i1;
    emxEnsureCapacity((emxArray__common *)jidx, b_val, (int)sizeof(int));
    b_val = i0 - i1;
    for (i0 = 0; i0 < b_val; i0++) {
      jidx->data[i0] = col_ind->data[i1 + i0] - 1;
    }

    i0 = row_ptr->data[i + 1] - 1;
    if (row_ptr->data[i] > i0) {
      i1 = 0;
      i0 = 0;
    } else {
      i1 = row_ptr->data[i] - 1;
    }

    b_val = rowval->size[0];
    rowval->size[0] = i0 - i1;
    emxEnsureCapacity((emxArray__common *)rowval, b_val, (int)sizeof(double));
    b_val = i0 - i1;
    for (i0 = 0; i0 < b_val; i0++) {
      rowval->data[i0] = val->data[i1 + i0];
    }

    iroa = (INSERT_VALUES);
    errCode = MatSetValues(t_mat, 1, &i, nnz->data[i], &jidx->data[0],
      &rowval->data[0], iroa);
    if (errCode != 0) {
      b_val = (M2C_DEBUG);
      if (b_val != 0) {
        b_m2c_error(errCode);
      }
    }

    i++;
  }

  emxFree_real_T(&rowval);
  emxFree_int32_T(&jidx);
  emxFree_int32_T(&nnz);
  type = (MAT_FINAL_ASSEMBLY);
  errCode = MatAssemblyBegin(t_mat, type);
  if (errCode != 0) {
    b_val = (M2C_DEBUG);
    if (b_val != 0) {
      c_m2c_error(errCode);
    }
  }

  type = (MAT_FINAL_ASSEMBLY);
  errCode = MatAssemblyEnd(t_mat, type);
  if (errCode != 0) {
    b_val = (M2C_DEBUG);
    if (b_val != 0) {
      d_m2c_error(errCode);
    }
  }

  return t_mat;
}

static void mptSolve(Mat A, Vec b, Vec x, const emxArray_char_T *solver, double
                     rtol, int maxit, const emxArray_char_T *pctype, const
                     emxArray_char_T *pcopt, Vec x0, int *flag, double *relres,
                     int *iter, emxArray_real_T *reshis, double times[2])
{
  KSP ksp;
  double time_setup;
  double time_solve;
  KSP t_ksp;
  int errCode;
  int b_flag;
  b_mptKSPSetup(A, solver, pctype, pcopt, &ksp, &time_setup);
  b_mptKSPSolve(ksp, b, x, rtol, maxit, x0, flag, relres, iter, reshis,
                &time_solve);
  times[0] = time_setup;
  times[1] = time_solve;
  t_ksp = ksp;
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      hb_m2c_error(errCode);
    }
  }
}

static Vec mptVecCreateFromArray(const emxArray_real_T *arr)
{
  int n;
  Vec t_vec;
  int errCode;
  int yk;
  int b_n;
  emxArray_int32_T *y;
  int k;
  emxArray_int32_T *idx;
  int iroa;
  n = arr->size[0];
  errCode = VecCreateSeq(PETSC_COMM_SELF, n, &t_vec);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      e_m2c_error(errCode);
    }
  }

  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }

  emxInit_int32_T1(&y, 2);
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(int));
  if (b_n > 0) {
    y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)idx, k, (int)sizeof(int));
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx->data[k] = y->data[y->size[0] * k];
  }

  emxFree_int32_T(&y);
  iroa = (INSERT_VALUES);
  errCode = VecSetValues(t_vec, n, &idx->data[0], &arr->data[0], iroa);
  emxFree_int32_T(&idx);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      f_m2c_error(errCode);
    }
  }

  errCode = VecAssemblyBegin(t_vec);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      g_m2c_error(errCode);
    }
  }

  errCode = VecAssemblyEnd(t_vec);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      h_m2c_error(errCode);
    }
  }

  return t_vec;
}

static void mptVecToArray(Vec vec, emxArray_real_T *arr)
{
  int n;
  int errCode;
  int yk;
  int k;
  int b_n;
  emxArray_int32_T *y;
  emxArray_int32_T *idx;
  errCode = VecGetLocalSize(vec, &n);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      kb_m2c_error(errCode);
    }
  }

  k = arr->size[0];
  arr->size[0] = n;
  emxEnsureCapacity((emxArray__common *)arr, k, (int)sizeof(double));
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }

  emxInit_int32_T1(&y, 2);
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(int));
  if (b_n > 0) {
    y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)idx, k, (int)sizeof(int));
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx->data[k] = y->data[y->size[0] * k];
  }

  emxFree_int32_T(&y);
  if (arr->size[0] < n) {
    lb_m2c_error();
  }

  errCode = VecGetValues(vec, n, &idx->data[0], &arr->data[0]);
  emxFree_int32_T(&idx);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      mb_m2c_error(errCode);
    }
  }
}

static void n_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetOperators returned error code %d\n",
            varargin_3);
}

static void nb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetType returned error code %d\n",
            varargin_3);
}

static void o_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetPCSide returned error code %d\n",
            varargin_3);
}

static void ob_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCSetType returned error code %d\n",
            varargin_3);
}

static void p_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetFromOptions returned error code %d\n",
            varargin_3);
}

static void pb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "petscPCFactorSetMatSolverPackage returned error code %d\n",
            varargin_3);
}

static void q_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetUp returned error code %d\n",
            varargin_3);
}

static void qb_m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsInsertString:InputError",
            "The argument must be a null-terminated string.");
}

static void r_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecNorm returned error code %d\n", varargin_3);
}

static void rb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "PetscOptionsInsertString returned error code %d\n", varargin_3);
}

static void s_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetTolerances returned error code %d\n",
            varargin_3);
}

static void t_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecCopy returned error code %d\n", varargin_3);
}

static void u_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "petscKSPSetResidualHistory returned error code %d\n", varargin_3);
}

static void v_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPSetInitialGuessNonzero returned error code %d\n", varargin_3);
}

static void w_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSolve returned error code %d\n",
            varargin_3);
}

static void x_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetConvergedReason returned error code %d\n", varargin_3);
}

static void y_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetResidualNorm returned error code %d\n",
            varargin_3);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

void mptSolveCRS(int *flag, double *relres, int *iter, double times[2])
{
  int i;
  *flag = -1;
  *relres = 1.7976931348623157E+308;
  *iter = 0;
  for (i = 0; i < 2; i++) {
    times[i] = 0.0;
  }
}

void mptSolveCRS_10args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, const emxArray_real_T *x0,
  emxArray_real_T *x, int *flag, double *relres, int *iter, emxArray_real_T
  *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec x0Vec;
  Vec xVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  double b_relres;
  int b_iter;
  Mat t_mat;
  int c_flag;
  Vec t_vec;
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = mptVecCreateFromArray(b);
  if (x0->size[0] == 0) {
    x0Vec = NULL;
    errCode = VecDuplicate(bVec, &t_vec_out);
    xVec = t_vec_out;
    if (errCode != 0) {
      c_flag = (M2C_DEBUG);
      if (c_flag != 0) {
        i_m2c_error(errCode);
      }
    }
  } else {
    x0Vec = mptVecCreateFromArray(x0);
    xVec = x0Vec;
  }

  mptSolve(AMat, bVec, xVec, solver, rtol, maxiter, pctype, solpack, x0Vec,
           &b_flag, &b_relres, &b_iter, reshis, times);
  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      ib_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  mptVecToArray(xVec, x);
  t_vec = xVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
}

void mptSolveCRS_11args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, const emxArray_real_T *x0, const
  emxArray_char_T *opts, emxArray_real_T *x, int *flag, double *relres, int
  *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec x0Vec;
  Vec xVec;
  Vec t_vec_out;
  int errCode;
  emxArray_char_T *b_opts;
  KSP ksp;
  double time_setup;
  int b_flag;
  int c_flag;
  double b_relres;
  int b_iter;
  double time_solve;
  KSP t_ksp;
  int loop_ub;
  Mat t_mat;
  Vec t_vec;
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = mptVecCreateFromArray(b);
  if (x0->size[0] == 0) {
    x0Vec = NULL;
    errCode = VecDuplicate(bVec, &t_vec_out);
    xVec = t_vec_out;
    if (errCode != 0) {
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        i_m2c_error(errCode);
      }
    }
  } else {
    x0Vec = mptVecCreateFromArray(x0);
    xVec = x0Vec;
  }

  if (!(opts->size[1] == 0)) {
    emxInit_char_T(&b_opts, 2);
    b_flag = b_opts->size[0] * b_opts->size[1];
    b_opts->size[0] = 1;
    b_opts->size[1] = opts->size[1];
    emxEnsureCapacity((emxArray__common *)b_opts, b_flag, (int)sizeof(char));
    loop_ub = opts->size[0] * opts->size[1];
    for (b_flag = 0; b_flag < loop_ub; b_flag++) {
      b_opts->data[b_flag] = opts->data[b_flag];
    }

    if (opts->data[opts->size[1] - 1] != '\x00') {
      b_flag = b_opts->size[0] * b_opts->size[1];
      b_opts->size[0] = 1;
      b_opts->size[1] = opts->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_opts, b_flag, (int)sizeof(char));
      loop_ub = opts->size[1];
      for (b_flag = 0; b_flag < loop_ub; b_flag++) {
        b_opts->data[b_opts->size[0] * b_flag] = opts->data[opts->size[0] *
          b_flag];
      }

      b_opts->data[b_opts->size[0] * opts->size[1]] = '\x00';
    }

    if (b_opts->data[b_opts->size[1] - 1] != '\x00') {
      qb_m2c_error();
    }

    errCode = PetscOptionsInsertString(NULL, &b_opts->data[0]);
    emxFree_char_T(&b_opts);
    if (errCode != 0) {
      rb_m2c_error(errCode);
    }
  }

  b_mptKSPSetup(AMat, solver, pctype, solpack, &ksp, &time_setup);
  b_mptKSPSolve(ksp, bVec, xVec, rtol, maxiter, x0Vec, &c_flag, &b_relres,
                &b_iter, reshis, &time_solve);
  t_ksp = ksp;
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      hb_m2c_error(errCode);
    }
  }

  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      ib_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  mptVecToArray(xVec, x);
  t_vec = xVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  *flag = c_flag;
  *relres = b_relres;
  *iter = b_iter;
  times[0] = time_setup;
  times[1] = time_solve;
}

void mptSolveCRS_4args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b,
  emxArray_real_T *x, int *flag, double *relres, int *iter, emxArray_real_T
  *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  PetscObject t_obj;
  MPI_Comm t_comm;
  KSP t_ksp;
  double t;
  double secs;
  int c_flag;
  double b_relres;
  int b_iter;
  double time_solve;
  Mat t_mat;
  Vec t_vec;
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = mptVecCreateFromArray(b);
  errCode = VecDuplicate(bVec, &t_vec_out);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      i_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(AMat);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      j_m2c_error(errCode);
    }
  }

  errCode = KSPCreate(t_comm, &t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      k_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(t_ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      j_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  t = MPI_Wtime();
  errCode = KSPSetOperators(t_ksp, AMat, AMat);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      n_m2c_error(errCode);
    }
  }

  b_flag = (PC_RIGHT);
  errCode = KSPSetPCSide(t_ksp, b_flag);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      o_m2c_error(errCode);
    }
  }

  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      p_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      q_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  secs = MPI_Wtime();
  mptKSPSolve(t_ksp, bVec, t_vec_out, NULL, &c_flag, &b_relres, &b_iter, reshis,
              &time_solve);
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      hb_m2c_error(errCode);
    }
  }

  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      ib_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  mptVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  *flag = c_flag;
  *relres = b_relres;
  *iter = b_iter;
  times[0] = secs - t;
  times[1] = time_solve;
}

void mptSolveCRS_5args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, emxArray_real_T *x, int *flag, double *relres, int
  *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  KSP ksp;
  double time_setup;
  int c_flag;
  double b_relres;
  int b_iter;
  double time_solve;
  KSP t_ksp;
  Mat t_mat;
  Vec t_vec;
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = mptVecCreateFromArray(b);
  errCode = VecDuplicate(bVec, &t_vec_out);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      i_m2c_error(errCode);
    }
  }

  mptKSPSetup(AMat, solver, &ksp, &time_setup);
  mptKSPSolve(ksp, bVec, t_vec_out, NULL, &c_flag, &b_relres, &b_iter, reshis,
              &time_solve);
  t_ksp = ksp;
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      hb_m2c_error(errCode);
    }
  }

  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      ib_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  mptVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  *flag = c_flag;
  *relres = b_relres;
  *iter = b_iter;
  times[0] = time_setup;
  times[1] = time_solve;
}

void mptSolveCRS_6args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, emxArray_real_T *x, int *flag, double
  *relres, int *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec obj;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  KSP ksp;
  double time_setup;
  double b_rtol;
  int val;
  double bnrm;
  PetscObject t_obj;
  MPI_Comm t_comm;
  double t;
  int maxits;
  int b_val;
  boolean_T b1;
  double secs;
  double res;
  int b_iter;
  double b_relres;
  double abstol;
  double dtol;
  emxArray_char_T *side;
  PC t_pc;
  PetscReal * a;
  int na;
  int b_side;
  KSP t_ksp;
  Mat t_mat;
  static const char cv3[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  static const char cv4[4] = { 'l', 'e', 'f', 't' };

  static const char cv5[5] = { 'r', 'i', 'g', 'h', 't' };

  Vec t_vec;
  KSPType t_type;
  PCType b_t_type;
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = mptVecCreateFromArray(b);
  obj = NULL;
  errCode = VecDuplicate(bVec, &t_vec_out);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      i_m2c_error(errCode);
    }
  }

  mptKSPSetup(AMat, solver, &ksp, &time_setup);
  b_rtol = rtol;
  val = (NORM_2);
  errCode = VecNorm(bVec, val, &bnrm);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      r_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      j_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  t = MPI_Wtime();
  maxits = (PETSC_DEFAULT);
  if (rtol == 0.0) {
    val = (PETSC_DEFAULT);
    b_rtol = val;
  }

  val = (PETSC_DEFAULT);
  b_val = (PETSC_DEFAULT);
  errCode = KSPSetTolerances(ksp, b_rtol, (double)val, (double)b_val, maxits);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      s_m2c_error(errCode);
    }
  }

  val = !(obj);
  b1 = !(val != 0);
  if (b1) {
    errCode = VecCopy(obj, t_vec_out);
    if (errCode != 0) {
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        t_m2c_error(errCode);
      }
    }
  }

  val = (PETSC_TRUE);
  errCode = KSPSetResidualHistory(ksp, NULL, maxits, val);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      u_m2c_error(errCode);
    }
  }

  errCode = KSPSetInitialGuessNonzero(ksp, (int)b1);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      v_m2c_error(errCode);
    }
  }

  errCode = KSPSolve(ksp, bVec, t_vec_out);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      w_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  secs = MPI_Wtime();
  errCode = KSPGetConvergedReason(ksp, &b_flag);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      x_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(ksp, &res);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      y_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(ksp, &b_iter);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      ab_m2c_error(errCode);
    }
  }

  b_relres = res / bnrm;
  errCode = KSPGetTolerances(ksp, &b_rtol, &abstol, &dtol, &maxits);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      bb_m2c_error(errCode);
    }
  }

  emxInit_char_T(&side, 2);
  if ((b_flag < 0) || (b_relres > b_rtol)) {
    errCode = KSPGetPC(ksp, &t_pc);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        cb_m2c_error(errCode);
      }
    }

    errCode = KSPGetPCSide(ksp, &b_side);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        db_m2c_error(errCode);
      }
    }

    val = (PC_LEFT);
    b_val = (PC_RIGHT);
    if (val == b_side) {
      val = 0;
    } else if (b_val == b_side) {
      val = 1;
    } else {
      val = -1;
    }

    switch (val) {
     case 0:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 4; val++) {
        side->data[val] = cv4[val];
      }
      break;

     case 1:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 5; val++) {
        side->data[val] = cv5[val];
      }
      break;

     default:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity((emxArray__common *)side, val, (int)sizeof(char));
      for (val = 0; val < 9; val++) {
        side->data[val] = cv3[val];
      }
      break;
    }

    errCode = KSPGetType(ksp, &t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        eb_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        fb_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, side, b_flag);
    b_m2c_printf(b_relres, b_iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  errCode = KSPGetResidualHistory(ksp, &a, &na);
  val = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity((emxArray__common *)reshis, val, (int)sizeof(double));
  for (val = 0; val < na; val++) {
    reshis->data[val] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      gb_m2c_error(errCode);
    }
  }

  t_ksp = ksp;
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      hb_m2c_error(errCode);
    }
  }

  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      ib_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      jb_m2c_error(errCode);
    }
  }

  mptVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      jb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
  times[0] = time_setup;
  times[1] = secs - t;
}

void mptSolveCRS_7args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, emxArray_real_T *x, int
  *flag, double *relres, int *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  KSP ksp;
  double time_setup;
  int c_flag;
  double b_relres;
  int b_iter;
  double time_solve;
  KSP t_ksp;
  Mat t_mat;
  Vec t_vec;
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = mptVecCreateFromArray(b);
  errCode = VecDuplicate(bVec, &t_vec_out);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      i_m2c_error(errCode);
    }
  }

  mptKSPSetup(AMat, solver, &ksp, &time_setup);
  b_mptKSPSolve(ksp, bVec, t_vec_out, rtol, maxiter, NULL, &c_flag, &b_relres,
                &b_iter, reshis, &time_solve);
  t_ksp = ksp;
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      hb_m2c_error(errCode);
    }
  }

  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      ib_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  mptVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  *flag = c_flag;
  *relres = b_relres;
  *iter = b_iter;
  times[0] = time_setup;
  times[1] = time_solve;
}

void mptSolveCRS_8args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, emxArray_real_T *x, int *flag, double *relres, int *iter,
  emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  PetscObject t_obj;
  MPI_Comm t_comm;
  KSP t_ksp;
  double t;
  boolean_T b3;
  emxArray_char_T *pctype0;
  PC t_pc;
  int loop_ub;
  double secs;
  int c_flag;
  double b_relres;
  int b_iter;
  double time_solve;
  Mat t_mat;
  Vec t_vec;
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = mptVecCreateFromArray(b);
  errCode = VecDuplicate(bVec, &t_vec_out);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      i_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(AMat);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      j_m2c_error(errCode);
    }
  }

  errCode = KSPCreate(t_comm, &t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      k_m2c_error(errCode);
    }
  }

  t_obj = (PetscObject)(t_ksp);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      j_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  t = MPI_Wtime();
  errCode = KSPSetOperators(t_ksp, AMat, AMat);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      n_m2c_error(errCode);
    }
  }

  b3 = !(pctype->size[1] == 0);
  emxInit_char_T(&pctype0, 2);
  if (b3) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        cb_m2c_error(errCode);
      }
    }

    if (pctype->data[pctype->size[1] - 1] != '\x00') {
      b_flag = pctype0->size[0] * pctype0->size[1];
      pctype0->size[0] = 1;
      pctype0->size[1] = pctype->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)pctype0, b_flag, (int)sizeof(char));
      loop_ub = pctype->size[1];
      for (b_flag = 0; b_flag < loop_ub; b_flag++) {
        pctype0->data[pctype0->size[0] * b_flag] = pctype->data[pctype->size[0] *
          b_flag];
      }

      pctype0->data[pctype0->size[0] * pctype->size[1]] = '\x00';
    } else {
      b_flag = pctype0->size[0] * pctype0->size[1];
      pctype0->size[0] = 1;
      pctype0->size[1] = pctype->size[1];
      emxEnsureCapacity((emxArray__common *)pctype0, b_flag, (int)sizeof(char));
      loop_ub = pctype->size[0] * pctype->size[1];
      for (b_flag = 0; b_flag < loop_ub; b_flag++) {
        pctype0->data[b_flag] = pctype->data[b_flag];
      }
    }

    errCode = PCSetType(t_pc, &pctype0->data[0]);
    if (errCode != 0) {
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        ob_m2c_error(errCode);
      }
    }
  }

  if ((!(solver->size[1] == 0)) && ((unsigned char)solver->data[solver->size[1]
       - 1] != 0)) {
    b_flag = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = solver->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)pctype0, b_flag, (int)sizeof(char));
    loop_ub = solver->size[1];
    for (b_flag = 0; b_flag < loop_ub; b_flag++) {
      pctype0->data[pctype0->size[0] * b_flag] = solver->data[solver->size[0] *
        b_flag];
    }

    pctype0->data[pctype0->size[0] * solver->size[1]] = '\x00';
  } else {
    b_flag = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = solver->size[1];
    emxEnsureCapacity((emxArray__common *)pctype0, b_flag, (int)sizeof(char));
    loop_ub = solver->size[0] * solver->size[1];
    for (b_flag = 0; b_flag < loop_ub; b_flag++) {
      pctype0->data[b_flag] = solver->data[b_flag];
    }
  }

  if (!(pctype0->size[1] == 0)) {
    errCode = KSPSetType(t_ksp, &pctype0->data[0]);
    if (errCode != 0) {
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        nb_m2c_error(errCode);
      }
    }
  }

  emxFree_char_T(&pctype0);
  b_flag = (PC_RIGHT);
  errCode = KSPSetPCSide(t_ksp, b_flag);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      o_m2c_error(errCode);
    }
  }

  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      p_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      q_m2c_error(errCode);
    }
  }

  mpi_Barrier(t_comm);
  secs = MPI_Wtime();
  b_mptKSPSolve(t_ksp, bVec, t_vec_out, rtol, maxiter, NULL, &c_flag, &b_relres,
                &b_iter, reshis, &time_solve);
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      hb_m2c_error(errCode);
    }
  }

  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      ib_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  mptVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  *flag = c_flag;
  *relres = b_relres;
  *iter = b_iter;
  times[0] = secs - t;
  times[1] = time_solve;
}

void mptSolveCRS_9args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, emxArray_real_T *x, int *flag, double
  *relres, int *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  int c_flag;
  double b_relres;
  int b_iter;
  Mat t_mat;
  Vec t_vec;
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = mptVecCreateFromArray(b);
  errCode = VecDuplicate(bVec, &t_vec_out);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      i_m2c_error(errCode);
    }
  }

  mptSolve(AMat, bVec, t_vec_out, solver, rtol, maxiter, pctype, solpack, NULL,
           &c_flag, &b_relres, &b_iter, reshis, times);
  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      ib_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  mptVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      jb_m2c_error(errCode);
    }
  }

  *flag = c_flag;
  *relres = b_relres;
  *iter = b_iter;
}

void mptSolveCRS_initialize(void)
{
}

void mptSolveCRS_terminate(void)
{
}
