function [flag, errCode, toplevel] = petscKSPGetConvergedReason(ksp)
%Gets the reason the KSP iteration was stopped.
%
%  [flag, errCode] = petscKSPGetConvergedReason(ksp)
%
%  SEE ALSO: KSPGetResidualNorm, petscKSPGetIterationNumber
%
% PETSc C interface:
%   PetscErrorCode  KSPGetConvergedReason(KSP ksp,KSPConvergedReason *reason)
% http://www.mcs.anl.gov/petsc/petsc-3.7/docs/manualpages/KSP/KSPGetConvergedReason.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = PetscKSP(ksp);
    
    flag = int32(0);
    errCode = coder.ceval('KSPGetConvergedReason', t_ksp, coder.wref(flag));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetConvergedReason returned error code %d\n', errCode)
    end
end
end
