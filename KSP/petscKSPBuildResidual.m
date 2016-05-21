function [errCode, toplevel] = petscKSPBuildResidual(ksp, v)
%Builds the residual in a vector provided.
%
%  errCode = petscKSPBuildResidual(ksp, v) computes the residual vector.
%
%  SEE ALSO: petscKSPCreate, petscKSPSolve
%
% PETSc C interface:
%   PetscErrorCode  KSPBuildResidual(KSP ksp,Vec t,Vec v,Vec *V)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPBuildResidual.html

%#codegen -args {PetscKSP, PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    t_ksp = PetscKSP(ksp);
    t_v = PetscVec(v);
    
    errCode = coder.ceval('KSPBuildResidual', t_ksp, PETSC_NULL_VEC, PETSC_NULL_VEC, coder.ref(t_v));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPBuildResidual returned error code %d\n', errCode)
    end
end
end
