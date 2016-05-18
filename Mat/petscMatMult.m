function [errCode, toplevel] = petscMatMult(A, x, y)
%Computes the matrix-vector product, y = Ax.
%
%  [errCode, toplevel] = petscMatMult(A, x, y) computes y = Ax. The vectors
%     x and y cannot be the same; i.e., one cannot call MatMult(A,y,y).
%
%  SEE ALSO: petscMatMultTranspose, petscMatMultAdd, petscMatMultTransposeAdd
%
% PETSc C interface:
%   PetscErrorCode MatMult(Mat A,PetscScalar a,Mat X,MatStructure str)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatMult.html

%#codegen -args {PetscMat, PetscVec, PetscVec}
errCode = int32(-1);

if ~coder.target('MATLAB')
    errCode = coder.ceval('MatMult', PetscMat(A), PetscVec(x), PetscVec(y));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatMult returned error code %d\n', errCode)
    end
end
end
