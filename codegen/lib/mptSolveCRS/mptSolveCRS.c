#include "mptSolveCRS.h"
#include "petscksp.h"
#include "petscsys.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

static void ab_m2c_error(int varargin_3);
static void b_m2c_error(int varargin_3);
static void b_m2c_printf(double varargin_2, int varargin_3);
static void bb_m2c_error(int varargin_3);
static void c_m2c_error(int varargin_3);
static void c_m2c_printf(double varargin_2, double varargin_3);
static void cb_m2c_error(int varargin_3);
static void d_m2c_error(int varargin_3);
static void d_m2c_printf(int varargin_2, double varargin_3);
static void db_m2c_error(int varargin_3);
static void e_m2c_error(int varargin_3);
static void e_m2c_printf(void);
static void eb_m2c_error(void);
static void emxInit_int32_T1(emxArray_int32_T **pEmxArray, int numDimensions);
static void f_m2c_error(int varargin_3);
static void fb_m2c_error(int varargin_3);
static void g_m2c_error(int varargin_3);
static void gb_m2c_error(int varargin_3);
static void h_m2c_error(int varargin_3);
static void hb_m2c_error(int varargin_3);
static void i_m2c_error(int varargin_3);
static void ib_m2c_error(int varargin_3);
static void j_m2c_error(int varargin_3);
static void jb_m2c_error(void);
static void k_m2c_error(int varargin_3);
static void kb_m2c_error(int varargin_3);
static void l_m2c_error(int varargin_3);
static void m2c_error(int varargin_3);
static void m2c_printf(KSPType varargin_2, PCType varargin_3, int varargin_4);
static void m_m2c_error(int varargin_3);
static KSP mptKSPSetup(Mat Amat, const emxArray_char_T *ksptype, const
  emxArray_char_T *pctype, const emxArray_char_T *solpack);
static void mptKSPSolve(KSP ksp, Vec b, Vec x, double rtol, int maxits, Vec x0,
  int *flag, double *relres, int *iter);
static Mat mptMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val);
static void mptSolve(Mat A, Vec b, Vec x, const emxArray_char_T *solver, double
                     rtol, int maxit, Vec x0, int *flag, double *relres, int
                     *iter);
static Vec mptVecCreateFromArray(const emxArray_real_T *arr);
static void mptVecToArray(Vec vec, emxArray_real_T *arr);
static void n_m2c_error(int varargin_3);
static void o_m2c_error(int varargin_3);
static void p_m2c_error(int varargin_3);
static void q_m2c_error(int varargin_3);
static void r_m2c_error(int varargin_3);
static void s_m2c_error(int varargin_3);
static void t_m2c_error(int varargin_3);
static void u_m2c_error(int varargin_3);
static void v_m2c_error(int varargin_3);
static void w_m2c_error(int varargin_3);
static void x_m2c_error(int varargin_3);
static void y_m2c_error(int varargin_3);
static void ab_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPDestroy returned error code %d\n",
            varargin_3);
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

static void bb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatDestroy returned error code %d\n",
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
  M2C_error("petsc:RuntimeError", "VecDestroy returned error code %d\n",
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
  M2C_error("petsc:RuntimeError", "VecGetLocalSize returned error code %d\n",
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

static void eb_m2c_error(void)
{
  M2C_error("runtime:Error", "Output array y is too small.");
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

static void f_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecSetValues returned error code %d\n",
            varargin_3);
}

static void fb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecGetValues returned error code %d\n",
            varargin_3);
}

static void g_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecAssemblyBegin returned error code %d\n",
            varargin_3);
}

static void gb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetType returned error code %d\n",
            varargin_3);
}

static void h_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecAssemblyEnd returned error code %d\n",
            varargin_3);
}

static void hb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCSetType returned error code %d\n",
            varargin_3);
}

static void i_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecDuplicate returned error code %d\n",
            varargin_3);
}

static void ib_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "petscPCFactorSetMatSolverPackage returned error code %d\n",
            varargin_3);
}

static void j_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PetscObjectGetComm returned error code %d\n",
            varargin_3);
}

static void jb_m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsInsertString:InputError",
            "The argument must be a null-terminated string.");
}

static void k_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPCreate returned error code %d\n",
            varargin_3);
}

