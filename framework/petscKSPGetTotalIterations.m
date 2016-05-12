function [its, errCode, toplevel] = petscKSPGetTotalIterations(ksp)
%Gets the total number of iterations this KSP object has performed
%since was created, counted over all linear solves
%
%  [its, errCode] = petscKSPGetTotalIterations(ksp)
%
%  SEE ALSO: KSPGetResidualNorm, petscKSPGetIterationNumber
%
% PETSc C interface:
%   PetscErrorCode  KSPGetTotalIterations(KSP ksp,PetscInt *its)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetTotalIterations.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = PetscKSP(ksp);
    
    its = int32(0);
    errCode = coder.ceval('KSPGetTotalIterations', t_ksp, coder.wref(its));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPGetTotalIterations returned error code %d\n', errCode)
    end
end
end
