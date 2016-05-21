function [errCode, toplevel] = petscVecAYPX(y, a, x)
%Computes y = a*y + x.
%
%  errCode = [errCode, toplevel] = petscVecAYPX(y, a, x) computes
%     y = a*y + x. Notes: x and y MUST be different vectors
%
%  SEE ALSO: petscVecAXPY
%
% PETSc C interface:
%   PetscErrorCode VecAYPX(Vec y,PetscScalar a,Vec x)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecAYPX.html

%#codegen -args {PetscVec, 0, PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('VecAYPX', PetscVec(y), a, PetscVec(x));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecAYPX returned error code %d\n', errCode)
    end
end
end
