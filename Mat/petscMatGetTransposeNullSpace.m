function [nullsp, errCode, toplevel] = petscMatGetTransposeNullSpace(mat)
%Retrieves the null space of the transpose of a matrix.
%
%  [nullsp, errCode] = petscMatGetTransposeNullSpace(mat) gets the left null
%  space attached to the matrix.
%
%  SEE ALSO
%  petscMatCreate, petscMatNullSpaceCreate, petscMatSetTransposeNullSpace,
%  petscMatSetNullSpace
%
% PETSc C interface:
%   PetscErrorCode MatGetTransposeNullSpace(Mat mat, MatNullSpace *nullsp)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatGetTransposeNullSpace.html

%#codegen -args {PetscMat}

errCode = int32(-1);

if ~isempty(coder.target)
    t_nullsp = coder.opaque('MatNullSpace');
    errCode = coder.ceval('MatGetTransposeNullSpace', PetscMat(mat), coder.wref(t_nullsp));
    
    toplevel = nargout>2;
    nullsp = PetscMatNullSpace(t_nullsp, toplevel);
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatGetTransposeNullSpace returned error code %d\n', errCode)
    end
    
end
end
