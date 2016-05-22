function [matNull, errCode, toplevel] = petscMatNullSpaceDestroy(matNull)
%Destroys a data structure used to project vectors out of null spaces.
%
%  PetscErrorCode  MatNullSpaceDestroy(MatNullSpace *sp)
%
%  SEE ALSO: 
%  petscMatNullSpaceCreate, petscMatNullSpaceRemove, petscMatNullSpaceSetFunction
%
% PETSc C interface:
%   PetscErrorCode MatNullSpaceDestroy(MatNullSpace *A)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatNullSpaceDestroy.html

%#codegen -args {PetscMatNullSpace}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = PetscMatNullSpace(matNull);
    
    errCode = coder.ceval('MatNullSpaceDestroy', coder.ref(t_mat));

    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatNullSpaceDestroy returned error code %d\n', errCode)
    end

    matNull = PetscMatNullSpace(t_mat, toplevel);
end
end
