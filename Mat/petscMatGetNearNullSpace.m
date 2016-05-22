function [nullsp, errCode, toplevel] = petscMatGetNearNullSpace(mat)
%Retrieves the near null space attached to a matrix.
%
%  [nullsp, errCode] = petscMatGetNearNullSpace(mat) gets the near null
%  space attached to the matrix.
%
%  SEE ALSO
%  petscMatCreate, petscMatNullSpaceCreate, petscMatSetNearNullSpace,
%  petscMatSetNullSpace
%
% PETSc C interface:
%   PetscErrorCode MatGetNearNullSpace(Mat mat, MatNullSpace *nullsp)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatGetNearNullSpace.html

%#codegen -args {PetscMat}

errCode = int32(-1);

if ~isempty(coder.target)
    t_nullsp = coder.opaque('MatNullSpace');
    errCode = coder.ceval('MatGetNearNullSpace', PetscMat(mat), coder.wref(t_nullsp));
    
    toplevel = nargout>2;
    nullsp = PetscMatNullSpace(t_nullsp, toplevel);
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatGetNearNullSpace returned error code %d\n', errCode)
    end
    
end
end
