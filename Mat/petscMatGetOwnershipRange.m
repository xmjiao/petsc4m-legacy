function [first_row, last_row, errCode, toplevel] = petscMatGetOwnershipRange(mat)
%Returns the range of matrix rows owned by this processor, assuming that 
%the matrix is laid out with the first n1 rows on the first processor, 
%the next n2 rows on the second, etc.
%
%   [first_row, ~, errCode] = petscMatGetOwnershipRange(mat)
%	mat	         - the matrix
%   first_row    - the global index of the first local row (0 based)
%   last_row     - one more than the global index of the last local row 
%
% PETSc C interface:
%   PetscErrorCode MatGetOwnershipRange(Mat mat,PetscInt *m,PetscInt *n)
% http://www.mcs.anl.gov/petsc/petsc-3.7/docs/manualpages/Mat/MatGetOwnershipRange.html

%#codegen -args {PetscMat}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = PetscMat(mat);
    
    first_row = int32(0);
    last_row = int32(0);

    errCode = coder.ceval('MatGetOwnershipRange', t_mat, coder.wref(first_row), coder.wref(last_row));
    
    toplevel = nargout>3;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatGetOwnershipRange returned error code %d\first_row', errCode)
    end
end
end
