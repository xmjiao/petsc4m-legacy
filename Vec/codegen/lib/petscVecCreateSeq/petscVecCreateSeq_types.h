#ifndef PETSCVECCREATESEQ_TYPES_H
#define PETSCVECCREATESEQ_TYPES_H
#include "rtwtypes.h"
#ifndef struct_emxArray_char_T_1x3
#define struct_emxArray_char_T_1x3

struct emxArray_char_T_1x3
{
  char data[3];
  int size[2];
};

#endif

#ifndef typedef_emxArray_char_T_1x3
#define typedef_emxArray_char_T_1x3

typedef struct emxArray_char_T_1x3 emxArray_char_T_1x3;

#endif

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

#ifndef struct_sKTBSjZ5yUw4dNg83KSwzI
#define struct_sKTBSjZ5yUw4dNg83KSwzI

struct sKTBSjZ5yUw4dNg83KSwzI
{
  emxArray_uint8_T *data;
  emxArray_char_T_1x3 type;
  int nitems;
};

#endif

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct sKTBSjZ5yUw4dNg83KSwzI struct0_T;

#endif
#endif
