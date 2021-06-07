function [Y, errCode, toplevel] = petscMatShift(Y, a)
% Computes Y = Y + a I, where a is a scalar and I is the identity matrix.
%
%  [Y, errCode, toplevel] = petscMatShift(Y, a) computes Y = Y + a I.
%
%  SEE ALSO: petscMatDiagonalSet, petscMatScale, petscMatDiagonalScale
%
% PETSc C interface:
%   PetscErrorCode MatShift(Mat Y,PetscScalar a)
% https://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatShift.html

%#codegen -args {PetscMat, 0}

errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('MatShift', PetscMat(Y), a);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'petscMatShift returned error code %d\n', errCode)
    end
end
end
