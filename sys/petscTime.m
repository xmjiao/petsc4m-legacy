function [t, errCode, toplevel] = petscTime
%Returns the current time of day in seconds. This returns wall-clock time.
%
%    [t, errCode] = petscTime
%
% PETSc C interface:
%   PetscErrorCode PetscTime(PetscLogDouble *t)
%
% https://petsc.org/release/docs/manualpages/Sys/PetscTime/

%#codegen -args {}

errCode = int32(-1);

if ~isempty(coder.target)
    coder.cinclude('petsc4m.h');

    t = double(0);

    errCode = coder.ceval('PetscTime', coder.wref(t));

    toplevel = nargout > 2;

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'petscTime returned error code %d\n', errCode)
    end
end
end
