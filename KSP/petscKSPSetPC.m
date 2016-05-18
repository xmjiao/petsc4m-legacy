function [errCode, toplevel] = petscKSPSetPC(ksp, pc)
%Sets the preconditioner to be used to calculate the application of 
%     the preconditioner on a vector.
%
%  errCode = petscKSPSetPC(ksp, pc) sets the pc of the KSP
%
%  SEE ALSO:  PetscKSPGetPC
%
% PETSc C interface:
%   PetscErrorCode  KSPSetPC(KSP ksp, PC pc)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetPC.html

%#codegen -args {PetscKSP, PetscPC}

errCode = int32(-1);

if ~coder.target('MATLAB')    
    errCode = coder.ceval('KSPSetPC', PetscKSP(ksp), PetscPC(pc));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPSetPC returned error code %d\n', errCode)
    end
end
end
