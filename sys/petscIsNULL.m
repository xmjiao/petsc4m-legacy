function isn = petscIsNULL(obj, type)
% Determine whether a given object is a null opointer of a particular type.
%
%    isn = petscIsNULL(obj)
%    isn = petscIsNULL(obj, type)


if ischar(obj)
    isn = isempty(obj);
elseif nargin<2
    isn = ~isstruct(obj) && obj || isstruct(obj) && ~any(obj.data);
else
    switch type
        case 'Mat'
            isn = ~isstruct(obj) && obj || isstruct(obj) && ...
                isequal(obj, PetscMat(PETSC_NULL_MAT,true));
        case 'Vec'
            isn = ~isstruct(obj) && obj || isstruct(obj) && ...
                isequal(obj, PetscVec(PETSC_NULL_VEC,true));
        case 'PetscOptions'
            isn = ~isstruct(obj) && obj || isstruct(obj) && ...
                isequal(obj, PetscOptions(PETSC_NULL_OPTIONS,true));
        otherwise
            error('Unknown data type %s\n', type);
    end
end