static void kb_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "PetscOptionsInsertString returned error code %d\n", varargin_3);
}

static void l_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetOperators returned error code %d\n",
            varargin_3);
}

static void m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "MatCreateSeqAIJ returned error code %d\n",
            varargin_3);
}

static void m2c_printf(KSPType varargin_2, PCType varargin_3, int varargin_4)
{
  M2C_printf("### %s with %s preconditioner stopped with flag %d.\n", varargin_2,
             varargin_3, varargin_4);
}

static void m_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetFromOptions returned error code %d\n",
            varargin_3);
}

static KSP mptKSPSetup(Mat Amat, const emxArray_char_T *ksptype, const
  emxArray_char_T *pctype, const emxArray_char_T *solpack)
{
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  int flag;
  KSP t_ksp;
  boolean_T b1;
  boolean_T b2;
  emxArray_char_T *pctype0;
  PC t_pc;
  int loop_ub;
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

  errCode = KSPSetOperators(t_ksp, Amat, Amat);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      l_m2c_error(errCode);
    }
  }

  b1 = !(pctype->size[1] == 0);
  b2 = !(solpack->size[1] == 0);
  emxInit_char_T(&pctype0, 2);
  if (b1 || b2) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      flag = (M2C_DEBUG);
      if (flag != 0) {
        w_m2c_error(errCode);
      }
    }

    if (b1) {
      if (pctype->data[pctype->size[1] - 1] != '\x00') {
        flag = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1] + 1;
        emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
        loop_ub = pctype->size[1];
        for (flag = 0; flag < loop_ub; flag++) {
          pctype0->data[pctype0->size[0] * flag] = pctype->data[pctype->size[0] *
            flag];
        }

        pctype0->data[pctype0->size[0] * pctype->size[1]] = '\x00';
      } else {
        flag = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1];
        emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
        loop_ub = pctype->size[0] * pctype->size[1];
        for (flag = 0; flag < loop_ub; flag++) {
          pctype0->data[flag] = pctype->data[flag];
        }
      }

      errCode = PCSetType(t_pc, &pctype0->data[0]);
      if (errCode != 0) {
        flag = (M2C_DEBUG);
        if (flag != 0) {
          hb_m2c_error(errCode);
        }
      }
    }

    if (b2) {
      if (solpack->data[solpack->size[1] - 1] != '\x00') {
        flag = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = solpack->size[1] + 1;
        emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
        loop_ub = solpack->size[1];
        for (flag = 0; flag < loop_ub; flag++) {
          pctype0->data[pctype0->size[0] * flag] = solpack->data[solpack->size[0]
            * flag];
        }

        pctype0->data[pctype0->size[0] * solpack->size[1]] = '\x00';
      } else {
        flag = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = solpack->size[1];
        emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
        loop_ub = solpack->size[0] * solpack->size[1];
        for (flag = 0; flag < loop_ub; flag++) {
          pctype0->data[flag] = solpack->data[flag];
        }
      }

      errCode = PCFactorSetMatSolverPackage(t_pc, &pctype0->data[0]);
      if (errCode != 0) {
        flag = (M2C_DEBUG);
        if (flag != 0) {
          ib_m2c_error(errCode);
        }
      }
    }
  }

  if ((!(ksptype->size[1] == 0)) && ((unsigned char)ksptype->data[ksptype->size
       [1] - 1] != 0)) {
    flag = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
    loop_ub = ksptype->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      pctype0->data[pctype0->size[0] * flag] = ksptype->data[ksptype->size[0] *
        flag];
    }

    pctype0->data[pctype0->size[0] * ksptype->size[1]] = '\x00';
  } else {
    flag = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = ksptype->size[1];
    emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
    loop_ub = ksptype->size[0] * ksptype->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      pctype0->data[flag] = ksptype->data[flag];
    }
  }

  if (!(pctype0->size[1] == 0)) {
    errCode = KSPSetType(t_ksp, &pctype0->data[0]);
    if (errCode != 0) {
      flag = (M2C_DEBUG);
      if (flag != 0) {
        gb_m2c_error(errCode);
      }
    }
  }

  emxFree_char_T(&pctype0);
  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      m_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    flag = (M2C_DEBUG);
    if (flag != 0) {
      n_m2c_error(errCode);
    }
  }

  return t_ksp;
}

