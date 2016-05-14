function [errCode, toplevel] = petscVecCopy(x, y)
%Creates a vector from x to y.
%
%  errCode = petscVecCopy(x, y) copies the entries from x to y. Both
%  x and y must be distributed in the same manner; local copies are done.
%
%  SEE ALSO: petscVecDuplicate
%
% PETSc C interface:
%   PetscErrorCode  VecCopy(Vec x, Vec y)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecCopy.html

%#codegen -args {PetscVec, PetscVec}

errCode = int32(-1);

if ~coder.target('MATLAB')
    errCode = coder.ceval('VecCopy', PetscVec(x), PetscVec(y));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecCopy returned error code %d\n', errCode)
    end
end
end
