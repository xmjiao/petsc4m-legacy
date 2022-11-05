function [errCode, toplevel] = petscBarrier(obj)
%Blocks until this routine is executed by all processors owning the object obj.
%
%          errCode = petscBarrier
%          errCode = petscBarrier(obj)
%
% PETSc C interface:
%   PetscErrorCode  PetscObjectGetComm(PetscObject obj,MPI_Comm *comm)
%
% https://petsc.org/release/docs/manualpages/Sys/PetscBarrier/

%#codegen -args {PetscObject} petscBarrier0 -args {}

errCode = int32(-1);

if ~isempty(coder.target)
    coder.cinclude('petsc4m.h');

    if nargin == 0
        obj = PETSC_NULL;
    end

    t_obj = PetscObject(obj);

    errCode = coder.ceval('PetscBarrier', t_obj);

    toplevel = nargout>1;

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'petscBarirer returned error code %d\n', errCode)
    end
end
end
