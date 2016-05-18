function [errCode, toplevel] = petscKSPSetType(ksp, type)
%Builds KSP for a particular solver.
%
%  errCode = petscKSPSetType(ksp, type) sets the type of the KSP
%
%  SEE ALSO:  PetscPCSetType, petscKSPCreate
%
% PETSc C interface:
%   PetscErrorCode  KSPSetType(KSP ksp, KSPType type)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetType.html

%#codegen -args {PetscKSP, PetscKSPType}

errCode = int32(-1);

if ~coder.target('MATLAB')
    if ischar(type)
        errCode = coder.ceval('KSPSetType', PetscKSP(ksp), coder.rref(type));
    else % If type is an opaque object of KSPType, do not pass by reference.
        errCode = coder.ceval('KSPSetType', PetscKSP(ksp), type);
    end
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPSetType returned error code %d\n', errCode)
    end
end
end
