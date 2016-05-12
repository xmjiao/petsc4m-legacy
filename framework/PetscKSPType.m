function type = PetscKSPType(arg) %#codegen
%Map an opaque object into a PETSc KSPType object
%
% type = PetscKSPType(arg)
%
% See also PetscKSP, PetscVec

coder.inline('always');

if nargin==0 && isempty(coder.target)
    type = opaque_obj; return;
end

if isstruct(arg) && ~isequal(arg.type, 'KSPType')
    m2c_error('PetscKSPType:WrongType', ...
        'Incorrect data type %s. Expected KSPType.', [arg.type char(0)]);
end

if ~isstruct(arg) || isempty(coder.target)
    type = arg;
else
    type = castdata('KSPType', arg.data);
end
