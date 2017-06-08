/*
 * Vec/codegen/lib/petscVecNorm/petscVecNorm_mex.c
 *
 * Auxiliary code for mexFunction of petscVecNorm
 *
 * C source code generated by m2c.
 * %#m2c options:7795f6c2d4fc56ab2e8c477a95083e94
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscVecNorm.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void marshallin_const_struct0_T(struct0_T *pStruct, const mxArray *mx, const char *mname) {
    mxArray             *sub_mx;

    if (!mxIsStruct(mx))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s has incorrect data type; struct is expected.", mname);
    if (!mxGetField(mx, 0, "data"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field data.", mname);
    if (!mxGetField(mx, 0, "type"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field type.", mname);
    if (!mxGetField(mx, 0, "nitems"))
        M2C_error("marshallin_const_struct0_T:WrongType",
            "Input argument %s is missing the field nitems.", mname);
    if (mxGetNumberOfFields(mx) > 3)
        M2C_warn("marshallin_const_struct0_T:ExtraFields",
            "Extra fields in %s and are ignored.", mname);

    sub_mx = mxGetField(mx, 0, "data");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument data has incorrect data type; uint8 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Dimension 2 of data should equal 1.");
    pStruct->data = mxMalloc(sizeof(emxArray_uint8_T));
    init_emxArray((emxArray__common*)(pStruct->data), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->data), "data", 1);

    sub_mx = mxGetField(mx, 0, "type");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument type has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[0] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Dimension 1 of type should equal 1.");
    pStruct->type = mxMalloc(sizeof(emxArray_char_T));
    init_emxArray((emxArray__common*)(pStruct->type), 2);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->type), "type", 2);

    sub_mx = mxGetField(mx, 0, "nitems");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongInputType",
            "Input argument nitems has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_struct0_T:WrongSizeOfInputArg",
            "Argument nitems should be a scalar.");
    pStruct->nitems = *(int32_T*)mxGetData(sub_mx);
}
static void destroy_struct0_T(struct0_T *pStruct) {

    free_emxArray((emxArray__common*)(pStruct->data));
    mxFree(pStruct->data);

    free_emxArray((emxArray__common*)(pStruct->type));
    mxFree(pStruct->type);


}


static void __petscVecNorm_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            x;
    int32_T              type;
    real64_T            *nrm;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm:WrongInputType",
            "Input argument x has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscVecNorm:WrongSizeOfInputArg",
            "Argument x should be a scalar.");
    marshallin_const_struct0_T(&x, prhs[0], "x");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm:WrongInputType",
            "Input argument type has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscVecNorm:WrongSizeOfInputArg",
            "Argument type should be a scalar.");
    type = *(int32_T*)mxGetData(prhs[1]);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm:WrongInputType",
            "Input argument nrm has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(prhs[2]) && mxGetDimensions(prhs[2])[0] != 2) 
        mexErrMsgIdAndTxt("petscVecNorm:WrongSizeOfInputArg",
            "Dimension 1 of nrm should equal 2.");
    if (mxGetNumberOfElements(prhs[2]) && mxGetDimensions(prhs[2])[1] != 1) 
        mexErrMsgIdAndTxt("petscVecNorm:WrongSizeOfInputArg",
            "Dimension 2 of nrm should equal 1.");
    nrm = mxMalloc(sizeof(real64_T) * 2);
    copy_mxArray_to_DataSize(nrm, 1, NULL, prhs[2], "nrm", 2);

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscVecNorm(&x, type, nrm, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&x);
    /* Nothing to be done for type */
    plhs[0] = move_ioArray_to_mxArray(nrm, mxDOUBLE_CLASS, prhs[2]);
    plhs[1] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[2] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}

static void __petscVecNorm_2args_api(mxArray **plhs, const mxArray ** prhs) {
    struct0_T            x;
    int32_T              type;
    real64_T            *nrm;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongInputType",
            "Input argument x has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongSizeOfInputArg",
            "Argument x should be a scalar.");
    marshallin_const_struct0_T(&x, prhs[0], "x");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongInputType",
            "Input argument type has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongSizeOfInputArg",
            "Argument type should be a scalar.");
    type = *(int32_T*)mxGetData(prhs[1]);

    nrm = mxMalloc(sizeof(real64_T));

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscVecNorm_2args(&x, type, nrm, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    destroy_struct0_T(&x);
    /* Nothing to be done for type */
    plhs[0] = move_scalar_to_mxArray(nrm, mxDOUBLE_CLASS);
    plhs[1] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[2] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3] = {NULL, NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 3) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscVecNorm:TooManyOutputArguments",
                "Too many output arguments for entry-point petscVecNorm.\n");
        /* Call the API function. */
        __petscVecNorm_api(outputs, prhs);
    }
    else if (nrhs == 2) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscVecNorm_2args:TooManyOutputArguments",
                "Too many output arguments for entry-point petscVecNorm_2args.\n");
        /* Call the API function. */
        __petscVecNorm_2args_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscVecNorm:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscVecNorm.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
