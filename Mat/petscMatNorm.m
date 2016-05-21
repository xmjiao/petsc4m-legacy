function [nrm, errCode, toplevel] = petscMatNorm(A, type)
%Calculates various norms of a matrix.
%
%  [nrm, errCode, toplevel] = petscMatNorm(A, type) computes the norm of 
%     matrix A of the given type, where type can be PETSC_NORM_1, 
%     PETSC_NORM_FROBENIUS, or NORM_INFINITY
%
%  SEE ALSO: petscVecNorm
%
% PETSc C interface:
%   PetscErrorCode MatNorm(Mat mat,NormType type,PetscReal *nrm)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatNorm.html

%#codegen -args {PetscMat, int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    nrm = double(0);
    errCode = coder.ceval('MatNorm', PetscMat(A), type, coder.wref(nrm));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatNorm returned error code %d\n', errCode)
    end
end
end
