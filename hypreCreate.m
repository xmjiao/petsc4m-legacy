function pc = hypreCreate(row_ptr, col_ind, val, opts)
% hypreCreate Create a hypre preconditioner for a matrix
%
%   pc = hypreCreate(row_ptr, col_ind, val, opts)
%
% Input Arguments:
%   row_ptr, col_ind, val: contents of CRS matrix
%   opts: character string containing the PETSc options such as
%        ' -pc_hypre_boomeramg_interp_type classical'
%
% Output Argument:
%   pc: The preconditioner object
%
% SEE ALSO:
%   hypreApply, hypreDestroy

if nargin >= 4 && ~isempty(opts)
    errCode = petscOptionsInsert(opts); assert(errCode==0, 'petscOptionsInsert failed');
end

[pc, errCode] = petscPCCreate(MPI_COMM_WORLD); assert(errCode==0, 'petscPCCreate failed'); 
errCode = petscPCSetType(pc, PETSC_PCHYPRE); assert(errCode==0, 'petscPCSetType failed'); 
errCode = petscPCSetFromOptions(pc); assert(errCode==0, 'PCSetFromOptions failed'); 

mat = petscMatCreateAIJFromCRS(row_ptr, col_ind, val);

errCode = petscPCSetOperators(pc, mat, mat); assert(errCode==0, 'petscPCSetOperators failed');

errCode = petscPCSetUp(pc); assert(errCode==0, 'petscPCSetUp failed');

end
