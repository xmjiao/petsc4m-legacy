function [v, errCode, toplevel] = petscVecShift(v, a)
% Shifts all of the components of a vector by computing x[i] = x[i] + shift.
%
%  [v, errCode, toplevel] = petscVecShift(v, a) computes v = v + shift.
%
% PETSc C interface:
%   PetscErrorCode  VecShift(Vec v,PetscScalar shift)
% https://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecShift.html

%#codegen -args {PetscVec, PetscScalar(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('VecShift', PetscVec(v), a);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'petscVecShift returned error code %d\n', errCode)
    end
end
end
