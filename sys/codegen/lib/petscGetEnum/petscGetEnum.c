#include "petscGetEnum.h"
#include "petscksp.h"
#include "petscsys.h"
#include "petscsys.h"
#include "petscksp.h"
#include "m2c.h"

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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error("petscGetNum:UnknownConstant", "Unknonw constant %s.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void petscGetEnum(const emxArray_char_T *name, int *val, boolean_T *toplevel)
{
  boolean_T b_bool;
  int kstr;
  int exitg57;
  static const char cv0[10] = { 'P', 'E', 'T', 'S', 'C', '_', 'T', 'R', 'U', 'E'
  };

  emxArray_char_T *b_name;
  int exitg56;
  static const char cv1[11] = { 'P', 'E', 'T', 'S', 'C', '_', 'F', 'A', 'L', 'S',
    'E' };

  int exitg55;
  static const char cv2[25] = { 'D', 'I', 'F', 'F', 'E', 'R', 'E', 'N', 'T', '_',
    'N', 'O', 'N', 'Z', 'E', 'R', 'O', '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N' };

  int loop_ub;
  int exitg54;
  static const char cv3[22] = { 'S', 'U', 'B', 'S', 'E', 'T', '_', 'N', 'O', 'N',
    'Z', 'E', 'R', 'O', '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N' };

  int exitg53;
  static const char cv4[20] = { 'S', 'A', 'M', 'E', '_', 'N', 'O', 'N', 'Z', 'E',
    'R', 'O', '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N' };

  int exitg52;
  static const char cv5[22] = { 'M', 'A', 'T', '_', 'D', 'O', '_', 'N', 'O', 'T',
    '_', 'C', 'O', 'P', 'Y', '_', 'V', 'A', 'L', 'U', 'E', 'S' };

  int exitg51;
  static const char cv6[15] = { 'M', 'A', 'T', '_', 'C', 'O', 'P', 'Y', '_', 'V',
    'A', 'L', 'U', 'E', 'S' };

  int exitg50;
  static const char cv7[25] = { 'M', 'A', 'T', '_', 'S', 'H', 'A', 'R', 'E', '_',
    'N', 'O', 'N', 'Z', 'E', 'R', 'O', '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N' };

  int exitg49;
  static const char cv8[18] = { 'M', 'A', 'T', '_', 'I', 'N', 'I', 'T', 'I', 'A',
    'L', '_', 'M', 'A', 'T', 'R', 'I', 'X' };

  int exitg48;
  static const char cv9[16] = { 'M', 'A', 'T', '_', 'R', 'E', 'U', 'S', 'E', '_',
    'M', 'A', 'T', 'R', 'I', 'X' };

  int exitg47;
  static const char cv10[17] = { 'M', 'A', 'T', '_', 'I', 'G', 'N', 'O', 'R',
    'E', '_', 'M', 'A', 'T', 'R', 'I', 'X' };

  int exitg46;
  static const char cv11[14] = { 'N', 'O', 'T', '_', 'S', 'E', 'T', '_', 'V',
    'A', 'L', 'U', 'E', 'S' };

  int exitg45;
  static const char cv12[13] = { 'I', 'N', 'S', 'E', 'R', 'T', '_', 'V', 'A',
    'L', 'U', 'E', 'S' };

  int exitg44;
  static const char cv13[10] = { 'A', 'D', 'D', '_', 'V', 'A', 'L', 'U', 'E',
    'S' };

  int exitg43;
  static const char cv14[10] = { 'M', 'A', 'X', '_', 'V', 'A', 'L', 'U', 'E',
    'S' };

  int exitg42;
  static const char cv15[17] = { 'I', 'N', 'S', 'E', 'R', 'T', '_', 'A', 'L',
    'L', '_', 'V', 'A', 'L', 'U', 'E', 'S' };

  int exitg41;
  static const char cv16[14] = { 'A', 'D', 'D', '_', 'A', 'L', 'L', '_', 'V',
    'A', 'L', 'U', 'E', 'S' };

  int exitg40;
  static const char cv17[16] = { 'I', 'N', 'S', 'E', 'R', 'T', '_', 'B', 'C',
    '_', 'V', 'A', 'L', 'U', 'E', 'S' };

  int exitg39;
  static const char cv18[13] = { 'A', 'D', 'D', '_', 'B', 'C', '_', 'V', 'A',
    'L', 'U', 'E', 'S' };

  int exitg38;
  static const char cv19[18] = { 'M', 'A', 'T', '_', 'F', 'I', 'N', 'A', 'L',
    '_', 'A', 'S', 'S', 'E', 'M', 'B', 'L', 'Y' };

  int exitg37;
  static const char cv20[18] = { 'M', 'A', 'T', '_', 'F', 'L', 'U', 'S', 'H',
    '_', 'A', 'S', 'S', 'E', 'M', 'B', 'L', 'Y' };

  int exitg36;
  static const char cv21[9] = { 'M', 'A', 'T', '_', 'L', 'O', 'C', 'A', 'L' };

  int exitg35;
  static const char cv22[14] = { 'M', 'A', 'T', '_', 'G', 'L', 'O', 'B', 'A',
    'L', '_', 'M', 'A', 'X' };

  int exitg34;
  static const char cv23[14] = { 'M', 'A', 'T', '_', 'G', 'L', 'O', 'B', 'A',
    'L', '_', 'S', 'U', 'M' };

  int exitg33;
  static const char cv24[16] = { 'M', 'A', 'T', '_', 'R', 'O', 'W', '_', 'O',
    'R', 'I', 'E', 'N', 'T', 'E', 'D' };

  int exitg32;
  static const char cv25[13] = { 'M', 'A', 'T', '_', 'S', 'Y', 'M', 'M', 'E',
    'T', 'R', 'I', 'C' };

  int exitg31;
  static const char cv26[26] = { 'M', 'A', 'T', '_', 'S', 'T', 'R', 'U', 'C',
    'T', 'U', 'R', 'A', 'L', 'L', 'Y', '_', 'S', 'Y', 'M', 'M', 'E', 'T', 'R',
    'I', 'C' };

  int exitg30;
  static const char cv27[17] = { 'M', 'A', 'T', '_', 'N', 'E', 'W', '_', 'D',
    'I', 'A', 'G', 'O', 'N', 'A', 'L', 'S' };

  int exitg29;
  static const char cv28[27] = { 'M', 'A', 'T', '_', 'I', 'G', 'N', 'O', 'R',
    'E', '_', 'O', 'F', 'F', '_', 'P', 'R', 'O', 'C', '_', 'E', 'N', 'T', 'R',
    'I', 'E', 'S' };

  int exitg28;
  static const char cv29[18] = { 'M', 'A', 'T', '_', 'U', 'S', 'E', '_', 'H',
    'A', 'S', 'H', '_', 'T', 'A', 'B', 'L', 'E' };

  int exitg27;
  static const char cv30[24] = { 'M', 'A', 'T', '_', 'K', 'E', 'E', 'P', '_',
    'N', 'O', 'N', 'Z', 'E', 'R', 'O', '_', 'P', 'A', 'T', 'T', 'E', 'R', 'N' };

  int exitg26;
  static const char cv31[23] = { 'M', 'A', 'T', '_', 'I', 'G', 'N', 'O', 'R',
    'E', '_', 'Z', 'E', 'R', 'O', '_', 'E', 'N', 'T', 'R', 'I', 'E', 'S' };

  int exitg25;
  static const char cv32[14] = { 'M', 'A', 'T', '_', 'U', 'S', 'E', '_', 'I',
    'N', 'O', 'D', 'E', 'S' };

  int exitg24;
  static const char cv33[13] = { 'M', 'A', 'T', '_', 'H', 'E', 'R', 'M', 'I',
    'T', 'I', 'A', 'N' };

  int exitg23;
  static const char cv34[20] = { 'M', 'A', 'T', '_', 'S', 'Y', 'M', 'M', 'E',
    'T', 'R', 'Y', '_', 'E', 'T', 'E', 'R', 'N', 'A', 'L' };

  int exitg22;
  static const char cv35[28] = { 'M', 'A', 'T', '_', 'N', 'E', 'W', '_', 'N',
    'O', 'N', 'Z', 'E', 'R', 'O', '_', 'L', 'O', 'C', 'A', 'T', 'I', 'O', 'N',
    '_', 'E', 'R', 'R' };

  int exitg21;
  static const char cv36[27] = { 'M', 'A', 'T', '_', 'I', 'G', 'N', 'O', 'R',
    'E', '_', 'L', 'O', 'W', 'E', 'R', '_', 'T', 'R', 'I', 'A', 'N', 'G', 'U',
    'L', 'A', 'R' };

  int exitg20;
  static const char cv37[26] = { 'M', 'A', 'T', '_', 'E', 'R', 'R', 'O', 'R',
    '_', 'L', 'O', 'W', 'E', 'R', '_', 'T', 'R', 'I', 'A', 'N', 'G', 'U', 'L',
    'A', 'R' };

  int exitg19;
  static const char cv38[26] = { 'M', 'A', 'T', '_', 'G', 'E', 'T', 'R', 'O',
    'W', '_', 'U', 'P', 'P', 'E', 'R', 'T', 'R', 'I', 'A', 'N', 'G', 'U', 'L',
    'A', 'R' };

  int exitg18;
  static const char cv39[7] = { 'M', 'A', 'T', '_', 'S', 'P', 'D' };

  int exitg17;
  static const char cv40[25] = { 'M', 'A', 'T', '_', 'N', 'O', '_', 'O', 'F',
    'F', '_', 'P', 'R', 'O', 'C', '_', 'Z', 'E', 'R', 'O', '_', 'R', 'O', 'W',
    'S' };

  int exitg16;
  static const char cv41[23] = { 'M', 'A', 'T', '_', 'N', 'O', '_', 'O', 'F',
    'F', '_', 'P', 'R', 'O', 'C', '_', 'E', 'N', 'T', 'R', 'I', 'E', 'S' };

  int exitg15;
  static const char cv42[30] = { 'M', 'A', 'T', '_', 'N', 'E', 'W', '_', 'N',
    'O', 'N', 'Z', 'E', 'R', 'O', '_', 'A', 'L', 'L', 'O', 'C', 'A', 'T', 'I',
    'O', 'N', '_', 'E', 'R', 'R' };

  int exitg14;
  static const char cv43[15] = { 'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O',
    'R', '_', 'N', 'O', 'N', 'E' };

  int exitg13;
  static const char cv44[13] = { 'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O',
    'R', '_', 'L', 'U' };

  int exitg12;
  static const char cv45[19] = { 'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O',
    'R', '_', 'C', 'H', 'O', 'L', 'E', 'S', 'K', 'Y' };

  int exitg11;
  static const char cv46[14] = { 'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O',
    'R', '_', 'I', 'L', 'U' };

  int exitg10;
  static const char cv47[14] = { 'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O',
    'R', '_', 'I', 'C', 'C' };

  int exitg9;
  static const char cv48[16] = { 'M', 'A', 'T', '_', 'F', 'A', 'C', 'T', 'O',
    'R', '_', 'I', 'L', 'U', 'D', 'T' };

  int exitg8;
  static const char cv49[6] = { 'N', 'O', 'R', 'M', '_', '1' };

  int exitg7;
  static const char cv50[6] = { 'N', 'O', 'R', 'M', '_', '2' };

  int exitg6;
  static const char cv51[14] = { 'N', 'O', 'R', 'M', '_', 'F', 'R', 'O', 'B',
    'E', 'N', 'I', 'U', 'S' };

  int exitg5;
  static const char cv52[13] = { 'N', 'O', 'R', 'M', '_', 'I', 'N', 'F', 'I',
    'N', 'I', 'T', 'Y' };

  int exitg4;
  static const char cv53[12] = { 'N', 'O', 'R', 'M', '_', '1', '_', 'A', 'N',
    'D', '_', '2' };

  int exitg3;
  static const char cv54[15] = { 'P', 'E', 'T', 'S', 'C', '_', 'D', 'E', 'T',
    'E', 'R', 'M', 'I', 'N', 'E' };

  int exitg2;
  static const char cv55[12] = { 'P', 'E', 'T', 'S', 'C', '_', 'D', 'E', 'C',
    'I', 'D', 'E' };

  int exitg1;
  static const char cv56[13] = { 'P', 'E', 'T', 'S', 'C', '_', 'D', 'E', 'F',
    'A', 'U', 'L', 'T' };

  b_bool = false;
  if (name->size[1] != 10) {
  } else {
    kstr = 0;
    do {
      exitg57 = 0;
      if (kstr + 1 < 11) {
        if (name->data[kstr] != cv0[kstr]) {
          exitg57 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg57 = 1;
      }
    } while (exitg57 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    b_bool = false;
    if (name->size[1] != 11) {
    } else {
      kstr = 0;
      do {
        exitg56 = 0;
        if (kstr + 1 < 12) {
          if (name->data[kstr] != cv1[kstr]) {
            exitg56 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg56 = 1;
        }
      } while (exitg56 == 0);
    }

    if (b_bool) {
      kstr = 1;
    } else {
      b_bool = false;
      if (name->size[1] != 25) {
      } else {
        kstr = 0;
        do {
          exitg55 = 0;
          if (kstr + 1 < 26) {
            if (name->data[kstr] != cv2[kstr]) {
              exitg55 = 1;
            } else {
              kstr++;
            }
          } else {
            b_bool = true;
            exitg55 = 1;
          }
        } while (exitg55 == 0);
      }

      if (b_bool) {
        kstr = 2;
      } else {
        b_bool = false;
        if (name->size[1] != 22) {
        } else {
          kstr = 0;
          do {
            exitg54 = 0;
            if (kstr + 1 < 23) {
              if (name->data[kstr] != cv3[kstr]) {
                exitg54 = 1;
              } else {
                kstr++;
              }
            } else {
              b_bool = true;
              exitg54 = 1;
            }
          } while (exitg54 == 0);
        }

        if (b_bool) {
          kstr = 3;
        } else {
          b_bool = false;
          if (name->size[1] != 20) {
          } else {
            kstr = 0;
            do {
              exitg53 = 0;
              if (kstr + 1 < 21) {
                if (name->data[kstr] != cv4[kstr]) {
                  exitg53 = 1;
                } else {
                  kstr++;
                }
              } else {
                b_bool = true;
                exitg53 = 1;
              }
            } while (exitg53 == 0);
          }

          if (b_bool) {
            kstr = 4;
          } else {
            b_bool = false;
            if (name->size[1] != 22) {
            } else {
              kstr = 0;
              do {
                exitg52 = 0;
                if (kstr + 1 < 23) {
                  if (name->data[kstr] != cv5[kstr]) {
                    exitg52 = 1;
                  } else {
                    kstr++;
                  }
                } else {
                  b_bool = true;
                  exitg52 = 1;
                }
              } while (exitg52 == 0);
            }

            if (b_bool) {
              kstr = 5;
            } else {
              b_bool = false;
              if (name->size[1] != 15) {
              } else {
                kstr = 0;
                do {
                  exitg51 = 0;
                  if (kstr + 1 < 16) {
                    if (name->data[kstr] != cv6[kstr]) {
                      exitg51 = 1;
                    } else {
                      kstr++;
                    }
                  } else {
                    b_bool = true;
                    exitg51 = 1;
                  }
                } while (exitg51 == 0);
              }

              if (b_bool) {
                kstr = 6;
              } else {
                b_bool = false;
                if (name->size[1] != 25) {
                } else {
                  kstr = 0;
                  do {
                    exitg50 = 0;
                    if (kstr + 1 < 26) {
                      if (name->data[kstr] != cv7[kstr]) {
                        exitg50 = 1;
                      } else {
                        kstr++;
                      }
                    } else {
                      b_bool = true;
                      exitg50 = 1;
                    }
                  } while (exitg50 == 0);
                }

                if (b_bool) {
                  kstr = 7;
                } else {
                  b_bool = false;
                  if (name->size[1] != 18) {
                  } else {
                    kstr = 0;
                    do {
                      exitg49 = 0;
                      if (kstr + 1 < 19) {
                        if (name->data[kstr] != cv8[kstr]) {
                          exitg49 = 1;
                        } else {
                          kstr++;
                        }
                      } else {
                        b_bool = true;
                        exitg49 = 1;
                      }
                    } while (exitg49 == 0);
                  }

                  if (b_bool) {
                    kstr = 8;
                  } else {
                    b_bool = false;
                    if (name->size[1] != 16) {
                    } else {
                      kstr = 0;
                      do {
                        exitg48 = 0;
                        if (kstr + 1 < 17) {
                          if (name->data[kstr] != cv9[kstr]) {
                            exitg48 = 1;
                          } else {
                            kstr++;
                          }
                        } else {
                          b_bool = true;
                          exitg48 = 1;
                        }
                      } while (exitg48 == 0);
                    }

                    if (b_bool) {
                      kstr = 9;
                    } else {
                      b_bool = false;
                      if (name->size[1] != 17) {
                      } else {
                        kstr = 0;
                        do {
                          exitg47 = 0;
                          if (kstr + 1 < 18) {
                            if (name->data[kstr] != cv10[kstr]) {
                              exitg47 = 1;
                            } else {
                              kstr++;
                            }
                          } else {
                            b_bool = true;
                            exitg47 = 1;
                          }
                        } while (exitg47 == 0);
                      }

                      if (b_bool) {
                        kstr = 10;
                      } else {
                        b_bool = false;
                        if (name->size[1] != 14) {
                        } else {
                          kstr = 0;
                          do {
                            exitg46 = 0;
                            if (kstr + 1 < 15) {
                              if (name->data[kstr] != cv11[kstr]) {
                                exitg46 = 1;
                              } else {
                                kstr++;
                              }
                            } else {
                              b_bool = true;
                              exitg46 = 1;
                            }
                          } while (exitg46 == 0);
                        }

                        if (b_bool) {
                          kstr = 11;
                        } else {
                          b_bool = false;
                          if (name->size[1] != 13) {
                          } else {
                            kstr = 0;
                            do {
                              exitg45 = 0;
                              if (kstr + 1 < 14) {
                                if (name->data[kstr] != cv12[kstr]) {
                                  exitg45 = 1;
                                } else {
                                  kstr++;
                                }
                              } else {
                                b_bool = true;
                                exitg45 = 1;
                              }
                            } while (exitg45 == 0);
                          }

                          if (b_bool) {
                            kstr = 12;
                          } else {
                            b_bool = false;
                            if (name->size[1] != 10) {
                            } else {
                              kstr = 0;
                              do {
                                exitg44 = 0;
                                if (kstr + 1 < 11) {
                                  if (name->data[kstr] != cv13[kstr]) {
                                    exitg44 = 1;
                                  } else {
                                    kstr++;
                                  }
                                } else {
                                  b_bool = true;
                                  exitg44 = 1;
                                }
                              } while (exitg44 == 0);
                            }

                            if (b_bool) {
                              kstr = 13;
                            } else {
                              b_bool = false;
                              if (name->size[1] != 10) {
                              } else {
                                kstr = 0;
                                do {
                                  exitg43 = 0;
                                  if (kstr + 1 < 11) {
                                    if (name->data[kstr] != cv14[kstr]) {
                                      exitg43 = 1;
                                    } else {
                                      kstr++;
                                    }
                                  } else {
                                    b_bool = true;
                                    exitg43 = 1;
                                  }
                                } while (exitg43 == 0);
                              }

                              if (b_bool) {
                                kstr = 14;
                              } else {
                                b_bool = false;
                                if (name->size[1] != 17) {
                                } else {
                                  kstr = 0;
                                  do {
                                    exitg42 = 0;
                                    if (kstr + 1 < 18) {
                                      if (name->data[kstr] != cv15[kstr]) {
                                        exitg42 = 1;
                                      } else {
                                        kstr++;
                                      }
                                    } else {
                                      b_bool = true;
                                      exitg42 = 1;
                                    }
                                  } while (exitg42 == 0);
                                }

                                if (b_bool) {
                                  kstr = 15;
                                } else {
                                  b_bool = false;
                                  if (name->size[1] != 14) {
                                  } else {
                                    kstr = 0;
                                    do {
                                      exitg41 = 0;
                                      if (kstr + 1 < 15) {
                                        if (name->data[kstr] != cv16[kstr]) {
                                          exitg41 = 1;
                                        } else {
                                          kstr++;
                                        }
                                      } else {
                                        b_bool = true;
                                        exitg41 = 1;
                                      }
                                    } while (exitg41 == 0);
                                  }

                                  if (b_bool) {
                                    kstr = 16;
                                  } else {
                                    b_bool = false;
                                    if (name->size[1] != 16) {
                                    } else {
                                      kstr = 0;
                                      do {
                                        exitg40 = 0;
                                        if (kstr + 1 < 17) {
                                          if (name->data[kstr] != cv17[kstr]) {
                                            exitg40 = 1;
                                          } else {
                                            kstr++;
                                          }
                                        } else {
                                          b_bool = true;
                                          exitg40 = 1;
                                        }
                                      } while (exitg40 == 0);
                                    }

                                    if (b_bool) {
                                      kstr = 17;
                                    } else {
                                      b_bool = false;
                                      if (name->size[1] != 13) {
                                      } else {
                                        kstr = 0;
                                        do {
                                          exitg39 = 0;
                                          if (kstr + 1 < 14) {
                                            if (name->data[kstr] != cv18[kstr])
                                            {
                                              exitg39 = 1;
                                            } else {
                                              kstr++;
                                            }
                                          } else {
                                            b_bool = true;
                                            exitg39 = 1;
                                          }
                                        } while (exitg39 == 0);
                                      }

                                      if (b_bool) {
                                        kstr = 18;
                                      } else {
                                        b_bool = false;
                                        if (name->size[1] != 18) {
                                        } else {
                                          kstr = 0;
                                          do {
                                            exitg38 = 0;
                                            if (kstr + 1 < 19) {
                                              if (name->data[kstr] != cv19[kstr])
                                              {
                                                exitg38 = 1;
                                              } else {
                                                kstr++;
                                              }
                                            } else {
                                              b_bool = true;
                                              exitg38 = 1;
                                            }
                                          } while (exitg38 == 0);
                                        }

                                        if (b_bool) {
                                          kstr = 19;
                                        } else {
                                          b_bool = false;
                                          if (name->size[1] != 18) {
                                          } else {
                                            kstr = 0;
                                            do {
                                              exitg37 = 0;
                                              if (kstr + 1 < 19) {
                                                if (name->data[kstr] !=
                                                    cv20[kstr]) {
                                                  exitg37 = 1;
                                                } else {
                                                  kstr++;
                                                }
                                              } else {
                                                b_bool = true;
                                                exitg37 = 1;
                                              }
                                            } while (exitg37 == 0);
                                          }

                                          if (b_bool) {
                                            kstr = 20;
                                          } else {
                                            b_bool = false;
                                            if (name->size[1] != 9) {
                                            } else {
                                              kstr = 0;
                                              do {
                                                exitg36 = 0;
                                                if (kstr + 1 < 10) {
                                                  if (name->data[kstr] !=
                                                      cv21[kstr]) {
                                                    exitg36 = 1;
                                                  } else {
                                                    kstr++;
                                                  }
                                                } else {
                                                  b_bool = true;
                                                  exitg36 = 1;
                                                }
                                              } while (exitg36 == 0);
                                            }

                                            if (b_bool) {
                                              kstr = 21;
                                            } else {
                                              b_bool = false;
                                              if (name->size[1] != 14) {
                                              } else {
                                                kstr = 0;
                                                do {
                                                  exitg35 = 0;
                                                  if (kstr + 1 < 15) {
                                                    if (name->data[kstr] !=
                                                        cv22[kstr]) {
                                                      exitg35 = 1;
                                                    } else {
                                                      kstr++;
                                                    }
                                                  } else {
                                                    b_bool = true;
                                                    exitg35 = 1;
                                                  }
                                                } while (exitg35 == 0);
                                              }

                                              if (b_bool) {
                                                kstr = 22;
                                              } else {
                                                b_bool = false;
                                                if (name->size[1] != 14) {
                                                } else {
                                                  kstr = 0;
                                                  do {
                                                    exitg34 = 0;
                                                    if (kstr + 1 < 15) {
                                                      if (name->data[kstr] !=
                                                          cv23[kstr]) {
                                                        exitg34 = 1;
                                                      } else {
                                                        kstr++;
                                                      }
                                                    } else {
                                                      b_bool = true;
                                                      exitg34 = 1;
                                                    }
                                                  } while (exitg34 == 0);
                                                }

                                                if (b_bool) {
                                                  kstr = 23;
                                                } else {
                                                  b_bool = false;
                                                  if (name->size[1] != 16) {
                                                  } else {
                                                    kstr = 0;
                                                    do {
                                                      exitg33 = 0;
                                                      if (kstr + 1 < 17) {
                                                        if (name->data[kstr] !=
                                                            cv24[kstr]) {
                                                          exitg33 = 1;
                                                        } else {
                                                          kstr++;
                                                        }
                                                      } else {
                                                        b_bool = true;
                                                        exitg33 = 1;
                                                      }
                                                    } while (exitg33 == 0);
                                                  }

                                                  if (b_bool) {
                                                    kstr = 24;
                                                  } else {
                                                    b_bool = false;
                                                    if (name->size[1] != 13) {
                                                    } else {
                                                      kstr = 0;
                                                      do {
                                                        exitg32 = 0;
                                                        if (kstr + 1 < 14) {
                                                          if (name->data[kstr]
                                                              != cv25[kstr]) {
                                                            exitg32 = 1;
                                                          } else {
                                                            kstr++;
                                                          }
                                                        } else {
                                                          b_bool = true;
                                                          exitg32 = 1;
                                                        }
                                                      } while (exitg32 == 0);
                                                    }

                                                    if (b_bool) {
                                                      kstr = 25;
                                                    } else {
                                                      b_bool = false;
                                                      if (name->size[1] != 26) {
                                                      } else {
                                                        kstr = 0;
                                                        do {
                                                          exitg31 = 0;
                                                          if (kstr + 1 < 27) {
                                                            if (name->data[kstr]
                                                                != cv26[kstr]) {
                                                              exitg31 = 1;
                                                            } else {
                                                              kstr++;
                                                            }
                                                          } else {
                                                            b_bool = true;
                                                            exitg31 = 1;
                                                          }
                                                        } while (exitg31 == 0);
                                                      }

                                                      if (b_bool) {
                                                        kstr = 26;
                                                      } else {
                                                        b_bool = false;
                                                        if (name->size[1] != 17)
                                                        {
                                                        } else {
                                                          kstr = 0;
                                                          do {
                                                            exitg30 = 0;
                                                            if (kstr + 1 < 18) {
                                                              if (name->
                                                                  data[kstr] !=
                                                                  cv27[kstr]) {
                                                                exitg30 = 1;
                                                              } else {
                                                                kstr++;
                                                              }
                                                            } else {
                                                              b_bool = true;
                                                              exitg30 = 1;
                                                            }
                                                          } while (exitg30 == 0);
                                                        }

                                                        if (b_bool) {
                                                          kstr = 27;
                                                        } else {
                                                          b_bool = false;
                                                          if (name->size[1] !=
                                                              27) {
                                                          } else {
                                                            kstr = 0;
                                                            do {
                                                              exitg29 = 0;
                                                              if (kstr + 1 < 28)
                                                              {
                                                                if (name->
                                                                    data[kstr]
                                                                    != cv28[kstr])
                                                                {
                                                                  exitg29 = 1;
                                                                } else {
                                                                  kstr++;
                                                                }
                                                              } else {
                                                                b_bool = true;
                                                                exitg29 = 1;
                                                              }
                                                            } while (exitg29 ==
                                                                     0);
                                                          }

                                                          if (b_bool) {
                                                            kstr = 28;
                                                          } else {
                                                            b_bool = false;
                                                            if (name->size[1] !=
                                                                18) {
                                                            } else {
                                                              kstr = 0;
                                                              do {
                                                                exitg28 = 0;
                                                                if (kstr + 1 <
                                                                    19) {
                                                                  if (name->
                                                                      data[kstr]
                                                                      !=
                                                                      cv29[kstr])
                                                                  {
                                                                    exitg28 = 1;
                                                                  } else {
                                                                    kstr++;
                                                                  }
                                                                } else {
                                                                  b_bool = true;
                                                                  exitg28 = 1;
                                                                }
                                                              } while (exitg28 ==
                                                                      0);
                                                            }

                                                            if (b_bool) {
                                                              kstr = 29;
                                                            } else {
                                                              b_bool = false;
                                                              if (name->size[1]
                                                                  != 24) {
                                                              } else {
                                                                kstr = 0;
                                                                do {
                                                                  exitg27 = 0;
                                                                  if (kstr + 1 <
                                                                      25) {
                                                                    if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv30[kstr])
                                                                    {
                                                                      exitg27 =
                                                                      1;
                                                                    } else {
                                                                      kstr++;
                                                                    }
                                                                  } else {
                                                                    b_bool =
                                                                      true;
                                                                    exitg27 = 1;
                                                                  }
                                                                } while (exitg27
                                                                      == 0);
                                                              }

                                                              if (b_bool) {
                                                                kstr = 30;
                                                              } else {
                                                                b_bool = false;
                                                                if (name->size[1]
                                                                    != 23) {
                                                                } else {
                                                                  kstr = 0;
                                                                  do {
                                                                    exitg26 = 0;
                                                                    if (kstr + 1
                                                                      < 24) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv31[kstr])
                                                                      {
                                                                      exitg26 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                    } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg26 =
                                                                      1;
                                                                    }
                                                                  } while
                                                                      (exitg26 ==
                                                                      0);
                                                                }

                                                                if (b_bool) {
                                                                  kstr = 31;
                                                                } else {
                                                                  b_bool = false;
                                                                  if (name->
                                                                      size[1] !=
                                                                      14) {
                                                                  } else {
                                                                    kstr = 0;
                                                                    do {
                                                                      exitg25 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 15) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv32[kstr])
                                                                      {
                                                                      exitg25 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg25 =
                                                                      1;
                                                                      }
                                                                    } while
                                                                      (exitg25 ==
                                                                      0);
                                                                  }

                                                                  if (b_bool) {
                                                                    kstr = 32;
                                                                  } else {
                                                                    b_bool =
                                                                      false;
                                                                    if
                                                                      (name->size
                                                                      [1] != 13)
                                                                    {
                                                                    } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg24 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 14) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv33[kstr])
                                                                      {
                                                                      exitg24 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg24 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg24 ==
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
                                                                      [1] != 20)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg23 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 21) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv34[kstr])
                                                                      {
                                                                      exitg23 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg23 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg23 ==
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
                                                                      [1] != 28)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg22 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 29) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv35[kstr])
                                                                      {
                                                                      exitg22 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg22 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg22 ==
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
                                                                      [1] != 27)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg21 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 28) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv36[kstr])
                                                                      {
                                                                      exitg21 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg21 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg21 ==
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
                                                                      [1] != 26)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg20 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 27) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv37[kstr])
                                                                      {
                                                                      exitg20 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg20 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg20 ==
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
                                                                      [1] != 26)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg19 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 27) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv38[kstr])
                                                                      {
                                                                      exitg19 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg19 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg19 ==
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
                                                                      [1] != 7)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg18 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 8) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv39[kstr])
                                                                      {
                                                                      exitg18 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg18 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg18 ==
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
                                                                      [1] != 25)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg17 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 26) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv40[kstr])
                                                                      {
                                                                      exitg17 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg17 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg17 ==
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
                                                                      [1] != 23)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg16 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 24) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv41[kstr])
                                                                      {
                                                                      exitg16 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg16 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg16 ==
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
                                                                      [1] != 30)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg15 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 31) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv42[kstr])
                                                                      {
                                                                      exitg15 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg15 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg15 ==
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
                                                                      [1] != 15)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg14 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 16) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv43[kstr])
                                                                      {
                                                                      exitg14 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg14 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg14 ==
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
                                                                      [1] != 13)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg13 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 14) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv44[kstr])
                                                                      {
                                                                      exitg13 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg13 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg13 ==
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
                                                                      [1] != 19)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg12 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 20) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv45[kstr])
                                                                      {
                                                                      exitg12 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg12 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg12 ==
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
                                                                      [1] != 14)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg11 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 15) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv46[kstr])
                                                                      {
                                                                      exitg11 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg11 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg11 ==
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
                                                                      [1] != 14)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg10 =
                                                                      0;
                                                                      if (kstr +
                                                                      1 < 15) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv47[kstr])
                                                                      {
                                                                      exitg10 =
                                                                      1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg10 =
                                                                      1;
                                                                      }
                                                                      } while
                                                                      (exitg10 ==
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
                                                                      [1] != 16)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg9 = 0;
                                                                      if (kstr +
                                                                      1 < 17) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv48[kstr])
                                                                      {
                                                                      exitg9 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg9 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg9 ==
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
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg8 = 0;
                                                                      if (kstr +
                                                                      1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv49[kstr])
                                                                      {
                                                                      exitg8 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg8 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg8 ==
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
                                                                      [1] != 6)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg7 = 0;
                                                                      if (kstr +
                                                                      1 < 7) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv50[kstr])
                                                                      {
                                                                      exitg7 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg7 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg7 ==
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
                                                                      [1] != 14)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg6 = 0;
                                                                      if (kstr +
                                                                      1 < 15) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv51[kstr])
                                                                      {
                                                                      exitg6 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg6 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg6 ==
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
                                                                      [1] != 13)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg5 = 0;
                                                                      if (kstr +
                                                                      1 < 14) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv52[kstr])
                                                                      {
                                                                      exitg5 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg5 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg5 ==
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
                                                                      [1] != 12)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg4 = 0;
                                                                      if (kstr +
                                                                      1 < 13) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv53[kstr])
                                                                      {
                                                                      exitg4 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg4 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg4 ==
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
                                                                      [1] != 15)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg3 = 0;
                                                                      if (kstr +
                                                                      1 < 16) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv54[kstr])
                                                                      {
                                                                      exitg3 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg3 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg3 ==
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
                                                                      [1] != 12)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg2 = 0;
                                                                      if (kstr +
                                                                      1 < 13) {
                                                                      if
                                                                      (name->data
                                                                      [kstr] !=
                                                                      cv55[kstr])
                                                                      {
                                                                      exitg2 = 1;
                                                                      } else {
                                                                      kstr++;
                                                                      }
                                                                      } else {
                                                                      b_bool =
                                                                      true;
                                                                      exitg2 = 1;
                                                                      }
                                                                      } while
                                                                      (exitg2 ==
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
                                                                      [1] != 13)
                                                                      {
                                                                      } else {
                                                                      kstr = 0;
                                                                      do {
                                                                      exitg1 = 0;
                                                                      if (kstr +
                                                                      1 < 14) {
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
    *val = (NOT_SET_VALUES);
    *toplevel = false;
    break;

   case 12:
    *val = (INSERT_VALUES);
    *toplevel = false;
    break;

   case 13:
    *val = (ADD_VALUES);
    *toplevel = false;
    break;

   case 14:
    *val = (MAX_VALUES);
    *toplevel = false;
    break;

   case 15:
    *val = (INSERT_ALL_VALUES);
    *toplevel = false;
    break;

   case 16:
    *val = (ADD_ALL_VALUES);
    *toplevel = false;
    break;

   case 17:
    *val = (INSERT_BC_VALUES);
    *toplevel = false;
    break;

   case 18:
    *val = (ADD_BC_VALUES);
    *toplevel = false;
    break;

   case 19:
    *val = (MAT_FINAL_ASSEMBLY);
    *toplevel = false;
    break;

   case 20:
    *val = (MAT_FLUSH_ASSEMBLY);
    *toplevel = false;
    break;

   case 21:
    *val = (MAT_LOCAL);
    *toplevel = false;
    break;

   case 22:
    *val = (MAT_GLOBAL_MAX);
    *toplevel = false;
    break;

   case 23:
    *val = (MAT_GLOBAL_SUM);
    *toplevel = false;
    break;

   case 24:
    *val = (MAT_ROW_ORIENTED);
    *toplevel = false;
    break;

   case 25:
    *val = (MAT_SYMMETRIC);
    *toplevel = false;
    break;

   case 26:
    *val = (MAT_STRUCTURALLY_SYMMETRIC);
    *toplevel = false;
    break;

   case 27:
    *val = (MAT_NEW_DIAGONALS);
    *toplevel = false;
    break;

   case 28:
    *val = (MAT_IGNORE_OFF_PROC_ENTRIES);
    *toplevel = false;
    break;

   case 29:
    *val = (MAT_USE_HASH_TABLE);
    *toplevel = false;
    break;

   case 30:
    *val = (MAT_KEEP_NONZERO_PATTERN);
    *toplevel = false;
    break;

   case 31:
    *val = (MAT_IGNORE_ZERO_ENTRIES);
    *toplevel = false;
    break;

   case 32:
    *val = (MAT_USE_INODES);
    *toplevel = false;
    break;

   case 33:
    *val = (MAT_HERMITIAN);
    *toplevel = false;
    break;

   case 34:
    *val = (MAT_SYMMETRY_ETERNAL);
    *toplevel = false;
    break;

   case 35:
    *val = (MAT_NEW_NONZERO_LOCATION_ERR);
    *toplevel = false;
    break;

   case 36:
    *val = (MAT_IGNORE_LOWER_TRIANGULAR);
    *toplevel = false;
    break;

   case 37:
    *val = (MAT_ERROR_LOWER_TRIANGULAR);
    *toplevel = false;
    break;

   case 38:
    *val = (MAT_GETROW_UPPERTRIANGULAR);
    *toplevel = false;
    break;

   case 39:
    *val = (MAT_SPD);
    *toplevel = false;
    break;

   case 40:
    *val = (MAT_NO_OFF_PROC_ZERO_ROWS);
    *toplevel = false;
    break;

   case 41:
    *val = (MAT_NO_OFF_PROC_ENTRIES);
    *toplevel = false;
    break;

   case 42:
    *val = (MAT_NEW_NONZERO_ALLOCATION_ERR);
    *toplevel = false;
    break;

   case 43:
    *val = (MAT_FACTOR_NONE);
    *toplevel = false;
    break;

   case 44:
    *val = (MAT_FACTOR_LU);
    *toplevel = false;
    break;

   case 45:
    *val = (MAT_FACTOR_CHOLESKY);
    *toplevel = false;
    break;

   case 46:
    *val = (MAT_FACTOR_ILU);
    *toplevel = false;
    break;

   case 47:
    *val = (MAT_FACTOR_ICC);
    *toplevel = false;
    break;

   case 48:
    *val = (MAT_FACTOR_ILUDT);
    *toplevel = false;
    break;

   case 49:
    *val = (NORM_1);
    *toplevel = false;
    break;

   case 50:
    *val = (NORM_2);
    *toplevel = false;
    break;

   case 51:
    *val = (NORM_FROBENIUS);
    *toplevel = false;
    break;

   case 52:
    *val = (NORM_INFINITY);
    *toplevel = false;
    break;

   case 53:
    *val = (NORM_1_AND_2);
    *toplevel = false;
    break;

   case 54:
    *val = (PETSC_DETERMINE);
    *toplevel = false;
    break;

   case 55:
    *val = (PETSC_DECIDE);
    *toplevel = false;
    break;

   case 56:
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
    emxEnsureCapacity((emxArray__common *)b_name, kstr, (int)sizeof(char));
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
