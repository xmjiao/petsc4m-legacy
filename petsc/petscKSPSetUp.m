function [errCode, toplevel] = petscKSPSetUp(ksp)
%Sets up the internal data structures for the later use of an iterative solver.
%
%  errCode = petscKSPSetUp(ksp)
%
%  SEE ALSO: petscKSPCreate, petscKSPSetOperators, petscKSPSolve, petscKSPDestroy
%
% PETSc C interface:
%   PetscErrorCode KSPSetUp(KSP ksp)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetUp.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = PetscKSP(ksp);
    
    errCode = coder.ceval('KSPSetUp', t_ksp);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPSetUp returned error code %d\n', errCode)
    end
end
end
