function [normtype, errCode, toplevel] = petscKSPGetNormType(ksp)
%Gets the norm that is used for convergence testing.
%
%  [normtype, errCode] = petscKSPGetNormType(ksp) returns the normt ype 
%  of the KSP.
%
%  SEE ALSO:  petscKSPSetNormType
%
% PETSc C interface:
%   PetscErrorCode  KSPGetNormType(KSP ksp, KSPNormType *normtype)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetNormType.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~isempty(coder.target)
    normtype = int32(0);
    errCode = coder.ceval('KSPGetNormType', PetscKSP(ksp), coder.wref(normtype));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetNormType returned error code %d\n', errCode)
    end
end
end
