function [val, errCode, toplevel] = petscVecDot(x, y)
%Computes the vector dot product.
%
%  [val, errCode] = petscVecDot(y, a, x) computes
%     y = a*x + y.
%
%  SEE ALSO: petscVecAYPX
%
% PETSc C interface:
%   PetscErrorCode  VecDot(Vec x,Vec y,PetscScalar *val)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDot.html

%#codegen -args {PetscVec, PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    val = double(0);
    errCode = coder.ceval('VecDot', PetscVec(x), PetscVec(y), coder.wref(val));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecDot returned error code %d\n', errCode)
    end
end
end
