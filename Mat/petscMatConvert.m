function [mat_out, errCode, toplevel] = petscMatConvert(mat_in, newtype, reuse)
%Converts a matrix to another matrix, either of the same or different type.
%
%  [mat_out, errCode] = petscMatConvert(mat_in, newtype, reuse) creates a
%  new matrix. If newtype==MATSAME, the new matrix would be the same 
%  type as the original matrix. reuse denotes if the destination matrix 
%  is to be created or reused. Use MAT_INPLACE_MATRIX for inplace conversion, 
%  otherwise use MAT_INITIAL_MATRIX or MAT_REUSE_MATRIX.
%
%  SEE ALSO: petscMatCopy, petscMatDuplicate, petscMatDestroy
%
% PETSc C interface:
%   PetscErrorCode MatConvert(Mat mat, MatType newtype, MatReuse reuse, Mat *M)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatConvert.html

%#codegen -args {PetscMat, PetscMatType, int32(0)}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat_out = coder.opaque('Mat');
    
    errCode = coder.ceval('MatConvert', PetscMat(mat_in), coder.rref(newtype), ...
        reuse, coder.wref(t_mat_out));
    
    toplevel = nargout>2;
    mat_out = PetscMat(t_mat_out, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatConvert returned error code %d\n', errCode)
    end
end
end
