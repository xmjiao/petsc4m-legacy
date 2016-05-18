function [errCode, toplevel] = petscVecAXPY(y, a, x)
%Computes y = a*x + y.
%
%  errCode = [errCode, toplevel] = petscVecAXPY(y, a, x) computes
%     y = a*x + y. Notes: x and y MUST be different vectors
%
%  SEE ALSO: petscVecAYPX
%
% PETSc C interface:
%   PetscErrorCode VecAXPY(Vec y,PetscScalar a,Vec x)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecAXPY.html

%#codegen -args {PetscVec, 0, PetscVec}

errCode = int32(-1);

if ~coder.target('MATLAB')
    errCode = coder.ceval('VecAXPY', PetscVec(y), a, PetscVec(x));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecAXPY returned error code %d\n', errCode)
    end
end
end