static void mptKSPSolve(KSP ksp, Vec b, Vec x, double rtol, int maxits, Vec x0,
  int *flag, double *relres, int *iter)
{
  int val;
  int b_val;
  int errCode;
  double b_rtol;
  double abstol;
  double dtol;
  int b_maxits;
  PC t_pc;
  KSPType t_type;
  PCType b_t_type;
  if (rtol == 0.0) {
    val = (PETSC_DEFAULT);
    rtol = val;
  }

  if (maxits == 0) {
    maxits = (PETSC_DEFAULT);
  }

  val = (PETSC_DEFAULT);
  b_val = (PETSC_DEFAULT);
  errCode = KSPSetTolerances(ksp, rtol, (double)val, (double)b_val, maxits);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      o_m2c_error(errCode);
    }
  }

  val = !(x0);
  if (!(val != 0)) {
    errCode = VecCopy(x0, x);
    if (errCode != 0) {
      *flag = (M2C_DEBUG);
      if (*flag != 0) {
        p_m2c_error(errCode);
      }
    }

    val = (PETSC_TRUE);
    errCode = KSPSetInitialGuessNonzero(ksp, val);
    if (errCode != 0) {
      *flag = (M2C_DEBUG);
      if (*flag != 0) {
        q_m2c_error(errCode);
      }
    }
  } else {
    val = (PETSC_FALSE);
    errCode = KSPSetInitialGuessNonzero(ksp, val);
    if (errCode != 0) {
      *flag = (M2C_DEBUG);
      if (*flag != 0) {
        q_m2c_error(errCode);
      }
    }
  }

  errCode = KSPSolve(ksp, b, x);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      r_m2c_error(errCode);
    }
  }

  errCode = KSPGetConvergedReason(ksp, flag);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      s_m2c_error(errCode);
    }
  }

  errCode = KSPGetResidualNorm(ksp, relres);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      t_m2c_error(errCode);
    }
  }

  errCode = KSPGetIterationNumber(ksp, iter);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      u_m2c_error(errCode);
    }
  }

  errCode = KSPGetTolerances(ksp, &b_rtol, &abstol, &dtol, &b_maxits);
  if (errCode != 0) {
    val = (M2C_DEBUG);
    if (val != 0) {
      v_m2c_error(errCode);
    }
  }

  if ((*flag < 0) || (*relres > b_rtol)) {
    errCode = KSPGetPC(ksp, &t_pc);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        w_m2c_error(errCode);
      }
    }

    errCode = KSPGetType(ksp, &t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        x_m2c_error(errCode);
      }
    }

    errCode = PCGetType(t_pc, &b_t_type);
    if (errCode != 0) {
      val = (M2C_DEBUG);
      if (val != 0) {
        y_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(b_maxits, dtol);
    e_m2c_printf();
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
                     rtol, int maxit, Vec x0, int *flag, double *relres, int
                     *iter)
{
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  KSP t_ksp;
  emxArray_char_T *ksptype0;
  int b_flag;
  int loop_ub;
  t_obj = (PetscObject)(A);
  errCode = PetscObjectGetComm(t_obj, &t_comm);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      j_m2c_error(errCode);
    }
  }

  errCode = KSPCreate(t_comm, &t_ksp);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      k_m2c_error(errCode);
    }
  }

  errCode = KSPSetOperators(t_ksp, A, A);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      l_m2c_error(errCode);
    }
  }

  emxInit_char_T(&ksptype0, 2);
  if ((!(solver->size[1] == 0)) && ((unsigned char)solver->data[solver->size[1]
       - 1] != 0)) {
    b_flag = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = solver->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)ksptype0, b_flag, (int)sizeof(char));
    loop_ub = solver->size[1];
    for (b_flag = 0; b_flag < loop_ub; b_flag++) {
      ksptype0->data[ksptype0->size[0] * b_flag] = solver->data[solver->size[0] *
        b_flag];
    }

    ksptype0->data[ksptype0->size[0] * solver->size[1]] = '\x00';
  } else {
    b_flag = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = solver->size[1];
    emxEnsureCapacity((emxArray__common *)ksptype0, b_flag, (int)sizeof(char));
    loop_ub = solver->size[0] * solver->size[1];
    for (b_flag = 0; b_flag < loop_ub; b_flag++) {
      ksptype0->data[b_flag] = solver->data[b_flag];
    }
  }

  if (!(ksptype0->size[1] == 0)) {
    errCode = KSPSetType(t_ksp, &ksptype0->data[0]);
    if (errCode != 0) {
      *flag = (M2C_DEBUG);
      if (*flag != 0) {
        gb_m2c_error(errCode);
      }
    }
  }

  emxFree_char_T(&ksptype0);
  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      m_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      n_m2c_error(errCode);
    }
  }

  mptKSPSolve(t_ksp, b, x, rtol, maxit, x0, flag, relres, iter);
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      ab_m2c_error(errCode);
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
      db_m2c_error(errCode);
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
    eb_m2c_error();
  }

  errCode = VecGetValues(vec, n, &idx->data[0], &arr->data[0]);
  emxFree_int32_T(&idx);
  if (errCode != 0) {
    yk = (M2C_DEBUG);
    if (yk != 0) {
      fb_m2c_error(errCode);
    }
  }
}

