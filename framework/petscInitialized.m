function [initialized, errCode] = petscInitialized
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

if ~coder.target('MATLAB')
    b = coder.opaque('PetscBool');
    errCode = coder.ceval('PetscInitialized', coder.wref(b));
    initialized = coder.ceval(' ', b);

    if errCode && (nargout<2 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'PetscInitialized returned error code %d\n', errCode)
    end
end

end
