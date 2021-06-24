function [errCode, toplevel] = petscMatSetValues(mat, ni, ix, nj, jx, v, iroa)
%Inserts or adds a block of values into a matrix. These values may be cached,
%so MatAssemblyBegin() and MatAssemblyEnd() must be called after all calls
%to MatSetValues() have been completed.
%
%  errCode = petscMatSetValues(mat, ni, ix, nj, jx, v)
%  	mat   - the matrix to insert in
%   ni,ix - the number of rows and their global (0-based) indices
%   nj,jx - the number of columns and their global (0-based) indices
%   v     - a logically two-dimensional array of values (by default it is
%           row majored but can be changed by calling petscMatSetOption.)
%
%  errCode = petscMatSetValues(mat, ni, ix, nj, jx, v, iora)
%   iora  - either INSERT_VALUES or ADD_VALUES, where INSERT_VALUES
%           replaces existing entries with new values and
%           ADD_VALUES adds values to any existing entries.
%
%  SEE ALSO: petscMatSetOption, petscMatAssemblyBegin, petscMatAssemblyEnd
%
% PETSc C interface:
%   PetscErrorCode MatSetValues(Mat mat,PetscInt m,const PetscInt idxm[],
%       PetscInt n,const PetscInt idxn[],const PetscScalar v[],InsertMode addv)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSetValues.html

%#codegen -args {PetscMat, int32(0), coder.typeof(int32(0), [inf,1]), int32(0),
%#codegen coder.typeof(int32(0), [inf,1]), coder.typeof(PetscScalar(0), [inf,1]), int32(0)}
%#codegen petscMatSetValues_Insert -args {PetscMat, int32(0), coder.typeof(int32(0),
%#codegen [inf,1]), int32(0), coder.typeof(int32(0), [inf,1]), coder.typeof(PetscScalar(0), [inf,1])}

errCode = int32(-1);
if nargin<7;
    iroa = PETSC_INSERT_VALUES;
end

if ~isempty(coder.target)
    t_mat = PetscMat(mat);
    
    errCode = coder.ceval('MatSetValues', t_mat, ni, coder.rref(ix), ...
        nj, coder.rref(jx), coder.rref(v), iroa);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatSetValues returned error code %d\n', errCode)
    end
end
end
