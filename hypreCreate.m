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

% if nargin >= 4 && ~isempty(opts)
%     errCode = petscOptionsInsert(opts); assert(errCode==int32(0), 'petscOptionsInsert failed');
% end

%[pc, errCode] = petscPCCreate(MPI_COMM_WORLD); assert(errCode==int32(0), 'petscPCCreate failed');
% errCode = petscPCSetType(pc, PETSC_PCHYPRE); assert(errCode==int32(0), 'petscPCSetType failed');
% errCode = petscPCSetFromOptions(pc); assert(errCode==int32(0), 'PCSetFromOptions failed');

% errCode = petscPCSetOperators(pc, mat, mat); assert(errCode==int32(0), 'petscPCSetOperators failed');

% errCode = petscPCSetUp(pc); assert(errCode==int32(0), 'petscPCSetUp failed');

if nargin<4
    opts = '';
end

mat = petscMatCreateAIJFromCRS(row_ptr, col_ind, PetscScalar(val));
pc = petscKSPSetup(mat, PETSC_KSPPREONLY, PETSC_PCHYPRE, opts);

end

function test %#ok<DEFNU>
%!test
%!shared A, b
%! tmp = load('data/494_bus.mat');
%! A = tmp.Problem.A;
%! b = A*ones(size(A, 1), 1);

%! [Arows, Acols, Avals] = crs_matrix(A);
%! pc = hypreCreate(Arows, Acols, Avals);
%! x = hypreApply(pc, b);
%! pc = hypreDestroy(pc);

%! assert(norm(b - A*double(x)) < 0.1 * norm(b))

end
