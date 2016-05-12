function mat = petscMatCreateFromCRS(row_ptr, col_ind, val, ncols, prefix)
% Creates a sparse matrix in PETSc from the CRS arrays format.
%
%    mat = petscMatCreateFromCRS(row_ptr, col_ind, val)
%      creates a PETSc matrix using the default sequential AIJ format.
%
%      row_ptr:   starting pointers for each row (1-based)
%      col_ind:   column indices in each row (1-based)
%      vals:      values in each row
%
%    mat = petscMatCreateFromCRS(row_ptr, col_ind, val, ncols, prefix)
%      ncols:     the global number of columns
%      prefix:    a character string specifics the prefix for the options.
%           If specified and is nonempty, the function will call
%           petscMatSetOptionsPrefix and then petscMatSetFromOptions
%           to set the matrix type. This can be used to created a parallel
%           matrix in PETSC_COMM_WORLD and set the local portion.
%
% SEE ALSO: petscVecCreateFromArray

%#codegen -args {coder.typeof(int32(0), [inf, 1]), coder.typeof(int32(0), [inf, 1]),
%#codegen coder.typeof(0, [inf, 1]), int32(0), coder.typeof(char(0), [1, inf])}

if nargin<3
    error('At least three arguments are required.');
end

n = int32(length(row_ptr)-1);

if nargin<4
    ncols = n;
end

% Count the number of nonzeros per row
nnz = coder.nullcopy(zeros(n, 1, 'int32'));
for i=1:n
    nnz(i) = row_ptr(i+1)-row_ptr(i);
end

if nargin<=3 || isempty(prefix)
    % Create default matrix using petscMatCreateSeqAIJ
    mat = petscMatCreateSeqAIJ(n, ncols, PETSC_DEFAULT, nnz);
    first_row = int32(0);
else
    mat = petscMatCreate;
    petscMatSetOptionsPrefix(mat, prefix);
    petscMatSetFromOptions(mat);
    petscMatSetSizes(mat, n, PETSC_DECIDE, PETSC_DETERMINE, ncols);
    % Since the matrix is may be parallel, 
    first_row = petscMatGetOwnershipRange(mat);
end

% Set values row by row
for i=1:n
    jidx = col_ind(row_ptr(i):row_ptr(i+1)-1)-1;
    rowval = val(row_ptr(i):row_ptr(i+1)-1);
    
    petscMatSetValues(mat, int32(1), i+first_row-1, nnz(i), jidx, rowval);
end

% Call assembly
petscMatAssemblyBegin(mat);
petscMatAssemblyEnd(mat);

end

function test %#ok<DEFNU>
%!test
%! b = sprand(100,100,0.3);
%! [rowptr, colind, val] = crs_createFromSparse(b); % This requires NumGeom
%! mat = petscMatCreateFromCRS(rowptr, colind, val);
%! [rowptr2, colind2, val2] = petscMatToCRS(mat);
%! assert(isequal(rowptr, rowptr2) && isequal(colind, colind2) && isequal(val, val2) );
end
