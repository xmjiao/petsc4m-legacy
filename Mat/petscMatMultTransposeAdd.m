function [errCode, toplevel] = petscMatMultTransposeAdd(A, v1, v2, v3)
%Computes v3 = v2 + A.' * v1.
%
%  [errCode, toplevel] = petscMatMultTransposeAdd(A, v1, v2, v3) computes 
%        v3 = v2 + A.'* v1. The vectors v1 and v3 cannot be the same; 
%        i.e., one cannot call MatMultTransposeAdd(A,v1,v2,v1).
%
%  SEE ALSO: petscMatMultTranspose, petscMatMultAdd, petscMatMultAdd
%
% PETSc C interface:
%   PetscErrorCode MatMultTransposeAdd(Mat mat,Vec v1,Vec v2,Vec v3)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatMultTransposeAdd.html

%#codegen -args {PetscMat, PetscVec, PetscVec, PetscVec}
errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('MatMultTransposeAdd', PetscMat(A), PetscVec(v1), PetscVec(v2), PetscVec(v3));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatMultTransposeAdd returned error code %d\n', errCode)
    end
end
end
