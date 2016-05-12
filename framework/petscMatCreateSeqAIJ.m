function [mat, errCode, toplevel] = petscMatCreateSeqAIJ(m, n, nz, nnz, varargin)
%Creates a sparse matrix in AIJ (compressed row) format.
%
%  [mat, errCode] = petscMatCreateSeqAIJ(m, n, nz)
%
%   m   - number of rows
%   n   - number of columns
%   nz  - number of nonzeros per row (same for all rows)
%
%  [Mat, errCode] = petscMatCreateSeqAIJ(m, n, ~, nnz)
%
%   nnz - a column vector containing the number of nonzeros in the various 
%         rows (possibly different for each row)
%
%  [Mat, errCode] = petscMatCreateSeqAIJ(m, n, nz, [], ~)
%  [Mat, errCode] = petscMatCreateSeqAIJ(m, n, ~, nnz, ~)
%  This is an optimized version for returning an opaque PETSc Mat object
%  instead of a MATLAB PetscMat object. It should be used when
%  petscMatCreateSeqAIJ is not a top-level function for code generation.
%
%  Note that for good matrix assembly performance, the user should preallocate the
%  matrix storage by setting the parameter nz (or the array nnz). By setting
%  these parameters accurately. Performance during matrix assembly can be
%  increased by more than a factor of 50.
%
%  SEE ALSO: petscAssembleMat, petscMatDestroy
%
% PETSc C interface:
%   PetscErrorCode  MatCreateSeqAIJ(comm,PetscInt m,PetscInt n,PetscInt nz,const PetscInt nnz[],Mat *A)
%         where comm should always be PETSC_COMM_SELF.
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatCreateSeqAIJ.html

%#codegen -args {int32(0), int32(0), int32(0), coder.typeof(int32(0), [inf,1])} 
%#codegen petscMatCreateSeqAIJ_FixedRows -args {int32(0), int32(0), int32(0)}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat = coder.opaque('Mat');
    
    comm = MPI_Comm(PETSC_COMM_SELF);
    if nargin==3
        % When petscMatCreateSeqAIJ is used as a top-level function for code
        % generation, we need to wrap the result into an MATLAB opaque object.
        nnz = coder.opaque('PetscInt *', 'NULL');
        errCode = coder.ceval('MatCreateSeqAIJ', comm, m, n, nz, nnz, coder.wref(t_mat));

    else
        errCode = coder.ceval('MatCreateSeqAIJ', comm, m, n, nz, coder.rref(nnz), coder.wref(t_mat));
    end

    toplevel = nargout>2;
    if toplevel
        mat = opaque_obj('Mat', t_mat);
    else
        mat = t_mat;
    end
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatCreateSeqAIJ returned error code %d\n', errCode)
    end
end
end
