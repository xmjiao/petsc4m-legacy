function [its, errCode, toplevel] = petscKSPGetIterationNumber(ksp)
%Gets the current iteration number.
%
%  [its, errCode] = petscKSPGetIterationNumber(ksp)
%
%  gets the current iteration number; if the KSPSolve() is complete, 
%  returns the number of iterations used. 
%
%  SEE ALSO: petscKSPGetConvergedReason, KSPGetResidualNorm, petscKSPGetTotalIterations
%
% PETSc C interface:
%   PetscErrorCode  KSPGetIterationNumber(KSP ksp,PetscInt *its)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetIterationNumber.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = PetscKSP(ksp);

    its = int32(0);
    errCode = coder.ceval('KSPGetIterationNumber', t_ksp, coder.wref(its));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetIterationNumber returned error code %d\n', errCode)
    end
end
end
