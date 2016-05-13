function [ksp, errCode, toplevel] = petscKSPCreate(comm)
%Creates a preconditioner context.
%
%  [ksp, errCode] = petscKSPCreate
%      creates a PETSc KSP using PETSC_COMM_WORLD
%
%  [ksp, errCode] = petscKSPCreate(comm)
%      comm: MPI Communicator
%
%  SEE ALSO: petscKSPSetUp, petscKSPSolve, petscKSPDestroy
%
% PETSc C interface:
%   PetscErrorCode  KSPCreate(MPI_Comm comm,KSP *ksp)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPCreate.html

%#codegen -args {MPI_Comm} petscKSPCreate_World -args {}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_ksp = coder.opaque('KSP');
    
    if nargin==0
        t_comm = MPI_Comm(PETSC_COMM_WORLD);
    else
        t_comm = MPI_Comm(comm);
    end
    
    errCode = coder.ceval('KSPCreate', t_comm, coder.wref(t_ksp));
    
    toplevel = nargout>2;
    ksp = PetscKSP(t_ksp, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'KSPCreate returned error code %d\n', errCode)
    end
end
end
