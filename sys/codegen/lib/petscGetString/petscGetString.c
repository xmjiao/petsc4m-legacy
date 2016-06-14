#include "petscGetString.h"
#include "m2c.h"
#include "mpetsc.h"

static boolean_T ab_isequal(const emxArray_char_T *varargin_1);
static boolean_T ac_isequal(const emxArray_char_T *varargin_1);
static boolean_T ad_isequal(const emxArray_char_T *varargin_1);
static boolean_T ae_isequal(const emxArray_char_T *varargin_1);
static boolean_T af_isequal(const emxArray_char_T *varargin_1);
static boolean_T ag_isequal(const emxArray_char_T *varargin_1);
static boolean_T ah_isequal(const emxArray_char_T *varargin_1);
static void b_char(const emxArray_uint8_T *varargin_1, emxArray_char_T *y);
static boolean_T b_isequal(const emxArray_char_T *varargin_1);
static boolean_T bb_isequal(const emxArray_char_T *varargin_1);
static boolean_T bc_isequal(const emxArray_char_T *varargin_1);
static boolean_T bd_isequal(const emxArray_char_T *varargin_1);
static boolean_T be_isequal(const emxArray_char_T *varargin_1);
static boolean_T bf_isequal(const emxArray_char_T *varargin_1);
static boolean_T bg_isequal(const emxArray_char_T *varargin_1);
static boolean_T bh_isequal(const emxArray_char_T *varargin_1);
static void c_char(char y[2]);
static boolean_T c_isequal(const emxArray_char_T *varargin_1);
static boolean_T cb_isequal(const emxArray_char_T *varargin_1);
static boolean_T cc_isequal(const emxArray_char_T *varargin_1);
static boolean_T cd_isequal(const emxArray_char_T *varargin_1);
static boolean_T ce_isequal(const emxArray_char_T *varargin_1);
static boolean_T cf_isequal(const emxArray_char_T *varargin_1);
static boolean_T cg_isequal(const emxArray_char_T *varargin_1);
static boolean_T ch_isequal(const emxArray_char_T *varargin_1);
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
static boolean_T gg_isequal(const emxArray_char_T *varargin_1);
static boolean_T h_isequal(const emxArray_char_T *varargin_1);
static boolean_T hb_isequal(const emxArray_char_T *varargin_1);
static boolean_T hc_isequal(const emxArray_char_T *varargin_1);
static boolean_T hd_isequal(const emxArray_char_T *varargin_1);
static boolean_T he_isequal(const emxArray_char_T *varargin_1);
static boolean_T hf_isequal(const emxArray_char_T *varargin_1);
static boolean_T hg_isequal(const emxArray_char_T *varargin_1);
static boolean_T i_isequal(const emxArray_char_T *varargin_1);
static boolean_T ib_isequal(const emxArray_char_T *varargin_1);
static boolean_T ic_isequal(const emxArray_char_T *varargin_1);
static boolean_T id_isequal(const emxArray_char_T *varargin_1);
static boolean_T ie_isequal(const emxArray_char_T *varargin_1);
static boolean_T if_isequal(const emxArray_char_T *varargin_1);
static boolean_T ig_isequal(const emxArray_char_T *varargin_1);
static boolean_T isequal(const emxArray_char_T *varargin_1);
static boolean_T j_isequal(const emxArray_char_T *varargin_1);
static boolean_T jb_isequal(const emxArray_char_T *varargin_1);
static boolean_T jc_isequal(const emxArray_char_T *varargin_1);
static boolean_T jd_isequal(const emxArray_char_T *varargin_1);
static boolean_T je_isequal(const emxArray_char_T *varargin_1);
static boolean_T jf_isequal(const emxArray_char_T *varargin_1);
static boolean_T jg_isequal(const emxArray_char_T *varargin_1);
static boolean_T k_isequal(const emxArray_char_T *varargin_1);
static boolean_T kb_isequal(const emxArray_char_T *varargin_1);
static boolean_T kc_isequal(const emxArray_char_T *varargin_1);
static boolean_T kd_isequal(const emxArray_char_T *varargin_1);
static boolean_T ke_isequal(const emxArray_char_T *varargin_1);
static boolean_T kf_isequal(const emxArray_char_T *varargin_1);
static boolean_T kg_isequal(const emxArray_char_T *varargin_1);
static boolean_T l_isequal(const emxArray_char_T *varargin_1);
static boolean_T lb_isequal(const emxArray_char_T *varargin_1);
static boolean_T lc_isequal(const emxArray_char_T *varargin_1);
static boolean_T ld_isequal(const emxArray_char_T *varargin_1);
static boolean_T le_isequal(const emxArray_char_T *varargin_1);
static boolean_T lf_isequal(const emxArray_char_T *varargin_1);
static boolean_T lg_isequal(const emxArray_char_T *varargin_1);
static void m2c_error(const emxArray_char_T *varargin_3);
static boolean_T m_isequal(const emxArray_char_T *varargin_1);
static boolean_T mb_isequal(const emxArray_char_T *varargin_1);
static boolean_T mc_isequal(const emxArray_char_T *varargin_1);
static boolean_T md_isequal(const emxArray_char_T *varargin_1);
static boolean_T me_isequal(const emxArray_char_T *varargin_1);
static boolean_T mf_isequal(const emxArray_char_T *varargin_1);
static boolean_T mg_isequal(const emxArray_char_T *varargin_1);
static boolean_T n_isequal(const emxArray_char_T *varargin_1);
static boolean_T nb_isequal(const emxArray_char_T *varargin_1);
static boolean_T nc_isequal(const emxArray_char_T *varargin_1);
static boolean_T nd_isequal(const emxArray_char_T *varargin_1);
static boolean_T ne_isequal(const emxArray_char_T *varargin_1);
static boolean_T nf_isequal(const emxArray_char_T *varargin_1);
static boolean_T ng_isequal(const emxArray_char_T *varargin_1);
static boolean_T o_isequal(const emxArray_char_T *varargin_1);
static boolean_T ob_isequal(const emxArray_char_T *varargin_1);
static boolean_T oc_isequal(const emxArray_char_T *varargin_1);
static boolean_T od_isequal(const emxArray_char_T *varargin_1);
static boolean_T oe_isequal(const emxArray_char_T *varargin_1);
static boolean_T of_isequal(const emxArray_char_T *varargin_1);
static boolean_T og_isequal(const emxArray_char_T *varargin_1);
static boolean_T p_isequal(const emxArray_char_T *varargin_1);
static boolean_T pb_isequal(const emxArray_char_T *varargin_1);
static boolean_T pc_isequal(const emxArray_char_T *varargin_1);
static boolean_T pd_isequal(const emxArray_char_T *varargin_1);
static boolean_T pe_isequal(const emxArray_char_T *varargin_1);
static boolean_T pf_isequal(const emxArray_char_T *varargin_1);
static boolean_T pg_isequal(const emxArray_char_T *varargin_1);
static boolean_T q_isequal(const emxArray_char_T *varargin_1);
static boolean_T qb_isequal(const emxArray_char_T *varargin_1);
static boolean_T qc_isequal(const emxArray_char_T *varargin_1);
static boolean_T qd_isequal(const emxArray_char_T *varargin_1);
static boolean_T qe_isequal(const emxArray_char_T *varargin_1);
static boolean_T qf_isequal(const emxArray_char_T *varargin_1);
static boolean_T qg_isequal(const emxArray_char_T *varargin_1);
static boolean_T r_isequal(const emxArray_char_T *varargin_1);
static boolean_T rb_isequal(const emxArray_char_T *varargin_1);
static boolean_T rc_isequal(const emxArray_char_T *varargin_1);
static boolean_T rd_isequal(const emxArray_char_T *varargin_1);
static boolean_T re_isequal(const emxArray_char_T *varargin_1);
static boolean_T rf_isequal(const emxArray_char_T *varargin_1);
static boolean_T rg_isequal(const emxArray_char_T *varargin_1);
static boolean_T s_isequal(const emxArray_char_T *varargin_1);
static boolean_T sb_isequal(const emxArray_char_T *varargin_1);
static boolean_T sc_isequal(const emxArray_char_T *varargin_1);
static boolean_T sd_isequal(const emxArray_char_T *varargin_1);
static boolean_T se_isequal(const emxArray_char_T *varargin_1);
static boolean_T sf_isequal(const emxArray_char_T *varargin_1);
static boolean_T sg_isequal(const emxArray_char_T *varargin_1);
static boolean_T t_isequal(const emxArray_char_T *varargin_1);
static boolean_T tb_isequal(const emxArray_char_T *varargin_1);
static boolean_T tc_isequal(const emxArray_char_T *varargin_1);
static boolean_T td_isequal(const emxArray_char_T *varargin_1);
static boolean_T te_isequal(const emxArray_char_T *varargin_1);
static boolean_T tf_isequal(const emxArray_char_T *varargin_1);
static boolean_T tg_isequal(const emxArray_char_T *varargin_1);
static boolean_T u_isequal(const emxArray_char_T *varargin_1);
static boolean_T ub_isequal(const emxArray_char_T *varargin_1);
static boolean_T uc_isequal(const emxArray_char_T *varargin_1);
static boolean_T ud_isequal(const emxArray_char_T *varargin_1);
static boolean_T ue_isequal(const emxArray_char_T *varargin_1);
static boolean_T uf_isequal(const emxArray_char_T *varargin_1);
static boolean_T ug_isequal(const emxArray_char_T *varargin_1);
static boolean_T v_isequal(const emxArray_char_T *varargin_1);
static boolean_T vb_isequal(const emxArray_char_T *varargin_1);
static boolean_T vc_isequal(const emxArray_char_T *varargin_1);
static boolean_T vd_isequal(const emxArray_char_T *varargin_1);
static boolean_T ve_isequal(const emxArray_char_T *varargin_1);
static boolean_T vf_isequal(const emxArray_char_T *varargin_1);
static boolean_T vg_isequal(const emxArray_char_T *varargin_1);
static boolean_T w_isequal(const emxArray_char_T *varargin_1);
static boolean_T wb_isequal(const emxArray_char_T *varargin_1);
static boolean_T wc_isequal(const emxArray_char_T *varargin_1);
static boolean_T wd_isequal(const emxArray_char_T *varargin_1);
static boolean_T we_isequal(const emxArray_char_T *varargin_1);
static boolean_T wf_isequal(const emxArray_char_T *varargin_1);
static boolean_T wg_isequal(const emxArray_char_T *varargin_1);
static boolean_T x_isequal(const emxArray_char_T *varargin_1);
static boolean_T xb_isequal(const emxArray_char_T *varargin_1);
static boolean_T xc_isequal(const emxArray_char_T *varargin_1);
static boolean_T xd_isequal(const emxArray_char_T *varargin_1);
static boolean_T xe_isequal(const emxArray_char_T *varargin_1);
static boolean_T xf_isequal(const emxArray_char_T *varargin_1);
static boolean_T xg_isequal(const emxArray_char_T *varargin_1);
static boolean_T y_isequal(const emxArray_char_T *varargin_1);
static boolean_T yb_isequal(const emxArray_char_T *varargin_1);
static boolean_T yc_isequal(const emxArray_char_T *varargin_1);
static boolean_T yd_isequal(const emxArray_char_T *varargin_1);
static boolean_T ye_isequal(const emxArray_char_T *varargin_1);
static boolean_T yf_isequal(const emxArray_char_T *varargin_1);
static boolean_T yg_isequal(const emxArray_char_T *varargin_1);
static boolean_T ab_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i27;
  boolean_T exitg1;
  static const char cv26[8] = { 'M', 'A', 'T', 'D', 'E', 'N', 'S', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i27 = varargin_1->size[k];
      if (i27 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv26[k])) {
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

static boolean_T ac_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i52;
  boolean_T exitg1;
  static const char cv51[6] = { 'M', 'A', 'T', 'F', 'F', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i52 = varargin_1->size[k];
      if (i52 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv51[k])) {
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

static boolean_T ad_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i77;
  boolean_T exitg1;
  static const char cv76[7] = { 'V', 'E', 'C', 'N', 'E', 'S', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i77 = varargin_1->size[k];
      if (i77 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv76[k])) {
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

static boolean_T ae_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i102;
  boolean_T exitg1;
  static const char cv101[6] = { 'K', 'S', 'P', 'C', 'G', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i102 = varargin_1->size[k];
      if (i102 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv101[k])) {
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

static boolean_T af_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i127;
  boolean_T exitg1;
  static const char cv126[5] = { 'P', 'C', 'I', 'C', 'C' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i127 = varargin_1->size[k];
      if (i127 != (k << 2) + 1) {
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
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv126[k])) {
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

static boolean_T ag_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i152;
  boolean_T exitg1;
  static const char cv151[5] = { 'P', 'C', 'S', 'V', 'D' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i152 = varargin_1->size[k];
      if (i152 != (k << 2) + 1) {
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
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv151[k])) {
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

static boolean_T ah_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i177;
  boolean_T exitg1;
  static const char cv176[17] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'C', 'U', 'S', 'P', 'A', 'R', 'S', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i177 = varargin_1->size[k];
      if (i177 != (k << 4) + 1) {
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
    while ((!exitg1) && (k < 17)) {
      if (!(varargin_1->data[k] == cv176[k])) {
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

static void b_char(const emxArray_uint8_T *varargin_1, emxArray_char_T *y)
{
  unsigned int uv0[2];
  int i2;
  int loop_ub;
  for (i2 = 0; i2 < 2; i2++) {
    uv0[i2] = (unsigned int)varargin_1->size[i2];
  }

  i2 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int)uv0[1];
  emxEnsureCapacity((emxArray__common *)y, i2, (int)sizeof(char));
  loop_ub = (int)uv0[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    y->data[i2] = (signed char)varargin_1->data[i2];
  }
}

static boolean_T b_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i3;
  boolean_T exitg1;
  static const char cv2[7] = { 'M', 'A', 'T', 'S', 'A', 'M', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i3 = varargin_1->size[k];
      if (i3 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv2[k])) {
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

static boolean_T bb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i28;
  boolean_T exitg1;
  static const char cv27[11] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'D', 'E', 'N',
    'S', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i28 = varargin_1->size[k];
      if (i28 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv27[k])) {
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

static boolean_T bc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i53;
  boolean_T exitg1;
  static const char cv52[7] = { 'M', 'A', 'T', 'F', 'F', 'T', 'W' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i53 = varargin_1->size[k];
      if (i53 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv52[k])) {
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

static boolean_T bd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i78;
  boolean_T exitg1;
  static const char cv77[13] = { 'K', 'S', 'P', 'R', 'I', 'C', 'H', 'A', 'R',
    'D', 'S', 'O', 'N' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i78 = varargin_1->size[k];
      if (i78 != 12 * k + 1) {
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
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv77[k])) {
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

static boolean_T be_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i103;
  boolean_T exitg1;
  static const char cv102[8] = { 'K', 'S', 'P', 'T', 'F', 'Q', 'M', 'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i103 = varargin_1->size[k];
      if (i103 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv102[k])) {
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

static boolean_T bf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i128;
  boolean_T exitg1;
  static const char cv127[5] = { 'P', 'C', 'A', 'S', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i128 = varargin_1->size[k];
      if (i128 != (k << 2) + 1) {
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
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv127[k])) {
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

static boolean_T bg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i153;
  boolean_T exitg1;
  static const char cv152[6] = { 'P', 'C', 'G', 'A', 'M', 'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i153 = varargin_1->size[k];
      if (i153 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv152[k])) {
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

static boolean_T bh_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i178;
  boolean_T exitg1;
  static const char cv177[14] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'B', 'S', 'T', 'R', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i178 = varargin_1->size[k];
      if (i178 != 13 * k + 1) {
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
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv177[k])) {
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
  int exitg2;
  int i4;
  boolean_T exitg1;
  static const char cv3[7] = { 'M', 'A', 'T', 'M', 'A', 'I', 'J' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i4 = varargin_1->size[k];
      if (i4 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv3[k])) {
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

static boolean_T cb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i29;
  boolean_T exitg1;
  static const char cv28[11] = { 'M', 'A', 'T', 'M', 'P', 'I', 'D', 'E', 'N',
    'S', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i29 = varargin_1->size[k];
      if (i29 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv28[k])) {
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

static boolean_T cc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i54;
  boolean_T exitg1;
  static const char cv53[11] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'C', 'U', 'F',
    'F', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i54 = varargin_1->size[k];
      if (i54 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv53[k])) {
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

static boolean_T cd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i79;
  boolean_T exitg1;
  static const char cv78[12] = { 'K', 'S', 'P', 'C', 'H', 'E', 'B', 'Y', 'S',
    'H', 'E', 'V' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i79 = varargin_1->size[k];
      if (i79 != 11 * k + 1) {
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
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv78[k])) {
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

static boolean_T ce_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i104;
  boolean_T exitg1;
  static const char cv103[5] = { 'K', 'S', 'P', 'C', 'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i104 = varargin_1->size[k];
      if (i104 != (k << 2) + 1) {
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
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv103[k])) {
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

static boolean_T cf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i129;
  boolean_T exitg1;
  static const char cv128[6] = { 'P', 'C', 'G', 'A', 'S', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i129 = varargin_1->size[k];
      if (i129 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv128[k])) {
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

static boolean_T cg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i154;
  boolean_T exitg1;
  static const char cv153[8] = { 'P', 'C', 'S', 'A', 'C', 'U', 'S', 'P' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i154 = varargin_1->size[k];
      if (i154 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv153[k])) {
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

static boolean_T ch_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i179;
  boolean_T exitg1;
  static const char cv178[15] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'S', 'B', 'S', 'T', 'R', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i179 = varargin_1->size[k];
      if (i179 != 14 * k + 1) {
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
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv178[k])) {
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

static boolean_T d_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i5;
  boolean_T exitg1;
  static const char cv4[10] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'M', 'A', 'I', 'J'
  };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i5 = varargin_1->size[k];
      if (i5 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv4[k])) {
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

static boolean_T db_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i30;
  boolean_T exitg1;
  static const char cv29[12] = { 'M', 'A', 'T', 'E', 'L', 'E', 'M', 'E', 'N',
    'T', 'A', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i30 = varargin_1->size[k];
      if (i30 != 11 * k + 1) {
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
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv29[k])) {
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

static boolean_T dc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i55;
  boolean_T exitg1;
  static const char cv54[15] = { 'M', 'A', 'T', 'T', 'R', 'A', 'N', 'S', 'P',
    'O', 'S', 'E', 'M', 'A', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i55 = varargin_1->size[k];
      if (i55 != 14 * k + 1) {
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
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv54[k])) {
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

static boolean_T dd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i80;
  boolean_T exitg1;
  static const char cv79[5] = { 'K', 'S', 'P', 'C', 'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i80 = varargin_1->size[k];
      if (i80 != (k << 2) + 1) {
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
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv79[k])) {
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

static boolean_T de_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i105;
  boolean_T exitg1;
  static const char cv104[9] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'C', 'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i105 = varargin_1->size[k];
      if (i105 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv104[k])) {
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

static boolean_T df_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i130;
  boolean_T exitg1;
  static const char cv129[5] = { 'P', 'C', 'K', 'S', 'P' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i130 = varargin_1->size[k];
      if (i130 != (k << 2) + 1) {
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
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv129[k])) {
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

static boolean_T dg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i155;
  boolean_T exitg1;
  static const char cv154[12] = { 'P', 'C', 'S', 'A', 'C', 'U', 'S', 'P', 'P',
    'O', 'L', 'Y' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i155 = varargin_1->size[k];
      if (i155 != 11 * k + 1) {
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
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv154[k])) {
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

static boolean_T e_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i6;
  boolean_T exitg1;
  static const char cv5[10] = { 'M', 'A', 'T', 'M', 'P', 'I', 'M', 'A', 'I', 'J'
  };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i6 = varargin_1->size[k];
      if (i6 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
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

static boolean_T eb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i31;
  boolean_T exitg1;
  static const char cv30[7] = { 'M', 'A', 'T', 'B', 'A', 'I', 'J' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i31 = varargin_1->size[k];
      if (i31 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv30[k])) {
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

static boolean_T ec_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i56;
  boolean_T exitg1;
  static const char cv55[18] = { 'M', 'A', 'T', 'S', 'C', 'H', 'U', 'R', 'C',
    'O', 'M', 'P', 'L', 'E', 'M', 'E', 'N', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i56 = varargin_1->size[k];
      if (i56 != 17 * k + 1) {
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
    while ((!exitg1) && (k < 18)) {
      if (!(varargin_1->data[k] == cv55[k])) {
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

static boolean_T ed_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i81;
  boolean_T exitg1;
  static const char cv80[10] = { 'K', 'S', 'P', 'G', 'R', 'O', 'P', 'P', 'C',
    'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i81 = varargin_1->size[k];
      if (i81 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv80[k])) {
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

static boolean_T ee_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i106;
  boolean_T exitg1;
  static const char cv105[7] = { 'K', 'S', 'P', 'L', 'S', 'Q', 'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i106 = varargin_1->size[k];
      if (i106 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv105[k])) {
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

static boolean_T ef_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i131;
  boolean_T exitg1;
  static const char cv130[11] = { 'P', 'C', 'C', 'O', 'M', 'P', 'O', 'S', 'I',
    'T', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i131 = varargin_1->size[k];
      if (i131 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv130[k])) {
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

static boolean_T eg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i156;
  boolean_T exitg1;
  static const char cv155[14] = { 'P', 'C', 'B', 'I', 'C', 'G', 'S', 'T', 'A',
    'B', 'C', 'U', 'S', 'P' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i156 = varargin_1->size[k];
      if (i156 != 13 * k + 1) {
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
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv155[k])) {
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

static boolean_T f_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i7;
  boolean_T exitg1;
  static const char cv6[5] = { 'M', 'A', 'T', 'I', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i7 = varargin_1->size[k];
      if (i7 != (k << 2) + 1) {
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
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv6[k])) {
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

static boolean_T fb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i32;
  boolean_T exitg1;
  static const char cv31[10] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'B', 'A', 'I',
    'J' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i32 = varargin_1->size[k];
      if (i32 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv31[k])) {
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

static boolean_T fc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i57;
  boolean_T exitg1;
  static const char cv56[9] = { 'M', 'A', 'T', 'P', 'Y', 'T', 'H', 'O', 'N' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i57 = varargin_1->size[k];
      if (i57 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv56[k])) {
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

static boolean_T fd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i82;
  boolean_T exitg1;
  static const char cv81[9] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'C', 'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i82 = varargin_1->size[k];
      if (i82 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv81[k])) {
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

static boolean_T fe_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i107;
  boolean_T exitg1;
  static const char cv106[10] = { 'K', 'S', 'P', 'P', 'R', 'E', 'O', 'N', 'L',
    'Y' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i107 = varargin_1->size[k];
      if (i107 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv106[k])) {
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

static boolean_T ff_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i132;
  boolean_T exitg1;
  static const char cv131[11] = { 'P', 'C', 'R', 'E', 'D', 'U', 'N', 'D', 'A',
    'N', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i132 = varargin_1->size[k];
      if (i132 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv131[k])) {
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

static boolean_T fg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i157;
  boolean_T exitg1;
  static const char cv156[10] = { 'P', 'C', 'A', 'I', 'N', 'V', 'C', 'U', 'S',
    'P' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i157 = varargin_1->size[k];
      if (i157 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv156[k])) {
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

static boolean_T g_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i8;
  boolean_T exitg1;
  static const char cv7[6] = { 'M', 'A', 'T', 'A', 'I', 'J' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i8 = varargin_1->size[k];
      if (i8 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv7[k])) {
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

static boolean_T gb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i33;
  boolean_T exitg1;
  static const char cv32[10] = { 'M', 'A', 'T', 'M', 'P', 'I', 'B', 'A', 'I',
    'J' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i33 = varargin_1->size[k];
      if (i33 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv32[k])) {
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

static boolean_T gc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i58;
  boolean_T exitg1;
  static const char cv57[14] = { 'M', 'A', 'T', 'H', 'Y', 'P', 'R', 'E', 'S',
    'T', 'R', 'U', 'C', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i58 = varargin_1->size[k];
      if (i58 != 13 * k + 1) {
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
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv57[k])) {
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

static boolean_T gd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i83;
  boolean_T exitg1;
  static const char cv82[11] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'C', 'G',
    'R', 'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i83 = varargin_1->size[k];
      if (i83 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv82[k])) {
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

static boolean_T ge_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i108;
  boolean_T exitg1;
  static const char cv107[6] = { 'K', 'S', 'P', 'Q', 'C', 'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i108 = varargin_1->size[k];
      if (i108 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv107[k])) {
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

static boolean_T gf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i133;
  boolean_T exitg1;
  static const char cv132[6] = { 'P', 'C', 'S', 'P', 'A', 'I' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i133 = varargin_1->size[k];
      if (i133 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv132[k])) {
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

static boolean_T gg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i158;
  boolean_T exitg1;
  static const char cv157[6] = { 'P', 'C', 'B', 'D', 'D', 'C' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i158 = varargin_1->size[k];
      if (i158 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv157[k])) {
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

static boolean_T h_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i9;
  boolean_T exitg1;
  static const char cv8[9] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i9 = varargin_1->size[k];
      if (i9 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv8[k])) {
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

static boolean_T hb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i34;
  boolean_T exitg1;
  static const char cv33[9] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'D', 'J' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i34 = varargin_1->size[k];
      if (i34 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv33[k])) {
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

static boolean_T hc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i59;
  boolean_T exitg1;
  static const char cv58[15] = { 'M', 'A', 'T', 'H', 'Y', 'P', 'R', 'E', 'S',
    'S', 'T', 'R', 'U', 'C', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i59 = varargin_1->size[k];
      if (i59 != 14 * k + 1) {
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
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv58[k])) {
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

static boolean_T hd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i84;
  boolean_T exitg1;
  static const char cv83[7] = { 'K', 'S', 'P', 'C', 'G', 'N', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i84 = varargin_1->size[k];
      if (i84 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv83[k])) {
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

static boolean_T he_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i109;
  boolean_T exitg1;
  static const char cv108[7] = { 'K', 'S', 'P', 'B', 'I', 'C', 'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i109 = varargin_1->size[k];
      if (i109 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv108[k])) {
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

static boolean_T hf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i134;
  boolean_T exitg1;
  static const char cv133[4] = { 'P', 'C', 'N', 'N' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i134 = varargin_1->size[k];
      if (i134 != 3 * k + 1) {
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
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv133[k])) {
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

static boolean_T hg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i159;
  boolean_T exitg1;
  static const char cv158[10] = { 'P', 'C', 'K', 'A', 'C', 'Z', 'M', 'A', 'R',
    'Z' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i159 = varargin_1->size[k];
      if (i159 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv158[k])) {
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

static boolean_T i_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i10;
  boolean_T exitg1;
  static const char cv9[9] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i10 = varargin_1->size[k];
      if (i10 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv9[k])) {
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

static boolean_T ib_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i35;
  boolean_T exitg1;
  static const char cv34[8] = { 'M', 'A', 'T', 'S', 'B', 'A', 'I', 'J' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i35 = varargin_1->size[k];
      if (i35 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv34[k])) {
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

static boolean_T ic_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i60;
  boolean_T exitg1;
  static const char cv59[12] = { 'M', 'A', 'T', 'S', 'U', 'B', 'M', 'A', 'T',
    'R', 'I', 'X' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i60 = varargin_1->size[k];
      if (i60 != 11 * k + 1) {
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
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv59[k])) {
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

static boolean_T id_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i85;
  boolean_T exitg1;
  static const char cv84[7] = { 'K', 'S', 'P', 'N', 'A', 'S', 'H' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i85 = varargin_1->size[k];
      if (i85 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv84[k])) {
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

static boolean_T ie_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i110;
  boolean_T exitg1;
  static const char cv109[9] = { 'K', 'S', 'P', 'M', 'I', 'N', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i110 = varargin_1->size[k];
      if (i110 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv109[k])) {
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

static boolean_T if_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i135;
  boolean_T exitg1;
  static const char cv134[10] = { 'P', 'C', 'C', 'H', 'O', 'L', 'E', 'S', 'K',
    'Y' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i135 = varargin_1->size[k];
      if (i135 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv134[k])) {
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

static boolean_T ig_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i160;
  boolean_T exitg1;
  static const char cv159[11] = { 'P', 'C', 'T', 'E', 'L', 'E', 'S', 'C', 'O',
    'P', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i160 = varargin_1->size[k];
      if (i160 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv159[k])) {
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

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i1;
  boolean_T exitg1;
  static const char cv1[17] = { 'P', 'E', 'T', 'S', 'C', '_', 'N', 'U', 'L', 'L',
    '_', 'S', 'T', 'R', 'I', 'N', 'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i1 = varargin_1->size[k];
      if (i1 != (k << 4) + 1) {
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
    while ((!exitg1) && (k < 17)) {
      if (!(varargin_1->data[k] == cv1[k])) {
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

static boolean_T j_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i11;
  boolean_T exitg1;
  static const char cv10[9] = { 'M', 'A', 'T', 'A', 'I', 'J', 'C', 'R', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i11 = varargin_1->size[k];
      if (i11 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv10[k])) {
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

static boolean_T jb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i36;
  boolean_T exitg1;
  static const char cv35[11] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'S', 'B', 'A',
    'I', 'J' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i36 = varargin_1->size[k];
      if (i36 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv35[k])) {
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

static boolean_T jc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i61;
  boolean_T exitg1;
  static const char cv60[11] = { 'M', 'A', 'T', 'L', 'O', 'C', 'A', 'L', 'R',
    'E', 'F' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i61 = varargin_1->size[k];
      if (i61 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv60[k])) {
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

static boolean_T jd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i86;
  boolean_T exitg1;
  static const char cv85[7] = { 'K', 'S', 'P', 'S', 'T', 'C', 'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i86 = varargin_1->size[k];
      if (i86 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv85[k])) {
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

static boolean_T je_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i111;
  boolean_T exitg1;
  static const char cv110[9] = { 'K', 'S', 'P', 'S', 'Y', 'M', 'M', 'L', 'Q' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i111 = varargin_1->size[k];
      if (i111 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv110[k])) {
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

static boolean_T jf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i136;
  boolean_T exitg1;
  static const char cv135[10] = { 'P', 'C', 'P', 'B', 'J', 'A', 'C', 'O', 'B',
    'I' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i136 = varargin_1->size[k];
      if (i136 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv135[k])) {
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

static boolean_T jg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i161;
  boolean_T exitg1;
  static const char cv160[16] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'S', 'U', 'P', 'E', 'R', 'L', 'U' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i161 = varargin_1->size[k];
      if (i161 != 15 * k + 1) {
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
    while ((!exitg1) && (k < 16)) {
      if (!(varargin_1->data[k] == cv160[k])) {
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

static boolean_T k_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i12;
  boolean_T exitg1;
  static const char cv11[12] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'C', 'R', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i12 = varargin_1->size[k];
      if (i12 != 11 * k + 1) {
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
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv11[k])) {
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

static boolean_T kb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i37;
  boolean_T exitg1;
  static const char cv36[11] = { 'M', 'A', 'T', 'M', 'P', 'I', 'S', 'B', 'A',
    'I', 'J' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i37 = varargin_1->size[k];
      if (i37 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv36[k])) {
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

static boolean_T kc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i62;
  boolean_T exitg1;
  static const char cv61[7] = { 'M', 'A', 'T', 'N', 'E', 'S', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i62 = varargin_1->size[k];
      if (i62 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv61[k])) {
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

static boolean_T kd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i87;
  boolean_T exitg1;
  static const char cv86[7] = { 'K', 'S', 'P', 'G', 'L', 'T', 'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i87 = varargin_1->size[k];
      if (i87 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv86[k])) {
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

static boolean_T ke_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i112;
  boolean_T exitg1;
  static const char cv111[6] = { 'K', 'S', 'P', 'L', 'C', 'D' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i112 = varargin_1->size[k];
      if (i112 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv111[k])) {
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

static boolean_T kf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i137;
  boolean_T exitg1;
  static const char cv136[5] = { 'P', 'C', 'M', 'A', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i137 = varargin_1->size[k];
      if (i137 != (k << 2) + 1) {
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
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv136[k])) {
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

static boolean_T kg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i162;
  boolean_T exitg1;
  static const char cv161[21] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'S', 'U', 'P', 'E', 'R', 'L', 'U', '_', 'D', 'I', 'S', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i162 = varargin_1->size[k];
      if (i162 != 20 * k + 1) {
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
    while ((!exitg1) && (k < 21)) {
      if (!(varargin_1->data[k] == cv161[k])) {
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

static boolean_T l_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i13;
  boolean_T exitg1;
  static const char cv12[12] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'C', 'R', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i13 = varargin_1->size[k];
      if (i13 != 11 * k + 1) {
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
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv12[k])) {
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

static boolean_T lb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i38;
  boolean_T exitg1;
  static const char cv37[11] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'B', 'S', 'T',
    'R', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i38 = varargin_1->size[k];
      if (i38 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv37[k])) {
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

static boolean_T lc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i63;
  boolean_T exitg1;
  static const char cv62[15] = { 'M', 'A', 'T', 'P', 'R', 'E', 'A', 'L', 'L',
    'O', 'C', 'A', 'T', 'O', 'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i63 = varargin_1->size[k];
      if (i63 != 14 * k + 1) {
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
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv62[k])) {
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

static boolean_T ld_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i88;
  boolean_T exitg1;
  static const char cv87[6] = { 'K', 'S', 'P', 'F', 'C', 'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i88 = varargin_1->size[k];
      if (i88 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv87[k])) {
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

static boolean_T le_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i113;
  boolean_T exitg1;
  static const char cv112[9] = { 'K', 'S', 'P', 'P', 'Y', 'T', 'H', 'O', 'N' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i113 = varargin_1->size[k];
      if (i113 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv112[k])) {
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

static boolean_T lf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i138;
  boolean_T exitg1;
  static const char cv137[7] = { 'P', 'C', 'H', 'Y', 'P', 'R', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i138 = varargin_1->size[k];
      if (i138 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv137[k])) {
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

static boolean_T lg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i163;
  boolean_T exitg1;
  static const char cv162[16] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'U', 'M', 'F', 'P', 'A', 'C', 'K' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i163 = varargin_1->size[k];
      if (i163 != 15 * k + 1) {
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
    while ((!exitg1) && (k < 16)) {
      if (!(varargin_1->data[k] == cv162[k])) {
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

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i180;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i180 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i180, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i180 = 0; i180 < loop_ub; i180++) {
    b_varargin_3->data[i180] = varargin_3->data[i180];
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
  int exitg2;
  int i14;
  boolean_T exitg1;
  static const char cv13[10] = { 'M', 'A', 'T', 'A', 'I', 'J', 'C', 'U', 'S',
    'P' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i14 = varargin_1->size[k];
      if (i14 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv13[k])) {
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

static boolean_T mb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i39;
  boolean_T exitg1;
  static const char cv38[11] = { 'M', 'A', 'T', 'M', 'P', 'I', 'B', 'S', 'T',
    'R', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i39 = varargin_1->size[k];
      if (i39 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv38[k])) {
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

static boolean_T mc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i64;
  boolean_T exitg1;
  static const char cv63[6] = { 'V', 'E', 'C', 'S', 'E', 'Q' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i64 = varargin_1->size[k];
      if (i64 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv63[k])) {
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

static boolean_T md_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i89;
  boolean_T exitg1;
  static const char cv88[10] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'F', 'C',
    'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i89 = varargin_1->size[k];
      if (i89 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv88[k])) {
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

static boolean_T me_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i114;
  boolean_T exitg1;
  static const char cv113[6] = { 'K', 'S', 'P', 'G', 'C', 'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i114 = varargin_1->size[k];
      if (i114 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv113[k])) {
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

static boolean_T mf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i139;
  boolean_T exitg1;
  static const char cv138[7] = { 'P', 'C', 'P', 'A', 'R', 'M', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i139 = varargin_1->size[k];
      if (i139 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv138[k])) {
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

static boolean_T mg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i164;
  boolean_T exitg1;
  static const char cv163[16] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'C', 'H', 'O', 'L', 'M', 'O', 'D' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i164 = varargin_1->size[k];
      if (i164 != 15 * k + 1) {
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
    while ((!exitg1) && (k < 16)) {
      if (!(varargin_1->data[k] == cv163[k])) {
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

static boolean_T n_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i15;
  boolean_T exitg1;
  static const char cv14[13] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'C', 'U', 'S', 'P' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i15 = varargin_1->size[k];
      if (i15 != 12 * k + 1) {
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
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv14[k])) {
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

static boolean_T nb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i40;
  boolean_T exitg1;
  static const char cv39[8] = { 'M', 'A', 'T', 'B', 'S', 'T', 'R', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i40 = varargin_1->size[k];
      if (i40 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv39[k])) {
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

static boolean_T nc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i65;
  boolean_T exitg1;
  static const char cv64[6] = { 'V', 'E', 'C', 'M', 'P', 'I' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i65 = varargin_1->size[k];
      if (i65 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv64[k])) {
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

static boolean_T nd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i90;
  boolean_T exitg1;
  static const char cv89[8] = { 'K', 'S', 'P', 'G', 'M', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i90 = varargin_1->size[k];
      if (i90 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv89[k])) {
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

static boolean_T ne_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i115;
  boolean_T exitg1;
  static const char cv114[10] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'G', 'C',
    'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i115 = varargin_1->size[k];
      if (i115 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv114[k])) {
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

static boolean_T nf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i140;
  boolean_T exitg1;
  static const char cv139[12] = { 'P', 'C', 'F', 'I', 'E', 'L', 'D', 'S', 'P',
    'L', 'I', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i140 = varargin_1->size[k];
      if (i140 != 11 * k + 1) {
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
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv139[k])) {
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

static boolean_T ng_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i165;
  boolean_T exitg1;
  static const char cv164[15] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'C', 'L', 'I', 'Q', 'U', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i165 = varargin_1->size[k];
      if (i165 != 14 * k + 1) {
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
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv164[k])) {
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

static boolean_T o_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i16;
  boolean_T exitg1;
  static const char cv15[13] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'C', 'U', 'S', 'P' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i16 = varargin_1->size[k];
      if (i16 != 12 * k + 1) {
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
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv15[k])) {
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

static boolean_T ob_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i41;
  boolean_T exitg1;
  static const char cv40[12] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'S', 'B', 'S',
    'T', 'R', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i41 = varargin_1->size[k];
      if (i41 != 11 * k + 1) {
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
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv40[k])) {
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

static boolean_T oc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i66;
  boolean_T exitg1;
  static const char cv65[11] = { 'V', 'E', 'C', 'S', 'T', 'A', 'N', 'D', 'A',
    'R', 'D' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i66 = varargin_1->size[k];
      if (i66 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv65[k])) {
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

static boolean_T od_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i91;
  boolean_T exitg1;
  static const char cv90[13] = { 'K', 'S', 'P', 'P', 'I', 'P', 'E', 'F', 'G',
    'M', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i91 = varargin_1->size[k];
      if (i91 != 12 * k + 1) {
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
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv90[k])) {
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

static boolean_T oe_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i116;
  boolean_T exitg1;
  static const char cv115[8] = { 'K', 'S', 'P', 'T', 'S', 'I', 'R', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i116 = varargin_1->size[k];
      if (i116 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv115[k])) {
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

static boolean_T of_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i141;
  boolean_T exitg1;
  static const char cv140[5] = { 'P', 'C', 'T', 'F', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i141 = varargin_1->size[k];
      if (i141 != (k << 2) + 1) {
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
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv140[k])) {
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

static boolean_T og_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i166;
  boolean_T exitg1;
  static const char cv165[12] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'K', 'L', 'U' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i166 = varargin_1->size[k];
      if (i166 != 11 * k + 1) {
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
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv165[k])) {
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

static boolean_T p_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i17;
  boolean_T exitg1;
  static const char cv16[14] = { 'M', 'A', 'T', 'A', 'I', 'J', 'C', 'U', 'S',
    'P', 'A', 'R', 'S', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i17 = varargin_1->size[k];
      if (i17 != 13 * k + 1) {
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
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv16[k])) {
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

static boolean_T pb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i42;
  boolean_T exitg1;
  static const char cv41[12] = { 'M', 'A', 'T', 'M', 'P', 'I', 'S', 'B', 'S',
    'T', 'R', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i42 = varargin_1->size[k];
      if (i42 != 11 * k + 1) {
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
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv41[k])) {
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

static boolean_T pc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i67;
  boolean_T exitg1;
  static const char cv66[9] = { 'V', 'E', 'C', 'S', 'H', 'A', 'R', 'E', 'D' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i67 = varargin_1->size[k];
      if (i67 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv66[k])) {
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

static boolean_T pd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i92;
  boolean_T exitg1;
  static const char cv91[9] = { 'K', 'S', 'P', 'F', 'G', 'M', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i92 = varargin_1->size[k];
      if (i92 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv91[k])) {
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

static boolean_T pe_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i117;
  boolean_T exitg1;
  static const char cv116[7] = { 'K', 'S', 'P', 'C', 'G', 'L', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i117 = varargin_1->size[k];
      if (i117 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv116[k])) {
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

static boolean_T pf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i142;
  boolean_T exitg1;
  static const char cv141[4] = { 'P', 'C', 'M', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i142 = varargin_1->size[k];
      if (i142 != 3 * k + 1) {
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
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv141[k])) {
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

static boolean_T pg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i167;
  boolean_T exitg1;
  static const char cv166[18] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'E', 'L', 'E', 'M', 'E', 'N', 'T', 'A', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i167 = varargin_1->size[k];
      if (i167 != 17 * k + 1) {
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
    while ((!exitg1) && (k < 18)) {
      if (!(varargin_1->data[k] == cv166[k])) {
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

static boolean_T q_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i18;
  boolean_T exitg1;
  static const char cv17[17] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'C', 'U', 'S', 'P', 'A', 'R', 'S', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i18 = varargin_1->size[k];
      if (i18 != (k << 4) + 1) {
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
    while ((!exitg1) && (k < 17)) {
      if (!(varargin_1->data[k] == cv17[k])) {
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

static boolean_T qb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i43;
  boolean_T exitg1;
  static const char cv42[9] = { 'M', 'A', 'T', 'S', 'B', 'S', 'T', 'R', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i43 = varargin_1->size[k];
      if (i43 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv42[k])) {
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

static boolean_T qc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i68;
  boolean_T exitg1;
  static const char cv67[10] = { 'V', 'E', 'C', 'S', 'E', 'Q', 'C', 'U', 'S',
    'P' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i68 = varargin_1->size[k];
      if (i68 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv67[k])) {
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

static boolean_T qd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i93;
  boolean_T exitg1;
  static const char cv92[9] = { 'K', 'S', 'P', 'L', 'G', 'M', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i93 = varargin_1->size[k];
      if (i93 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv92[k])) {
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

static boolean_T qe_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i118;
  boolean_T exitg1;
  static const char cv117[6] = { 'P', 'C', 'N', 'O', 'N', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i118 = varargin_1->size[k];
      if (i118 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv117[k])) {
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

static boolean_T qf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i143;
  boolean_T exitg1;
  static const char cv142[10] = { 'P', 'C', 'G', 'A', 'L', 'E', 'R', 'K', 'I',
    'N' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i143 = varargin_1->size[k];
      if (i143 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv142[k])) {
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

static boolean_T qg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i168;
  boolean_T exitg1;
  static const char cv167[13] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'E', 'S', 'S', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i168 = varargin_1->size[k];
      if (i168 != 12 * k + 1) {
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
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv167[k])) {
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

static boolean_T r_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i19;
  boolean_T exitg1;
  static const char cv18[17] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'C', 'U', 'S', 'P', 'A', 'R', 'S', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i19 = varargin_1->size[k];
      if (i19 != (k << 4) + 1) {
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
    while ((!exitg1) && (k < 17)) {
      if (!(varargin_1->data[k] == cv18[k])) {
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

static boolean_T rb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i44;
  boolean_T exitg1;
  static const char cv43[7] = { 'M', 'A', 'T', 'D', 'A', 'A', 'D' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i44 = varargin_1->size[k];
      if (i44 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv43[k])) {
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

static boolean_T rc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i69;
  boolean_T exitg1;
  static const char cv68[10] = { 'V', 'E', 'C', 'M', 'P', 'I', 'C', 'U', 'S',
    'P' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i69 = varargin_1->size[k];
      if (i69 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv68[k])) {
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

static boolean_T rd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i94;
  boolean_T exitg1;
  static const char cv93[9] = { 'K', 'S', 'P', 'D', 'G', 'M', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i94 = varargin_1->size[k];
      if (i94 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv93[k])) {
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

static boolean_T re_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i119;
  boolean_T exitg1;
  static const char cv118[8] = { 'P', 'C', 'J', 'A', 'C', 'O', 'B', 'I' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i119 = varargin_1->size[k];
      if (i119 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv118[k])) {
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

static boolean_T rf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i144;
  boolean_T exitg1;
  static const char cv143[8] = { 'P', 'C', 'E', 'X', 'O', 'T', 'I', 'C' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i144 = varargin_1->size[k];
      if (i144 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv143[k])) {
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

static boolean_T rg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i169;
  boolean_T exitg1;
  static const char cv168[14] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'L', 'U', 'S', 'O', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i169 = varargin_1->size[k];
      if (i169 != 13 * k + 1) {
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
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv168[k])) {
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

static boolean_T s_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i20;
  boolean_T exitg1;
  static const char cv19[14] = { 'M', 'A', 'T', 'A', 'I', 'J', 'V', 'I', 'E',
    'N', 'N', 'A', 'C', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i20 = varargin_1->size[k];
      if (i20 != 13 * k + 1) {
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
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv19[k])) {
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

static boolean_T sb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i45;
  boolean_T exitg1;
  static const char cv44[7] = { 'M', 'A', 'T', 'M', 'F', 'F', 'D' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i45 = varargin_1->size[k];
      if (i45 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv44[k])) {
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

static boolean_T sc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i70;
  boolean_T exitg1;
  static const char cv69[7] = { 'V', 'E', 'C', 'C', 'U', 'S', 'P' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i70 = varargin_1->size[k];
      if (i70 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv69[k])) {
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

static boolean_T sd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i95;
  boolean_T exitg1;
  static const char cv94[9] = { 'K', 'S', 'P', 'P', 'G', 'M', 'R', 'E', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i95 = varargin_1->size[k];
      if (i95 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv94[k])) {
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

static boolean_T se_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i120;
  boolean_T exitg1;
  static const char cv119[5] = { 'P', 'C', 'S', 'O', 'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i120 = varargin_1->size[k];
      if (i120 != (k << 2) + 1) {
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
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv119[k])) {
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

static boolean_T sf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i145;
  boolean_T exitg1;
  static const char cv144[4] = { 'P', 'C', 'C', 'P' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i145 = varargin_1->size[k];
      if (i145 != 3 * k + 1) {
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
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv144[k])) {
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

static boolean_T sg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i170;
  boolean_T exitg1;
  static const char cv169[14] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'M', 'U', 'M', 'P', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i170 = varargin_1->size[k];
      if (i170 != 13 * k + 1) {
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
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv169[k])) {
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

static boolean_T t_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i21;
  boolean_T exitg1;
  static const char cv20[17] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'V', 'I', 'E', 'N', 'N', 'A', 'C', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i21 = varargin_1->size[k];
      if (i21 != (k << 4) + 1) {
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
    while ((!exitg1) && (k < 17)) {
      if (!(varargin_1->data[k] == cv20[k])) {
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

static boolean_T tb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i46;
  boolean_T exitg1;
  static const char cv45[9] = { 'M', 'A', 'T', 'N', 'O', 'R', 'M', 'A', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i46 = varargin_1->size[k];
      if (i46 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv45[k])) {
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

static boolean_T tc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i71;
  boolean_T exitg1;
  static const char cv70[14] = { 'V', 'E', 'C', 'S', 'E', 'Q', 'V', 'I', 'E',
    'N', 'N', 'A', 'C', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i71 = varargin_1->size[k];
      if (i71 != 13 * k + 1) {
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
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv70[k])) {
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

static boolean_T td_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i96;
  boolean_T exitg1;
  static const char cv95[8] = { 'K', 'S', 'P', 'T', 'C', 'Q', 'M', 'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i96 = varargin_1->size[k];
      if (i96 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv95[k])) {
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

static boolean_T te_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i121;
  boolean_T exitg1;
  static const char cv120[4] = { 'P', 'C', 'L', 'U' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i121 = varargin_1->size[k];
      if (i121 != 3 * k + 1) {
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
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv120[k])) {
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

static boolean_T tf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i146;
  boolean_T exitg1;
  static const char cv145[6] = { 'P', 'C', 'B', 'F', 'B', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i146 = varargin_1->size[k];
      if (i146 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv145[k])) {
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

static boolean_T tg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i171;
  boolean_T exitg1;
  static const char cv170[20] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'M', 'K', 'L', '_', 'P', 'A', 'R', 'D', 'I', 'S', 'O' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i171 = varargin_1->size[k];
      if (i171 != 19 * k + 1) {
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
    while ((!exitg1) && (k < 20)) {
      if (!(varargin_1->data[k] == cv170[k])) {
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

static boolean_T u_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i22;
  boolean_T exitg1;
  static const char cv21[17] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'V', 'I', 'E', 'N', 'N', 'A', 'C', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i22 = varargin_1->size[k];
      if (i22 != (k << 4) + 1) {
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
    while ((!exitg1) && (k < 17)) {
      if (!(varargin_1->data[k] == cv21[k])) {
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

static boolean_T ub_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i47;
  boolean_T exitg1;
  static const char cv46[18] = { 'M', 'A', 'T', 'N', 'O', 'R', 'M', 'A', 'L',
    'H', 'E', 'R', 'M', 'I', 'T', 'I', 'A', 'N' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i47 = varargin_1->size[k];
      if (i47 != 17 * k + 1) {
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
    while ((!exitg1) && (k < 18)) {
      if (!(varargin_1->data[k] == cv46[k])) {
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

static boolean_T uc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i72;
  boolean_T exitg1;
  static const char cv71[14] = { 'V', 'E', 'C', 'M', 'P', 'I', 'V', 'I', 'E',
    'N', 'N', 'A', 'C', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i72 = varargin_1->size[k];
      if (i72 != 13 * k + 1) {
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
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv71[k])) {
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

static boolean_T ud_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i97;
  boolean_T exitg1;
  static const char cv96[7] = { 'K', 'S', 'P', 'B', 'C', 'G', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i97 = varargin_1->size[k];
      if (i97 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv96[k])) {
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

static boolean_T ue_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i122;
  boolean_T exitg1;
  static const char cv121[7] = { 'P', 'C', 'S', 'H', 'E', 'L', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i122 = varargin_1->size[k];
      if (i122 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv121[k])) {
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

static boolean_T uf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i147;
  boolean_T exitg1;
  static const char cv146[5] = { 'P', 'C', 'L', 'S', 'C' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i147 = varargin_1->size[k];
      if (i147 != (k << 2) + 1) {
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
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv146[k])) {
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

static boolean_T ug_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i172;
  boolean_T exitg1;
  static const char cv171[21] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'M', 'K', 'L', '_', 'C', 'P', 'A', 'R', 'D', 'I', 'S', 'O' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i172 = varargin_1->size[k];
      if (i172 != 20 * k + 1) {
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
    while ((!exitg1) && (k < 21)) {
      if (!(varargin_1->data[k] == cv171[k])) {
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

static boolean_T v_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i23;
  boolean_T exitg1;
  static const char cv22[10] = { 'M', 'A', 'T', 'A', 'I', 'J', 'P', 'E', 'R',
    'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i23 = varargin_1->size[k];
      if (i23 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv22[k])) {
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

static boolean_T vb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i48;
  boolean_T exitg1;
  static const char cv47[6] = { 'M', 'A', 'T', 'L', 'R', 'C' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i48 = varargin_1->size[k];
      if (i48 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv47[k])) {
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

static boolean_T vc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i73;
  boolean_T exitg1;
  static const char cv72[11] = { 'V', 'E', 'C', 'V', 'I', 'E', 'N', 'N', 'A',
    'C', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i73 = varargin_1->size[k];
      if (i73 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv72[k])) {
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

static boolean_T vd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i98;
  boolean_T exitg1;
  static const char cv97[8] = { 'K', 'S', 'P', 'I', 'B', 'C', 'G', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i98 = varargin_1->size[k];
      if (i98 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv97[k])) {
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

static boolean_T ve_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i123;
  boolean_T exitg1;
  static const char cv122[9] = { 'P', 'C', 'B', 'J', 'A', 'C', 'O', 'B', 'I' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i123 = varargin_1->size[k];
      if (i123 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv122[k])) {
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

static boolean_T vf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i148;
  boolean_T exitg1;
  static const char cv147[8] = { 'P', 'C', 'P', 'Y', 'T', 'H', 'O', 'N' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i148 = varargin_1->size[k];
      if (i148 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv147[k])) {
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

static boolean_T vg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i173;
  boolean_T exitg1;
  static const char cv172[15] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'P', 'A', 'S', 'T', 'I', 'X' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i173 = varargin_1->size[k];
      if (i173 != 14 * k + 1) {
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
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv172[k])) {
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

static boolean_T w_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i24;
  boolean_T exitg1;
  static const char cv23[13] = { 'M', 'A', 'T', 'S', 'E', 'Q', 'A', 'I', 'J',
    'P', 'E', 'R', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i24 = varargin_1->size[k];
      if (i24 != 12 * k + 1) {
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
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv23[k])) {
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

static boolean_T wb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i49;
  boolean_T exitg1;
  static const char cv48[10] = { 'M', 'A', 'T', 'S', 'C', 'A', 'T', 'T', 'E',
    'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i49 = varargin_1->size[k];
      if (i49 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv48[k])) {
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

static boolean_T wc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i74;
  boolean_T exitg1;
  static const char cv73[10] = { 'V', 'E', 'C', 'S', 'E', 'Q', 'C', 'U', 'D',
    'A' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i74 = varargin_1->size[k];
      if (i74 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv73[k])) {
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

static boolean_T wd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i99;
  boolean_T exitg1;
  static const char cv98[8] = { 'K', 'S', 'P', 'F', 'B', 'C', 'G', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i99 = varargin_1->size[k];
      if (i99 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv98[k])) {
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

static boolean_T we_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i124;
  boolean_T exitg1;
  static const char cv123[4] = { 'P', 'C', 'M', 'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i124 = varargin_1->size[k];
      if (i124 != 3 * k + 1) {
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
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv123[k])) {
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

static boolean_T wf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i149;
  boolean_T exitg1;
  static const char cv148[6] = { 'P', 'C', 'P', 'F', 'M', 'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i149 = varargin_1->size[k];
      if (i149 != 5 * k + 1) {
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
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv148[k])) {
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

static boolean_T wg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i174;
  boolean_T exitg1;
  static const char cv173[15] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'M', 'A', 'T', 'L', 'A', 'B' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i174 = varargin_1->size[k];
      if (i174 != 14 * k + 1) {
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
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv173[k])) {
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

static boolean_T x_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i25;
  boolean_T exitg1;
  static const char cv24[13] = { 'M', 'A', 'T', 'M', 'P', 'I', 'A', 'I', 'J',
    'P', 'E', 'R', 'M' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i25 = varargin_1->size[k];
      if (i25 != 12 * k + 1) {
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
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv24[k])) {
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

static boolean_T xb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i50;
  boolean_T exitg1;
  static const char cv49[11] = { 'M', 'A', 'T', 'B', 'L', 'O', 'C', 'K', 'M',
    'A', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i50 = varargin_1->size[k];
      if (i50 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv49[k])) {
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

static boolean_T xc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i75;
  boolean_T exitg1;
  static const char cv74[10] = { 'V', 'E', 'C', 'M', 'P', 'I', 'C', 'U', 'D',
    'A' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i75 = varargin_1->size[k];
      if (i75 != 9 * k + 1) {
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
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv74[k])) {
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

static boolean_T xd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i100;
  boolean_T exitg1;
  static const char cv99[9] = { 'K', 'S', 'P', 'F', 'B', 'C', 'G', 'S', 'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i100 = varargin_1->size[k];
      if (i100 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv99[k])) {
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

static boolean_T xe_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i125;
  boolean_T exitg1;
  static const char cv124[11] = { 'P', 'C', 'E', 'I', 'S', 'E', 'N', 'S', 'T',
    'A', 'T' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i125 = varargin_1->size[k];
      if (i125 != 10 * k + 1) {
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
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv124[k])) {
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

static boolean_T xf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i150;
  boolean_T exitg1;
  static const char cv149[9] = { 'P', 'C', 'S', 'Y', 'S', 'P', 'F', 'M', 'G' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i150 = varargin_1->size[k];
      if (i150 != (k << 3) + 1) {
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
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv149[k])) {
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

static boolean_T xg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i175;
  boolean_T exitg1;
  static const char cv174[14] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'P', 'E', 'T', 'S', 'C' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i175 = varargin_1->size[k];
      if (i175 != 13 * k + 1) {
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
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv174[k])) {
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

static boolean_T y_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i26;
  boolean_T exitg1;
  static const char cv25[8] = { 'M', 'A', 'T', 'S', 'H', 'E', 'L', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i26 = varargin_1->size[k];
      if (i26 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv25[k])) {
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

static boolean_T yb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i51;
  boolean_T exitg1;
  static const char cv50[12] = { 'M', 'A', 'T', 'C', 'O', 'M', 'P', 'O', 'S',
    'I', 'T', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i51 = varargin_1->size[k];
      if (i51 != 11 * k + 1) {
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
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv50[k])) {
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

static boolean_T yc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i76;
  boolean_T exitg1;
  static const char cv75[7] = { 'V', 'E', 'C', 'C', 'U', 'D', 'A' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i76 = varargin_1->size[k];
      if (i76 != 6 * k + 1) {
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
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv75[k])) {
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

static boolean_T yd_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i101;
  boolean_T exitg1;
  static const char cv100[8] = { 'K', 'S', 'P', 'B', 'C', 'G', 'S', 'L' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i101 = varargin_1->size[k];
      if (i101 != 7 * k + 1) {
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
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv100[k])) {
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

static boolean_T ye_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i126;
  boolean_T exitg1;
  static const char cv125[5] = { 'P', 'C', 'I', 'L', 'U' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i126 = varargin_1->size[k];
      if (i126 != (k << 2) + 1) {
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
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv125[k])) {
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

static boolean_T yf_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i151;
  boolean_T exitg1;
  static const char cv150[14] = { 'P', 'C', 'R', 'E', 'D', 'I', 'S', 'T', 'R',
    'I', 'B', 'U', 'T', 'E' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i151 = varargin_1->size[k];
      if (i151 != 13 * k + 1) {
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
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv150[k])) {
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

static boolean_T yg_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  int i176;
  boolean_T exitg1;
  static const char cv175[12] = { 'M', 'A', 'T', 'S', 'O', 'L', 'V', 'E', 'R',
    'B', 'A', 'S' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      i176 = varargin_1->size[k];
      if (i176 != 11 * k + 1) {
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
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv175[k])) {
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

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void petscGetString(const emxArray_char_T *name, emxArray_char_T *str, boolean_T
                    *toplevel)
{
  emxArray_char_T *b_str;
  emxArray_uint8_T *str1;
  const char * c_str;
  int empty;
  int i0;
  int n;
  char * ptr;
  emxArray_char_T *b_name;
  char cv0[2];
  emxInit_char_T(&b_str, 2);
  emxInit_uint8_T(&str1, 2);
  if (isequal(name)) {
    c_str = (NULL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (b_isequal(name)) {
    c_str = (MATSAME);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (c_isequal(name)) {
    c_str = (MATMAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (d_isequal(name)) {
    c_str = (MATSEQMAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (e_isequal(name)) {
    c_str = (MATMPIMAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (f_isequal(name)) {
    c_str = (MATIS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (g_isequal(name)) {
    c_str = (MATAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (h_isequal(name)) {
    c_str = (MATSEQAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (i_isequal(name)) {
    c_str = (MATMPIAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (j_isequal(name)) {
    c_str = (MATMPIAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (k_isequal(name)) {
    c_str = (MATSEQAIJCRL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (l_isequal(name)) {
    c_str = (MATMPIAIJCRL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (m_isequal(name)) {
    c_str = (MATAIJCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (n_isequal(name)) {
    c_str = (MATSEQAIJCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (o_isequal(name)) {
    c_str = (MATMPIAIJCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (p_isequal(name)) {
    c_str = (MATAIJCUSPARSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (q_isequal(name)) {
    c_str = (MATSEQAIJCUSPARSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (r_isequal(name)) {
    c_str = (MATMPIAIJCUSPARSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (s_isequal(name)) {
    c_str = (MATAIJVIENNACL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (t_isequal(name)) {
    c_str = (MATSEQAIJVIENNACL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (u_isequal(name)) {
    c_str = (MATMPIAIJVIENNACL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (v_isequal(name)) {
    c_str = (MATAIJPERM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (w_isequal(name)) {
    c_str = (MATSEQAIJPERM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (x_isequal(name)) {
    c_str = (MATMPIAIJPERM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (y_isequal(name)) {
    c_str = (MATSHELL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ab_isequal(name)) {
    c_str = (MATDENSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (bb_isequal(name)) {
    c_str = (MATSEQDENSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (cb_isequal(name)) {
    c_str = (MATMPIDENSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (db_isequal(name)) {
    c_str = (MATELEMENTAL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (eb_isequal(name)) {
    c_str = (MATBAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (fb_isequal(name)) {
    c_str = (MATSEQBAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (gb_isequal(name)) {
    c_str = (MATMPIBAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (hb_isequal(name)) {
    c_str = (MATMPIADJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ib_isequal(name)) {
    c_str = (MATSBAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (jb_isequal(name)) {
    c_str = (MATSEQSBAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (kb_isequal(name)) {
    c_str = (MATMPISBAIJ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (lb_isequal(name)) {
    c_str = (MATSEQBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (mb_isequal(name)) {
    c_str = (MATMPIBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (nb_isequal(name)) {
    c_str = (MATBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ob_isequal(name)) {
    c_str = (MATSEQSBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (pb_isequal(name)) {
    c_str = (MATMPISBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (qb_isequal(name)) {
    c_str = (MATSBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (rb_isequal(name)) {
    c_str = (MATDAAD);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (sb_isequal(name)) {
    c_str = (MATMFFD);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (tb_isequal(name)) {
    c_str = (MATNORMAL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ub_isequal(name)) {
    c_str = (MATNORMALHERMITIAN);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (vb_isequal(name)) {
    c_str = (MATLRC);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (wb_isequal(name)) {
    c_str = (MATSCATTER);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (xb_isequal(name)) {
    c_str = (MATBLOCKMAT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (yb_isequal(name)) {
    c_str = (MATCOMPOSITE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ac_isequal(name)) {
    c_str = (MATFFT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (bc_isequal(name)) {
    c_str = (MATFFTW);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (cc_isequal(name)) {
    c_str = (MATSEQCUFFT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (dc_isequal(name)) {
    c_str = (MATTRANSPOSEMAT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ec_isequal(name)) {
    c_str = (MATSCHURCOMPLEMENT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (fc_isequal(name)) {
    c_str = (MATPYTHON);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (gc_isequal(name)) {
    c_str = (MATHYPRESTRUCT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (hc_isequal(name)) {
    c_str = (MATHYPRESSTRUCT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ic_isequal(name)) {
    c_str = (MATSUBMATRIX);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (jc_isequal(name)) {
    c_str = (MATSUBMATRIX);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (kc_isequal(name)) {
    c_str = (MATNEST);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (lc_isequal(name)) {
    c_str = (MATPREALLOCATOR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (mc_isequal(name)) {
    c_str = (VECSEQ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (nc_isequal(name)) {
    c_str = (VECMPI);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (oc_isequal(name)) {
    c_str = (VECSTANDARD);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (pc_isequal(name)) {
    c_str = (VECSHARED);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (qc_isequal(name)) {
    c_str = (VECSEQCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (rc_isequal(name)) {
    c_str = (VECMPICUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (sc_isequal(name)) {
    c_str = (VECCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (tc_isequal(name)) {
    c_str = (VECSEQVIENNACL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (uc_isequal(name)) {
    c_str = (VECMPIVIENNACL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (vc_isequal(name)) {
    c_str = (VECVIENNACL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (wc_isequal(name)) {
    c_str = (VECSEQCUDA);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (xc_isequal(name)) {
    c_str = (VECMPICUDA);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (yc_isequal(name)) {
    c_str = (VECCUDA);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ad_isequal(name)) {
    c_str = (VECNEST);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (bd_isequal(name)) {
    c_str = (KSPRICHARDSON);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (cd_isequal(name)) {
    c_str = (KSPCHEBYSHEV);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (dd_isequal(name)) {
    c_str = (KSPCG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ed_isequal(name)) {
    c_str = (KSPGROPPCG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (fd_isequal(name)) {
    c_str = (KSPPIPECG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (gd_isequal(name)) {
    c_str = (KSPPIPECGRR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (hd_isequal(name)) {
    c_str = (KSPCGNE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (id_isequal(name)) {
    c_str = (KSPNASH);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (jd_isequal(name)) {
    c_str = (KSPSTCG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (kd_isequal(name)) {
    c_str = (KSPGLTR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ld_isequal(name)) {
    c_str = (KSPFCG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (md_isequal(name)) {
    c_str = (KSPPIPEFCG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (nd_isequal(name)) {
    c_str = (KSPGMRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (od_isequal(name)) {
    c_str = (KSPPIPEFGMRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (pd_isequal(name)) {
    c_str = (KSPFGMRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (qd_isequal(name)) {
    c_str = (KSPLGMRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (rd_isequal(name)) {
    c_str = (KSPDGMRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (sd_isequal(name)) {
    c_str = (KSPPGMRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (td_isequal(name)) {
    c_str = (KSPTCQMR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ud_isequal(name)) {
    c_str = (KSPBCGS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (vd_isequal(name)) {
    c_str = (KSPIBCGS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (wd_isequal(name)) {
    c_str = (KSPFBCGS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (xd_isequal(name)) {
    c_str = (KSPFBCGSR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (yd_isequal(name)) {
    c_str = (KSPBCGSL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ae_isequal(name)) {
    c_str = (KSPCGS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (be_isequal(name)) {
    c_str = (KSPTFQMR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ce_isequal(name)) {
    c_str = (KSPCR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (de_isequal(name)) {
    c_str = (KSPPIPECR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ee_isequal(name)) {
    c_str = (KSPLSQR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (fe_isequal(name)) {
    c_str = (KSPPREONLY);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ge_isequal(name)) {
    c_str = (KSPQCG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (he_isequal(name)) {
    c_str = (KSPBICG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ie_isequal(name)) {
    c_str = (KSPMINRES);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (je_isequal(name)) {
    c_str = (KSPSYMMLQ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ke_isequal(name)) {
    c_str = (KSPLCD);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (le_isequal(name)) {
    c_str = (KSPPYTHON);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (me_isequal(name)) {
    c_str = (KSPGCR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ne_isequal(name)) {
    c_str = (KSPPIPEGCR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (oe_isequal(name)) {
    c_str = (KSPTSIRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (pe_isequal(name)) {
    c_str = (KSPCGLS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (qe_isequal(name)) {
    c_str = (PCNONE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (re_isequal(name)) {
    c_str = (PCJACOBI);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (se_isequal(name)) {
    c_str = (PCSOR);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (te_isequal(name)) {
    c_str = (PCLU);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ue_isequal(name)) {
    c_str = (PCSHELL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ve_isequal(name)) {
    c_str = (PCBJACOBI);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (we_isequal(name)) {
    c_str = (PCMG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (xe_isequal(name)) {
    c_str = (PCEISENSTAT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ye_isequal(name)) {
    c_str = (PCILU);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (af_isequal(name)) {
    c_str = (PCICC);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (bf_isequal(name)) {
    c_str = (PCASM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (cf_isequal(name)) {
    c_str = (PCGASM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (df_isequal(name)) {
    c_str = (PCKSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ef_isequal(name)) {
    c_str = (PCCOMPOSITE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ff_isequal(name)) {
    c_str = (PCREDUNDANT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (gf_isequal(name)) {
    c_str = (PCSPAI);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (hf_isequal(name)) {
    c_str = (PCNN);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (if_isequal(name)) {
    c_str = (PCCHOLESKY);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (jf_isequal(name)) {
    c_str = (PCPBJACOBI);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (kf_isequal(name)) {
    c_str = (PCMAT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (lf_isequal(name)) {
    c_str = (PCHYPRE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (mf_isequal(name)) {
    c_str = (PCPARMS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (nf_isequal(name)) {
    c_str = (PCFIELDSPLIT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (of_isequal(name)) {
    c_str = (PCTFS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (pf_isequal(name)) {
    c_str = (PCML);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (qf_isequal(name)) {
    c_str = (PCGALERKIN);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (rf_isequal(name)) {
    c_str = (PCEXOTIC);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (sf_isequal(name)) {
    c_str = (PCCP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (tf_isequal(name)) {
    c_str = (PCBFBT);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (uf_isequal(name)) {
    c_str = (PCLSC);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (vf_isequal(name)) {
    c_str = (PCPYTHON);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (wf_isequal(name)) {
    c_str = (PCPFMG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (xf_isequal(name)) {
    c_str = (PCSYSPFMG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (yf_isequal(name)) {
    c_str = (PCREDISTRIBUTE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ag_isequal(name)) {
    c_str = (PCSVD);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (bg_isequal(name)) {
    c_str = (PCGAMG);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (cg_isequal(name)) {
    c_str = (PCSACUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (dg_isequal(name)) {
    c_str = (PCSACUSPPOLY);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (eg_isequal(name)) {
    c_str = (PCBICGSTABCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (fg_isequal(name)) {
    c_str = (PCAINVCUSP);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (gg_isequal(name)) {
    c_str = (PCBDDC);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (hg_isequal(name)) {
    c_str = (PCKACZMARZ);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ig_isequal(name)) {
    c_str = (PCTELESCOPE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (jg_isequal(name)) {
    c_str = (MATSOLVERSUPERLU);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (kg_isequal(name)) {
    c_str = (MATSOLVERSUPERLU_DIST);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (lg_isequal(name)) {
    c_str = (MATSOLVERUMFPACK);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (mg_isequal(name)) {
    c_str = (MATSOLVERCHOLMOD);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ng_isequal(name)) {
    c_str = (MATSOLVERCLIQUE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (og_isequal(name)) {
    c_str = (MATSOLVERKLU);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (pg_isequal(name)) {
    c_str = (MATSOLVERELEMENTAL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (qg_isequal(name)) {
    c_str = (MATSOLVERESSL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (rg_isequal(name)) {
    c_str = (MATSOLVERLUSOL);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (sg_isequal(name)) {
    c_str = (MATSOLVERMUMPS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (tg_isequal(name)) {
    c_str = (MATSOLVERMKL_PARDISO);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ug_isequal(name)) {
    c_str = (MATSOLVERMKL_CPARDISO);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (vg_isequal(name)) {
    c_str = (MATSOLVERPASTIX);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (wg_isequal(name)) {
    c_str = (MATSOLVERMATLAB);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (xg_isequal(name)) {
    c_str = (MATSOLVERPETSC);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (yg_isequal(name)) {
    c_str = (MATSOLVERBAS);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ah_isequal(name)) {
    c_str = (MATSOLVERCUSPARSE);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (bh_isequal(name)) {
    c_str = (MATSOLVERBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else if (ch_isequal(name)) {
    c_str = (MATSOLVERSBSTRM);
    empty = !(c_str);
    if (!(empty != 0)) {
      n = strlen(c_str) + 1;
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = n;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
      for (i0 = 0; i0 < n; i0++) {
        str1->data[i0] = 0;
      }

      ptr = (char *)(c_str);
      for (empty = 1; empty <= n; empty++) {
        str1->data[empty - 1] = *(ptr);
        ptr = ptr+1;
      }
    } else {
      i0 = str1->size[0] * str1->size[1];
      str1->size[0] = 1;
      str1->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)str1, i0, (int)sizeof(unsigned char));
    }

    b_char(str1, b_str);
    i0 = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = b_str->size[1];
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    empty = b_str->size[0] * b_str->size[1];
    for (i0 = 0; i0 < empty; i0++) {
      str->data[i0] = b_str->data[i0];
    }

    *toplevel = true;
  } else {
    emxInit_char_T(&b_name, 2);
    i0 = b_name->size[0] * b_name->size[1];
    b_name->size[0] = 1;
    b_name->size[1] = name->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_name, i0, (int)sizeof(char));
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
    emxEnsureCapacity((emxArray__common *)str, i0, (int)sizeof(char));
    emxFree_char_T(&b_name);
    for (i0 = 0; i0 < 2; i0++) {
      str->data[i0] = cv0[i0];
    }

    *toplevel = true;
  }

  emxFree_uint8_T(&str1);
  emxFree_char_T(&b_str);
}

void petscGetString_initialize(void)
{
}

void petscGetString_terminate(void)
{
}
