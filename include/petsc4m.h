/*
   petsc4m.h
 */

#ifndef __PETSC4M__
#define __PETSC4M__

#include "petscsys.h"
#include "petscksp.h"

typedef PetscErrorCode (*MatNullSpaceRemoveFunc)(MatNullSpace,Vec,void*);

/* Define some missing data types and constants for pre 3.7.0 versions */
#if PETSC_VERSION_LT(3,7,0)

#define MAT_INPLACE_MATRIX  (MAT_IGNORE_MATRIX+1)

#define MAT_SUBSET_OFF_PROC_ENTRIES  (MAT_NEW_NONZERO_ALLOCATION_ERR+1)

#define PetscOptions   PetscOption

#define MATNORMALHERMITIAN  "normalh"
#define MATPREALLOCATOR     "preallocator"

#define VECSEQCUDA          "seqcuda"
#define VECMPICUDA          "mpicuda"
#define VECCUDA             "cuda"

#define KSPPIPECGRR         "pipecgrr"
#define KSPPIPEFCG          "pipefcg"
#define KSPPIPEGCR          "pipefcr"
#define KSPPIPEFGMRES       "pipefgmres"
#define KSPPIPEFGMRES       "pipefgmres"
#define KSPTSIRM            "tsirm"
#define KSPCGLS             "cgls"

#define PCTELESCOPE         "telescope"

#define PetscOptionsInsertString(arg1, arg2)   PetscOptionsInsertString(arg2)
#define PetscOptionsInsertFile(arg1, arg2, arg3 , arg4)   PetscOptionsInsertFile(arg1, arg3, arg4)

#define PetscOptionsSetValue(arg1, arg2, arg3)   PetscOptionsSetValue(arg2, arg3)

#define PetscOptionsGetBool(arg1, arg2, arg3 , arg4, arg5)  PetscOptionsGetBool(arg2, arg3, arg4, arg5)
#define PetscOptionsGetInt(arg1, arg2, arg3 , arg4, arg5)  PetscOptionsGetInt(arg2, arg3, arg4, arg5)
#define PetscOptionsGetReal(arg1, arg2, arg3 , arg4, arg5)  PetscOptionsGetReal(arg2, arg3, arg4, arg5)
#define PetscOptionsGetString(arg1, arg2, arg3 , arg4, arg5, arg6)  PetscOptionsGetString(arg2, arg3, arg4, arg5, arg6)

#define PetscOptionsHasName(arg1, arg2, arg3 , arg4)  PetscOptionsHasName(arg2, arg3, arg4)

#endif /* __PETSC_PRE_3_7_0_ */

#endif /* __PETSC4M__ */
