function [vec, errCode, toplevel] = petscVecCreateSeq(n)
%Creates a standard, sequential array-style vector.
%
%  [vec, errCode] = petscVecCreateSeq(n)
%  n - the vector length
%
%  SEE ALSO: petscAssembleVec, petscVecDestroy
%
% PETSc C interface:
%   PetscErrorCode  VecCreateSeq(MPI_Comm comm,PetscInt n,Vec *v)
%         where comm should always be PETSC_COMM_SELF.
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecCreateSeq.html

%#codegen -args {int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    t_vec = coder.opaque('Vec');
    
    comm = MPI_Comm(PETSC_COMM_SELF);
    errCode = coder.ceval('VecCreateSeq', comm, n, coder.wref(t_vec));
    
    toplevel = nargout>2;
    vec = PetscVec(t_vec, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecCreateSeq returned error code %d\n', errCode)
    end
end
end
