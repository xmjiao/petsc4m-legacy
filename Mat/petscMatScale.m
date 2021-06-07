function [mat, errCode, toplevel] = petscMatScale(mat, a)
% Scales all elements of a matrix by a given number.
%
%  [X, errCode, toplevel] = petscMatScale(X, a) computes X = a*X.
%
%  SEE ALSO: petscMatDiagonalScale
%
% PETSc C interface:
%   PetscErrorCode MatScale(Mat mat,PetscScalar a)
% https://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatScale.html

%#codegen -args {PetscMat, 0}

errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('MatScale', PetscMat(mat), a);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'petscMatScale returned error code %d\n', errCode)
    end
end
end
