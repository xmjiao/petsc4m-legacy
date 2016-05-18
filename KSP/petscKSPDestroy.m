function [ksp_out, errCode, toplevel] = petscKSPDestroy(ksp)
%Destroys KSP context.
%
%  [ksp, errCode] = petscKSPDestroy(ksp)
%
%  SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve
%
% PETSc C interface:
%   PetscErrorCode KSPDestroy(KSP *A)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPDestroy.html

%#codegen -args {PetscKSP}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = PetscKSP(ksp);
    
    errCode = coder.ceval('KSPDestroy', coder.ref(t_ksp));

    toplevel = nargout>2;
    ksp_out = PetscKSP(t_ksp, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPDestroy returned error code %d\n', errCode)
    end
end
end
