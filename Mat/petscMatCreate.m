function [mat, errCode, toplevel] = petscMatCreate(comm)
%Creates a matrix where the type is determined from either a call to
%MatSetType() or from the options database with a call to MatSetFromOptions().
%If you never call MatSetType() or MatSetFromOptions(), it will generate
%an error when you try to use the matrix. The default matrix type is AIJ.
%
%  [mat, errCode] = petscMatCreate
%      Create a PETSc matrix using PETSC_COMM_WORLD
%
%  [mat, errCode] = petscMatCreate(comm)
%      comm: MPI Communicator
%
%  SEE ALSO: petscMatSetType, petscMatSetFromOptions
%
% PETSc C interface:
%   PetscErrorCode  MatCreate(MPI_Comm comm,Mat *A)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatCreate.html

%#codegen -args {MPI_Comm} petscMatCreate_World -args {}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = coder.opaque('Mat');
    
    if nargin==0
        t_comm = MPI_Comm(PETSC_COMM_WORLD);
    else
        t_comm = MPI_Comm(comm);
    end
    
    errCode = coder.ceval('MatCreate', t_comm, coder.wref(t_mat));
    
    toplevel = nargout>2;
    mat = PetscMat(t_mat, toplevel);
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatCreate returned error code %d\n', errCode)
    end
end
end
