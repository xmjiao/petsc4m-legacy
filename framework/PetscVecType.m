function type = PetscVecType(arg) %#codegen
%Map an opaque object into a PETSc VecType object
%
% type = PetscVecType(arg)
%
% See also PetscVec, PetscMat

coder.inline('always');

if nargin==0 && isempty(coder.target)
    type = opaque_obj; return;
end

if isstruct(arg) && ~isequal(arg.type, 'VecType')
    m2c_error('PetscVecType:WrongType', ...
        'Incorrect data type %s. Expected VecType.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    type = arg;
else
    type = castdata('VecType', arg.data);
end
