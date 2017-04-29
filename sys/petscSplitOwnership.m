function [n, N, errCode, toplevel] = petscSplitOwnership(comm, n, N)
%Given a global (or local) length determines a local (or global) length.
%
%   [n, ~, errCode] = petscSplitOwnership(comm, PETSC_DECIDE, N)
%   [~, N, errCode] = petscSplitOwnership(comm, n, PETSC_DECIDE)
%	comm	- MPI communicator that shares the object being divided
%   n       - local length
%   N       - global length
%
%
% PETSc C interface:
%   PetscErrorCode  PetscSplitOwnership(MPI_Comm comm,PetscInt *n,PetscInt *N)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscSplitOwnership.html

%#codegen -args {MPI_Comm, int32(0), int32(0)}

errCode = int32(-1);
coder.cinclude('petsc4m.h');

if ~isempty(coder.target)
    t_comm = MPI_Comm(comm);
    
    if nargin<3
        N = PETSC_DECIDE;
    end
    errCode = coder.ceval('PetscSplitOwnership', t_comm, coder.ref(n), coder.ref(N));

    toplevel = nargout > 3;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PetscSplitOwnership returned error code %d\n', errCode)
    end
end
end
