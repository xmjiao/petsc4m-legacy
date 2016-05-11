function mat = petscMatCreateFromCRS(row_ptr, col_ind, val)
% Creates a sequential sparse matrix in PETSc from the CRS arrays format.
%    mat = petscMatCreateFromCRS(row_ptr, col_ind, val);

%#codegen -args {coder.typeof(int32(0), [inf, 1]), 
%#    coder.typeof(int32(0), [inf, 1]), coder.typeof(0, [inf, 1])}

n = int32(length(row_ptr)-1);

% Count the number of nonzeros per row
nnz = zeros(1, n, 'int32');
for i=1:n
    nnz(i) = row_ptr(i+1)-row_ptr(i);
end

% Create default matrix using petscMatCreateSeqAIJ
mat = petscMatCreateSeqAIJ(n, n, int32(0), nnz);

% Set values row by row
for i=1:n
    jidx = col_ind(row_ptr(i):row_ptr(i+1)-1)-1;
    rowval = val(row_ptr(i):row_ptr(i+1)-1);
    
    petscMatSetValues(mat, i, 1, nnz(i), jidx, rowval);
end

% Call assembly
petscMatAssemblyBegin(mat);
petscMatAssemblyEnd(mat);

end
