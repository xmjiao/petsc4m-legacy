function [errCode, toplevel] = petscKSPSetTolerances(ksp, rtol, arg2, dtol, maxits)
%Sets the iteration tolerances used by the default KSP convergence testers.
%
% Syntax:
%
%  [errCode, toplevel] = petscKSPSetTolerances(ksp, rtol)
%  [errCode, toplevel] = petscKSPSetTolerances(ksp, rtol, maxits)
%  [errCode, toplevel] = petscKSPSetTolerances(ksp, rtol, abstol, dtol, maxits)
%
% Description
%
%  errCode = petscKSPSetTolerances(ksp, rtol) sets the relative tolerance
%       and let PETSc decides the rest.
%
%  errCode = petscKSPSetTolerances(ksp, maxits) sets the relative tolerance
%       and the maximum-iteration counts, and let PETSc decides the rest.
%
%  errCode = petscKSPSetTolerances(ksp, rtol, abstol, dtol, maxits) sets 
%       the relative, absolute, divergence tolerances and the max-iteration count.
%
%  uses the matrix Pmat to construct the preconditioner.
%
%  SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve, petscKSPDestroy
%
% PETSc C interface:
%   % PetscErrorCode  KSPSetTolerances(KSP ksp,PetscReal rtol,PetscReal abstol,PetscReal dtol,PetscInt maxits)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetTolerances.html

%#codegen -args {PetscKSP, 0, 0, 0, int32(0)}
%#codegen petscKSPSetTolerances_2args -args {PetscKSP, 0}
%#codegen petscKSPSetTolerances_3args -args {PetscKSP, 0, int32(0)}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = PetscKSP(ksp);
    
    if nargin==2
        abstol = PETSC_DEFAULT;
        dtol = PETSC_DEFAULT;
        maxits = PETSC_DEFAULT;
    elseif nargin==3
        maxits = arg2;
        abstol = PETSC_DEFAULT;
        dtol = PETSC_DEFAULT;
    else
        abstol = arg2;
    end
    
    errCode = coder.ceval('KSPSetTolerances', t_ksp, rtol, abstol, dtol, maxits);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPSetTolerances returned error code %d\n', errCode)
    end
end
end
