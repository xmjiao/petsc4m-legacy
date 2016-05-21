function [rnorm, errCode, toplevel] = petscKSPGetResidualNorm(ksp)
%Gets the last (approximate preconditioned) residual norm that has been computed.
%
%  [rnorm, errCode] = petscKSPGetResidualNorm(ksp)
%
%  SEE ALSO: KSPGetResidualNorm, petscKSPGetIterationNumber
%
% PETSc C interface:
%   PetscErrorCode  KSPGetResidualNorm(KSP ksp,PetscInt *rnorm)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetResidualNorm.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~isempty(coder.target)
    t_ksp = PetscKSP(ksp);
    
    rnorm = 0;
    errCode = coder.ceval('KSPGetResidualNorm', t_ksp, coder.wref(rnorm));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetResidualNorm returned error code %d\n', errCode)
    end
end
end
