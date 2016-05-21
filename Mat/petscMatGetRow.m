function [ncols, cols, vals, errCode, toplevel] = petscMatGetRow(mat, row)
%Gets a row of a matrix. The indices are 0-based.
%
%  [ncols, cols, vals, errCode] = petscMatGetRow(mat, ni)
%  	mat   - the matrix
%
%  SEE ALSO: petscMatGetValues
%
% PETSc C interface:
%   PetscErrorCode MatGetRow(Mat mat,PetscInt row,PetscInt *ncols,
%       const PetscInt *cols[],const PetscScalar *vals[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatGetRow.html

%#codegen -args {PetscMat, int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = PetscMat(mat);
    
    t_ncols = int32(0);
    t_cols = coder.opaque('const int *');
    t_vals = coder.opaque('const double *');
    
    errCode = coder.ceval('MatGetRow', t_mat, row, coder.ref(t_ncols), ...
        coder.wref(t_cols), coder.wref(t_vals));
    
    toplevel = nargout>4;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatGetRow returned error code %d\n', errCode)
    end
    
    % Copy data out
    ncols = t_ncols;
    cols = coder.nullcopy(zeros(ncols, 1, 'int32'));
    vals = coder.nullcopy(zeros(ncols, 1));
    
    coder.ceval('memcpy', coder.ref(cols), t_cols, ncols*4);
    coder.ceval('memcpy', coder.ref(vals), t_vals, ncols*8);

    % Free PETSc internal storage
    errCode = coder.ceval('MatRestoreRow', t_mat, row, coder.ref(t_ncols), ...
        coder.ref(t_cols), coder.ref(t_vals));
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatRestoreRow returned error code %d\n', errCode)
    end    
end
end
