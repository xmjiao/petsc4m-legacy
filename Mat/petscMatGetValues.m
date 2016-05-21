function [v, errCode] = petscMatGetValues(mat, ni, ix, nj, jx, v)
%Gets a block of values from a matrix.
%
%  [v, errCode] = petscMatGetValues(mat, ni, ix, nj, jx)
%  	mat   - the matrix
%   ni,ix - the number of rows and their global (0-based) indices
%   nj,jx - the number of columns and their global (0-based) indices
%   v     - a logically two-dimensional array of values (by default it is
%           row majored but can be changed by calling petscMatSetOption.)
%
%  [v, errCode] = petscMatGetValues(mat, ni, ix, nj, jx, v)
%   uses the memory preallocated in the input v.
%
%  SEE ALSO: petscMatGetRow, petscMatSetValues
%
% PETSc C interface:
%   PetscErrorCode MatGetValues(Mat mat,PetscInt m,const PetscInt idxm[],
%       PetscInt n,const PetscInt idxn[],PetscScalar v[])
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatGetValues.html

%#codegen -args {PetscMat, int32(0), coder.typeof(int32(0), [inf,1]), int32(0),
%#codegen coder.typeof(int32(0), [inf,1]), coder.typeof(0, [inf,1])}
%#codegen petscMatGetValues_Alloc -args {PetscMat, int32(0), coder.typeof(int32(0),
%#codegen [inf,1]), int32(0), coder.typeof(int32(0), [inf,1])}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = PetscMat(mat);
    
    if nargin<6
        v = coder.nullcopy(zeros(ni*nj, 1));
    end
    
    errCode = coder.ceval('MatGetValues', t_mat, ni, coder.rref(ix), ...
        nj, coder.rref(jx), coder.ref(v));

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatGetValues returned error code %d\n', errCode)
    end
end
end
