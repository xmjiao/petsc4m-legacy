function [errCode, toplevel] = petscMatSetSizes(mat, m, n, M, N)
%Sets the local and global sizes, and checks to determine compatibility.
%
%errCode = petscMatSetSizes(mat, m, n)
%  	mat   - the matrix
%   m     - the number of local rows
%   n     - the number of local columns
%   In this case, the numbers of global rows and columns are PETSC_DETERMINE
%
% errCode = petscMatSetSizes(mat, m, n, M, N)
%   M	  - number of global rows
%   N	  - number of global columns
%   
%  SEE ALSO: petscMatGetSize, petscSplitOwnership
%
% PETSc C interface:
%   PetscErrorCode  MatSetSizes(Mat A, PetscInt m, PetscInt n, PetscInt M, PetscInt N)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSetSizes.html

%#codegen -args {PetscMat, int32(0), int32(0), int32(0), int32(0)}
%#codegen petscMatSetSizes_Local -args {PetscMat, int32(0), int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = PetscMat(mat);
    
    if nargin<4;
        M = PETSC_DETERMINE;
        N = PETSC_DETERMINE;
    end
    errCode = coder.ceval('MatSetSizes', t_mat, m, n, M, N);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatSetSizes returned error code %d\n', errCode)
    end
end
end
