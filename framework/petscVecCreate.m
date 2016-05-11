function [vec, errCode, toplevel] = petscVecCreate(comm)
%Creates an empty vector object. The type then must be set with
%VecSetType() or VecSetFromOptions().
%
%  [vec, errCode] = petscVecCreate
%      Create a PETSc vector using PETSC_COMM_WORLD
%
%  [vec, errCode] = petscVecCreate(comm)
%      comm: MPI Communicator
%
%  SEE ALSO: petscVecSetType, petscVecSetFromOptions
%
% PETSc C interface:
%   PetscErrorCode  VecCreate(MPI_Comm comm, Vec *vec)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecCreate.html

%#codegen -args {MPI_Comm} petscVecCreate_World -args {}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_vec = coder.opaque('Vec');
    
    if nargin==0
        t_comm = MPI_Comm(PETSC_COMM_WORLD);
    else
        t_comm = MPI_Comm(comm);
    end
    
    errCode = coder.ceval('VecCreate', t_comm, coder.wref(t_vec));
    
    if nargout>2
        vec = opaque_obj('Vec', t_vec);
        toplevel = true;
    else
        vec = t_vec;
    end
    
    if errCode && (nargout<2 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'VecCreate returned error code %d\n', errCode)
    end
end
end
