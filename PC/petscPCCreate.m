function [pc, errCode, toplevel] = petscPCCreate(comm)
%Creates a preconditioner context.
%
%  [pc, errCode] = petscPCCreate
%      creates a PETSc PC using PETSC_COMM_WORLD
%
%  [pc, errCode] = petscPCCreate(comm)
%      comm: MPI Communicator
%
%  SEE ALSO: petscPCSetUp, petscPCApply, petscPCDestroy
%
% PETSc C interface:
%   PetscErrorCode  PCCreate(MPI_Comm comm,PC *pc)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCCreate.html

%#codegen -args {MPI_Comm} petscPCCreate_World -args {}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_pc = coder.opaque('PC');
    
    if nargin==0
        t_comm = MPI_Comm(PETSC_COMM_WORLD);
    else
        t_comm = MPI_Comm(comm);
    end
    
    errCode = coder.ceval('PCCreate', t_comm, coder.wref(t_pc));
    
    toplevel = nargout>2;
    pc = PetscPC(t_pc, toplevel);
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'PCCreate returned error code %d\n', errCode)
    end
end
end
