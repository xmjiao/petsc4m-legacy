function [errCode, toplevel] = petscKSPSolve(ksp, b, x)
%Solves linear system.
%
%  errCode = petscKSPSolve(ksp, b)
%
%  solves the linear system with b as the RHS and saves the solution into b.
%     ksp - iterative context obtained from petscKSPCreate()
%     b	  - the right hand side vector
%
%  errCode = petscKSPSolve(ksp, b, x)
%
%  solves the linear system and saves the solution into vector x.
%
%  SEE ALSO: petscKSPCreate, petscKSPSetOperators, petscKSPSetUp, petscKSPDestroy
%
% PETSc C interface:
%   PetscErrorCode KSPSolve(KSP ksp,Vec b,Vec x)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSolve.html

%#codegen -args {PetscKSP, PetscVec, PetscVec}
%#codegen petscKSPSolve_2args -args {PetscKSP, PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    t_ksp = PetscKSP(ksp);
    t_b = PetscVec(b);
    
    if nargin==2
        t_x = t_b;
    else
        t_x = PetscVec(x);
    end
    
    errCode = coder.ceval('KSPSolve', t_ksp, t_b, t_x);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPSolve returned error code %d\n', errCode)
    end
end
end
