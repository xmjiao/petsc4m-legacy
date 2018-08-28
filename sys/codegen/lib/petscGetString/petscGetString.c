#include "petscGetString.h"
#include "m2c.h"
#include "petsc4m.h"

static boolean_T ab_isequal(const emxArray_char_T *varargin_1);
static boolean_T ac_isequal(const emxArray_char_T *varargin_1);
static boolean_T ad_isequal(const emxArray_char_T *varargin_1);
static boolean_T ae_isequal(const emxArray_char_T *varargin_1);
static boolean_T af_isequal(const emxArray_char_T *varargin_1);
static boolean_T ag_isequal(const emxArray_char_T *varargin_1);
static void b_char(const emxArray_uint8_T *varargin_1, emxArray_char_T *y);
static boolean_T b_isequal(const emxArray_char_T *varargin_1);
static boolean_T bb_isequal(const emxArray_char_T *varargin_1);
static boolean_T bc_isequal(const emxArray_char_T *varargin_1);
static boolean_T bd_isequal(const emxArray_char_T *varargin_1);
static boolean_T be_isequal(const emxArray_char_T *varargin_1);
static boolean_T bf_isequal(const emxArray_char_T *varargin_1);
static boolean_T bg_isequal(const emxArray_char_T *varargin_1);
static void c_char(char y[2]);
static boolean_T c_isequal(const emxArray_char_T *varargin_1);
static boolean_T cb_isequal(const emxArray_char_T *varargin_1);
static boolean_T cc_isequal(const emxArray_char_T *varargin_1);
static boolean_T cd_isequal(const emxArray_char_T *varargin_1);
static boolean_T ce_isequal(const emxArray_char_T *varargin_1);
static boolean_T cf_isequal(const emxArray_char_T *varargin_1);
static boolean_T cg_isequal(const emxArray_char_T *varargin_1);
static boolean_T d_isequal(const emxArray_char_T *varargin_1);
static boolean_T db_isequal(const emxArray_char_T *varargin_1);
static boolean_T dc_isequal(const emxArray_char_T *varargin_1);
static boolean_T dd_isequal(const emxArray_char_T *varargin_1);
static boolean_T de_isequal(const emxArray_char_T *varargin_1);
static boolean_T df_isequal(const emxArray_char_T *varargin_1);
static boolean_T dg_isequal(const emxArray_char_T *varargin_1);
static boolean_T e_isequal(const emxArray_char_T *varargin_1);
static boolean_T eb_isequal(const emxArray_char_T *varargin_1);
static boolean_T ec_isequal(const emxArray_char_T *varargin_1);
static boolean_T ed_isequal(const emxArray_char_T *varargin_1);
static boolean_T ee_isequal(const emxArray_char_T *varargin_1);
static boolean_T ef_isequal(const emxArray_char_T *varargin_1);
static boolean_T eg_isequal(const emxArray_char_T *varargin_1);
static boolean_T f_isequal(const emxArray_char_T *varargin_1);
static boolean_T fb_isequal(const emxArray_char_T *varargin_1);
static boolean_T fc_isequal(const emxArray_char_T *varargin_1);
static boolean_T fd_isequal(const emxArray_char_T *varargin_1);
static boolean_T fe_isequal(const emxArray_char_T *varargin_1);
static boolean_T ff_isequal(const emxArray_char_T *varargin_1);
static boolean_T fg_isequal(const emxArray_char_T *varargin_1);
static boolean_T g_isequal(const emxArray_char_T *varargin_1);
static boolean_T gb_isequal(const emxArray_char_T *varargin_1);
static boolean_T gc_isequal(const emxArray_char_T *varargin_1);
static boolean_T gd_isequal(const emxArray_char_T *varargin_1);
static boolean_T ge_isequal(const emxArray_char_T *varargin_1);
static boolean_T gf_isequal(const emxArray_char_T *varargin_1);
static boolean_T h_isequal(const emxArray_char_T *varargin_1);
static boolean_T hb_isequal(const emxArray_char_T *varargin_1);
static boolean_T hc_isequal(const emxArray_char_T *varargin_1);
static boolean_T hd_isequal(const emxArray_char_T *varargin_1);
static boolean_T he_isequal(const emxArray_char_T *varargin_1);
static boolean_T hf_isequal(const emxArray_char_T *varargin_1);
static boolean_T i_isequal(const emxArray_char_T *varargin_1);
static boolean_T ib_isequal(const emxArray_char_T *varargin_1);
static boolean_T ic_isequal(const emxArray_char_T *varargin_1);
static boolean_T id_isequal(const emxArray_char_T *varargin_1);
static boolean_T ie_isequal(const emxArray_char_T *varargin_1);
static boolean_T if_isequal(const emxArray_char_T *varargin_1);
static boolean_T isequal(const emxArray_char_T *varargin_1);
static boolean_T j_isequal(const emxArray_char_T *varargin_1);
static boolean_T jb_isequal(const emxArray_char_T *varargin_1);
static boolean_T jc_isequal(const emxArray_char_T *varargin_1);
static boolean_T jd_isequal(const emxArray_char_T *varargin_1);
static boolean_T je_isequal(const emxArray_char_T *varargin_1);
static boolean_T jf_isequal(const emxArray_char_T *varargin_1);
static boolean_T k_isequal(const emxArray_char_T *varargin_1);
static boolean_T kb_isequal(const emxArray_char_T *varargin_1);
static boolean_T kc_isequal(const emxArray_char_T *varargin_1);
static boolean_T kd_isequal(const emxArray_char_T *varargin_1);
static boolean_T ke_isequal(const emxArray_char_T *varargin_1);
static boolean_T kf_isequal(const emxArray_char_T *varargin_1);
static boolean_T l_isequal(const emxArray_char_T *varargin_1);
static boolean_T lb_isequal(const emxArray_char_T *varargin_1);
static boolean_T lc_isequal(const emxArray_char_T *varargin_1);
static boolean_T ld_isequal(const emxArray_char_T *varargin_1);
static boolean_T le_isequal(const emxArray_char_T *varargin_1);
static boolean_T lf_isequal(const emxArray_char_T *varargin_1);
static void m2c_error(const emxArray_char_T *varargin_3);
static boolean_T m_isequal(const emxArray_char_T *varargin_1);
static boolean_T mb_isequal(const emxArray_char_T *varargin_1);
static boolean_T mc_isequal(const emxArray_char_T *varargin_1);
static boolean_T md_isequal(const emxArray_char_T *varargin_1);
static boolean_T me_isequal(const emxArray_char_T *varargin_1);
static boolean_T mf_isequal(const emxArray_char_T *varargin_1);
static boolean_T n_isequal(const emxArray_char_T *varargin_1);
static boolean_T nb_isequal(const emxArray_char_T *varargin_1);
static boolean_T nc_isequal(const emxArray_char_T *varargin_1);
static boolean_T nd_isequal(const emxArray_char_T *varargin_1);
static boolean_T ne_isequal(const emxArray_char_T *varargin_1);
static boolean_T nf_isequal(const emxArray_char_T *varargin_1);
static boolean_T o_isequal(const emxArray_char_T *varargin_1);
static boolean_T ob_isequal(const emxArray_char_T *varargin_1);
static boolean_T oc_isequal(const emxArray_char_T *varargin_1);
static boolean_T od_isequal(const emxArray_char_T *varargin_1);
static boolean_T oe_isequal(const emxArray_char_T *varargin_1);
static boolean_T of_isequal(const emxArray_char_T *varargin_1);
static boolean_T p_isequal(const emxArray_char_T *varargin_1);
static boolean_T pb_isequal(const emxArray_char_T *varargin_1);
static boolean_T pc_isequal(const emxArray_char_T *varargin_1);
static boolean_T pd_isequal(const emxArray_char_T *varargin_1);
static boolean_T pe_isequal(const emxArray_char_T *varargin_1);
static boolean_T pf_isequal(const emxArray_char_T *varargin_1);
static boolean_T q_isequal(const emxArray_char_T *varargin_1);
static boolean_T qb_isequal(const emxArray_char_T *varargin_1);
static boolean_T qc_isequal(const emxArray_char_T *varargin_1);
static boolean_T qd_isequal(const emxArray_char_T *varargin_1);
static boolean_T qe_isequal(const emxArray_char_T *varargin_1);
static boolean_T qf_isequal(const emxArray_char_T *varargin_1);
static boolean_T r_isequal(const emxArray_char_T *varargin_1);
static boolean_T rb_isequal(const emxArray_char_T *varargin_1);
static boolean_T rc_isequal(const emxArray_char_T *varargin_1);
static boolean_T rd_isequal(const emxArray_char_T *varargin_1);
static boolean_T re_isequal(const emxArray_char_T *varargin_1);
static boolean_T rf_isequal(const emxArray_char_T *varargin_1);
static boolean_T s_isequal(const emxArray_char_T *varargin_1);
static boolean_T sb_isequal(const emxArray_char_T *varargin_1);
static boolean_T sc_isequal(const emxArray_char_T *varargin_1);
static boolean_T sd_isequal(const emxArray_char_T *varargin_1);
static boolean_T se_isequal(const emxArray_char_T *varargin_1);
static boolean_T sf_isequal(const emxArray_char_T *varargin_1);
static boolean_T t_isequal(const emxArray_char_T *varargin_1);
static boolean_T tb_isequal(const emxArray_char_T *varargin_1);
static boolean_T tc_isequal(const emxArray_char_T *varargin_1);
static boolean_T td_isequal(const emxArray_char_T *varargin_1);
static boolean_T te_isequal(const emxArray_char_T *varargin_1);
static boolean_T tf_isequal(const emxArray_char_T *varargin_1);
static boolean_T u_isequal(const emxArray_char_T *varargin_1);
static boolean_T ub_isequal(const emxArray_char_T *varargin_1);
static boolean_T uc_isequal(const emxArray_char_T *varargin_1);
static boolean_T ud_isequal(const emxArray_char_T *varargin_1);
static boolean_T ue_isequal(const emxArray_char_T *varargin_1);
static boolean_T uf_isequal(const emxArray_char_T *varargin_1);
static boolean_T v_isequal(const emxArray_char_T *varargin_1);
static boolean_T vb_isequal(const emxArray_char_T *varargin_1);
static boolean_T vc_isequal(const emxArray_char_T *varargin_1);
static boolean_T vd_isequal(const emxArray_char_T *varargin_1);
static boolean_T ve_isequal(const emxArray_char_T *varargin_1);
static boolean_T vf_isequal(const emxArray_char_T *varargin_1);
static boolean_T w_isequal(const emxArray_char_T *varargin_1);
static boolean_T wb_isequal(const emxArray_char_T *varargin_1);
static boolean_T wc_isequal(const emxArray_char_T *varargin_1);
static boolean_T wd_isequal(const emxArray_char_T *varargin_1);
static boolean_T we_isequal(const emxArray_char_T *varargin_1);
static boolean_T wf_isequal(const emxArray_char_T *varargin_1);
static boolean_T x_isequal(const emxArray_char_T *varargin_1);
static boolean_T xb_isequal(const emxArray_char_T *varargin_1);
static boolean_T xc_isequal(const emxArray_char_T *varargin_1);
static boolean_T xd_isequal(const emxArray_char_T *varargin_1);
static boolean_T xe_isequal(const emxArray_char_T *varargin_1);
static boolean_T xf_isequal(const emxArray_char_T *varargin_1);
static boolean_T y_isequal(const emxArray_char_T *varargin_1);
static boolean_T yb_isequal(const emxArray_char_T *varargin_1);
static boolean_T yc_isequal(const emxArray_char_T *varargin_1);
static boolean_T yd_isequal(const emxArray_char_T *varargin_1);
static boolean_T ye_isequal(const emxArray_char_T *varargin_1);
static boolean_T yf_isequal(const emxArray_char_T *varargin_1);
static boolean_T ab_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv26[12] = { 'M', 'A', 'T', 'E', 'L', 'E', 'M', 'E', 'N',
    'T', 'A', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv26[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ac_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv51[11] = { 'M', 'A', 'T', 'L', 'O', 'C', 'A', 'L', 'R',
    'E', 'F' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv51[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ad_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv76[9] = { 'K', 'S', 'P', 'F', 'G', 'M', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv76[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ae_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv101[7] = { 'K', 'S', 'P', 'C', 'G', 'L', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv101[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T af_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv126[4] = { 'P', 'C', 'M', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv126[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ag_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv151[21] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'M', 'K', 'L', '_', 'C', 'P', 'A', 'R', 'D', 'I', 'S', 'O' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 21) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 21)) {
      if (!(varargin_1->data[k] == cv151[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static void b_char(const emxArray_uint8_T *varargin_1, emxArray_char_T *y)
{
  int i1;
  unsigned int uv0[2];
  int loop_ub;
  for (i1 = 0; i1 < 2; i1++) {
    uv0[i1] = (unsigned int)varargin_1->size[i1];
  }

  i1 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int)uv0[1];
  emxEnsureCapacity_char_T(y, i1);
  loop_ub = (int)uv0[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    y->data[i1] = (signed char)varargin_1->data[i1];
  }
}

static boolean_T b_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv2[7] = { 'M', 'A', 'T', 'S', 'A', 'M', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv2[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T bb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv27[7] = { 'M', 'A', 'T', 'B', 'A', 'I', 'J' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv27[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T bc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv52[7] = { 'M', 'A', 'T', 'N', 'E', 'S', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv52[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T bd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv77[9] = { 'K', 'S', 'P', 'L', 'G', 'M', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv77[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T be_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv102[6] = { 'P', 'C', 'N', 'O', 'N', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv102[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T bf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv127[10] = { 'P', 'C', 'G', 'A', 'L', 'E', 'R', 'K', 'I',
    'N' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv127[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T bg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv152[15] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'P', 'A', 'S', 'T', 'I', 'X' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 15) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv152[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static void c_char(char y[2])
{
  y[0] = '\x00';
  y[1] = '\x01';
}

static boolean_T c_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv3[7] = { 'M', 'A', 'T', 'M', 'A', 'I', 'J' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv3[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T cb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv28[10] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'B', 'A', 'I',
    'J' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv28[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T cc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv53[15] = { 'M', 'A', 'T', 'P', 'R', 'E', 'A', 'L', 'L',
    'O', 'C', 'A', 'T', 'O', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 15) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv53[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T cd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv78[9] = { 'K', 'S', 'P', 'D', 'G', 'M', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv78[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ce_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv103[8] = { 'P', 'C', 'J', 'A', 'C', 'O', 'B', 'I' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv103[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T cf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv128[8] = { 'P', 'C', 'E', 'X', 'O', 'T', 'I', 'C' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv128[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T cg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv153[15] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'M', 'A', 'T', 'L', 'A', 'B' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 15) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv153[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T d_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv4[10] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'M', 'A', 'I', 'J'
  };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv4[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T db_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv29[10] = { 'M', 'A', 'T', 'M', 'P', 'I', 'B', 'A', 'I',
    'J' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv29[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T dc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv54[6] = { 'V', 'E', 'C', 'S', 'E', 'Q' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv54[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T dd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv79[9] = { 'K', 'S', 'P', 'P', 'G', 'M', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv79[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T de_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv104[5] = { 'P', 'C', 'S', 'O', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv104[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T df_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv129[4] = { 'P', 'C', 'C', 'P' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv129[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T dg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv154[14] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'P', 'E', 'T', 'S', 'C' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv154[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T e_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv5[10] = { 'M', 'A', 'T', 'M', 'P', 'I', 'M', 'A', 'I', 'J'
  };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv5[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T eb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv30[9] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'D', 'J' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv30[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ec_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv55[6] = { 'V', 'E', 'C', 'M', 'P', 'I' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv55[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ed_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv80[8] = { 'K', 'S', 'P', 'T', 'C', 'Q', 'M', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv80[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ee_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv105[4] = { 'P', 'C', 'L', 'U' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv105[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ef_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv130[6] = { 'P', 'C', 'B', 'F', 'B', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv130[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T eg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv155[12] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'B', 'A', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv155[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T f_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv6[5] = { 'M', 'A', 'T', 'I', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv6[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T fb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv31[8] = { 'M', 'A', 'T', 'S', 'B', 'A', 'I', 'J' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv31[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T fc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv56[11] = { 'V', 'E', 'C', 'S', 'T', 'A', 'N', 'D', 'A',
    'R', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv56[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T fd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv81[7] = { 'K', 'S', 'P', 'B', 'C', 'G', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv81[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T fe_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv106[7] = { 'P', 'C', 'S', 'H', 'E', 'L', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv106[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ff_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv131[5] = { 'P', 'C', 'L', 'S', 'C' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv131[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T fg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv156[17] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'C', 'U', 'S', 'P', 'A', 'R', 'S', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 17) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 17)) {
      if (!(varargin_1->data[k] == cv156[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T g_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv7[6] = { 'M', 'A', 'T', 'A', 'I', 'J' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv7[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T gb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv32[11] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'S', 'B', 'A',
    'I', 'J' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv32[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T gc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv57[9] = { 'V', 'E', 'C', 'S', 'H', 'A', 'R', 'E', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv57[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T gd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv82[8] = { 'K', 'S', 'P', 'I', 'B', 'C', 'G', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv82[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ge_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv107[9] = { 'P', 'C', 'B', 'J', 'A', 'C', 'O', 'B', 'I' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv107[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T gf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv132[8] = { 'P', 'C', 'P', 'Y', 'T', 'H', 'O', 'N' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv132[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T h_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv8[9] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv8[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T hb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv33[11] = { 'M', 'A', 'T', 'M', 'P', 'I', 'S', 'B', 'A',
    'I', 'J' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv33[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T hc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv58[14] = { 'V', 'E', 'C', 'S', 'E', 'Q', 'V', 'I', 'E',
    'N', 'N', 'A', 'C', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv58[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T hd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv83[8] = { 'K', 'S', 'P', 'F', 'B', 'C', 'G', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv83[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T he_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv108[4] = { 'P', 'C', 'M', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv108[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T hf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv133[6] = { 'P', 'C', 'P', 'F', 'M', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv133[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T i_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv9[9] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv9[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ib_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv34[7] = { 'M', 'A', 'T', 'D', 'A', 'A', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv34[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ic_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv59[14] = { 'V', 'E', 'C', 'M', 'P', 'I', 'V', 'I', 'E',
    'N', 'N', 'A', 'C', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv59[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T id_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv84[9] = { 'K', 'S', 'P', 'F', 'B', 'C', 'G', 'S', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv84[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ie_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv109[11] = { 'P', 'C', 'E', 'I', 'S', 'E', 'N', 'S', 'T',
    'A', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv109[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T if_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv134[9] = { 'P', 'C', 'S', 'Y', 'S', 'P', 'F', 'M', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv134[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv1[17] = { 'P', 'E', 'T', 'S', 'C', '_', 'N', 'U', 'L', 'L',
    '_', 'S', 'T', 'R', 'I', 'N', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 17) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 17)) {
      if (!(varargin_1->data[k] == cv1[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T j_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv10[9] = { 'M', 'A', 'T', 'A', 'I', 'J', 'C', 'R', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv10[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T jb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv35[7] = { 'M', 'A', 'T', 'M', 'F', 'F', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv35[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T jc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv60[11] = { 'V', 'E', 'C', 'V', 'I', 'E', 'N', 'N', 'A',
    'C', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv60[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T jd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv85[8] = { 'K', 'S', 'P', 'B', 'C', 'G', 'S', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv85[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T je_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv110[5] = { 'P', 'C', 'I', 'L', 'U' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv110[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T jf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv135[14] = { 'P', 'C', 'R', 'E', 'D', 'I', 'S', 'T', 'R',
    'I', 'B', 'U', 'T', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv135[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T k_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv11[12] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'C', 'R', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv11[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T kb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv36[9] = { 'M', 'A', 'T', 'N', 'O', 'R', 'M', 'A', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv36[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T kc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv61[10] = { 'V', 'E', 'C', 'S', 'E', 'Q', 'C', 'U', 'D',
    'A' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv61[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T kd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv86[6] = { 'K', 'S', 'P', 'C', 'G', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv86[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ke_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv111[5] = { 'P', 'C', 'I', 'C', 'C' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv111[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T kf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv136[5] = { 'P', 'C', 'S', 'V', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv136[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T l_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv12[12] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'C', 'R', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv12[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T lb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv37[18] = { 'M', 'A', 'T', 'N', 'O', 'R', 'M', 'A', 'L',
    'H', 'E', 'R', 'M', 'I', 'T', 'I', 'A', 'N' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 18) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 18)) {
      if (!(varargin_1->data[k] == cv37[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T lc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv62[10] = { 'V', 'E', 'C', 'M', 'P', 'I', 'C', 'U', 'D',
    'A' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv62[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ld_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv87[8] = { 'K', 'S', 'P', 'T', 'F', 'Q', 'M', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv87[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T le_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv112[5] = { 'P', 'C', 'A', 'S', 'M' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv112[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T lf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv137[6] = { 'P', 'C', 'G', 'A', 'M', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv137[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
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
  emxEnsureCapacity_char_T(b_varargin_3, i2);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("petscGetNum:UnknownConstant", "Unknonw constant %s.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static boolean_T m_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv13[14] = { 'M', 'A', 'T', 'A', 'I', 'J', 'C', 'U', 'S',
    'P', 'A', 'R', 'S', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv13[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T mb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv38[6] = { 'M', 'A', 'T', 'L', 'R', 'C' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv38[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T mc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv63[7] = { 'V', 'E', 'C', 'C', 'U', 'D', 'A' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv63[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T md_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv88[5] = { 'K', 'S', 'P', 'C', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv88[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T me_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv113[6] = { 'P', 'C', 'G', 'A', 'S', 'M' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv113[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T mf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv138[6] = { 'P', 'C', 'B', 'D', 'D', 'C' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv138[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T n_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv14[17] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'C', 'U', 'S', 'P', 'A', 'R', 'S', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 17) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 17)) {
      if (!(varargin_1->data[k] == cv14[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T nb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv39[10] = { 'M', 'A', 'T', 'S', 'C', 'A', 'T', 'T', 'E',
    'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv39[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T nc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv64[7] = { 'V', 'E', 'C', 'N', 'E', 'S', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv64[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T nd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv89[9] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'C', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv89[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ne_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv114[5] = { 'P', 'C', 'K', 'S', 'P' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv114[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T nf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv139[10] = { 'P', 'C', 'K', 'A', 'C', 'Z', 'M', 'A', 'R',
    'Z' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv139[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T o_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv15[17] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'C', 'U', 'S', 'P', 'A', 'R', 'S', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 17) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 17)) {
      if (!(varargin_1->data[k] == cv15[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ob_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv40[11] = { 'M', 'A', 'T', 'B', 'L', 'O', 'C', 'K', 'M',
    'A', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv40[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T oc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv65[13] = { 'K', 'S', 'P', 'R', 'I', 'C', 'H', 'A', 'R',
    'D', 'S', 'O', 'N' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv65[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T od_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv90[7] = { 'K', 'S', 'P', 'L', 'S', 'Q', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv90[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T oe_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv115[11] = { 'P', 'C', 'C', 'O', 'M', 'P', 'O', 'S', 'I',
    'T', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv115[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T of_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv140[11] = { 'P', 'C', 'T', 'E', 'L', 'E', 'S', 'C', 'O',
    'P', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv140[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T p_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv16[14] = { 'M', 'A', 'T', 'A', 'I', 'J', 'V', 'I', 'E',
    'N', 'N', 'A', 'C', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv16[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T pb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv41[12] = { 'M', 'A', 'T', 'C', 'O', 'M', 'P', 'O', 'S',
    'I', 'T', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv41[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T pc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv66[12] = { 'K', 'S', 'P', 'C', 'H', 'E', 'B', 'Y', 'S',
    'H', 'E', 'V' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv66[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T pd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv91[10] = { 'K', 'S', 'P', 'P', 'R', 'E', 'O', 'N', 'L',
    'Y' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv91[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T pe_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv116[11] = { 'P', 'C', 'R', 'E', 'D', 'U', 'N', 'D', 'A',
    'N', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv116[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T pf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv141[16] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'S', 'U', 'P', 'E', 'R', 'L', 'U' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 16) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 16)) {
      if (!(varargin_1->data[k] == cv141[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T q_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv17[17] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'V', 'I', 'E', 'N', 'N', 'A', 'C', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 17) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 17)) {
      if (!(varargin_1->data[k] == cv17[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T qb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv42[6] = { 'M', 'A', 'T', 'F', 'F', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv42[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T qc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv67[5] = { 'K', 'S', 'P', 'C', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv67[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T qd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv92[6] = { 'K', 'S', 'P', 'Q', 'C', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv92[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T qe_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv117[6] = { 'P', 'C', 'S', 'P', 'A', 'I' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv117[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T qf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv142[21] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'S', 'U', 'P', 'E', 'R', 'L', 'U', '_', 'D', 'I', 'S', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 21) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 21)) {
      if (!(varargin_1->data[k] == cv142[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T r_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv18[17] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'V', 'I', 'E', 'N', 'N', 'A', 'C', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 17) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 17)) {
      if (!(varargin_1->data[k] == cv18[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T rb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv43[7] = { 'M', 'A', 'T', 'F', 'F', 'T', 'W' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv43[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T rc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv68[10] = { 'K', 'S', 'P', 'G', 'R', 'O', 'P', 'P', 'C',
    'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv68[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T rd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv93[7] = { 'K', 'S', 'P', 'B', 'I', 'C', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv93[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T re_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv118[4] = { 'P', 'C', 'N', 'N' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv118[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T rf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv143[16] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'U', 'M', 'F', 'P', 'A', 'C', 'K' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 16) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 16)) {
      if (!(varargin_1->data[k] == cv143[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T s_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv19[10] = { 'M', 'A', 'T', 'A', 'I', 'J', 'P', 'E', 'R',
    'M' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv19[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T sb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv44[11] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'C', 'U', 'F',
    'F', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv44[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T sc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv69[9] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'C', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv69[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T sd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv94[9] = { 'K', 'S', 'P', 'M', 'I', 'N', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv94[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T se_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv119[10] = { 'P', 'C', 'C', 'H', 'O', 'L', 'E', 'S', 'K',
    'Y' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv119[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T sf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv144[16] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'C', 'H', 'O', 'L', 'M', 'O', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 16) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 16)) {
      if (!(varargin_1->data[k] == cv144[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T t_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv20[13] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'P', 'E', 'R', 'M' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv20[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T tb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv45[15] = { 'M', 'A', 'T', 'T', 'R', 'A', 'N', 'S', 'P',
    'O', 'S', 'E', 'M', 'A', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 15) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv45[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T tc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv70[11] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'C', 'G',
    'R', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv70[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T td_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv95[9] = { 'K', 'S', 'P', 'S', 'Y', 'M', 'M', 'L', 'Q' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv95[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T te_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv120[10] = { 'P', 'C', 'P', 'B', 'J', 'A', 'C', 'O', 'B',
    'I' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv120[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T tf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv145[12] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'K', 'L', 'U' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv145[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T u_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv21[13] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'P', 'E', 'R', 'M' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv21[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ub_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv46[18] = { 'M', 'A', 'T', 'S', 'C', 'H', 'U', 'R', 'C',
    'O', 'M', 'P', 'L', 'E', 'M', 'E', 'N', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 18) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 18)) {
      if (!(varargin_1->data[k] == cv46[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T uc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv71[7] = { 'K', 'S', 'P', 'C', 'G', 'N', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv71[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ud_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv96[6] = { 'K', 'S', 'P', 'L', 'C', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv96[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ue_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv121[5] = { 'P', 'C', 'M', 'A', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv121[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T uf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv146[18] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'E', 'L', 'E', 'M', 'E', 'N', 'T', 'A', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 18) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 18)) {
      if (!(varargin_1->data[k] == cv146[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T v_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv22[8] = { 'M', 'A', 'T', 'S', 'H', 'E', 'L', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv22[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T vb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv47[9] = { 'M', 'A', 'T', 'P', 'Y', 'T', 'H', 'O', 'N' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv47[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T vc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv72[6] = { 'K', 'S', 'P', 'F', 'C', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv72[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T vd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv97[9] = { 'K', 'S', 'P', 'P', 'Y', 'T', 'H', 'O', 'N' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv97[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ve_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv122[7] = { 'P', 'C', 'H', 'Y', 'P', 'R', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv122[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T vf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv147[13] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'E', 'S', 'S', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv147[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T w_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv23[8] = { 'M', 'A', 'T', 'D', 'E', 'N', 'S', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv23[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T wb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv48[14] = { 'M', 'A', 'T', 'H', 'Y', 'P', 'R', 'E', 'S',
    'T', 'R', 'U', 'C', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv48[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T wc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv73[10] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'F', 'C',
    'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv73[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T wd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv98[6] = { 'K', 'S', 'P', 'G', 'C', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv98[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T we_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv123[7] = { 'P', 'C', 'P', 'A', 'R', 'M', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv123[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T wf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv148[14] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'L', 'U', 'S', 'O', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv148[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T x_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv24[11] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'D', 'E', 'N',
    'S', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv24[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T xb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv49[15] = { 'M', 'A', 'T', 'H', 'Y', 'P', 'R', 'E', 'S',
    'S', 'T', 'R', 'U', 'C', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 15) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv49[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T xc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv74[8] = { 'K', 'S', 'P', 'G', 'M', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv74[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T xd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv99[10] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'G', 'C',
    'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv99[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T xe_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv124[12] = { 'P', 'C', 'F', 'I', 'E', 'L', 'D', 'S', 'P',
    'L', 'I', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv124[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T xf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv149[14] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'M', 'U', 'M', 'P', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv149[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T y_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv25[11] = { 'M', 'A', 'T', 'M', 'P', 'I', 'D', 'E', 'N',
    'S', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv25[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T yb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv50[12] = { 'M', 'A', 'T', 'S', 'U', 'B', 'M', 'A', 'T',
    'R', 'I', 'X' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv50[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T yc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv75[13] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'F', 'G',
    'M', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv75[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T yd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv100[8] = { 'K', 'S', 'P', 'T', 'S', 'I', 'R', 'M' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv100[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ye_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv125[5] = { 'P', 'C', 'T', 'F', 'S' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv125[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T yf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv150[20] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'M', 'K', 'L', '_', 'P', 'A', 'R', 'D', 'I', 'S', 'O' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 20) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 20)) {
      if (!(varargin_1->data[k] == cv150[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

void petscGetString(const emxArray_char_T *name, emxArray_char_T *str, boolean_T
                    *toplevel)
{
  emxArray_uint8_T *str1;
  emxArray_char_T *b_name;
  const char * b_str;
  int empty;
  int i0;
  int n;
  char * ptr;
  char cv0[2];
  emxInit_uint8_T(&str1, 2);
  emxInit_char_T(&b_name, 2);
  if (isequal(name)) {
    b_str = (NULL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (b_isequal(name)) {
    b_str = (MATSAME);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (c_isequal(name)) {
    b_str = (MATMAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (d_isequal(name)) {
    b_str = (MATSEQMAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (e_isequal(name)) {
    b_str = (MATMPIMAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (f_isequal(name)) {
    b_str = (MATIS);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (g_isequal(name)) {
    b_str = (MATAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (h_isequal(name)) {
    b_str = (MATSEQAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (i_isequal(name)) {
    b_str = (MATMPIAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (j_isequal(name)) {
    b_str = (MATMPIAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (k_isequal(name)) {
    b_str = (MATSEQAIJCRL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (l_isequal(name)) {
    b_str = (MATMPIAIJCRL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (m_isequal(name)) {
    b_str = (MATAIJCUSPARSE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (n_isequal(name)) {
    b_str = (MATSEQAIJCUSPARSE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (o_isequal(name)) {
    b_str = (MATMPIAIJCUSPARSE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (p_isequal(name)) {
    b_str = (MATAIJVIENNACL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (q_isequal(name)) {
    b_str = (MATSEQAIJVIENNACL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (r_isequal(name)) {
    b_str = (MATMPIAIJVIENNACL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (s_isequal(name)) {
    b_str = (MATAIJPERM);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (t_isequal(name)) {
    b_str = (MATSEQAIJPERM);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (u_isequal(name)) {
    b_str = (MATMPIAIJPERM);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (v_isequal(name)) {
    b_str = (MATSHELL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (w_isequal(name)) {
    b_str = (MATDENSE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (x_isequal(name)) {
    b_str = (MATSEQDENSE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (y_isequal(name)) {
    b_str = (MATMPIDENSE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ab_isequal(name)) {
    b_str = (MATELEMENTAL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (bb_isequal(name)) {
    b_str = (MATBAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (cb_isequal(name)) {
    b_str = (MATSEQBAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (db_isequal(name)) {
    b_str = (MATMPIBAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (eb_isequal(name)) {
    b_str = (MATMPIADJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (fb_isequal(name)) {
    b_str = (MATSBAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (gb_isequal(name)) {
    b_str = (MATSEQSBAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (hb_isequal(name)) {
    b_str = (MATMPISBAIJ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ib_isequal(name)) {
    b_str = (MATDAAD);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (jb_isequal(name)) {
    b_str = (MATMFFD);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (kb_isequal(name)) {
    b_str = (MATNORMAL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (lb_isequal(name)) {
    b_str = (MATNORMALHERMITIAN);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (mb_isequal(name)) {
    b_str = (MATLRC);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (nb_isequal(name)) {
    b_str = (MATSCATTER);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ob_isequal(name)) {
    b_str = (MATBLOCKMAT);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (pb_isequal(name)) {
    b_str = (MATCOMPOSITE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (qb_isequal(name)) {
    b_str = (MATFFT);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (rb_isequal(name)) {
    b_str = (MATFFTW);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (sb_isequal(name)) {
    b_str = (MATSEQCUFFT);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (tb_isequal(name)) {
    b_str = (MATTRANSPOSEMAT);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ub_isequal(name)) {
    b_str = (MATSCHURCOMPLEMENT);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (vb_isequal(name)) {
    b_str = (MATPYTHON);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (wb_isequal(name)) {
    b_str = (MATHYPRESTRUCT);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (xb_isequal(name)) {
    b_str = (MATHYPRESSTRUCT);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (yb_isequal(name)) {
    b_str = (MATSUBMATRIX);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ac_isequal(name)) {
    b_str = (MATSUBMATRIX);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (bc_isequal(name)) {
    b_str = (MATNEST);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (cc_isequal(name)) {
    b_str = (MATPREALLOCATOR);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (dc_isequal(name)) {
    b_str = (VECSEQ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ec_isequal(name)) {
    b_str = (VECMPI);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (fc_isequal(name)) {
    b_str = (VECSTANDARD);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (gc_isequal(name)) {
    b_str = (VECSHARED);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (hc_isequal(name)) {
    b_str = (VECSEQVIENNACL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ic_isequal(name)) {
    b_str = (VECMPIVIENNACL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (jc_isequal(name)) {
    b_str = (VECVIENNACL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (kc_isequal(name)) {
    b_str = (VECSEQCUDA);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (lc_isequal(name)) {
    b_str = (VECMPICUDA);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (mc_isequal(name)) {
    b_str = (VECCUDA);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (nc_isequal(name)) {
    b_str = (VECNEST);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (oc_isequal(name)) {
    b_str = (KSPRICHARDSON);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (pc_isequal(name)) {
    b_str = (KSPCHEBYSHEV);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (qc_isequal(name)) {
    b_str = (KSPCG);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (rc_isequal(name)) {
    b_str = (KSPGROPPCG);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (sc_isequal(name)) {
    b_str = (KSPPIPECG);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (tc_isequal(name)) {
    b_str = (KSPPIPECGRR);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (uc_isequal(name)) {
    b_str = (KSPCGNE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (vc_isequal(name)) {
    b_str = (KSPFCG);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (wc_isequal(name)) {
    b_str = (KSPPIPEFCG);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (xc_isequal(name)) {
    b_str = (KSPGMRES);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (yc_isequal(name)) {
    b_str = (KSPPIPEFGMRES);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ad_isequal(name)) {
    b_str = (KSPFGMRES);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (bd_isequal(name)) {
    b_str = (KSPLGMRES);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (cd_isequal(name)) {
    b_str = (KSPDGMRES);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (dd_isequal(name)) {
    b_str = (KSPPGMRES);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ed_isequal(name)) {
    b_str = (KSPTCQMR);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (fd_isequal(name)) {
    b_str = (KSPBCGS);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (gd_isequal(name)) {
    b_str = (KSPIBCGS);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (hd_isequal(name)) {
    b_str = (KSPFBCGS);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (id_isequal(name)) {
    b_str = (KSPFBCGSR);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (jd_isequal(name)) {
    b_str = (KSPBCGSL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (kd_isequal(name)) {
    b_str = (KSPCGS);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ld_isequal(name)) {
    b_str = (KSPTFQMR);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (md_isequal(name)) {
    b_str = (KSPCR);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (nd_isequal(name)) {
    b_str = (KSPPIPECR);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (od_isequal(name)) {
    b_str = (KSPLSQR);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (pd_isequal(name)) {
    b_str = (KSPPREONLY);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (qd_isequal(name)) {
    b_str = (KSPQCG);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (rd_isequal(name)) {
    b_str = (KSPBICG);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (sd_isequal(name)) {
    b_str = (KSPMINRES);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (td_isequal(name)) {
    b_str = (KSPSYMMLQ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ud_isequal(name)) {
    b_str = (KSPLCD);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (vd_isequal(name)) {
    b_str = (KSPPYTHON);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (wd_isequal(name)) {
    b_str = (KSPGCR);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (xd_isequal(name)) {
    b_str = (KSPPIPEGCR);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (yd_isequal(name)) {
    b_str = (KSPTSIRM);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ae_isequal(name)) {
    b_str = (KSPCGLS);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (be_isequal(name)) {
    b_str = (PCNONE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ce_isequal(name)) {
    b_str = (PCJACOBI);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (de_isequal(name)) {
    b_str = (PCSOR);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ee_isequal(name)) {
    b_str = (PCLU);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (fe_isequal(name)) {
    b_str = (PCSHELL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ge_isequal(name)) {
    b_str = (PCBJACOBI);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (he_isequal(name)) {
    b_str = (PCMG);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ie_isequal(name)) {
    b_str = (PCEISENSTAT);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (je_isequal(name)) {
    b_str = (PCILU);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ke_isequal(name)) {
    b_str = (PCICC);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (le_isequal(name)) {
    b_str = (PCASM);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (me_isequal(name)) {
    b_str = (PCGASM);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ne_isequal(name)) {
    b_str = (PCKSP);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (oe_isequal(name)) {
    b_str = (PCCOMPOSITE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (pe_isequal(name)) {
    b_str = (PCREDUNDANT);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (qe_isequal(name)) {
    b_str = (PCSPAI);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (re_isequal(name)) {
    b_str = (PCNN);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (se_isequal(name)) {
    b_str = (PCCHOLESKY);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (te_isequal(name)) {
    b_str = (PCPBJACOBI);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ue_isequal(name)) {
    b_str = (PCMAT);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ve_isequal(name)) {
    b_str = (PCHYPRE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (we_isequal(name)) {
    b_str = (PCPARMS);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (xe_isequal(name)) {
    b_str = (PCFIELDSPLIT);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ye_isequal(name)) {
    b_str = (PCTFS);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (af_isequal(name)) {
    b_str = (PCML);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (bf_isequal(name)) {
    b_str = (PCGALERKIN);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (cf_isequal(name)) {
    b_str = (PCEXOTIC);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (df_isequal(name)) {
    b_str = (PCCP);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ef_isequal(name)) {
    b_str = (PCBFBT);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ff_isequal(name)) {
    b_str = (PCLSC);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (gf_isequal(name)) {
    b_str = (PCPYTHON);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (hf_isequal(name)) {
    b_str = (PCPFMG);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (if_isequal(name)) {
    b_str = (PCSYSPFMG);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (jf_isequal(name)) {
    b_str = (PCREDISTRIBUTE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (kf_isequal(name)) {
    b_str = (PCSVD);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (lf_isequal(name)) {
    b_str = (PCGAMG);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (mf_isequal(name)) {
    b_str = (PCBDDC);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (nf_isequal(name)) {
    b_str = (PCKACZMARZ);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (of_isequal(name)) {
    b_str = (PCTELESCOPE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (pf_isequal(name)) {
    b_str = (MATSOLVERSUPERLU);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (qf_isequal(name)) {
    b_str = (MATSOLVERSUPERLU_DIST);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (rf_isequal(name)) {
    b_str = (MATSOLVERUMFPACK);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (sf_isequal(name)) {
    b_str = (MATSOLVERCHOLMOD);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (tf_isequal(name)) {
    b_str = (MATSOLVERKLU);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (uf_isequal(name)) {
    b_str = (MATSOLVERELEMENTAL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (vf_isequal(name)) {
    b_str = (MATSOLVERESSL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (wf_isequal(name)) {
    b_str = (MATSOLVERLUSOL);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (xf_isequal(name)) {
    b_str = (MATSOLVERMUMPS);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (yf_isequal(name)) {
    b_str = (MATSOLVERMKL_PARDISO);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (ag_isequal(name)) {
    b_str = (MATSOLVERMKL_CPARDISO);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (bg_isequal(name)) {
    b_str = (MATSOLVERPASTIX);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (cg_isequal(name)) {
    b_str = (MATSOLVERMATLAB);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (dg_isequal(name)) {
    b_str = (MATSOLVERPETSC);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (eg_isequal(name)) {
    b_str = (MATSOLVERBAS);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else if (fg_isequal(name)) {
    b_str = (MATSOLVERCUSPARSE);
    empty = !(b_str);
    if (!(empty != 0)) {
      n = strlen(b_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity_uint8_T(str1, i0);
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(b_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity_uint8_T(str1, i0);
    }

    b_char(str1, b_name);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_name->size[1];
    emxEnsureCapacity_char_T(str, i0);
    empty = b_name->size[0] * b_name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_name->data[i0];
    }
  } else {
    i0 = b_name->size[0] * b_name->size[1];
    b_name->size[0] = 1;
    b_name->size[1] = name->size[1] + 1;
    emxEnsureCapacity_char_T(b_name, i0);
    empty = name->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      b_name->data[b_name->size[0] * i0] = name->data[name->size[0] * i0];
    }

    b_name->data[b_name->size[0] * name->size[1]] = '\x00';
    m2c_error(b_name);
    c_char(cv0);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 2;
    str->size[1] = 1;
    emxEnsureCapacity_char_T(str, i0);
    for (i0 = 0; i0 < 2; i0++) {
      str->data[i0] = cv0[i0];
    }
  }

  emxFree_char_T(&b_name);
  emxFree_uint8_T(&str1);
  *toplevel = true;
}

void petscGetString_initialize(void)
{
}

void petscGetString_terminate(void)
{
}
