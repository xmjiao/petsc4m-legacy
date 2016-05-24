function [errCode, toplevel] = petscKSPSetNormType(ksp, normtype)
%Sets the norm that is used for convergence testing.
%
%  errCode = petscKSPSetNormType(ksp, normtype) sets the normtype of the KSP
%
%  SEE ALSO:  petscKSPGetNormType
%
% PETSc C interface:
%   PetscErrorCode  KSPSetNormType(KSP ksp,KSPNormType normtype)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/petscKSPSetNormType.html

%#codegen -args {PetscKSP, int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('KSPSetNormType', PetscKSP(ksp), normtype);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPSetNormType returned error code %d\n', errCode)
    end
end
end
