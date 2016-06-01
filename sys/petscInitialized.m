function [initialized, errCode, toplevel] = petscInitialized
%Determine whether PETSc is initialized.
%   [initialized, errCode] = petscInitialized
%
%   initialized(int)
%   errCode(int) return code (0 indicates OK)
%
% SEE ALSO: petscInitialize, petscFinalize, PetscFinalized

% PETSc C interface:
%   PetscErrorCode PetscInitialized(PetscBool  *isInitialized)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscInitialized.html

%#codegen -args {}
initialized = int32(0);
errCode = int32(-1);

if ~isempty(coder.target)
    coder.cinclude('mpetsc.h');
    b = coder.opaque('PetscBool');
    errCode = coder.ceval('PetscInitialized', coder.wref(b));
    initialized = coder.ceval(' ', b);

    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscInitialized returned error code %d\n', errCode)
    end
end

end
