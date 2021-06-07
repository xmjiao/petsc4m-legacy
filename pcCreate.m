function pc = pcCreate(row_ptr, col_ind, val, type, opts)
% hypreCreate Create a hypre preconditioner
% 

if nargin<4
    type = PETSC_PCHYPRE;
end

if ~petscInitialized
    petscInitialize;
end

pc = petscPCCreate(MPI_COMM_WORLD);
petscPCSetType(pc, type);
mat = petscMatCreateAIJFromCRS(row_ptr, col_ind, val);

petscPCSetOperators(pc, mat, mat);

end