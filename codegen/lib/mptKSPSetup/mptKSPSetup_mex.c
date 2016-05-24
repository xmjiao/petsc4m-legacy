/*
 * codegen/lib/mptKSPSetup/mptKSPSetup_mex.c
 *
 * Auxiliary code for mexFunction of mptKSPSetup
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscMat, PetscKSPType, PetscPCType, PetscMatSolverPackage} mptKSPSetup_1arg -args {PetscMat} mptKSPSetup_2args -args {PetscMat, PetscKSPType} mptKSPSetup_3args -args {PetscMat, PetscKSPType, PetscPCType}  enableInline=1 withPetsc=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "mptKSPSetup.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void mptKSPSetup_api(const mxArray ** prhs, const mxArray **plhs) {

    emxArray_char_T      ksptype;
    emxArray_char_T      pctype;
    emxArray_char_T      pcopt;

    struct0_T            Amat;
    struct0_T            ksp;
    mxArray              *_sub_mx1;

    real64_T             *time;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("mptKSPSetup:WrongInputType",
            "Input argument Amat has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("mptKSPSetup:InputStructWrongFields",
            "Input argument Amat has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("mptKSPSetup:WrongSizeOfInputArg",
            "Argument Amat must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("mptKSPSetup:WrongInputStruct",
            "Input argument Amat does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup:WrongInputType",
            "Input argument Amat.data has incorrect data type. uint8 is expected.");
    *(void**)&Amat.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)Amat.data, "Amat.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("mptKSPSetup:WrongInputStruct",
            "Input argument Amat does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup:WrongInputType",
            "Input argument Amat.type has incorrect data type. char is expected.");
    *(void**)&Amat.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)Amat.type, "Amat.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("mptKSPSetup:WrongInputStruct",
            "Input argument Amat does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup:WrongInputType",
            "Input argument Amat.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("mptKSPSetup:WrongSizeOfInputArg",
            "Argument Amat.nitems should be a scalar.");
    Amat.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup:WrongInputType",
            "Input argument ksptype has incorrect data type. char is expected.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)&ksptype, "ksptype", 2);
    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup:WrongInputType",
            "Input argument pctype has incorrect data type. char is expected.");
    alias_mxArray_to_emxArray(prhs[2], (emxArray__common *)&pctype, "pctype", 2);
    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup:WrongInputType",
            "Input argument pcopt has incorrect data type. char is expected.");
    alias_mxArray_to_emxArray(prhs[3], (emxArray__common *)&pcopt, "pcopt", 2);

    /* Preallocate output variables */
    *(void **)&ksp.data = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)ksp.data, 1);
    *(void **)&ksp.type = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)ksp.type, 2);
    {mwSize l_size[] = {1, 1};
    *(void **)&time = prealloc_mxArray((mxArray**)&plhs[1], mxDOUBLE_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    mptKSPSetup_initialize();

    mptKSPSetup(&Amat, &ksptype, &pctype, &pcopt, &ksp, time, toplevel);

    mptKSPSetup_terminate();

    /* Marshall out function outputs */
    {const char *_fields[] = { "data", "type", "nitems",  ""};
    int32_T _one=1;
    plhs[0] = create_struct_mxArray(1, &_one, 3, _fields);}
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 0, move_emxArray_to_mxArray((emxArray__common*)ksp.data, mxUINT8_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 1, move_emxArray_to_mxArray((emxArray__common*)ksp.type, mxCHAR_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 2, copy_scalar_to_mxArray(&ksp.nitems, mxINT32_CLASS));
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)Amat.type); mxFree(Amat.type);
    free_emxArray((emxArray__common*)Amat.data); mxFree(Amat.data);

    free_emxArray((emxArray__common*)&ksptype);
    free_emxArray((emxArray__common*)&pctype);
    free_emxArray((emxArray__common*)&pcopt);
    free_emxArray((emxArray__common*)ksp.type); mxFree(ksp.type);
    free_emxArray((emxArray__common*)ksp.data); mxFree(ksp.data);

}
void mptKSPSetup_1arg_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            Amat;
    struct0_T            ksp;
    mxArray              *_sub_mx1;

    real64_T             *time;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("mptKSPSetup_1arg:WrongInputType",
            "Input argument Amat has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("mptKSPSetup_1arg:InputStructWrongFields",
            "Input argument Amat has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("mptKSPSetup_1arg:WrongSizeOfInputArg",
            "Argument Amat must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("mptKSPSetup_1arg:WrongInputStruct",
            "Input argument Amat does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup_1arg:WrongInputType",
            "Input argument Amat.data has incorrect data type. uint8 is expected.");
    *(void**)&Amat.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)Amat.data, "Amat.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("mptKSPSetup_1arg:WrongInputStruct",
            "Input argument Amat does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup_1arg:WrongInputType",
            "Input argument Amat.type has incorrect data type. char is expected.");
    *(void**)&Amat.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)Amat.type, "Amat.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("mptKSPSetup_1arg:WrongInputStruct",
            "Input argument Amat does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup_1arg:WrongInputType",
            "Input argument Amat.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("mptKSPSetup_1arg:WrongSizeOfInputArg",
            "Argument Amat.nitems should be a scalar.");
    Amat.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    *(void **)&ksp.data = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)ksp.data, 1);
    *(void **)&ksp.type = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)ksp.type, 2);
    {mwSize l_size[] = {1, 1};
    *(void **)&time = prealloc_mxArray((mxArray**)&plhs[1], mxDOUBLE_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    mptKSPSetup_initialize();

    mptKSPSetup_1arg(&Amat, &ksp, time, toplevel);

    mptKSPSetup_terminate();

    /* Marshall out function outputs */
    {const char *_fields[] = { "data", "type", "nitems",  ""};
    int32_T _one=1;
    plhs[0] = create_struct_mxArray(1, &_one, 3, _fields);}
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 0, move_emxArray_to_mxArray((emxArray__common*)ksp.data, mxUINT8_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 1, move_emxArray_to_mxArray((emxArray__common*)ksp.type, mxCHAR_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 2, copy_scalar_to_mxArray(&ksp.nitems, mxINT32_CLASS));
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)Amat.type); mxFree(Amat.type);
    free_emxArray((emxArray__common*)Amat.data); mxFree(Amat.data);

    free_emxArray((emxArray__common*)ksp.type); mxFree(ksp.type);
    free_emxArray((emxArray__common*)ksp.data); mxFree(ksp.data);

}
void mptKSPSetup_2args_api(const mxArray ** prhs, const mxArray **plhs) {

    emxArray_char_T      ksptype;

    struct0_T            Amat;
    struct0_T            ksp;
    mxArray              *_sub_mx1;

    real64_T             *time;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("mptKSPSetup_2args:WrongInputType",
            "Input argument Amat has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("mptKSPSetup_2args:InputStructWrongFields",
            "Input argument Amat has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("mptKSPSetup_2args:WrongSizeOfInputArg",
            "Argument Amat must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("mptKSPSetup_2args:WrongInputStruct",
            "Input argument Amat does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup_2args:WrongInputType",
            "Input argument Amat.data has incorrect data type. uint8 is expected.");
    *(void**)&Amat.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)Amat.data, "Amat.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("mptKSPSetup_2args:WrongInputStruct",
            "Input argument Amat does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup_2args:WrongInputType",
            "Input argument Amat.type has incorrect data type. char is expected.");
    *(void**)&Amat.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)Amat.type, "Amat.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("mptKSPSetup_2args:WrongInputStruct",
            "Input argument Amat does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup_2args:WrongInputType",
            "Input argument Amat.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("mptKSPSetup_2args:WrongSizeOfInputArg",
            "Argument Amat.nitems should be a scalar.");
    Amat.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup_2args:WrongInputType",
            "Input argument ksptype has incorrect data type. char is expected.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)&ksptype, "ksptype", 2);

    /* Preallocate output variables */
    *(void **)&ksp.data = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)ksp.data, 1);
    *(void **)&ksp.type = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)ksp.type, 2);
    {mwSize l_size[] = {1, 1};
    *(void **)&time = prealloc_mxArray((mxArray**)&plhs[1], mxDOUBLE_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    mptKSPSetup_initialize();

    mptKSPSetup_2args(&Amat, &ksptype, &ksp, time, toplevel);

    mptKSPSetup_terminate();

    /* Marshall out function outputs */
    {const char *_fields[] = { "data", "type", "nitems",  ""};
    int32_T _one=1;
    plhs[0] = create_struct_mxArray(1, &_one, 3, _fields);}
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 0, move_emxArray_to_mxArray((emxArray__common*)ksp.data, mxUINT8_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 1, move_emxArray_to_mxArray((emxArray__common*)ksp.type, mxCHAR_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 2, copy_scalar_to_mxArray(&ksp.nitems, mxINT32_CLASS));
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)Amat.type); mxFree(Amat.type);
    free_emxArray((emxArray__common*)Amat.data); mxFree(Amat.data);

    free_emxArray((emxArray__common*)&ksptype);
    free_emxArray((emxArray__common*)ksp.type); mxFree(ksp.type);
    free_emxArray((emxArray__common*)ksp.data); mxFree(ksp.data);

}
void mptKSPSetup_3args_api(const mxArray ** prhs, const mxArray **plhs) {

    emxArray_char_T      ksptype;
    emxArray_char_T      pctype;

    struct0_T            Amat;
    struct0_T            ksp;
    mxArray              *_sub_mx1;

    real64_T             *time;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("mptKSPSetup_3args:WrongInputType",
            "Input argument Amat has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("mptKSPSetup_3args:InputStructWrongFields",
            "Input argument Amat has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("mptKSPSetup_3args:WrongSizeOfInputArg",
            "Argument Amat must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("mptKSPSetup_3args:WrongInputStruct",
            "Input argument Amat does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup_3args:WrongInputType",
            "Input argument Amat.data has incorrect data type. uint8 is expected.");
    *(void**)&Amat.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)Amat.data, "Amat.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("mptKSPSetup_3args:WrongInputStruct",
            "Input argument Amat does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup_3args:WrongInputType",
            "Input argument Amat.type has incorrect data type. char is expected.");
    *(void**)&Amat.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)Amat.type, "Amat.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("mptKSPSetup_3args:WrongInputStruct",
            "Input argument Amat does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup_3args:WrongInputType",
            "Input argument Amat.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("mptKSPSetup_3args:WrongSizeOfInputArg",
            "Argument Amat.nitems should be a scalar.");
    Amat.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup_3args:WrongInputType",
            "Input argument ksptype has incorrect data type. char is expected.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)&ksptype, "ksptype", 2);
    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("mptKSPSetup_3args:WrongInputType",
            "Input argument pctype has incorrect data type. char is expected.");
    alias_mxArray_to_emxArray(prhs[2], (emxArray__common *)&pctype, "pctype", 2);

    /* Preallocate output variables */
    *(void **)&ksp.data = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)ksp.data, 1);
    *(void **)&ksp.type = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)ksp.type, 2);
    {mwSize l_size[] = {1, 1};
    *(void **)&time = prealloc_mxArray((mxArray**)&plhs[1], mxDOUBLE_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    mptKSPSetup_initialize();

    mptKSPSetup_3args(&Amat, &ksptype, &pctype, &ksp, time, toplevel);

    mptKSPSetup_terminate();

    /* Marshall out function outputs */
    {const char *_fields[] = { "data", "type", "nitems",  ""};
    int32_T _one=1;
    plhs[0] = create_struct_mxArray(1, &_one, 3, _fields);}
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 0, move_emxArray_to_mxArray((emxArray__common*)ksp.data, mxUINT8_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 1, move_emxArray_to_mxArray((emxArray__common*)ksp.type, mxCHAR_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 2, copy_scalar_to_mxArray(&ksp.nitems, mxINT32_CLASS));
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)Amat.type); mxFree(Amat.type);
    free_emxArray((emxArray__common*)Amat.data); mxFree(Amat.data);

    free_emxArray((emxArray__common*)&ksptype);
    free_emxArray((emxArray__common*)&pctype);
    free_emxArray((emxArray__common*)ksp.type); mxFree(ksp.type);
    free_emxArray((emxArray__common*)ksp.data); mxFree(ksp.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 4) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("mptKSPSetup:TooManyOutputArguments","Too many output arguments for entry-point mptKSPSetup.");
        /* Call the API function. */
        mptKSPSetup_api(prhs, (const mxArray**)outputs);
    }
    else if (nrhs == 1) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("mptKSPSetup_1arg:TooManyOutputArguments","Too many output arguments for entry-point mptKSPSetup_1arg.");
        /* Call the API function. */
        mptKSPSetup_1arg_api(prhs, (const mxArray**)outputs);
    }
    else if (nrhs == 2) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("mptKSPSetup_2args:TooManyOutputArguments","Too many output arguments for entry-point mptKSPSetup_2args.");
        /* Call the API function. */
        mptKSPSetup_2args_api(prhs, (const mxArray**)outputs);
    }
    else if (nrhs == 3) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("mptKSPSetup_3args:TooManyOutputArguments","Too many output arguments for entry-point mptKSPSetup_3args.");
        /* Call the API function. */
        mptKSPSetup_3args_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("mptKSPSetup:WrongNumberOfInputs","Incorrect number of input variables for entry-point mptKSPSetup.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}