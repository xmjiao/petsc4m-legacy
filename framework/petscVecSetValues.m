function errCode = petscVecSetValues(vec, ni, ix, y, iroa)
%Inserts or adds values into certain locations of a vector.
%
%  errCode = petscVecSetValues(vec, ni, ix, y)
%  	vec  - vector to insert in
%   ni   - number of elements to be inserted
%   ix   - (0-based) indices where to insert
%   y    - array of values
%
%   errCode = petscVecSetValues(vec, ni, ix, y, iora)
%   iora  - either INSERT_VALUES or ADD_VALUES, where INSERT_VALUES
%           replaces existing entries with new values (as above) and
%           ADD_VALUES adds values to any existing entries.
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

if ~coder.target('MATLAB')
    if nargin<5
        iroa = PETSC_INSERT_VALUES;
    end
    
    t_vec = PetscVec(vec);
    
    errCode = coder.ceval('VecSetValues', t_vec, ni, coder.rref(ix), coder.rref(y), iroa);

    if errCode && (nargout==0 || coder.ismatlabthread)
        m2c_error('petsc:RuntimeError', 'VecSetValues returned error code %d\n', errCode)
    end
end
end
