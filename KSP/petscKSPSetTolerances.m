function [errCode, toplevel] = petscKSPSetTolerances(ksp, rtol, abstol, dtol, maxits)
%Sets the iteration tolerances used by the default KSP convergence testers.
%
% Syntax:
%
%  [errCode, toplevel] = petscKSPSetTolerances(ksp, rtol)
%  [errCode, toplevel] = petscKSPSetTolerances(ksp, rtol, abstol, dtol, maxits)
%
% Description
%
%  errCode = petscKSPSetTolerances(ksp, rtol) sets the relative tolerance
%       and let PETSc decides the rest.
%
%  errCode = petscKSPSetTolerances(ksp, rtol, abstol, dtol, maxits) sets 
%       the relative, absolute, divergence tolerances and the max-iteration count.
%
%  uses the matrix Pmat to construct the preconditioner.
%
%  SEE ALSO: petscKSPGetTolerances
%
% PETSc C interface:
%   PetscErrorCode  KSPSetTolerances(KSP ksp,PetscReal rtol,PetscReal abstol,PetscReal dtol,PetscInt maxits)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetTolerances.html

%#codegen -args {PetscKSP, 0, 0, 0, int32(0)}
%#codegen petscKSPSetTolerances_2args -args {PetscKSP, 0}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = PetscKSP(ksp);
    
    if nargin==2
        abstol = double(PETSC_DEFAULT);
        dtol = double(PETSC_DEFAULT);
        maxits = PETSC_DEFAULT;
    end
    
    errCode = coder.ceval('KSPSetTolerances', t_ksp, rtol, abstol, dtol, maxits);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPSetTolerances returned error code %d\n', errCode)
    end
end
end
