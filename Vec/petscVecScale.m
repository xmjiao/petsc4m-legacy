function [v, errCode, toplevel] = petscVecScale(v, a)
% Scales a vector.
%
%  [v, errCode, toplevel] = petscVecScale(v, a) computes v = a*v.
%
% PETSc C interface:
%   PetscErrorCode  VecScale(Vec x, PetscScalar alpha)
% https://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecScale.html

%#codegen -args {PetscVec, PetscScalar(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('VecScale', PetscVec(v), a);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'petscVecScale returned error code %d\n', errCode)
    end
end
end
