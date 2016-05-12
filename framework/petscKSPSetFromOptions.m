function [errCode, toplevel] = petscKSPSetFromOptions(ksp)
%Sets KSP options from the options database. This routine must be called
%before KSPSetUp() if the user is to be allowed to set the Krylov type.
%
%  errCode = petscKSPSetFromOptions(ksp)
%
%  SEE ALSO: petscKSPCreate, petscKSPSetOperators, petscKSPSolve, petscKSPDestroy
%
% PETSc C interface:
%   PetscErrorCode KSPSetFromOptions(KSP ksp)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetFromOptions.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = PetscKSP(ksp);
    
    errCode = coder.ceval('KSPSetFromOptions', t_ksp);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPSetFromOptions returned error code %d\n', errCode)
    end
end
end
