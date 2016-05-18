function [errCode, toplevel] = petscMatMultHermitianTransposeAdd(A, v1, v2, v3)
%Computes v3 = v2 + A' * v1.
%
%  [errCode, toplevel] = petscMatMultHermitianTransposeAdd(A, v1, v2, v3)
%        computes v3 = v2 + A'* v1. The vectors v1 and v3 cannot be the same;
%        i.e., one cannot call MatMultHermitianTransposeAdd(A,v1,v2,v1).
%
%  SEE ALSO: petscMatMultHermitianTranspose, petscMatMultTransposeAdd, petscMatMultAdd
%
% PETSc C interface:
%   PetscErrorCode MatMultHermitianTransposeAdd(Mat mat,Vec v1,Vec v2,Vec v3)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatMultHermitianTransposeAdd.html

%#codegen -args {PetscMat, PetscVec, PetscVec, PetscVec}
errCode = int32(-1);

if ~coder.target('MATLAB')
    errCode = coder.ceval('MatMultHermitianTransposeAdd', PetscMat(A), PetscVec(v1), PetscVec(v2), PetscVec(v3));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatMultHermitianTransposeAdd returned error code %d\n', errCode)
    end
end
end
