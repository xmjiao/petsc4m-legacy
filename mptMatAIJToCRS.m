function [row_ptr, col_ind, val] = mptMatAIJToCRS(mat)
% Exports a sparse matrix in PETSc into CRS format.
%
%    [row_ptr, col_ind, val] = mptMatAIJToCRS(mat)
%      row_ptr:   starting pointers for each row (1-based)
%      col_ind:   column indices in each row (1-based)
%      vals:      values in each row
%
% SEE ALSO: mptMatAIJCreateFromCRS

[first_row, last_row] = petscMatGetOwnershipRange(mat);

nrows = last_row-first_row;
info = petscMatGetInfo(mat);
nnz = int32(info.nz_used);

row_ptr = coder.nullcopy(zeros(nrows+1, 1, 'int32'));
col_ind = coder.nullcopy(zeros(nnz, 1, 'int32'));
val = coder.nullcopy(zeros(nnz, 1));

ind = int32(1);
for row=1:nrows
    [ncols, row_cols, row_vals] = petscMatGetRow(mat, row+first_row-1);
    
    for j=1:ncols
        col_ind(j+ind-1) = row_cols(j) + 1;
        val(j+ind-1) = row_vals(j);
    end
    
    row_ptr(row) = ind;
    ind = ind + ncols;
end

row_ptr(nrows+1) = ind;
end

function test %#ok<DEFNU>
%!test
%! b = sprand(100,100,0.3);
%! [rowptr, colind, val] = crs_matrix(b);
%! mat = mptMatCreateAIJFromCRS(rowptr, colind, val);
%! [rowptr2, colind2, val2] = mptMatAIJToCRS(mat);
%! assert(isequal(rowptr, rowptr2) && isequal(colind, colind2) && isequal(val, val2) );
end

