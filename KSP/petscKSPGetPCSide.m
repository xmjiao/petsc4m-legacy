function [side, errCode, toplevel] = petscKSPGetPCSide(ksp)
%Gets the preconditioning side.
%
%  [side, errCode] = petscKSPGetPCSide(ksp) returns the side of the KSP.
%
%  SEE ALSO:  petscKSPSetPCSide
%
% PETSc C interface:
%   PetscErrorCode  KSPGetPCSide(KSP ksp,PCSide *side)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetPCSide.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~isempty(coder.target)
    side = int32(0);
    errCode = coder.ceval('KSPGetPCSide', PetscKSP(ksp), coder.wref(side));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetPCSide returned error code %d\n', errCode)
    end
end
end
