#include "petscGetEnum.h"
#include "petscGetEnum_types.h"
#include "m2c.h"
#include "petsc4m.h"

static boolean_T ab_strcmp(const emxArray_char_T *a);

static boolean_T ac_strcmp(const emxArray_char_T *a);

static boolean_T b_strcmp(const emxArray_char_T *a);

static boolean_T bb_strcmp(const emxArray_char_T *a);

static boolean_T bc_strcmp(const emxArray_char_T *a);

static boolean_T c_strcmp(const emxArray_char_T *a);

static boolean_T cb_strcmp(const emxArray_char_T *a);

static boolean_T cc_strcmp(const emxArray_char_T *a);

static boolean_T d_strcmp(const emxArray_char_T *a);

static boolean_T db_strcmp(const emxArray_char_T *a);

static boolean_T dc_strcmp(const emxArray_char_T *a);

static boolean_T e_strcmp(const emxArray_char_T *a);

static boolean_T eb_strcmp(const emxArray_char_T *a);

static boolean_T ec_strcmp(const emxArray_char_T *a);

static boolean_T f_strcmp(const emxArray_char_T *a);

static boolean_T fb_strcmp(const emxArray_char_T *a);

static boolean_T fc_strcmp(const emxArray_char_T *a);

static boolean_T g_strcmp(const emxArray_char_T *a);

static boolean_T gb_strcmp(const emxArray_char_T *a);

static boolean_T gc_strcmp(const emxArray_char_T *a);

static boolean_T h_strcmp(const emxArray_char_T *a);

static boolean_T hb_strcmp(const emxArray_char_T *a);

static boolean_T hc_strcmp(const emxArray_char_T *a);

static boolean_T i_strcmp(const emxArray_char_T *a);

static boolean_T ib_strcmp(const emxArray_char_T *a);

static boolean_T ic_strcmp(const emxArray_char_T *a);

static boolean_T j_strcmp(const emxArray_char_T *a);

static boolean_T jb_strcmp(const emxArray_char_T *a);

static boolean_T jc_strcmp(const emxArray_char_T *a);

static boolean_T k_strcmp(const emxArray_char_T *a);

static boolean_T kb_strcmp(const emxArray_char_T *a);

static boolean_T kc_strcmp(const emxArray_char_T *a);

static boolean_T l_strcmp(const emxArray_char_T *a);

static boolean_T lb_strcmp(const emxArray_char_T *a);

static boolean_T lc_strcmp(const emxArray_char_T *a);

static void m2c_error(const emxArray_char_T *varargin_3);

static boolean_T m_strcmp(const emxArray_char_T *a);

static boolean_T mb_strcmp(const emxArray_char_T *a);

static boolean_T mc_strcmp(const emxArray_char_T *a);

static boolean_T n_strcmp(const emxArray_char_T *a);

static boolean_T nb_strcmp(const emxArray_char_T *a);

static boolean_T nc_strcmp(const emxArray_char_T *a);

static boolean_T o_strcmp(const emxArray_char_T *a);

static boolean_T ob_strcmp(const emxArray_char_T *a);

static boolean_T oc_strcmp(const emxArray_char_T *a);

static boolean_T p_strcmp(const emxArray_char_T *a);

static boolean_T pb_strcmp(const emxArray_char_T *a);

static boolean_T pc_strcmp(const emxArray_char_T *a);

static boolean_T q_strcmp(const emxArray_char_T *a);

static boolean_T qb_strcmp(const emxArray_char_T *a);

static boolean_T qc_strcmp(const emxArray_char_T *a);

static boolean_T r_strcmp(const emxArray_char_T *a);

static boolean_T rb_strcmp(const emxArray_char_T *a);

static boolean_T rc_strcmp(const emxArray_char_T *a);

static boolean_T s_strcmp(const emxArray_char_T *a);

static boolean_T sb_strcmp(const emxArray_char_T *a);

static boolean_T t_strcmp(const emxArray_char_T *a);

static boolean_T tb_strcmp(const emxArray_char_T *a);

static boolean_T u_strcmp(const emxArray_char_T *a);

static boolean_T ub_strcmp(const emxArray_char_T *a);

static boolean_T v_strcmp(const emxArray_char_T *a);

static boolean_T vb_strcmp(const emxArray_char_T *a);

static boolean_T w_strcmp(const emxArray_char_T *a);

static boolean_T wb_strcmp(const emxArray_char_T *a);

static boolean_T x_strcmp(const emxArray_char_T *a);

static boolean_T xb_strcmp(const emxArray_char_T *a);

