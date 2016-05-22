function [errCode, toplevel] = petscMatNullSpaceRemove(mat, vec)
%Removes all the components of a null space from a vector.
%
%   errCode = petscMatNullSpaceRemove(mat, vec)
%
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: 
% petscMatNullSpaceCreate, petscMatNullSpaceDestroy, petscMatNullSpaceSetFunction
%
% PETSc C interface:
%   PetscErrorCode  MatNullSpaceRemove(MatNullSpace sp,Vec vec)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatNullSpaceRemove.html

%#codegen -args {PetscMatNullSpace, PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('MatNullSpaceRemove', ...
        PetscMatNullSpace(mat), PetscVec(vec));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatNullSpaceRemove returned error code %d\n', errCode)
    end
end

end