static void n_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetUp returned error code %d\n",
            varargin_3);
}

static void o_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSetTolerances returned error code %d\n",
            varargin_3);
}

static void p_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "VecCopy returned error code %d\n", varargin_3);
}

static void q_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPSetInitialGuessNonzero returned error code %d\n", varargin_3);
}

static void r_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPSolve returned error code %d\n",
            varargin_3);
}

static void s_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetConvergedReason returned error code %d\n", varargin_3);
}

static void t_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetResidualNorm returned error code %d\n",
            varargin_3);
}

static void u_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "KSPGetIterationNumber returned error code %d\n", varargin_3);
}

static void v_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetTolerances returned error code %d\n",
            varargin_3);
}

static void w_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetPC returned error code %d\n",
            varargin_3);
}

static void x_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "KSPGetType returned error code %d\n",
            varargin_3);
}

static void y_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError", "PCGetType returned error code %d\n",
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

void mptSolveCRS(int *flag, double *relres, int *iter)
{
  *flag = -1;
  *relres = 1.7976931348623157E+308;
  *iter = 0;
}

void mptSolveCRS_10args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, const emxArray_real_T *x0,
  emxArray_real_T *x, int *flag, double *relres, int *iter)
{
  Mat AMat;
  Vec bVec;
  Vec x0Vec;
  Vec xVec;
  Vec t_vec_out;
  int errCode;
  KSP ksp;
  int b_flag;
  double b_relres;
  int b_iter;
  KSP t_ksp;
  int c_flag;
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

  ksp = mptKSPSetup(AMat, solver, pctype, solpack);
  mptKSPSolve(ksp, bVec, xVec, rtol, maxiter, x0Vec, &b_flag, &b_relres, &b_iter);
  t_ksp = ksp;
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      ab_m2c_error(errCode);
    }
  }

  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      bb_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  mptVecToArray(xVec, x);
  t_vec = xVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
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
  *iter)
{
  Mat AMat;
  Vec bVec;
  Vec x0Vec;
  Vec xVec;
  Vec t_vec_out;
  int errCode;
  emxArray_char_T *b_opts;
  KSP ksp;
  int b_flag;
  double b_relres;
  int loop_ub;
  KSP t_ksp;
  int c_flag;
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
      jb_m2c_error();
    }

    errCode = PetscOptionsInsertString(NULL, &b_opts->data[0]);
    emxFree_char_T(&b_opts);
    if (errCode != 0) {
      kb_m2c_error(errCode);
    }
  }

  ksp = mptKSPSetup(AMat, solver, pctype, solpack);
  mptKSPSolve(ksp, bVec, xVec, rtol, maxiter, x0Vec, &b_flag, &b_relres,
              &loop_ub);
  t_ksp = ksp;
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      ab_m2c_error(errCode);
    }
  }

  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      bb_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  mptVecToArray(xVec, x);
  t_vec = xVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = loop_ub;
}

