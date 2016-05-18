function [errCode, toplevel] = petscMatMultHermitianTranspose(A, x, y)
%Computes matrix Hermitian transpose times a vector.
%
%  [errCode, toplevel] = petscMatMultHermitianTranspose(A, x, y) computes 
%    y = A'x. The vectors The vectors x and y cannot be the same; i.e., 
%    one cannot call MatMultHermitianTranspose(A,y,y).
%
%  SEE ALSO: petscMatMult, petscMatMultAdd, petscMatMultTranspose, petscMatMultTransposeAdd
%
% PETSc C interface:
%   PetscErrorCode MatMultHermitianTranspose(Mat A,PetscScalar a,Mat X,MatStructure str)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatMultHermitianTranspose.html

%#codegen -args {PetscMat, PetscVec, PetscVec}
errCode = int32(-1);

if ~coder.target('MATLAB')
    errCode = coder.ceval('MatMultHermitianTranspose', PetscMat(A), PetscVec(x), PetscVec(y));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatMultHermitianTranspose returned error code %d\n', errCode)
    end
end
end
