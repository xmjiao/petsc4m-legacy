function type = PetscPCType(arg) %#codegen
%Map an opaque object into a PETSc PCType object
%
% type = PetscPCType(arg)
%
% See also PetscPC, PetscVec

coder.inline('always');

if nargin==0 && isempty(coder.target)
    type = opaque_obj; return;
end

if isstruct(arg) && ~isequal(arg.type, 'PCType')
    m2c_error('PetscPCType:WrongType', ...
        'Incorrect data type %s. Expected PCType.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    type = arg;
else
    type = castdata('PCType', arg.data);
end
