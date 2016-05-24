function [errCode, toplevel] = petscKSPSetPCSide(ksp, side)
%Sets the preconditioning side.
%
%  errCode = petscKSPSetPCSide(ksp, side) sets the side of the KSP
%
%  SEE ALSO:  petscKSPGetPCSide
%
% PETSc C interface:
%   PetscErrorCode  KSPSetPCSide(KSP ksp, PCSide side)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetPCSide.html

%#codegen -args {PetscKSP, int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('KSPSetPCSide', PetscKSP(ksp), side);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPSetPCSide returned error code %d\n', errCode)
    end
end
end
