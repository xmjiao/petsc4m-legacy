#include "petscGetEnum.h"
#include "m2c.h"
#include "petsc4m.h"

static void m2c_error(const emxArray_char_T *varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i0);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("petscGetEnum:UnknownConstant", "Unknonw constant %s.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscGetEnum(const emxArray_char_T *name, int *val, boolean_T *toplevel)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv0[10] = { 'P', 'E', 'T', 'S', 'C', '_', 'T', 'R', 'U', 'E'
  };

  emxArray_char_T *b_name;
  static const char cv1[11] = { 'P', 'E', 'T', 'S', 'C', '_', 'F', 'A', 'L', 'S',
    'E' };

  static const char cv2[25] = { 'D', 'I', 'F', 'F', 'E', 'R', 'E', 'N', 'T', '_',
    'N', 'O', 'N', 'Z', 'E', 'R', 'O', '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N' };

  int loop_ub;
  static const char cv3[22] = { 'S', 'U', 'B', 'S', 'E', 'T', '_', 'N', 'O', 'N',
    'Z', 'E', 'R', 'O', '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N' };

  static const char cv4[20] = { 'S', 'A', 'M', 'E', '_', 'N', 'O', 'N', 'Z', 'E',
    'R', 'O', '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N' };

  static const char cv5[22] = { 'M', 'A', 'T', '_', 'D', 'O', '_', 'N', 'O', 'T',
    '_', 'C', 'O', 'P', 'Y', '_', 'V', 'A', 'L', 'U', 'E', 'S' };

  static const char cv6[15] = { 'M', 'A', 'T', '_', 'C', 'O', 'P', 'Y', '_', 'V',
    'A', 'L', 'U', 'E', 'S' };

  static const char cv7[25] = { 'M', 'A', 'T', '_', 'S', 'H', 'A', 'R', 'E', '_',
    'N', 'O', 'N', 'Z', 'E', 'R', 'O', '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N' };

  static const char cv8[18] = { 'M', 'A', 'T', '_', 'I', 'N', 'I', 'T', 'I', 'A',
    'L', '_', 'M', 'A', 'T', 'R', 'I', 'X' };

  static const char cv9[16] = { 'M', 'A', 'T', '_', 'R', 'E', 'U', 'S', 'E', '_',
    'M', 'A', 'T', 'R', 'I', 'X' };

  static const char cv10[17] = { 'M', 'A', 'T', '_', 'I', 'G', 'N', 'O', 'R',
    'E', '_', 'M', 'A', 'T', 'R', 'I', 'X' };

  static const char cv11[18] = { 'M', 'A', 'T', '_', 'I', 'N', 'P', 'L', 'A',
    'C', 'E', '_', 'M', 'A', 'T', 'R', 'I', 'X' };

  static const char cv12[14] = { 'N', 'O', 'T', '_', 'S', 'E', 'T', '_', 'V',
    'A', 'L', 'U', 'E', 'S' };

  static const char cv13[13] = { 'I', 'N', 'S', 'E', 'R', 'T', '_', 'V', 'A',
    'L', 'U', 'E', 'S' };

  static const char cv14[10] = { 'A', 'D', 'D', '_', 'V', 'A', 'L', 'U', 'E',
    'S' };

  static const char cv15[10] = { 'M', 'A', 'X', '_', 'V', 'A', 'L', 'U', 'E',
    'S' };

  static const char cv16[17] = { 'I', 'N', 'S', 'E', 'R', 'T', '_', 'A', 'L',
    'L', '_', 'V', 'A', 'L', 'U', 'E', 'S' };

  static const char cv17[14] = { 'A', 'D', 'D', '_', 'A', 'L', 'L', '_', 'V',
    'A', 'L', 'U', 'E', 'S' };

  static const char cv18[16] = { 'I', 'N', 'S', 'E', 'R', 'T', '_', 'B', 'C',
    '_', 'V', 'A', 'L', 'U', 'E', 'S' };

  static const char cv19[13] = { 'A', 'D', 'D', '_', 'B', 'C', '_', 'V', 'A',
    'L', 'U', 'E', 'S' };

  static const char cv20[18] = { 'M', 'A', 'T', '_', 'F', 'I', 'N', 'A', 'L',
    '_', 'A', 'S', 'S', 'E', 'M', 'B', 'L', 'Y' };

  static const char cv21[18] = { 'M', 'A', 'T', '_', 'F', 'L', 'U', 'S', 'H',
    '_', 'A', 'S', 'S', 'E', 'M', 'B', 'L', 'Y' };

  static const char cv22[9] = { 'M', 'A', 'T', '_', 'L', 'O', 'C', 'A', 'L' };

  static const char cv23[14] = { 'M', 'A', 'T', '_', 'G', 'L', 'O', 'B', 'A',
    'L', '_', 'M', 'A', 'X' };

  static const char cv24[14] = { 'M', 'A', 'T', '_', 'G', 'L', 'O', 'B', 'A',
    'L', '_', 'S', 'U', 'M' };

  static const char cv25[16] = { 'M', 'A', 'T', '_', 'R', 'O', 'W', '_', 'O',
    'R', 'I', 'E', 'N', 'T', 'E', 'D' };

  static const char cv26[13] = { 'M', 'A', 'T', '_', 'S', 'Y', 'M', 'M', 'E',
    'T', 'R', 'I', 'C' };

  static const char cv27[26] = { 'M', 'A', 'T', '_', 'S', 'T', 'R', 'U', 'C',
    'T', 'U', 'R', 'A', 'L', 'L', 'Y', '_', 'S', 'Y', 'M', 'M', 'E', 'T', 'R',
    'I', 'C' };

  static const char cv28[17] = { 'M', 'A', 'T', '_', 'N', 'E', 'W', '_', 'D',
    'I', 'A', 'G', 'O', 'N', 'A', 'L', 'S' };

  static const char cv29[27] = { 'M', 'A', 'T', '_', 'I', 'G', 'N', 'O', 'R',
    'E', '_', 'O', 'F', 'F', '_', 'P', 'R', 'O', 'C', '_', 'E', 'N', 'T', 'R',
    'I', 'E', 'S' };

  static const char cv30[18] = { 'M', 'A', 'T', '_', 'U', 'S', 'E', '_', 'H',
    'A', 'S', 'H', '_', 'T', 'A', 'B', 'L', 'E' };

  static const char cv31[24] = { 'M', 'A', 'T', '_', 'K', 'E', 'E', 'P', '_',
    'N', 'O', 'N', 'Z', 'E', 'R', 'O', '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N' };

  static const char cv32[23] = { 'M', 'A', 'T', '_', 'I', 'G', 'N', 'O', 'R',
    'E', '_', 'Z', 'E', 'R', 'O', '_', 'E', 'N', 'T', 'R', 'I', 'E', 'S' };

  static const char cv33[14] = { 'M', 'A', 'T', '_', 'U', 'S', 'E', '_', 'I',
    'N', 'O', 'D', 'E', 'S' };

  static const char cv34[13] = { 'M', 'A', 'T', '_', 'H', 'E', 'R', 'M', 'I',
    'T', 'I', 'A', 'N' };

  static const char cv35[20] = { 'M', 'A', 'T', '_', 'S', 'Y', 'M', 'M', 'E',
    'T', 'R', 'Y', '_', 'E', 'T', 'E', 'R', 'N', 'A', 'L' };

  static const char cv36[28] = { 'M', 'A', 'T', '_', 'N', 'E', 'W', '_', 'N',
    'O', 'N', 'Z', 'E', 'R', 'O', '_', 'L', 'O', 'C', 'A', 'T', 'I', 'O', 'N',
    '_', 'E', 'R', 'R' };

  static const char cv37[27] = { 'M', 'A', 'T', '_', 'I', 'G', 'N', 'O', 'R',
    'E', '_', 'L', 'O', 'W', 'E', 'R', '_', 'T', 'R', 'I', 'A', 'N', 'G', 'U',
    'L', 'A', 'R' };

  static const char cv38[26] = { 'M', 'A', 'T', '_', 'E', 'R', 'R', 'O', 'R',
    '_', 'L', 'O', 'W', 'E', 'R', '_', 'T', 'R', 'I', 'A', 'N', 'G', 'U', 'L',
    'A', 'R' };

  static const char cv39[26] = { 'M', 'A', 'T', '_', 'G', 'E', 'T', 'R', 'O',
    'W', '_', 'U', 'P', 'P', 'E', 'R', 'T', 'R', 'I', 'A', 'N', 'G', 'U', 'L',
    'A', 'R' };

  static const char cv40[7] = { 'M', 'A', 'T', '_', 'S', 'P', 'D' };

  static const char cv41[25] = { 'M', 'A', 'T', '_', 'N', 'O', '_', 'O', 'F',
    'F', '_', 'P', 'R', 'O', 'C', '_', 'Z', 'E', 'R', 'O', '_', 'R', 'O', 'W',
    'S' };

  static const char cv42[23] = { 'M', 'A', 'T', '_', 'N', 'O', '_', 'O', 'F',
    'F', '_', 'P', 'R', 'O', 'C', '_', 'E', 'N', 'T', 'R', 'I', 'E', 'S' };

  static const char cv43[30] = { 'M', 'A', 'T', '_', 'N', 'E', 'W', '_', 'N',
    'O', 'N', 'Z', 'E', 'R', 'O', '_', 'A', 'L', 'L', 'O', 'C', 'A', 'T', 'I',
    'O', 'N', '_', 'E', 'R', 'R' };

  static const char cv44[27] = { 'M', 'A', 'T', '_', 'S', 'U', 'B', 'S', 'E',
    'T', '_', 'O', 'F', 'F', '_', 'P', 'R', 'O', 'C', '_', 'E', 'N', 'T', 'R',
    'I', 'E', 'S' };

  static const char cv45[15] = { 'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O',
    'R', '_', 'N', 'O', 'N', 'E' };

  static const char cv46[13] = { 'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O',
    'R', '_', 'L', 'U' };

  static const char cv47[19] = { 'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O',
    'R', '_', 'C', 'H', 'O', 'L', 'E', 'S', 'K', 'Y' };

  static const char cv48[14] = { 'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O',
    'R', '_', 'I', 'L', 'U' };

  static const char cv49[14] = { 'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O',
    'R', '_', 'I', 'C', 'C' };

  static const char cv50[16] = { 'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O',
    'R', '_', 'I', 'L', 'U', 'D', 'T' };

  static const char cv51[6] = { 'N', 'O', 'R', 'M', '_', '1' };

  static const char cv52[6] = { 'N', 'O', 'R', 'M', '_', '2' };

  static const char cv53[14] = { 'N', 'O', 'R', 'M', '_', 'F', 'R', 'O', 'B',
    'E', 'N', 'I', 'U', 'S' };

  static const char cv54[13] = { 'N', 'O', 'R', 'M', '_', 'I', 'N', 'F', 'I',
    'N', 'I', 'T', 'Y' };

  static const char cv55[12] = { 'N', 'O', 'R', 'M', '_', '1', '_', 'A', 'N',
    'D', '_', '2' };

  static const char cv56[16] = { 'K', 'S', 'P', '_', 'N', 'O', 'R', 'M', '_',
    'D', 'E', 'F', 'A', 'U', 'L', 'T' };

  static const char cv57[13] = { 'K', 'S', 'P', '_', 'N', 'O', 'R', 'M', '_',
    'N', 'O', 'N', 'E' };

  static const char cv58[23] = { 'K', 'S', 'P', '_', 'N', 'O', 'R', 'M', '_',
    'P', 'R', 'E', 'C', 'O', 'N', 'D', 'I', 'T', 'I', 'O', 'N', 'E', 'D' };

  static const char cv59[25] = { 'K', 'S', 'P', '_', 'N', 'O', 'R', 'M', '_',
    'U', 'N', 'P', 'R', 'E', 'C', 'O', 'N', 'D', 'I', 'T', 'I', 'O', 'N', 'E',
    'D' };

  static const char cv60[16] = { 'K', 'S', 'P', '_', 'N', 'O', 'R', 'M', '_',
    'N', 'A', 'T', 'U', 'R', 'A', 'L' };

  static const char cv61[7] = { 'P', 'C', '_', 'L', 'E', 'F', 'T' };

  static const char cv62[8] = { 'P', 'C', '_', 'R', 'I', 'G', 'H', 'T' };

  static const char cv63[12] = { 'P', 'C', '_', 'S', 'Y', 'M', 'M', 'E', 'T',
    'R', 'I', 'C' };

  static const char cv64[15] = { 'P', 'E', 'T', 'S', 'C', '_', 'D', 'E', 'T',
    'E', 'R', 'M', 'I', 'N', 'E' };

  static const char cv65[12] = { 'P', 'E', 'T', 'S', 'C', '_', 'D', 'E', 'C',
    'I', 'D', 'E' };

  static const char cv66[13] = { 'P', 'E', 'T', 'S', 'C', '_', 'D', 'E', 'F',
    'A', 'U', 'L', 'T' };

  b_bool = false;
  if (name->size[1] == 10) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 11) {
        if (name->data[kstr] != cv0[kstr]) {
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
    if (name->size[1] == 11) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr + 1 < 12) {
          if (name->data[kstr] != cv1[kstr]) {
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
      if (name->size[1] == 25) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr + 1 < 26) {
            if (name->data[kstr] != cv2[kstr]) {
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
        if (name->size[1] == 22) {
          kstr = 0;
          do {
            exitg1 = 0;
            if (kstr + 1 < 23) {
              if (name->data[kstr] != cv3[kstr]) {
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
          if (name->size[1] == 20) {
            kstr = 0;
            do {
              exitg1 = 0;
              if (kstr + 1 < 21) {
                if (name->data[kstr] != cv4[kstr]) {
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
            if (name->size[1] == 22) {
              kstr = 0;
              do {
                exitg1 = 0;
                if (kstr + 1 < 23) {
                  if (name->data[kstr] != cv5[kstr]) {
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
              if (name->size[1] == 15) {
                kstr = 0;
                do {
                  exitg1 = 0;
                  if (kstr + 1 < 16) {
                    if (name->data[kstr] != cv6[kstr]) {
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
                if (name->size[1] == 25) {
                  kstr = 0;
                  do {
                    exitg1 = 0;
                    if (kstr + 1 < 26) {
                      if (name->data[kstr] != cv7[kstr]) {
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
                  if (name->size[1] == 18) {
                    kstr = 0;
                    do {
                      exitg1 = 0;
                      if (kstr + 1 < 19) {
                        if (name->data[kstr] != cv8[kstr]) {
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
                    if (name->size[1] == 16) {
                      kstr = 0;
                      do {
                        exitg1 = 0;
                        if (kstr + 1 < 17) {
                          if (name->data[kstr] != cv9[kstr]) {
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
                      b_bool = false;
                      if (name->size[1] == 17) {
                        kstr = 0;
                        do {
                          exitg1 = 0;
                          if (kstr + 1 < 18) {
                            if (name->data[kstr] != cv10[kstr]) {
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
                        kstr = 10;
                      } else {
                        b_bool = false;
                        if (name->size[1] == 18) {
                          kstr = 0;
                          do {
                            exitg1 = 0;
                            if (kstr + 1 < 19) {
                              if (name->data[kstr] != cv11[kstr]) {
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
                          kstr = 11;
                        } else {
                          b_bool = false;
                          if (name->size[1] == 14) {
                            kstr = 0;
                            do {
                              exitg1 = 0;
                              if (kstr + 1 < 15) {
                                if (name->data[kstr] != cv12[kstr]) {
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
                            kstr = 12;
                          } else {
                            b_bool = false;
                            if (name->size[1] == 13) {
                              kstr = 0;
                              do {
                                exitg1 = 0;
                                if (kstr + 1 < 14) {
                                  if (name->data[kstr] != cv13[kstr]) {
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
                              kstr = 13;
                            } else {
                              b_bool = false;
                              if (name->size[1] == 10) {
                                kstr = 0;
                                do {
                                  exitg1 = 0;
                                  if (kstr + 1 < 11) {
                                    if (name->data[kstr] != cv14[kstr]) {
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
                                kstr = 14;
                              } else {
                                b_bool = false;
                                if (name->size[1] == 10) {
                                  kstr = 0;
                                  do {
                                    exitg1 = 0;
                                    if (kstr + 1 < 11) {
                                      if (name->data[kstr] != cv15[kstr]) {
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
                                  kstr = 15;
                                } else {
                                  b_bool = false;
                                  if (name->size[1] == 17) {
                                    kstr = 0;
                                    do {
                                      exitg1 = 0;
                                      if (kstr + 1 < 18) {
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
                                    kstr = 16;
                                  } else {
                                    b_bool = false;
                                    if (name->size[1] == 14) {
                                      kstr = 0;
                                      do {
                                        exitg1 = 0;
                                        if (kstr + 1 < 15) {
                                          if (name->data[kstr] != cv17[kstr]) {
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
                                      kstr = 17;
                                    } else {
                                      b_bool = false;
                                      if (name->size[1] == 16) {
                                        kstr = 0;
                                        do {
                                          exitg1 = 0;
                                          if (kstr + 1 < 17) {
                                            if (name->data[kstr] != cv18[kstr])
                                            {
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
                                        kstr = 18;
                                      } else {
                                        b_bool = false;
                                        if (name->size[1] == 13) {
                                          kstr = 0;
                                          do {
                                            exitg1 = 0;
                                            if (kstr + 1 < 14) {
                                              if (name->data[kstr] != cv19[kstr])
                                              {
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
                                          kstr = 19;
                                        } else {
                                          b_bool = false;
                                          if (name->size[1] == 18) {
                                            kstr = 0;
                                            do {
                                              exitg1 = 0;
                                              if (kstr + 1 < 19) {
                                                if (name->data[kstr] !=
                                                    cv20[kstr]) {
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
                                            kstr = 20;
                                          } else {
                                            b_bool = false;
                                            if (name->size[1] == 18) {
                                              kstr = 0;
                                              do {
                                                exitg1 = 0;
                                                if (kstr + 1 < 19) {
                                                  if (name->data[kstr] !=
                                                      cv21[kstr]) {
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
                                              kstr = 21;
                                            } else {
                                              b_bool = false;
                                              if (name->size[1] == 9) {
                                                kstr = 0;
                                                do {
                                                  exitg1 = 0;
                                                  if (kstr + 1 < 10) {
                                                    if (name->data[kstr] !=
                                                        cv22[kstr]) {
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
                                                kstr = 22;
                                              } else {
                                                b_bool = false;
                                                if (name->size[1] == 14) {
                                                  kstr = 0;
                                                  do {
                                                    exitg1 = 0;
                                                    if (kstr + 1 < 15) {
                                                      if (name->data[kstr] !=
                                                          cv23[kstr]) {
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
                                                  kstr = 23;
                                                } else {
                                                  b_bool = false;
                                                  if (name->size[1] == 14) {
                                                    kstr = 0;
                                                    do {
                                                      exitg1 = 0;
                                                      if (kstr + 1 < 15) {
                                                        if (name->data[kstr] !=
                                                            cv24[kstr]) {
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
                                                    kstr = 24;
                                                  } else {
                                                    b_bool = false;
                                                    if (name->size[1] == 16) {
                                                      kstr = 0;
                                                      do {
                                                        exitg1 = 0;
                                                        if (kstr + 1 < 17) {
                                                          if (name->data[kstr]
                                                              != cv25[kstr]) {
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
                                                      kstr = 25;
                                                    } else {
                                                      b_bool = false;
                                                      if (name->size[1] == 13) {
                                                        kstr = 0;
                                                        do {
                                                          exitg1 = 0;
                                                          if (kstr + 1 < 14) {
                                                            if (name->data[kstr]
                                                                != cv26[kstr]) {
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
                                                        kstr = 26;
                                                      } else {
                                                        b_bool = false;
                                                        if (name->size[1] == 26)
                                                        {
                                                          kstr = 0;
                                                          do {
                                                            exitg1 = 0;
                                                            if (kstr + 1 < 27) {
                                                              if (name->
                                                                  data[kstr] !=
                                                                  cv27[kstr]) {
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
                                                          kstr = 27;
                                                        } else {
                                                          b_bool = false;
                                                          if (name->size[1] ==
                                                              17) {
                                                            kstr = 0;
                                                            do {
                                                              exitg1 = 0;
                                                              if (kstr + 1 < 18)
                                                              {
                                                                if (name->
                                                                    data[kstr]
                                                                    != cv28[kstr])
                                                                {
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
                                                            kstr = 28;
                                                          } else {
                                                            b_bool = false;
                                                            if (name->size[1] ==
                                                                27) {
                                                              kstr = 0;
                                                              do {
                                                                exitg1 = 0;
                                                                if (kstr + 1 <
                                                                    28) {
                                                                  if (name->
                                                                      data[kstr]
                                                                      !=
                                                                      cv29[kstr])
                                                                  {
                                                                    exitg1 = 1;
                                                                  } else {
                                                                    kstr++;
                                                                  }
                                                                } else {
                                                                  b_bool = true;
                                                                  exitg1 = 1;
                                                                }
                                                              } while (exitg1 ==
                                                                      0);
                                                            }

                                                            if (b_bool) {
                                                              kstr = 29;
                                                            } else {
                                                              b_bool = false;
                                                              if (name->size[1] ==
                                                                  18) {
                                                                kstr = 0;
                                                                do {
                                                                  exitg1 = 0;
                                                                  if (kstr + 1 <
                                                                      19) {
                                                                    if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv30[kstr])
                                                                    {
                                                                      exitg1 = 1;
                                                                    } else {
                                                                      kstr++;
                                                                    }
                                                                  } else {
                                                                    b_bool =
                                                                      true;
                                                                    exitg1 = 1;
                                                                  }
                                                                } while (exitg1 ==
                                                                      0);
                                                              }

                                                              if (b_bool) {
                                                                kstr = 30;
                                                              } else {
                                                                b_bool = false;
                                                                if (name->size[1]
                                                                    == 24) {
                                                                  kstr = 0;
                                                                  do {
                                                                    exitg1 = 0;
                                                                    if (kstr + 1
                                                                      < 25) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv31[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                    } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                    }
                                                                  } while
                                                                      (exitg1 ==
                                                                      0);
                                                                }

                                                                if (b_bool) {
                                                                  kstr = 31;
                                                                } else {
                                                                  b_bool = false;
                                                                  if (name->
                                                                      size[1] ==
                                                                      23) {
                                                                    kstr = 0;
                                                                    do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 24) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv32[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                    } while
                                                                      (exitg1 ==
                                                                      0);
                                                                  }

                                                                  if (b_bool) {
                                                                    kstr = 32;
                                                                  } else {
                                                                    b_bool =
                                                                      false;
                                                                    if
                                                                      (name->size
                                                                      [1] == 14)
                                                                    {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 15) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv33[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                    }

                                                                    if (b_bool)
                                                                    {
                                                                      kstr = 33;
                                                                    } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 13)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 14) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv34[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 34;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 20)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 21) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv35[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 35;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 28)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 29) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv36[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 36;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 27)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 28) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv37[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 37;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 26)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 27) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv38[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 38;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 26)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 27) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv39[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 39;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 7)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv40[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 40;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 25)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 26) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv41[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 41;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 23)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 24) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv42[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 42;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 30)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 31) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv43[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 43;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 27)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 28) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv44[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 44;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 15)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 16) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv45[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 45;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 13)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 14) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv46[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 46;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 19)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 20) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv47[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 47;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 14)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 15) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv48[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 48;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 14)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 15) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv49[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 49;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 16)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 17) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv50[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 50;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 6)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv51[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 51;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 6)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv52[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 52;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 14)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 15) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv53[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 53;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 13)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 14) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv54[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 54;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 12)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 13) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv55[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 55;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 16)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 17) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv56[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 56;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 13)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 14) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv57[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 57;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 23)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 24) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv58[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 58;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 25)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 26) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv59[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 59;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 16)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 17) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv60[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 60;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 7)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv61[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 61;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 8)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 9) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv62[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 62;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 12)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 13) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv63[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 63;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 15)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 16) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv64[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 64;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 12)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 13) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv65[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 65;
                                                                      } else {
                                                                      b_bool =
                                                                      false;
                                                                      if
                                                                      (name->size
                                                                      [1] == 13)
                                                                      {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 14) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv66[kstr])
                                                                      {
                                                                      exitg1 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg1 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg1 ==
                                                                      0);
                                                                      }

                                                                      if (b_bool)
                                                                      {
                                                                      kstr = 66;
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
              }
            }
          }
        }
      }
    }
  }

  switch (kstr) {
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
    kstr = b_name->size[0] * b_name->size[1];
    b_name->size[0] = 1;
    b_name->size[1] = name->size[1] + 1;
    emxEnsureCapacity_char_T(b_name, kstr);
    loop_ub = name->size[1];
    for (kstr = 0; kstr < loop_ub; kstr++) {
      b_name->data[b_name->size[0] * kstr] = name->data[name->size[0] * kstr];
    }

    b_name->data[b_name->size[0] * name->size[1]] = '\x00';
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