void mptSolveCRS_4args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b,
  emxArray_real_T *x, int *flag, double *relres, int *iter)
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  PetscObject t_obj;
  MPI_Comm t_comm;
  KSP t_ksp;
  double b_relres;
  int b_iter;
  int c_flag;
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

  errCode = KSPSetOperators(t_ksp, AMat, AMat);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      l_m2c_error(errCode);
    }
  }

  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      m_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      n_m2c_error(errCode);
    }
  }

  mptKSPSolve(t_ksp, bVec, t_vec_out, 0.0, 0, NULL, &b_flag, &b_relres, &b_iter);
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      ab_m2c_error(errCode);
    }
  }

  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      bb_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  mptVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
}

void mptSolveCRS_5args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, emxArray_real_T *x, int *flag, double *relres, int
  *iter)
{
  Mat AMat;
  Vec bVec;
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
  errCode = VecDuplicate(bVec, &t_vec_out);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      i_m2c_error(errCode);
    }
  }

  mptSolve(AMat, bVec, t_vec_out, solver, 0.0, 0, NULL, &b_flag, &b_relres,
           &b_iter);
  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      bb_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  mptVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
}

void mptSolveCRS_6args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, emxArray_real_T *x, int *flag, double
  *relres, int *iter)
{
  Mat AMat;
  Vec bVec;
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
  errCode = VecDuplicate(bVec, &t_vec_out);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      i_m2c_error(errCode);
    }
  }

  mptSolve(AMat, bVec, t_vec_out, solver, rtol, 0, NULL, &b_flag, &b_relres,
           &b_iter);
  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      bb_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  mptVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
}

void mptSolveCRS_7args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, emxArray_real_T *x, int
  *flag, double *relres, int *iter)
{
  Mat AMat;
  Vec bVec;
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
  errCode = VecDuplicate(bVec, &t_vec_out);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      i_m2c_error(errCode);
    }
  }

  mptSolve(AMat, bVec, t_vec_out, solver, rtol, maxiter, NULL, &b_flag,
           &b_relres, &b_iter);
  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      bb_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  mptVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
}

void mptSolveCRS_8args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, emxArray_real_T *x, int *flag, double *relres, int *iter)
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  PetscObject t_obj;
  MPI_Comm t_comm;
  KSP t_ksp;
  boolean_T b0;
  emxArray_char_T *pctype0;
  PC t_pc;
  int loop_ub;
  double b_relres;
  int c_flag;
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

  errCode = KSPSetOperators(t_ksp, AMat, AMat);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      l_m2c_error(errCode);
    }
  }

  b0 = !(pctype->size[1] == 0);
  emxInit_char_T(&pctype0, 2);
  if (b0) {
    errCode = KSPGetPC(t_ksp, &t_pc);
    if (errCode != 0) {
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        w_m2c_error(errCode);
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
        hb_m2c_error(errCode);
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
        gb_m2c_error(errCode);
      }
    }
  }

  emxFree_char_T(&pctype0);
  errCode = KSPSetFromOptions(t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      m_m2c_error(errCode);
    }
  }

  errCode = KSPSetUp(t_ksp);
  if (errCode != 0) {
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      n_m2c_error(errCode);
    }
  }

  mptKSPSolve(t_ksp, bVec, t_vec_out, rtol, maxiter, NULL, &b_flag, &b_relres,
              &loop_ub);
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      ab_m2c_error(errCode);
    }
  }

  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      bb_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  mptVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = loop_ub;
}

void mptSolveCRS_9args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, emxArray_real_T *x, int *flag, double
  *relres, int *iter)
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  KSP ksp;
  double b_relres;
  int b_iter;
  KSP t_ksp;
  int c_flag;
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

  ksp = mptKSPSetup(AMat, solver, pctype, solpack);
  mptKSPSolve(ksp, bVec, t_vec_out, rtol, maxiter, NULL, &b_flag, &b_relres,
              &b_iter);
  t_ksp = ksp;
  errCode = KSPDestroy(&t_ksp);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      ab_m2c_error(errCode);
    }
  }

  t_mat = AMat;
  errCode = MatDestroy(&t_mat);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      bb_m2c_error(errCode);
    }
  }

  t_vec = bVec;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  mptVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  errCode = VecDestroy(&t_vec);
  if (errCode != 0) {
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
}

void mptSolveCRS_initialize(void)
{
}

void mptSolveCRS_terminate(void)
{
}
