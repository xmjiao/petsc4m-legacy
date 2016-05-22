function [errCode, toplevel] = petscMatSetNearNullSpace(mat, nullSp)
%Attaches a null space to a matrix, which is often the null space (rigid body
%modes) of the operator without boundary conditions. This null space will be
%used to provide near null space vectors to a multigrid preconditioner
%built from this matrix.
%
%   errCode = petscMatSetNearNullSpace(mat, nullSp)
%
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO:
%     petscMatCreate, petscMatNullSpaceCreate, petscMatSetNullSpace,
%     petscMatGetNullSpace, petscMatSetTransposeNullSpace,
%     petscMatGetTransposeNullSpace, petscMatNullSpaceRemove,
%     petscMatNullSpaceCreateRigidBody
%
% PETSc C interface:
%   PetscErrorCode MatSetNearNullSpace(Mat mat, MatNullSpace nullsp)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSetNearNullSpace.html

%#codegen -args {PetscMat, PetscMatNullSpace}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = PetscMat(mat);
    t_nullSp = PetscMatNullSpace(nullSp);
    
    errCode = coder.ceval('MatSetNearNullSpace', t_mat, t_nullSp);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatSetNearNullSpace returned error code %d\n', errCode)
    end
end

end
