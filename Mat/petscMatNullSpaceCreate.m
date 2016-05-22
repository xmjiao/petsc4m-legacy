function [nullsp, errCode, toplevel] = petscMatNullSpaceCreate(comm, has_cnst, n, vecs)
%Creates a data structure used to project vectors out of null spaces.
%
%  [nullsp, errCode] = petscMatNullSpaceCreate(comm, has_cnst)
%      comm: MPI Communicator (typically PETSC_COMM_WORLD)
%      has_cnst: PETSC_TRUE if the null space contains the constant vector; otherwise PETSC_FALSE
%
%  [nullsp, errCode] = petscMatNullSpaceCreate(comm, has_cnst, n, vecs)
%      n	- number of vectors (excluding constant vector) in null space
%      vecs	- the vectors that span the null space (excluding the constant
%             vector); these vectors must be orthonormal. These vectors are
%             NOT copied, so do not change them after this call. You should
%             free the array that you pass in and destroy the vectors (this
%             will reduce the reference count for them by one).
%
%  SEE ALSO: petscMatSetType, petscMatSetFromOptions
%
% PETSc C interface:
%   MatNullSpaceCreate(MPI_Comm comm,PetscBool has_cnst,PetscInt n,const Vec vecs[],MatNullSpace *SP)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatNullSpaceCreate.html

%#codegen -args {MPI_Comm, int32(0), int32(0), PetscVecArray}
%#codegen petscMatNullSpaceCreate_2args -args {MPI_Comm, int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    t_nullsp = coder.opaque('MatNullSpace');    
    t_comm = MPI_Comm(comm);
    
    if nargin<3; n = int32(0); end
    if nargin>3
        t_vecs = PetscVecArray(vecs);
    else
        t_vecs = coder.opaque('Vec *', 'NULL');
    end
    
    errCode = coder.ceval('MatNullSpaceCreate', t_comm, has_cnst, n, ...
        t_vecs, coder.wref(t_nullsp));
    
    toplevel = nargout>2;
    nullsp = PetscMatNullSpace(t_nullsp, toplevel);
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatNullSpaceCreate returned error code %d\n', errCode)
    end
end
end
