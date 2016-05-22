/*
 * Mat/codegen/lib/petscMatNullSpaceCreate/petscMatNullSpaceCreate_mex.c
 *
 * Auxiliary code for mexFunction of petscMatNullSpaceCreate
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {MPI_Comm, int32(0), int32(0), PetscVecArray} petscMatNullSpaceCreate_2args -args {MPI_Comm, int32(0)}  enableInline=1 withPetsc=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscMatNullSpaceCreate.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscMatNullSpaceCreate_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            comm;
    struct0_T            vecs;
    struct0_T            nullsp;
    mxArray              *_sub_mx1;

    int32_T              has_cnst;
    int32_T              n;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument comm has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:InputStructWrongFields",
            "Input argument comm has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongSizeOfInputArg",
            "Argument comm must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputStruct",
            "Input argument comm does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument comm.data has incorrect data type. uint8 is expected.");
    *(void**)&comm.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)comm.data, "comm.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputStruct",
            "Input argument comm does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument comm.type has incorrect data type. char is expected.");
    *(void**)&comm.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)comm.type, "comm.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputStruct",
            "Input argument comm does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument comm.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongSizeOfInputArg",
            "Argument comm.nitems should be a scalar.");
    comm.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument has_cnst has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongSizeOfInputArg",
            "Argument has_cnst should be a scalar.");
    has_cnst = *(int32_T*)mxGetData(prhs[1]);
    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument n has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongSizeOfInputArg",
            "Argument n should be a scalar.");
    n = *(int32_T*)mxGetData(prhs[2]);

    if (!mxIsStruct(prhs[3]))
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument vecs has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[3])!=3)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:InputStructWrongFields",
            "Input argument vecs has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[3]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongSizeOfInputArg",
            "Argument vecs must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[3], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputStruct",
            "Input argument vecs does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument vecs.data has incorrect data type. uint8 is expected.");
    *(void**)&vecs.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)vecs.data, "vecs.data", 1);
    _sub_mx1 = mxGetField(prhs[3], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputStruct",
            "Input argument vecs does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument vecs.type has incorrect data type. char is expected.");
    *(void**)&vecs.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)vecs.type, "vecs.type", 2);
    _sub_mx1 = mxGetField(prhs[3], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputStruct",
            "Input argument vecs does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongInputType",
            "Input argument vecs.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongSizeOfInputArg",
            "Argument vecs.nitems should be a scalar.");
    vecs.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    *(void **)&nullsp.data = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)nullsp.data, 1);
    *(void **)&nullsp.type = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)nullsp.type, 2);
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[1], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscMatNullSpaceCreate_initialize();

    petscMatNullSpaceCreate(&comm, has_cnst, n, &vecs, &nullsp, errCode, toplevel);

    petscMatNullSpaceCreate_terminate();

    /* Marshall out function outputs */
    {const char *_fields[] = { "data", "type", "nitems",  ""};
    int32_T _one=1;
    plhs[0] = create_struct_mxArray(1, &_one, 3, _fields);}
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 0, move_emxArray_to_mxArray((emxArray__common*)nullsp.data, mxUINT8_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 1, move_emxArray_to_mxArray((emxArray__common*)nullsp.type, mxCHAR_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 2, copy_scalar_to_mxArray(&nullsp.nitems, mxINT32_CLASS));
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)comm.type); mxFree(comm.type);
    free_emxArray((emxArray__common*)comm.data); mxFree(comm.data);

    free_emxArray((emxArray__common*)vecs.type); mxFree(vecs.type);
    free_emxArray((emxArray__common*)vecs.data); mxFree(vecs.data);

    free_emxArray((emxArray__common*)nullsp.type); mxFree(nullsp.type);
    free_emxArray((emxArray__common*)nullsp.data); mxFree(nullsp.data);

}
void petscMatNullSpaceCreate_2args_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            comm;
    struct0_T            nullsp;
    mxArray              *_sub_mx1;

    int32_T              has_cnst;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongInputType",
            "Input argument comm has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:InputStructWrongFields",
            "Input argument comm has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongSizeOfInputArg",
            "Argument comm must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongInputStruct",
            "Input argument comm does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongInputType",
            "Input argument comm.data has incorrect data type. uint8 is expected.");
    *(void**)&comm.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)comm.data, "comm.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongInputStruct",
            "Input argument comm does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongInputType",
            "Input argument comm.type has incorrect data type. char is expected.");
    *(void**)&comm.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)comm.type, "comm.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongInputStruct",
            "Input argument comm does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongInputType",
            "Input argument comm.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongSizeOfInputArg",
            "Argument comm.nitems should be a scalar.");
    comm.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongInputType",
            "Input argument has_cnst has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:WrongSizeOfInputArg",
            "Argument has_cnst should be a scalar.");
    has_cnst = *(int32_T*)mxGetData(prhs[1]);

    /* Preallocate output variables */
    *(void **)&nullsp.data = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)nullsp.data, 1);
    *(void **)&nullsp.type = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)nullsp.type, 2);
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[1], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscMatNullSpaceCreate_initialize();

    petscMatNullSpaceCreate_2args(&comm, has_cnst, &nullsp, errCode, toplevel);

    petscMatNullSpaceCreate_terminate();

    /* Marshall out function outputs */
    {const char *_fields[] = { "data", "type", "nitems",  ""};
    int32_T _one=1;
    plhs[0] = create_struct_mxArray(1, &_one, 3, _fields);}
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 0, move_emxArray_to_mxArray((emxArray__common*)nullsp.data, mxUINT8_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 1, move_emxArray_to_mxArray((emxArray__common*)nullsp.type, mxCHAR_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 2, copy_scalar_to_mxArray(&nullsp.nitems, mxINT32_CLASS));
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)comm.type); mxFree(comm.type);
    free_emxArray((emxArray__common*)comm.data); mxFree(comm.data);

    free_emxArray((emxArray__common*)nullsp.type); mxFree(nullsp.type);
    free_emxArray((emxArray__common*)nullsp.data); mxFree(nullsp.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 4) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscMatNullSpaceCreate:TooManyOutputArguments","Too many output arguments for entry-point petscMatNullSpaceCreate.");
        /* Call the API function. */
        petscMatNullSpaceCreate_api(prhs, (const mxArray**)outputs);
    }
    else if (nrhs == 2) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscMatNullSpaceCreate_2args:TooManyOutputArguments","Too many output arguments for entry-point petscMatNullSpaceCreate_2args.");
        /* Call the API function. */
        petscMatNullSpaceCreate_2args_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscMatNullSpaceCreate:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscMatNullSpaceCreate.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}