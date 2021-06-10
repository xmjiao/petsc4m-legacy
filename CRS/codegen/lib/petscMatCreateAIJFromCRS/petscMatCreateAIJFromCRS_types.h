#ifndef PETSCMATCREATEAIJFROMCRS_TYPES_H
#define PETSCMATCREATEAIJFROMCRS_TYPES_H

#include "rtwtypes.h"

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T
struct emxArray_char_T {
  char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif
#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T
typedef struct emxArray_char_T emxArray_char_T;
#endif

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T
struct emxArray_uint8_T {
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

#ifndef struct_emxArray_char_T_1x3
#define struct_emxArray_char_T_1x3
struct emxArray_char_T_1x3 {
  char data[3];
  int size[2];
};
#endif
#ifndef typedef_emxArray_char_T_1x3
#define typedef_emxArray_char_T_1x3
typedef struct emxArray_char_T_1x3 emxArray_char_T_1x3;
#endif

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  emxArray_uint8_T *data;
  emxArray_char_T_1x3 type;
  int nitems;
} struct0_T;
#endif

#endif
