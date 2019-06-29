function [mat, errCode, toplevel] = petscPCFactorGetMatrix(pc)
%Gets the factored matrix from the preconditioner context. This routine 
%is valid only for the LU, incomplete LU, Cholesky, and incomplete Cholesky methods.
%
%  [mat, errCode] = petscPCFactorGetMatrix(pc) gets the factor for the
%  matrix. 
%
% Notes: It does not increase the reference count for the matrix, so DO NOT
% destroy it.
%
%  SEE ALSO:  petscPCFactorSetMatSolverType,
%  petscPCFactorSetUpMatSolverType
%
% PETSc C interface:
%   PetscErrorCode  PCFactorGetMatrix(PC pc,Mat *mat)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCFactorGetMatrix.html

%#codegen -args {PetscPC}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = coder.opaque('Mat');
    errCode = coder.ceval('PCFactorGetMatrix', PetscPC(pc), coder.wref(t_mat));
    
    toplevel = nargout>2;
    mat = PetscMat(t_mat, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCFactorGetMatrix returned error code %d\n', errCode)
    end
end
end
