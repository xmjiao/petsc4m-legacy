function [t, errCode, toplevel] = petscGetCPUTime
%Returns the CPU time in seconds used by the process.
%
%    [t, errCode] = petscGetCPUTime
%
% PETSc C interface:
%   PetscErrorCode PetscGetCPUTime(PetscLogDouble *t)
%
% https://petsc.org/release/docs/manualpages/Sys/PetscGetCPUTime/

%#codegen -args {}

errCode = int32(-1);

if ~isempty(coder.target)
    coder.cinclude('petsctime.h');

    t = double(0);

    errCode = coder.ceval('PetscGetCPUTime', coder.wref(t));

    toplevel = nargout > 2;

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'petscGetCPUTime returned error code %d\n', errCode)
    end
end
end
