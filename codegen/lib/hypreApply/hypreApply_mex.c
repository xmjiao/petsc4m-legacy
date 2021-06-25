/*
 * codegen/lib/hypreApply/hypreApply_mex.c
 *
 * Auxiliary code for mexFunction of hypreApply
 *
 * C source code generated by m2c.
 * %#m2c options:a1a24eaeceb78b64561d081664df0f1b
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "hypreApply.h"
#include "hypreApply_types.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void marshallin_const_M2C_OpaqueType(M2C_OpaqueType *pStruct, const mxArray *mx, const char *mname) {
    mxArray             *sub_mx;

    if (!mxIsStruct(mx))
        M2C_error("marshallin_const_M2C_OpaqueType:WrongType",
            "Input argument %s has incorrect data type; struct is expected.", mname);
    if (!mxGetField(mx, 0, "data"))
        M2C_error("marshallin_const_M2C_OpaqueType:WrongType",
            "Input argument %s is missing the field data.", mname);
    if (!mxGetField(mx, 0, "type"))
        M2C_error("marshallin_const_M2C_OpaqueType:WrongType",
            "Input argument %s is missing the field type.", mname);
    if (!mxGetField(mx, 0, "nitems"))
        M2C_error("marshallin_const_M2C_OpaqueType:WrongType",
            "Input argument %s is missing the field nitems.", mname);
    if (mxGetNumberOfFields(mx) > 3)
        M2C_warn("marshallin_const_M2C_OpaqueType:ExtraFields",
            "Extra fields in %s and are ignored.", mname);

    sub_mx = mxGetField(mx, 0, "data");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongInputType",
            "Input argument data has incorrect data type; uint8 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongSizeOfInputArg",
            "Dimension 2 of data should be equal to 1.");
    pStruct->data = (emxArray_uint8_T*)mxMalloc(sizeof(emxArray_uint8_T));
    init_emxArray((emxArray__common*)(pStruct->data), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->data), "data", 1);

    sub_mx = mxGetField(mx, 0, "type");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongInputType",
            "Input argument type has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[0] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongSizeOfInputArg",
            "Dimension 1 of type should be equal to 1.");
    pStruct->type = (emxArray_char_T*)mxMalloc(sizeof(emxArray_char_T));
    init_emxArray((emxArray__common*)(pStruct->type), 2);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->type), "type", 2);

    sub_mx = mxGetField(mx, 0, "nitems");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongInputType",
            "Input argument nitems has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongSizeOfInputArg",
            "Argument nitems should be a scalar.");
    pStruct->nitems = *(int32_T*)mxGetData(sub_mx);
}
static void destroy_M2C_OpaqueType(M2C_OpaqueType *pStruct) {

    free_emxArray((emxArray__common*)(pStruct->data));
    mxFree(pStruct->data);

    free_emxArray((emxArray__common*)(pStruct->type));
    mxFree(pStruct->type);


}


static void __hypreApply_api(mxArray **plhs, const mxArray ** prhs) {
    M2C_OpaqueType       pc;
    emxArray_real_T      x;
    emxArray_real_T      y;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("hypreApply:WrongInputType",
            "Input argument pc has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("hypreApply:WrongSizeOfInputArg",
            "Argument pc should be a scalar.");
    marshallin_const_M2C_OpaqueType(&pc, prhs[0], "pc");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("hypreApply:WrongInputType",
            "Input argument x has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(prhs[1]) && mxGetDimensions(prhs[1])[1] != 1) 
        mexErrMsgIdAndTxt("hypreApply:WrongSizeOfInputArg",
            "Dimension 2 of x should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)(&x), "x", 1);
    init_emxArray((emxArray__common*)(&y), 1);

    /* Invoke the target function */
    hypreApply(&pc, &x, &y);

    /* Deallocate input and marshall out function outputs */
    destroy_M2C_OpaqueType(&pc);
    free_emxArray((emxArray__common*)(&x));
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)(&y), mxDOUBLE_CLASS);
    mxFree(y.size);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    if (nrhs == 2) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("hypreApply:TooManyOutputArguments",
                "Too many output arguments for entry-point hypreApply.\n");
        /* Call the API function. */
        __hypreApply_api(plhs, prhs);
    }
    else
        mexErrMsgIdAndTxt("hypreApply:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point hypreApply.");
}
