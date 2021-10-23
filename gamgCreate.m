function pc = gamgCreate(row_ptr, col_ind, val, opts)
% gamgCreate Create a  preconditioner for a matrix
%
%   pc = gamgCreate(row_ptr, col_ind, val, opts)
%
% Input Arguments:
%   row_ptr, col_ind, val: contents of CRS matrix
%   opts: character string containing the PETSc options such as
%        ' -pc_gamg_boomeramg_interp_type classical'(TBD)
%
% Output Argument:
%   pc: The preconditioner object
%
% SEE ALSO:
%   gamgApply, gamgDestroy

if nargin >= 4 && ~isempty(opts)
    errCode = petscOptionsInsert(opts); assert(errCode==int32(0), 'petscOptionsInsert failed');
end

[pc, errCode] = petscPCCreate(MPI_COMM_WORLD); assert(errCode==int32(0), 'petscPCCreate failed');
errCode = petscPCSetType(pc, PETSC_PCGAMG); assert(errCode==int32(0), 'petscPCSetType failed');
errCode = petscPCSetFromOptions(pc); assert(errCode==int32(0), 'PCSetFromOptions failed');

mat = petscMatCreateAIJFromCRS(row_ptr, col_ind, PetscScalar(val));

errCode = petscPCSetOperators(pc, mat, mat); assert(errCode==int32(0), 'petscPCSetOperators failed');

errCode = petscPCSetUp(pc); assert(errCode==int32(0), 'petscPCSetUp failed');

end
