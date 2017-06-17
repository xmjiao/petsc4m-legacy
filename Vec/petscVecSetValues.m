function [errCode, toplevel] = petscVecSetValues(vec, ni, ix, y, iroa)
%Inserts or adds values into certain locations of a vector.
%
%  errCode = petscVecSetValues(vec, ni, ix, y)
%  	vec  - vector to insert in
%   ni   - number of elements to be inserted
%   ix   - (0-based) indices where to insert
%   y    - array of values
%
%   errCode = petscVecSetValues(vec, ni, ix, y, iora)
%   iora  - either PETSC_INSERT_VALUES or PETSC_ADD_VALUES, where
%           PETSC_INSERT_VALUES replaces existing entries with new values
%           (as above) and PETSC_ADD_VALUES adds values to any existing entries.
%
%  SEE ALSO: petscAssembleVec, VecAssemblyBegin(), VecAssemblyEnd(),
%            petscVecSet, petscVecCreate, petscVecDestroy
%
% PETSc C interface:
%   PetscErrorCode  VecSetValues(Vec x,PetscInt ni,const PetscInt ix[],const PetscScalar y[],InsertMode iora)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecSetValues.html

%#codegen -args {PetscVec, int32(0), coder.typeof(int32(0), [inf,1]), coder.typeof(0, [inf,1]), int32(0)}
%#codegen petscVecSetValues_Insert -args {PetscVec, int32(0), coder.typeof(int32(0), [inf,1]), coder.typeof(0, [inf,1])}

errCode = int32(-1);

if ~isempty(coder.target)
    if nargin<5
        iroa = PETSC_INSERT_VALUES;
    end

    t_vec = PetscVec(vec);

    errCode = coder.ceval('VecSetValues', t_vec, ni, coder.rref(ix), coder.rref(y), iroa);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecSetValues returned error code %d\n', errCode);
    end
end
end

function test %#ok<DEFNU>
%!test
%! vec_x = petscVecCreateSeq(int32(10));
%! y = rand(10, 1);
%! idx = int32(0:9)';
%!
%! errCode = petscVecSetValues(vec_x, int32(10), idx, y, PETSC_INSERT_VALUES);
%! result = petscVecToArray(vec_x);
%! petscVecDestroy(vec_x);
%!
%! assert(errCode == 0 && isequal(y, result));
end
