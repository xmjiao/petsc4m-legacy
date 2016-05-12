function [m, n, errCode, toplevel] = petscMatGetSize(mat)
%Returns the numbers of global rows and columns in a matrix.
%
%[m, n, errCode] = petscMatGetSize(mat)
%  	mat   - the matrix
%   m     - the number of global rows
%   n     - the number of global columns
%
%  SEE ALSO: petscMatSetSizes, petscMatGetLocalSize
%
% PETSc C interface:
%   PetscErrorCode MatGetSize(Mat mat,PetscInt *m,PetscInt *n)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatGetSize.html

%#codegen -args {PetscMat}

errCode = int32(-1);

if ~coder.target('MATLAB')
    t_mat = PetscMat(mat);
    
    m = int32(0);
    n = int32(0);
    errCode = coder.ceval('MatGetSize', t_mat, coder.wref(m), coder.wref(n));
    
    toplevel = nargout>3;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatGetSize returned error code %d\n', errCode)
    end
end
end
