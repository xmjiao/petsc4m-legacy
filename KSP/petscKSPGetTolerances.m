function [rtol, abstol, dtol, maxits, errCode, toplevel] = petscKSPGetTolerances(ksp)
%Gets the relative, absolute, divergence, and maximum iteration tolerances
%used by the default KSP convergence tests.
%
% Syntax:
%
%  [rtol, arg2, dtol, maxits, errCode, toplevel] = petscKSPGetTolerances(ksp)
%  obtains the relative, absolute, divergence tolerances and the max-iteration count.
%
%  SEE ALSO: petscKSPSetTolerances
%
% PETSc C interface:
%   PetscErrorCode  KSPGetTolerances(KSP ksp,PetscReal *rtol,PetscReal *abstol,PetscReal *dtol,PetscInt *maxits)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetTolerances.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = PetscKSP(ksp);
    
    rtol = double(0);
    abstol = double(0);
    dtol = double(0);
    maxits = int32(0);
    
    errCode = coder.ceval('KSPGetTolerances', t_ksp, coder.wref(rtol), ...
        coder.wref(abstol), coder.wref(dtol), coder.wref(maxits));
    
    toplevel = nargout>5;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetTolerances returned error code %d\n', errCode)
    end
end
end
