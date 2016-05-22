function [errCode, toplevel] = petscMatSetNullSpace(mat, nullSp)
%Attaches a null space to a matrix.
%
%   errCode = petscMatSetNullSpace(mat, nullSp)
%
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: 
%     petscMatCreate, petscMatNullSpaceCreate, petscMatSetNearNullSpace, 
%     petscMatGetNullSpace, petscMatSetTransposeNullSpace, 
%     petscMatGetTransposeNullSpace, petscMatNullSpaceRemove, 
%     petscMatNullSpaceCreateRigidBody
%
% PETSc C interface:
%   PetscErrorCode MatSetNullSpace(Mat mat, MatNullSpace nullsp)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSetNullSpace.html

%#codegen -args {PetscMat, PetscMatNullSpace}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = PetscMat(mat);
    t_nullSp = PetscMatNullSpace(nullSp);
    
    errCode = coder.ceval('MatSetNullSpace', t_mat, t_nullSp);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatSetNullSpace returned error code %d\n', errCode)
    end
end

end
