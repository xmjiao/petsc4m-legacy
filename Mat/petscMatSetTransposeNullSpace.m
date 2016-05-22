function [errCode, toplevel] = petscMatSetTransposeNullSpace(mat, nullSp)
%Attaches the left null space of a matrix.
%
%   errCode = petscMatSetTransposeNullSpace(mat, nullSp)
%
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO:
%     petscMatCreate, petscMatNullSpaceCreate, petscMatSetNullSpace,
%     petscMatGetNullSpace, petscMatGetTransposeNullSpace, 
%     petscMatNullSpaceRemove, petscMatNullSpaceCreateRigidBody
%
% PETSc C interface:
%   PetscErrorCode MatSetTransposeNullSpace(Mat mat, MatNullSpace nullsp)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSetTransposeNullSpace.html

%#codegen -args {PetscMat, PetscMatNullSpace}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = PetscMat(mat);
    t_nullSp = PetscMatNullSpace(nullSp);
    
    errCode = coder.ceval('MatSetTransposeNullSpace', t_mat, t_nullSp);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatSetTransposeNullSpace returned error code %d\n', errCode)
    end
end

end
