function [Amat, Pmat, errCode, toplevel] = petscKSPGetOperators(pc)
% Gets the matrix associated with the linear system and a (possibly) 
% different one associated with the preconditioner.
%
%  [Amat, Pmat, errCode] = petscKSPGetOperators(pc) gets the matrix operator. 
%
% Note: This function is to be useful when calling KSPCreate and KSPDestroy manually.
%
%  SEE ALSO:  petscKSPSetOperators
%
% PETSc C interface:
%   PetscErrorCode  KSPGetOperators(KSP ksp,Mat *Amat,Mat *Pmat)
% https://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetOperators.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~isempty(coder.target)
    Amat_t = coder.opaque('Mat');
    Pmat_t = coder.opaque('Mat');
    errCode = coder.ceval('KSPGetOperators', PetscKSP(pc), coder.wref(Amat_t), coder.wref(Pmat_t));
    
    toplevel = nargout>3;
    Amat = PetscMat(Amat_t, toplevel);
    Pmat = PetscMat(Pmat_t, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetOperators returned error code %d\n', errCode)
    end
end
end
