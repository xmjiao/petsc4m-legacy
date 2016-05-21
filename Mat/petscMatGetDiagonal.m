function [errCode, toplevel] = petscMatGetDiagonal(A, v)
%Gets the diagonal of a matrix.
%
%  errCode = petscMatGetDiagonal(mat, v) copies the diagonal entries of A
%     into vector v. Currently only correct in parallel for square matrices.
%
%  SEE ALSO: petscMatGetRow, petscMatGetSubMatrices, petscMatGetSubmatrix,
%            petscMatGetRowMaxAbs
%
% PETSc C interface:
%   PetscErrorCode MatGetDiagonal(Mat mat,Vec v)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatGetDiagonal.html

%#codegen -args {PetscMat, PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('MatGetDiagonal', PetscMat(A), PetscVec(v));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatGetDiagonal returned error code %d\n', errCode)
    end
end
end
