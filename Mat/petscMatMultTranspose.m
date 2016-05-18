function [errCode, toplevel] = petscMatMultTranspose(A, x, y)
%Computes matrix transpose times a vector.
%
%  [errCode, toplevel] = petscMatMultTranspose(A, x, y) computes y = A'x. The vectors
%    The vectors x and y cannot be the same; i.e., one cannot call MatMultTranspose(A,y,y).
%
%  SEE ALSO: petscMatMult, petscMatMultAdd, petscMatMultTransposeAdd
%
% PETSc C interface:
%   PetscErrorCode MatMultTranspose(Mat A,PetscScalar a,Mat X,MatStructure str)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatMultTranspose.html

%#codegen -args {PetscMat, PetscVec, PetscVec}
errCode = int32(-1);

if ~coder.target('MATLAB')
    errCode = coder.ceval('MatMultTranspose', PetscMat(A), PetscVec(x), PetscVec(y));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatMultTranspose returned error code %d\n', errCode)
    end
end
end