static boolean_T y_strcmp(const emxArray_char_T *a);

static boolean_T yb_strcmp(const emxArray_char_T *a);

static boolean_T ab_strcmp(const emxArray_char_T *a)
{
  static const char cv[14] = {'M', 'A', 'T', '_', 'G', 'L', 'O',
                              'B', 'A', 'L', '_', 'S', 'U', 'M'};
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

static boolean_T ac_strcmp(const emxArray_char_T *a)
{
  static const char cv[14] = {'M', 'A', 'T', '_', 'F', 'A', 'C',
                              'T', 'O', 'R', '_', 'I', 'C', 'C'};
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

static boolean_T b_strcmp(const emxArray_char_T *a)
{
  static const char cv[10] = {'P', 'E', 'T', 'S', 'C', '_', 'T', 'R', 'U', 'E'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 10) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 10) {
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

static boolean_T bb_strcmp(const emxArray_char_T *a)
{
  static const char cv[16] = {'M', 'A', 'T', '_', 'R', 'O', 'W', '_',
                              'O', 'R', 'I', 'E', 'N', 'T', 'E', 'D'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 16) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 16) {
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

static boolean_T bc_strcmp(const emxArray_char_T *a)
{
  static const char cv[16] = {'M', 'A', 'T', '_', 'F', 'A', 'C', 'T',
                              'O', 'R', '_', 'I', 'L', 'U', 'D', 'T'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 16) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 16) {
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
  static const char cv[11] = {'P', 'E', 'T', 'S', 'C', '_',
                              'F', 'A', 'L', 'S', 'E'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 11) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 11) {
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

static boolean_T cb_strcmp(const emxArray_char_T *a)
{
  static const char cv[13] = {'M', 'A', 'T', '_', 'S', 'Y', 'M',
                              'M', 'E', 'T', 'R', 'I', 'C'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 13) {
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

static boolean_T cc_strcmp(const emxArray_char_T *a)
{
  static const char cv[6] = {'N', 'O', 'R', 'M', '_', '1'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 6) {
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
  static const char cv[25] = {'D', 'I', 'F', 'F', 'E', 'R', 'E', 'N', 'T',
                              '_', 'N', 'O', 'N', 'Z', 'E', 'R', 'O', '_',
                              'P', 'A', 'T', 'T', 'E', 'R', 'N'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 25) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 25) {
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

static boolean_T db_strcmp(const emxArray_char_T *a)
{
  static const char cv[26] = {'M', 'A', 'T', '_', 'S', 'T', 'R', 'U', 'C',
                              'T', 'U', 'R', 'A', 'L', 'L', 'Y', '_', 'S',
                              'Y', 'M', 'M', 'E', 'T', 'R', 'I', 'C'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 26) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 26) {
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

static boolean_T dc_strcmp(const emxArray_char_T *a)
{
  static const char cv[6] = {'N', 'O', 'R', 'M', '_', '2'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 6) {
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
  static const char cv[22] = {'S', 'U', 'B', 'S', 'E', 'T', '_', 'N',
                              'O', 'N', 'Z', 'E', 'R', 'O', '_', 'P',
                              'A', 'T', 'T', 'E', 'R', 'N'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 22) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 22) {
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

static boolean_T eb_strcmp(const emxArray_char_T *a)
{
  static const char cv[17] = {'M', 'A', 'T', '_', 'N', 'E', 'W', '_', 'D',
                              'I', 'A', 'G', 'O', 'N', 'A', 'L', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 17) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 17) {
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

static boolean_T ec_strcmp(const emxArray_char_T *a)
{
  static const char cv[14] = {'N', 'O', 'R', 'M', '_', 'F', 'R',
                              'O', 'B', 'E', 'N', 'I', 'U', 'S'};
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

static boolean_T f_strcmp(const emxArray_char_T *a)
{
  static const char cv[20] = {'S', 'A', 'M', 'E', '_', 'N', 'O', 'N', 'Z', 'E',
                              'R', 'O', '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 20) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 20) {
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

static boolean_T fb_strcmp(const emxArray_char_T *a)
{
  static const char cv[27] = {'M', 'A', 'T', '_', 'I', 'G', 'N', 'O', 'R',
                              'E', '_', 'O', 'F', 'F', '_', 'P', 'R', 'O',
                              'C', '_', 'E', 'N', 'T', 'R', 'I', 'E', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 27) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 27) {
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

static boolean_T fc_strcmp(const emxArray_char_T *a)
{
  static const char cv[13] = {'N', 'O', 'R', 'M', '_', 'I', 'N',
                              'F', 'I', 'N', 'I', 'T', 'Y'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 13) {
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

static boolean_T g_strcmp(const emxArray_char_T *a)
{
  static const char cv[22] = {'M', 'A', 'T', '_', 'D', 'O', '_', 'N',
                              'O', 'T', '_', 'C', 'O', 'P', 'Y', '_',
                              'V', 'A', 'L', 'U', 'E', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 22) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 22) {
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

static boolean_T gb_strcmp(const emxArray_char_T *a)
{
  static const char cv[18] = {'M', 'A', 'T', '_', 'U', 'S', 'E', '_', 'H',
                              'A', 'S', 'H', '_', 'T', 'A', 'B', 'L', 'E'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 18) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 18) {
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

static boolean_T gc_strcmp(const emxArray_char_T *a)
{
  static const char cv[12] = {'N', 'O', 'R', 'M', '_', '1',
                              '_', 'A', 'N', 'D', '_', '2'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 12) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 12) {
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

static boolean_T h_strcmp(const emxArray_char_T *a)
{
  static const char cv[15] = {'M', 'A', 'T', '_', 'C', 'O', 'P', 'Y',
                              '_', 'V', 'A', 'L', 'U', 'E', 'S'};
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

static boolean_T hb_strcmp(const emxArray_char_T *a)
{
  static const char cv[24] = {'M', 'A', 'T', '_', 'K', 'E', 'E', 'P',
                              '_', 'N', 'O', 'N', 'Z', 'E', 'R', 'O',
                              '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 24) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 24) {
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

static boolean_T hc_strcmp(const emxArray_char_T *a)
{
  static const char cv[16] = {'K', 'S', 'P', '_', 'N', 'O', 'R', 'M',
                              '_', 'D', 'E', 'F', 'A', 'U', 'L', 'T'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 16) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 16) {
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

static boolean_T i_strcmp(const emxArray_char_T *a)
{
  static const char cv[25] = {'M', 'A', 'T', '_', 'S', 'H', 'A', 'R', 'E',
                              '_', 'N', 'O', 'N', 'Z', 'E', 'R', 'O', '_',
                              'P', 'A', 'T', 'T', 'E', 'R', 'N'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 25) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 25) {
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

static boolean_T ib_strcmp(const emxArray_char_T *a)
{
  static const char cv[23] = {'M', 'A', 'T', '_', 'I', 'G', 'N', 'O',
                              'R', 'E', '_', 'Z', 'E', 'R', 'O', '_',
                              'E', 'N', 'T', 'R', 'I', 'E', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 23) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 23) {
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

static boolean_T ic_strcmp(const emxArray_char_T *a)
{
  static const char cv[13] = {'K', 'S', 'P', '_', 'N', 'O', 'R',
                              'M', '_', 'N', 'O', 'N', 'E'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 13) {
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

static boolean_T j_strcmp(const emxArray_char_T *a)
{
  static const char cv[18] = {'M', 'A', 'T', '_', 'I', 'N', 'I', 'T', 'I',
                              'A', 'L', '_', 'M', 'A', 'T', 'R', 'I', 'X'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 18) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 18) {
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

static boolean_T jb_strcmp(const emxArray_char_T *a)
{
  static const char cv[14] = {'M', 'A', 'T', '_', 'U', 'S', 'E',
                              '_', 'I', 'N', 'O', 'D', 'E', 'S'};
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

static boolean_T jc_strcmp(const emxArray_char_T *a)
{
  static const char cv[23] = {'K', 'S', 'P', '_', 'N', 'O', 'R', 'M',
                              '_', 'P', 'R', 'E', 'C', 'O', 'N', 'D',
                              'I', 'T', 'I', 'O', 'N', 'E', 'D'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 23) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 23) {
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

static boolean_T k_strcmp(const emxArray_char_T *a)
{
  static const char cv[16] = {'M', 'A', 'T', '_', 'R', 'E', 'U', 'S',
                              'E', '_', 'M', 'A', 'T', 'R', 'I', 'X'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 16) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 16) {
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

static boolean_T kb_strcmp(const emxArray_char_T *a)
{
  static const char cv[13] = {'M', 'A', 'T', '_', 'H', 'E', 'R',
                              'M', 'I', 'T', 'I', 'A', 'N'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 13) {
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

static boolean_T kc_strcmp(const emxArray_char_T *a)
{
  static const char cv[25] = {'K', 'S', 'P', '_', 'N', 'O', 'R', 'M', '_',
                              'U', 'N', 'P', 'R', 'E', 'C', 'O', 'N', 'D',
                              'I', 'T', 'I', 'O', 'N', 'E', 'D'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 25) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 25) {
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

static boolean_T l_strcmp(const emxArray_char_T *a)
{
  static const char cv[17] = {'M', 'A', 'T', '_', 'I', 'G', 'N', 'O', 'R',
                              'E', '_', 'M', 'A', 'T', 'R', 'I', 'X'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 17) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 17) {
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

static boolean_T lb_strcmp(const emxArray_char_T *a)
{
  static const char cv[20] = {'M', 'A', 'T', '_', 'S', 'Y', 'M', 'M', 'E', 'T',
                              'R', 'Y', '_', 'E', 'T', 'E', 'R', 'N', 'A', 'L'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 20) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 20) {
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

static boolean_T lc_strcmp(const emxArray_char_T *a)
{
  static const char cv[16] = {'K', 'S', 'P', '_', 'N', 'O', 'R', 'M',
                              '_', 'N', 'A', 'T', 'U', 'R', 'A', 'L'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 16) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 16) {
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
  M2C_error("petscGetEnum:UnknownConstant", "Unknonw constant %s.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static boolean_T m_strcmp(const emxArray_char_T *a)
{
  static const char cv[18] = {'M', 'A', 'T', '_', 'I', 'N', 'P', 'L', 'A',
                              'C', 'E', '_', 'M', 'A', 'T', 'R', 'I', 'X'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 18) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 18) {
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

static boolean_T mb_strcmp(const emxArray_char_T *a)
{
  static const char cv[28] = {'M', 'A', 'T', '_', 'N', 'E', 'W', '_', 'N', 'O',
                              'N', 'Z', 'E', 'R', 'O', '_', 'L', 'O', 'C', 'A',
                              'T', 'I', 'O', 'N', '_', 'E', 'R', 'R'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 28) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 28) {
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

static boolean_T mc_strcmp(const emxArray_char_T *a)
{
  static const char cv[7] = {'P', 'C', '_', 'L', 'E', 'F', 'T'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 7) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 7) {
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

static boolean_T n_strcmp(const emxArray_char_T *a)
{
  static const char cv[14] = {'N', 'O', 'T', '_', 'S', 'E', 'T',
                              '_', 'V', 'A', 'L', 'U', 'E', 'S'};
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

static boolean_T nb_strcmp(const emxArray_char_T *a)
{
  static const char cv[27] = {'M', 'A', 'T', '_', 'I', 'G', 'N', 'O', 'R',
                              'E', '_', 'L', 'O', 'W', 'E', 'R', '_', 'T',
                              'R', 'I', 'A', 'N', 'G', 'U', 'L', 'A', 'R'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 27) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 27) {
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

static boolean_T nc_strcmp(const emxArray_char_T *a)
{
  static const char cv[8] = {'P', 'C', '_', 'R', 'I', 'G', 'H', 'T'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 8) {
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

static boolean_T o_strcmp(const emxArray_char_T *a)
{
  static const char cv[13] = {'I', 'N', 'S', 'E', 'R', 'T', '_',
                              'V', 'A', 'L', 'U', 'E', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 13) {
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

static boolean_T ob_strcmp(const emxArray_char_T *a)
{
  static const char cv[26] = {'M', 'A', 'T', '_', 'E', 'R', 'R', 'O', 'R',
                              '_', 'L', 'O', 'W', 'E', 'R', '_', 'T', 'R',
                              'I', 'A', 'N', 'G', 'U', 'L', 'A', 'R'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 26) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 26) {
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

static boolean_T oc_strcmp(const emxArray_char_T *a)
{
  static const char cv[12] = {'P', 'C', '_', 'S', 'Y', 'M',
                              'M', 'E', 'T', 'R', 'I', 'C'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 12) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 12) {
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

static boolean_T p_strcmp(const emxArray_char_T *a)
{
  static const char cv[10] = {'A', 'D', 'D', '_', 'V', 'A', 'L', 'U', 'E', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 10) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 10) {
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

static boolean_T pb_strcmp(const emxArray_char_T *a)
{
  static const char cv[26] = {'M', 'A', 'T', '_', 'G', 'E', 'T', 'R', 'O',
                              'W', '_', 'U', 'P', 'P', 'E', 'R', 'T', 'R',
                              'I', 'A', 'N', 'G', 'U', 'L', 'A', 'R'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 26) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 26) {
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

static boolean_T pc_strcmp(const emxArray_char_T *a)
{
  static const char cv[15] = {'P', 'E', 'T', 'S', 'C', '_', 'D', 'E',
                              'T', 'E', 'R', 'M', 'I', 'N', 'E'};
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

static boolean_T q_strcmp(const emxArray_char_T *a)
{
  static const char cv[10] = {'M', 'A', 'X', '_', 'V', 'A', 'L', 'U', 'E', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 10) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 10) {
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

static boolean_T qb_strcmp(const emxArray_char_T *a)
{
  static const char cv[7] = {'M', 'A', 'T', '_', 'S', 'P', 'D'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 7) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 7) {
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

static boolean_T qc_strcmp(const emxArray_char_T *a)
{
  static const char cv[12] = {'P', 'E', 'T', 'S', 'C', '_',
                              'D', 'E', 'C', 'I', 'D', 'E'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 12) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 12) {
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

static boolean_T r_strcmp(const emxArray_char_T *a)
{
  static const char cv[17] = {'I', 'N', 'S', 'E', 'R', 'T', '_', 'A', 'L',
                              'L', '_', 'V', 'A', 'L', 'U', 'E', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 17) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 17) {
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

static boolean_T rb_strcmp(const emxArray_char_T *a)
{
  static const char cv[25] = {'M', 'A', 'T', '_', 'N', 'O', '_', 'O', 'F',
                              'F', '_', 'P', 'R', 'O', 'C', '_', 'Z', 'E',
                              'R', 'O', '_', 'R', 'O', 'W', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 25) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 25) {
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

static boolean_T rc_strcmp(const emxArray_char_T *a)
{
  static const char cv[13] = {'P', 'E', 'T', 'S', 'C', '_', 'D',
                              'E', 'F', 'A', 'U', 'L', 'T'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 13) {
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

static boolean_T s_strcmp(const emxArray_char_T *a)
{
  static const char cv[14] = {'A', 'D', 'D', '_', 'A', 'L', 'L',
                              '_', 'V', 'A', 'L', 'U', 'E', 'S'};
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

static boolean_T sb_strcmp(const emxArray_char_T *a)
{
  static const char cv[23] = {'M', 'A', 'T', '_', 'N', 'O', '_', 'O',
                              'F', 'F', '_', 'P', 'R', 'O', 'C', '_',
                              'E', 'N', 'T', 'R', 'I', 'E', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 23) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 23) {
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

static boolean_T t_strcmp(const emxArray_char_T *a)
{
  static const char cv[16] = {'I', 'N', 'S', 'E', 'R', 'T', '_', 'B',
                              'C', '_', 'V', 'A', 'L', 'U', 'E', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 16) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 16) {
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

static boolean_T tb_strcmp(const emxArray_char_T *a)
{
  static const char cv[30] = {'M', 'A', 'T', '_', 'N', 'E', 'W', '_', 'N', 'O',
                              'N', 'Z', 'E', 'R', 'O', '_', 'A', 'L', 'L', 'O',
                              'C', 'A', 'T', 'I', 'O', 'N', '_', 'E', 'R', 'R'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 30) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 30) {
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

static boolean_T u_strcmp(const emxArray_char_T *a)
{
  static const char cv[13] = {'A', 'D', 'D', '_', 'B', 'C', '_',
                              'V', 'A', 'L', 'U', 'E', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 13) {
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

static boolean_T ub_strcmp(const emxArray_char_T *a)
{
  static const char cv[27] = {'M', 'A', 'T', '_', 'S', 'U', 'B', 'S', 'E',
                              'T', '_', 'O', 'F', 'F', '_', 'P', 'R', 'O',
                              'C', '_', 'E', 'N', 'T', 'R', 'I', 'E', 'S'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 27) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 27) {
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

static boolean_T v_strcmp(const emxArray_char_T *a)
{
  static const char cv[18] = {'M', 'A', 'T', '_', 'F', 'I', 'N', 'A', 'L',
                              '_', 'A', 'S', 'S', 'E', 'M', 'B', 'L', 'Y'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 18) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 18) {
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

static boolean_T vb_strcmp(const emxArray_char_T *a)
{
  static const char cv[15] = {'M', 'A', 'T', '_', 'F', 'A', 'C', 'T',
                              'O', 'R', '_', 'N', 'O', 'N', 'E'};
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

static boolean_T w_strcmp(const emxArray_char_T *a)
{
  static const char cv[18] = {'M', 'A', 'T', '_', 'F', 'L', 'U', 'S', 'H',
                              '_', 'A', 'S', 'S', 'E', 'M', 'B', 'L', 'Y'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 18) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 18) {
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

static boolean_T wb_strcmp(const emxArray_char_T *a)
{
  static const char cv[13] = {'M', 'A', 'T', '_', 'F', 'A', 'C',
                              'T', 'O', 'R', '_', 'L', 'U'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 13) {
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

static boolean_T x_strcmp(const emxArray_char_T *a)
{
  static const char cv[9] = {'M', 'A', 'T', '_', 'L', 'O', 'C', 'A', 'L'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 9) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 9) {
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

static boolean_T xb_strcmp(const emxArray_char_T *a)
{
  static const char cv[19] = {'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O', 'R',
                              '_', 'C', 'H', 'O', 'L', 'E', 'S', 'K', 'Y'};
  int exitg1;
  int kstr;
  boolean_T b_bool;
  b_bool = false;
  if (a->size[1] == 19) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 19) {
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

static boolean_T y_strcmp(const emxArray_char_T *a)
{
  static const char cv[14] = {'M', 'A', 'T', '_', 'G', 'L', 'O',
                              'B', 'A', 'L', '_', 'M', 'A', 'X'};
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

static boolean_T yb_strcmp(const emxArray_char_T *a)
{
  static const char cv[14] = {'M', 'A', 'T', '_', 'F', 'A', 'C',
                              'T', 'O', 'R', '_', 'I', 'L', 'U'};
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

void petscGetEnum(const emxArray_char_T *name, int *val, boolean_T *toplevel)
{
  emxArray_char_T *b_name;
  int b_index;
  int i;
  if (b_strcmp(name)) {
    b_index = 0;
  } else if (c_strcmp(name)) {
    b_index = 1;
  } else if (d_strcmp(name)) {
    b_index = 2;
  } else if (e_strcmp(name)) {
    b_index = 3;
  } else if (f_strcmp(name)) {
    b_index = 4;
  } else if (g_strcmp(name)) {
    b_index = 5;
  } else if (h_strcmp(name)) {
    b_index = 6;
  } else if (i_strcmp(name)) {
    b_index = 7;
  } else if (j_strcmp(name)) {
    b_index = 8;
  } else if (k_strcmp(name)) {
    b_index = 9;
  } else if (l_strcmp(name)) {
    b_index = 10;
  } else if (m_strcmp(name)) {
    b_index = 11;
  } else if (n_strcmp(name)) {
    b_index = 12;
  } else if (o_strcmp(name)) {
    b_index = 13;
  } else if (p_strcmp(name)) {
    b_index = 14;
  } else if (q_strcmp(name)) {
    b_index = 15;
  } else if (r_strcmp(name)) {
    b_index = 16;
  } else if (s_strcmp(name)) {
    b_index = 17;
  } else if (t_strcmp(name)) {
    b_index = 18;
  } else if (u_strcmp(name)) {
    b_index = 19;
  } else if (v_strcmp(name)) {
    b_index = 20;
  } else if (w_strcmp(name)) {
    b_index = 21;
  } else if (x_strcmp(name)) {
    b_index = 22;
  } else if (y_strcmp(name)) {
    b_index = 23;
  } else if (ab_strcmp(name)) {
    b_index = 24;
  } else if (bb_strcmp(name)) {
    b_index = 25;
  } else if (cb_strcmp(name)) {
    b_index = 26;
  } else if (db_strcmp(name)) {
    b_index = 27;
  } else if (eb_strcmp(name)) {
    b_index = 28;
  } else if (fb_strcmp(name)) {
    b_index = 29;
  } else if (gb_strcmp(name)) {
    b_index = 30;
  } else if (hb_strcmp(name)) {
    b_index = 31;
  } else if (ib_strcmp(name)) {
    b_index = 32;
  } else if (jb_strcmp(name)) {
    b_index = 33;
  } else if (kb_strcmp(name)) {
    b_index = 34;
  } else if (lb_strcmp(name)) {
    b_index = 35;
  } else if (mb_strcmp(name)) {
    b_index = 36;
  } else if (nb_strcmp(name)) {
    b_index = 37;
  } else if (ob_strcmp(name)) {
    b_index = 38;
  } else if (pb_strcmp(name)) {
    b_index = 39;
  } else if (qb_strcmp(name)) {
    b_index = 40;
  } else if (rb_strcmp(name)) {
    b_index = 41;
  } else if (sb_strcmp(name)) {
    b_index = 42;
  } else if (tb_strcmp(name)) {
    b_index = 43;
  } else if (ub_strcmp(name)) {
    b_index = 44;
  } else if (vb_strcmp(name)) {
    b_index = 45;
  } else if (wb_strcmp(name)) {
    b_index = 46;
  } else if (xb_strcmp(name)) {
    b_index = 47;
  } else if (yb_strcmp(name)) {
    b_index = 48;
  } else if (ac_strcmp(name)) {
    b_index = 49;
  } else if (bc_strcmp(name)) {
    b_index = 50;
  } else if (cc_strcmp(name)) {
    b_index = 51;
  } else if (dc_strcmp(name)) {
    b_index = 52;
  } else if (ec_strcmp(name)) {
    b_index = 53;
  } else if (fc_strcmp(name)) {
    b_index = 54;
  } else if (gc_strcmp(name)) {
    b_index = 55;
  } else if (hc_strcmp(name)) {
    b_index = 56;
  } else if (ic_strcmp(name)) {
    b_index = 57;
  } else if (jc_strcmp(name)) {
    b_index = 58;
  } else if (kc_strcmp(name)) {
    b_index = 59;
  } else if (lc_strcmp(name)) {
    b_index = 60;
  } else if (mc_strcmp(name)) {
    b_index = 61;
  } else if (nc_strcmp(name)) {
    b_index = 62;
  } else if (oc_strcmp(name)) {
    b_index = 63;
  } else if (pc_strcmp(name)) {
    b_index = 64;
  } else if (qc_strcmp(name)) {
    b_index = 65;
  } else if (rc_strcmp(name)) {
    b_index = 66;
  } else {
    b_index = -1;
  }
  switch (b_index) {
  case 0:
    *val = (PETSC_TRUE);
    *toplevel = false;
    break;
  case 1:
    *val = (PETSC_FALSE);
    *toplevel = false;
    break;
  case 2:
    *val = (DIFFERENT_NONZERO_PATTERN);
    *toplevel = false;
    break;
  case 3:
    *val = (SUBSET_NONZERO_PATTERN);
    *toplevel = false;
    break;
  case 4:
    *val = (SAME_NONZERO_PATTERN);
    *toplevel = false;
    break;
  case 5:
    *val = (MAT_DO_NOT_COPY_VALUES);
    *toplevel = false;
    break;
  case 6:
    *val = (MAT_COPY_VALUES);
    *toplevel = false;
    break;
  case 7:
    *val = (MAT_SHARE_NONZERO_PATTERN);
    *toplevel = false;
    break;
  case 8:
    *val = (MAT_INITIAL_MATRIX);
    *toplevel = false;
    break;
  case 9:
    *val = (MAT_REUSE_MATRIX);
    *toplevel = false;
    break;
  case 10:
    *val = (MAT_IGNORE_MATRIX);
    *toplevel = false;
    break;
  case 11:
    *val = (MAT_INPLACE_MATRIX);
    *toplevel = false;
    break;
  case 12:
    *val = (NOT_SET_VALUES);
    *toplevel = false;
    break;
  case 13:
    *val = (INSERT_VALUES);
    *toplevel = false;
    break;
  case 14:
    *val = (ADD_VALUES);
    *toplevel = false;
    break;
  case 15:
    *val = (MAX_VALUES);
    *toplevel = false;
    break;
  case 16:
    *val = (INSERT_ALL_VALUES);
    *toplevel = false;
    break;
  case 17:
    *val = (ADD_ALL_VALUES);
    *toplevel = false;
    break;
  case 18:
    *val = (INSERT_BC_VALUES);
    *toplevel = false;
    break;
  case 19:
    *val = (ADD_BC_VALUES);
    *toplevel = false;
    break;
  case 20:
    *val = (MAT_FINAL_ASSEMBLY);
    *toplevel = false;
    break;
  case 21:
    *val = (MAT_FLUSH_ASSEMBLY);
    *toplevel = false;
    break;
  case 22:
    *val = (MAT_LOCAL);
    *toplevel = false;
    break;
  case 23:
    *val = (MAT_GLOBAL_MAX);
    *toplevel = false;
    break;
  case 24:
    *val = (MAT_GLOBAL_SUM);
    *toplevel = false;
    break;
  case 25:
    *val = (MAT_ROW_ORIENTED);
    *toplevel = false;
    break;
  case 26:
    *val = (MAT_SYMMETRIC);
    *toplevel = false;
    break;
  case 27:
    *val = (MAT_STRUCTURALLY_SYMMETRIC);
    *toplevel = false;
    break;
  case 28:
    *val = (MAT_NEW_DIAGONALS);
    *toplevel = false;
    break;
  case 29:
    *val = (MAT_IGNORE_OFF_PROC_ENTRIES);
    *toplevel = false;
    break;
  case 30:
    *val = (MAT_USE_HASH_TABLE);
    *toplevel = false;
    break;
  case 31:
    *val = (MAT_KEEP_NONZERO_PATTERN);
    *toplevel = false;
    break;
  case 32:
    *val = (MAT_IGNORE_ZERO_ENTRIES);
    *toplevel = false;
    break;
  case 33:
    *val = (MAT_USE_INODES);
    *toplevel = false;
    break;
  case 34:
    *val = (MAT_HERMITIAN);
    *toplevel = false;
    break;
  case 35:
    *val = (MAT_SYMMETRY_ETERNAL);
    *toplevel = false;
    break;
  case 36:
    *val = (MAT_NEW_NONZERO_LOCATION_ERR);
    *toplevel = false;
    break;
  case 37:
    *val = (MAT_IGNORE_LOWER_TRIANGULAR);
    *toplevel = false;
    break;
  case 38:
    *val = (MAT_ERROR_LOWER_TRIANGULAR);
    *toplevel = false;
    break;
  case 39:
    *val = (MAT_GETROW_UPPERTRIANGULAR);
    *toplevel = false;
    break;
  case 40:
    *val = (MAT_SPD);
    *toplevel = false;
    break;
  case 41:
    *val = (MAT_NO_OFF_PROC_ZERO_ROWS);
    *toplevel = false;
    break;
  case 42:
    *val = (MAT_NO_OFF_PROC_ENTRIES);
    *toplevel = false;
    break;
  case 43:
    *val = (MAT_NEW_NONZERO_ALLOCATION_ERR);
    *toplevel = false;
    break;
  case 44:
    *val = (MAT_SUBSET_OFF_PROC_ENTRIES);
    *toplevel = false;
    break;
  case 45:
    *val = (MAT_FACTOR_NONE);
    *toplevel = false;
    break;
  case 46:
    *val = (MAT_FACTOR_LU);
    *toplevel = false;
    break;
  case 47:
    *val = (MAT_FACTOR_CHOLESKY);
    *toplevel = false;
    break;
  case 48:
    *val = (MAT_FACTOR_ILU);
    *toplevel = false;
    break;
  case 49:
    *val = (MAT_FACTOR_ICC);
    *toplevel = false;
    break;
  case 50:
    *val = (MAT_FACTOR_ILUDT);
    *toplevel = false;
    break;
  case 51:
    *val = (NORM_1);
    *toplevel = false;
    break;
  case 52:
    *val = (NORM_2);
    *toplevel = false;
    break;
  case 53:
    *val = (NORM_FROBENIUS);
    *toplevel = false;
    break;
  case 54:
    *val = (NORM_INFINITY);
    *toplevel = false;
    break;
  case 55:
    *val = (NORM_1_AND_2);
    *toplevel = false;
    break;
  case 56:
    *val = (KSP_NORM_DEFAULT);
    *toplevel = false;
    break;
  case 57:
    *val = (KSP_NORM_NONE);
    *toplevel = false;
    break;
  case 58:
    *val = (KSP_NORM_PRECONDITIONED);
    *toplevel = false;
    break;
  case 59:
    *val = (KSP_NORM_UNPRECONDITIONED);
    *toplevel = false;
    break;
  case 60:
    *val = (KSP_NORM_NATURAL);
    *toplevel = false;
    break;
  case 61:
    *val = (PC_LEFT);
    *toplevel = false;
    break;
  case 62:
    *val = (PC_RIGHT);
    *toplevel = false;
    break;
  case 63:
    *val = (PC_SYMMETRIC);
    *toplevel = false;
    break;
  case 64:
    *val = (PETSC_DETERMINE);
    *toplevel = false;
    break;
  case 65:
    *val = (PETSC_DECIDE);
    *toplevel = false;
    break;
  case 66:
    *val = (PETSC_DEFAULT);
    *toplevel = false;
    break;
  default:
    emxInit_char_T(&b_name, 2);
    *toplevel = true;
    *val = MIN_int32_T;
    i = b_name->size[0] * b_name->size[1];
    b_name->size[0] = 1;
    b_name->size[1] = name->size[1] + 1;
    emxEnsureCapacity_char_T(b_name, i);
    b_index = name->size[1];
    for (i = 0; i < b_index; i++) {
      b_name->data[i] = name->data[i];
    }
    b_name->data[name->size[1]] = '\x00';
    m2c_error(b_name);
    emxFree_char_T(&b_name);
    break;
  }
}

void petscGetEnum_initialize(void)
{
}

void petscGetEnum_terminate(void)
{
}
