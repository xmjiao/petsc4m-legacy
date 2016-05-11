function type = PetscMatType(arg) %#codegen
%Map an opaque object into a PETSc MatType object
%
% type = PetscMatType(arg)
%
% See also PetscMat, PetscVec

coder.inline('always');

if nargin==0 && isempty(coder.target)
    type = opaque_obj; return;
end

if isstruct(arg) && ~isequal(arg.type, 'MatType')
    m2c_error('PetscMatType:WrongType', ...
        'Incorrect data type %s. Expected MatType.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    type = arg;
else
    type = castdata('MatType', arg.data);
end
