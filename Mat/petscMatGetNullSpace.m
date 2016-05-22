function [nullsp, errCode, toplevel] = petscMatGetNullSpace(mat)
%Retrieves the null space to a matrix.
%
%  [nullsp, errCode] = petscMatGetNullSpace(mat) gets the null space of
%  the matrix.
%
%  SEE ALSO
%  petscMatCreate, petscMatNullSpaceCreate, petscMatSetNearNullSpace, 
%  petscMatSetNullSpace
%
% PETSc C interface:
%   PetscErrorCode MatGetNullSpace(Mat mat, MatNullSpace *nullsp)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatGetNullSpace.html

%#codegen -args {PetscMat}

errCode = int32(-1);

if ~isempty(coder.target)
    t_nullsp = coder.opaque('MatNullSpace');
    errCode = coder.ceval('MatGetNullSpace', PetscMat(mat), coder.wref(t_nullsp));
    
    toplevel = nargout>2;
    nullsp = PetscMatNullSpace(t_nullsp, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatGetNullSpace returned error code %d\n', errCode)
    end
    
end
end
