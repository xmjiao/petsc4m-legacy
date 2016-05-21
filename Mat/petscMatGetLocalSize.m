function [m, n, errCode, toplevel] = petscMatGetLocalSize(mat)
%Returns the number of rows and columns in a matrix stored locally. 
%This information may be implementation dependent, so use with care.
%
%[m, n, errCode] = petscMatGetLocalSize(mat)
%  	mat   - the matrix
%   m     - the number of local rows
%   n     - the number of local columns
%
%  SEE ALSO: petscMatGetSize
%
% PETSc C interface:
%   PetscErrorCode MatGetLocalSize(Mat mat,PetscInt *m,PetscInt *n)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatGetLocalSize.html

%#codegen -args {PetscMat}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = PetscMat(mat);
    
    m = int32(0);
    n = int32(0);
    errCode = coder.ceval('MatGetLocalSize', t_mat, coder.wref(m), coder.wref(n));
    
    toplevel = nargout>3;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatGetLocalSize returned error code %d\n', errCode)
    end
end
end
