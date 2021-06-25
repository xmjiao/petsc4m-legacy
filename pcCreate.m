function pc = pcCreate(row_ptr, col_ind, val, pctype, opts)
% pcCreate Create a PETSc preconditioner for a matrix
%
%   pc = pcCreate(row_ptr, col_ind, val, opts)
%
% Input Arguments:
%   row_ptr, col_ind, val: contents of CRS matrix
%   pctype: ID of specific preconditioner or solver, such as PETSC_PCHYPRE,
%            or PETSC_MATSOLVERMUMPS, etc.
%   opts:  character string containing the PETSc options for the specific
%        preconditioner or solver, such as 
%        ' -pc_hypre_boomeramg_interp_type classical'
%
% Output Argument:
%   pc: The preconditioner object
%
% SEE ALSO:
%   pcApply, pcDestroy

% Create PetscPC object
[pc, errCode] = petscPCCreate(MPI_COMM_WORLD); assert(errCode==int32(0), 'petscPCCreate failed');

% Set the operators
mat = petscMatCreateAIJFromCRS(row_ptr, col_ind, PetscScalar(val));
errCode = petscPCSetOperators(pc, mat, mat); assert(errCode==int32(0), 'petscPCSetOperators failed');

% Set options for PetscPC
switch pctype
    case {PETSC_MATSOLVERMUMPS, PETSC_MATSOLVERSUPERLU, ...
            PETSC_MATSOLVERSUPERLU_DIST, PETSC_MATSOLVERMKL_PARDISO, ...
            PETSC_MATSOLVERUMFPACK}
        errCode = petscPCSetType(pc, PETSC_PCLU); assert(errCode==int32(0), 'petscPCSetType failed');
        petscOptionsInsert(['-pc_factor_mat_solver_type ' pctype]);
    otherwise
        errCode = petscPCSetType(pc, pctype); assert(errCode==int32(0), 'petscPCSetType failed');
end
if nargin >= 4 && ~isempty(opts)
    errCode = petscOptionsInsert(opts); assert(errCode==int32(0), 'petscOptionsInsert failed');
end
errCode = petscPCSetFromOptions(pc); assert(errCode==int32(0), 'PCSetFromOptions failed');

% Setup the preconditioner
errCode = petscPCSetUp(pc); assert(errCode==int32(0), 'petscPCSetUp failed');

end
