function [errCode, toplevel] = petscMatNullSpaceSetFunction(nullSp, rmvFunc, ctx)
%Sets a function that removes a null space from a vector.
%
%   errCode = petscMatNullSpaceSetFunction(nullSp, rmvFunc)
%
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO:
%     petscMatCreate, petscMatNullSpaceCreate, petscMatSetNullSpace,
%     petscMatGetNullSpace, petscMatSetTransposeNullSpace,
%     petscMatGetTransposeNullSpace, petscMatNullSpaceRemove,
%     petscMatNullSpaceCreateRigidBody
%
% This is an advanced function and requires C programing for remvFunc.
%
% PETSc C interface:
%   PetscErrorCode  MatNullSpaceSetFunction(MatNullSpace sp,
%                   PetscErrorCode (*rem)(MatNullSpace,Vec,void*),void *ctx)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatNullSpaceSetFunction.html

%#codegen -args {PetscMatNullSpace, PetscMatNullSpaceRemoveFunc, m2c_opaque_ptr}

errCode = int32(-1);

if ~isempty(coder.target)
    t_nullSp = PetscMatNullSpace(nullSp);
    t_rmvFunc = PetscMatNullSpaceRemoveFunc(rmvFunc);
    t_ctx = m2c_opaque_ptr(ctx);
    
    errCode = coder.ceval('MatNullSpaceSetFunction', t_nullSp, t_rmvFunc, t_ctx);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatNullSpaceSetFunction returned error code %d\n', errCode)
    end
end

end
